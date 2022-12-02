#include <iostream>
#include <fstream>
#include <vector>
#include <map>

int main(){
    std::fstream f;
    f.open("input.txt");
    std::vector<std::string> in;
    if(f.is_open()){
        while(f) {
            std::string tmp;
            getline(f, tmp);
            if(tmp != ""){
                in.push_back(tmp);
            }
        }
    }
    // X is rock, Y is paper, Z is scissor
    // A is rock, B is paper, C is scissor
    std::map<char, int> baseMap{{'Y', 2}, {'Z', 3}, {'X', 1}};
    std::map<char, char> winMap{{'X', 'C'}, {'Y', 'A'}, {'Z', 'B'}};
    std::map<char, char> drawMap{{'X', 'A'}, {'Y', 'B'}, {'Z', 'C'}};
    int sumPoints = 0;
    for(int i = 0; i < in.size(); i++){
        std::string tmp = in.at(i);
        if(winMap[tmp[2]] == tmp[0]){
            sumPoints += baseMap[tmp[2]] + 6;
        } else if(drawMap[tmp[2]] == tmp[0]) {
           sumPoints += baseMap[tmp[2]] + 3; 
        } else { 
            sumPoints += baseMap[tmp[2]];
        }
    }
    std::cout << sumPoints << std::endl;
}