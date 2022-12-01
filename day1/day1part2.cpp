#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main(){
    std::fstream file;
    int topThree[3] = {0,0,0};
    file.open("inputpart1.txt");
    int sum = 0;
    if(file.is_open()) {
        while (file) {
            std::string tmp;
            getline(file, tmp);
            if(tmp != ""){
                sum += stoi(tmp);
            } else {
                if (sum > topThree[2]) {
                    if (sum > topThree[1]) {
                        if (sum > topThree[0]) {
                            topThree[2] = topThree[1];
                            topThree[1] = topThree[0];
                            topThree[0] = sum;
                        } else {
                            topThree[2] = topThree[1];
                            topThree[1] = sum;
                        }
                    } else {
                        topThree[2] = topThree[1];
                    }
                } 
                sum = 0;
            }
        }
    }
    int summa = 0;
    for(int i = 0; i < 3; i++){
        std::cout << topThree[i] << std::endl;
        summa += topThree[i];
    }
    std::cout << summa << std::endl;
}