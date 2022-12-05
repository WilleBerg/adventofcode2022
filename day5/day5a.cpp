#include <iostream>
#include <fstream>
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
    f.open("./day5/input.txt");
    std::vector<std::string> in;
    while(f) {
        std::string tmp;
        getline(f, tmp);
        if(tmp == "") continue;
        in.push_back(tmp);
    }
    std::vector<std::vector<std::string>> boxes(9,std::vector<std::string>(0));
    for(int i = 7; i >= 0; i--) {
        int count = 0;
        int which = 0;
        std::string tmp = "";
        for(int j = 0; j < in[i].size(); j++) {
            if(count < 3) {
                if(in[i][j] != ' ') tmp += in[i][j];
                count++;
            } else {
                if (tmp != "") {
                    boxes[which].push_back(tmp);
                    tmp = "";
                    count = 0;
                    which++;
                } else {
                    tmp = "";
                    count = 0;
                    which++; 
                }
            } 
        }
        if(tmp != "") boxes[which].push_back(tmp);
    }
    for (int i = 9; i < in.size(); i++) {
        std::vector<std::string> command = split(in[i], ' ');
        int amount = std::stoi("" + command[1]);
        int from = std::stoi("" + command[3]) - 1;
        int to = std::stoi("" + command[5]) - 1;
        for (int j = 0; j < amount; j++) {
            std::string box = boxes[from].back();
            boxes[from].pop_back();
            boxes[to].push_back(box);
        }
    }
    std::string ans = "";
    for(int i = 0; i < boxes.size(); i++) {
        ans += boxes[i].back()[1];
    }
    std::cout << ans << std::endl;
}