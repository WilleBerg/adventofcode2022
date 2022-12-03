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
    for (int i = 0; i < in.size(); i += 3) {
        //std::cout << "i : " << i << std::endl;
        //std::cout << "in size " << in.size() << std::endl;
        std::unordered_set<char> set1, set2, set3;
        std::vector<std::unordered_set<char>> setV{ set1, set2, set3 };
        for(int k = i; k < i + 3; k++) {
            //std::cout << "k : " << k << std::endl;
            for(int j = 0; j < in.at(k).length(); j++){
                char tmp = in.at(k)[j];
                if (setV.at(k - i).find(tmp) == setV.at(k - i).end()){
                   setV.at(k - i).insert(tmp);
                } 
            }
        }
        auto iter = setV.at(0).begin();
        while(iter != setV.at(0).end()){
            if(setV.at(1).find(*iter) != setV.at(1).end() && setV.at(2).find(*iter) != setV.at(2).end()){
                //std::cout << "Found " << *iter << std::endl;
                c.push_back(*iter);
                break;
            }
            iter++;
        }
    }
    int prioSum = 0;
    for(auto &letter : c) {
        //std::cout << letter << std::endl;
        if (letter >= 97) {
            prioSum += (letter - 96);
        } else {
            prioSum += (letter - 38);
        }
    }
    std::cout << prioSum << std::endl;
}