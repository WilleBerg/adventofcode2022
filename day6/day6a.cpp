#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <set>

bool checkQueue(std::queue<char> q) {
    std::set<char> s;
    while(!q.empty()) {
        char tmp = q.front();
        q.pop();
        if (s.find(tmp) != s.end()) {
            return false;
        } else {
            s.insert(tmp);
        }
    }
    return true;
}

int main() {
    std::vector<std::string> in;
    std::fstream f;
    f.open("./day6/input.txt");
    if (f.is_open()) {
        while (f) {
            std::string tmp;
            getline(f, tmp);
            if (tmp == "") continue;
            in.push_back(tmp);
        }
    }
    std::queue<char> q;
    bool b = true;
    int after = 0;
    for (int i = 0; i < in[0].size(); i++) {
        if (q.size() < 4) {
            q.push(in[0][i]);
        } else {
            if (checkQueue(q)) {
                after = i;
                break;
            } else {
                q.push(in[0][i]);
                q.pop();
            }
        }
    }
    std::cout << after << std::endl;
}