#include<iostream>
#include<fstream>
#include<string>

int main () {
    std::string path;
    std::ifstream file_name;
    std::cout << "\nEnter path to .txt";
    std::cin >> path;
    file_name.open(path);

    if(!file_name.is_open()) {
        std::cout<<"\nFail to open file: ";
    }
    else {
        std::cout<<"\nFile opend.\n";
        std::string str;
        while(std::getline(file_name,str)) {
            std::cout << str << std::endl;
        }
    }
    file_name.close();
}
