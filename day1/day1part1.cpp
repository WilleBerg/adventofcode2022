#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream input("inputpart1.txt");
    std::string line;
    int largest = 0;
    int sum = 0;
    if(input.is_open()){
        while(input) {
            std::string tmp;
            std::getline(input, tmp);
            if (tmp != ""){
                sum += std::stoi(tmp);
            } else {
                std::cout << "Sum done: " << sum << std::endl; 
                if(sum > largest){
                    largest = sum;
                }
                sum = 0;
            }
        }
    }
    std::cout << largest << std::endl;
}