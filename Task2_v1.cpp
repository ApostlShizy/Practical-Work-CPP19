#include<iostream>
#include<fstream>

int main () {
    std::string path;
    std::ifstream file_name;
    std::cout << "\nEnter path to .txt";
    std::cin >> path;
    file_name.open(path);    

    if(!file_name.is_open()) {
        std::cout<<"Fail to open file"<<std::endl;
    }
    else {
        std::cout<<"File opend"<<std::endl;
        char array [20];
        while(!file_name.eof()) {
            file_name.read(array,sizeof(array));
            array[file_name.gcount()] = 0;            
            std::cout<<array;
        }
    }
    file_name.close();
}