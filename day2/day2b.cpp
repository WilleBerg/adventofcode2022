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
    std::map<char, char> winMap{{'C', 'X'}, {'A', 'Y'}, {'B', 'Z'}};
    std::map<char, char> drawMap{{'A', 'X'}, {'B', 'Y'}, {'C', 'Z'}};
    std::map<char, char> loseMap{{'B', 'X'}, {'C', 'Y'}, {'A', 'Z'}};
    std::map<char, int> anotherMap{{'X', 0}, {'Y', 3}, {'Z', 6}};
    std::map<char, std::map<char,char>> oneMoreMap{{'X', loseMap}, {'Y', drawMap}, {'Z', winMap}};

    int sumPoints = 0;
    for(int i = 0; i < in.size(); i++){
        std::string tmp = in.at(i);
        sumPoints += anotherMap[tmp[2]] + baseMap[oneMoreMap[tmp[2]][tmp[0]]];  
    }
    std::cout << sumPoints << std::endl;
}