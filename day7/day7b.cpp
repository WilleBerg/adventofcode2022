#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <stack>

class File {
    public:
        int size;
        std::string name; 
};

class Dir {
    public:
        std::set<std::string> s;
        int sizeTotal = 0;
        int checkedDirsLeft = 0;
        std::set<std::string> set;
        std::set<std::string> setFile;
        std::map<std::string, Dir> dirMap;
        std::string name;
        bool hasAdded = false;
};

std::vector<std::string> split(std::string s, char delim) {
    std::vector<std::string> result;
    std::string tmp = "";
    for(int i = 0; i < s.length(); i++) {
        if(s[i] != delim) tmp += s[i];
        else {
            result.push_back(tmp);
            tmp = "";
        }
    }
    result.push_back(tmp);
    return result;
}

int main() {
    std::fstream f;
    std::vector<std::string> v;
    f.open("./day7/input.txt");
    if(f.is_open()) {
        while (f) {
            std::string tmp;
            getline(f, tmp);
            if (tmp == "") continue;
            v.push_back(tmp);
        }
    }
    std::cout << "Read file" << std::endl;
    Dir current;
    current.name = "/";
    int total = 0;
    std::stack<Dir> stack;
    int totalAll = 0;
    for(int i = 0; i < v.size(); i++) {
        std::vector<std::string> tmp = split(v[i], ' ');
        if(v[i][0] == '$') {
            std::cout << "Command " << v[i] << std::endl;
            if(tmp[1] == "cd") {
                if(tmp[2] == "/"){
                    continue;
                } else if (tmp[2] == ".."){
                    stack.top().sizeTotal += current.sizeTotal;
                    if (current.sizeTotal <= 100000 && !current.hasAdded) {
                        current.hasAdded = false; 
                        total += current.sizeTotal;
                    }
                    current = stack.top();
                    stack.pop();
                    std::cout << "Now in dir " << current.name << std::endl;
                } else {
                    stack.push(current);
                    current = current.dirMap[tmp[2]];
                    std::cout << "  Now in dir " << current.name << std::endl;
                }
            } else {
                continue;
            }
        } else {
            std::cout << v[i] << std::endl;
            if(tmp[0] == "dir") {
                Dir newDir;
                newDir.name = tmp[1];
                current.dirMap[newDir.name] = newDir;
                current.checkedDirsLeft++;
                std::cout << "  Added new dir to " << current.name << std::endl;
                
            } else {
                if (current.s.find(tmp[1]) != current.s.end()) continue;
                File file;
                std::cout << "  Added new file to " << current.name << std::endl;
                file.size = stoi(tmp[0]);
                file.name = tmp[1];
                current.sizeTotal += file.size;
                totalAll += file.size;
                current.setFile.insert(tmp[1]);
            }
        }
    }
    if (current.sizeTotal <= 100000) total += current.sizeTotal;
    std::cout << totalAll << std::endl;
    int unusedSize = 70000000 - totalAll;
    int sizeToRemove = 30000000 - unusedSize;
    std::cout << sizeToRemove << std::endl;
    std::cout << total << std::endl;
    Dir newDir2;
    current = newDir2;
    current.name = "/";
    std::stack<Dir> stack2;
    int smallestRemove = INT32_MAX;
    for(int i = 0; i < v.size(); i++) {
        std::vector<std::string> tmp = split(v[i], ' ');
        if(v[i][0] == '$') {
            if(tmp[1] == "cd") {
                if(tmp[2] == "/"){
                    continue;
                } else if (tmp[2] == ".."){
                    stack2.top().sizeTotal += current.sizeTotal;
                    std::cout << "Current sizeTotal " << current.sizeTotal << std::endl;
                    if (current.sizeTotal > sizeToRemove && current.sizeTotal < smallestRemove) {
                        std::cout << current.sizeTotal << " is smaller than " << smallestRemove << " and larger than " << sizeToRemove << std::endl;
                        smallestRemove = current.sizeTotal;
                    }
                    current = stack2.top();
                    stack2.pop();
                } else {
                    stack2.push(current);
                    current = current.dirMap[tmp[2]];
                }
            } else {
                continue;
            }
        } else {
            if(tmp[0] == "dir") {
                Dir newDir;
                newDir.name = tmp[1];
                current.dirMap[newDir.name] = newDir;
                
            } else {
                if (current.s.find(tmp[1]) != current.s.end()) continue;
                File file;
                file.size = stoi(tmp[0]);
                file.name = tmp[1];
                current.sizeTotal += file.size;
                current.setFile.insert(tmp[1]);
            }
        }
    }
    if (current.sizeTotal > sizeToRemove && current.sizeTotal < smallestRemove) {
        std::cout << current.sizeTotal << " is smaller than " << smallestRemove << " and larger than " << sizeToRemove << std::endl;
        smallestRemove = current.sizeTotal;
    }
    std::cout << smallestRemove << std::endl;
}