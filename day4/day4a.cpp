#include <iostream>
#include <fstream>
#include <map>
#include <unordered_set>
#include <vector>

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
    std::vector<std::string> in; 
    f.open("./day4/input.txt");
    while(f) {
        std::string tmp;
        getline(f,tmp);
        if(tmp == "") break;
        in.push_back(tmp);
    }
    int c = 0;
    for(int i = 0; i < in.size(); i++){
        std::unordered_set<int> set;
        std::unordered_set<int> set2;
        std::vector<std::string> cl = split(in[i], ',');
        std::vector<std::string> cll = split(cl[0], '-');
        std::vector<std::string> clr = split(cl[1], '-');
        std::pair<int,int> lb(std::stoi("" + cll[0]), std::stoi("" + cll[1]));
        std::pair<int,int> rb(std::stoi("" + clr[0]), std::stoi("" + clr[1]));
        for(int j = lb.first; j < lb.second + 1; j++){
            set.insert(j);
        } 
        for(int j = rb.first; j < rb.second + 1; j++){
            set2.insert(j);
        }
        bool b = true;
        if (set.size() >= set2.size()) {
            auto iter = set2.begin();
            while (iter != set2.end()) {
                if (set.find(*iter) == set.end()) {
                    b = false;
                    break;
                }
                iter++;
            }
        } else {
            auto iter = set.begin();
            while (iter != set.end()) {
                if (set2.find(*iter) == set2.end()) {
                    b = false;
                    break;
                }
                iter++;
            } 
        }
        if (b) c++;
    }
    std::cout << c << std::endl;
}