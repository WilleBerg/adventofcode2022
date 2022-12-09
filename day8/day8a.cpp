#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <stack>

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
int ctoi(char c) {
    std::map<char, int> m{{'0', 0}, {'1', 1}, {'2', 2}, {'3', 3}, {'4', 4}, {'5', 5}, {'6', 6}, {'7', 7}, {'8', 8}, {'9', 9}};
    return m[c];
}
bool checkUp(std::vector<std::string> v, int x, int y, int val, std::set<std::pair<int,int>> s) {
    for (int i = y - 1; i >= 0; i--){
        int tmp = ctoi(v[i][x]);
        if (tmp >= val) return false;
    }
    return true;
}
bool checkDown(std::vector<std::string> v, int x, int y, int val, std::set<std::pair<int,int>> s) {
    for (int i = y + 1; i < v.size(); i++){
        int tmp = ctoi(v[i][x]);
        if (tmp >= val) return false;
    }
    return true;
}
bool checkLeft(std::vector<std::string> v, int x, int y, int val, std::set<std::pair<int,int>> s) {
    for (int i = x - 1; i >= 0; i--){
        int tmp = ctoi(v[y][i]);
        if (tmp >= val) return false;
    }

    return true;
}
bool checkRight(std::vector<std::string> v, int x, int y, int val, std::set<std::pair<int,int>> s) {
    for (int i = x + 1; i < v[y].length(); i++){
        int tmp = ctoi(v[y][i]);
        if (tmp >= val) return false;
    }
    return true;
}
bool isVisible(std::vector<std::string> v, int x, int y, int val, std::set<std::pair<int,int>> s) {
    bool up = checkUp(v, x, y, val, s);
    bool down = checkDown(v, x, y, val, s);
    bool left = checkLeft(v, x, y, val, s);
    bool right = checkRight(v, x, y, val, s);
    return up || down || left || right;
}


int main() {
    std::fstream f;
    std::vector<std::string> v;
    f.open("./day8/input.txt");
    if(f.is_open()) {
        while (f) {
            std::string tmp;
            getline(f, tmp);
            if (tmp == "") continue;
            v.push_back(tmp);
        }
    }
    int visCount = 0;
    std::vector<std::pair<int,int>> vis;
    std::set<std::pair<int,int>> set;
    std::cout << "Read file" << std::endl;
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].length(); j++) {
            if (i == 0 || i == v.size() - 1) {
                visCount++;
                vis.push_back(std::pair<int,int>(i,j));
                set.insert(std::pair<int,int>(i,j));
            } else if (j == 0 || j == v[i].length() - 1) {
                visCount++;
                vis.push_back(std::pair<int,int>(i,j));
                set.insert(std::pair<int,int>(i,j));
            }
        }
    }
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].length(); j++) {
            if (i == 0 || i == v.size() - 1) {
                continue;
            } else if (j == 0 || j == v[i].length() - 1) {
                continue;
            } else {
                int val = ctoi(v[i][j]);
                bool isVis = isVisible(v, j, i, val, set);
                if (isVis) {
                    visCount++;
                }
            }
        }
    }
   std::cout << visCount << std::endl;
}