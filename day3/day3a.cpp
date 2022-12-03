#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <unordered_set>

int main(){
    std::fstream file;
    file.open("input.txt");
    std::vector<std::string> in;    
    if(file.is_open()){
        while (file){
            std::string tmp;
            getline(file, tmp);
            if (tmp == "") continue; 
            in.push_back(tmp);
        }
    }
    std::vector<char> c;
    for (int i = 0; i < in.size(); i++) {
        std::unordered_set<char> set;
        std::unordered_set<char> alreadyAdded;
        for(int j = 0; j < in.at(i).length(); j++) {
            char tmp = in.at(i)[j];
            if (j < in.at(i).length() / 2) {
                set.insert(tmp);
            } else {
                if(set.find(tmp) != set.end() && alreadyAdded.find(tmp) == alreadyAdded.end()){
                    alreadyAdded.insert(tmp);
                    c.push_back(tmp);
                }
            }
        }
    }
    int prioSum = 0;
    for(auto &letter : c) {
        std::cout << letter << std::endl;
        if (letter >= 97) {
            prioSum += (letter - 96);
        } else {
            prioSum += (letter - 38);
        }
    }
    std::cout << prioSum << std::endl;

}
