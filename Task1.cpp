#include<iostream>
#include<fstream>
 
const std::string file_name = "words.txt";
const std::string path = "words.txt";

int main() {
    int count = 0;
    std::string request_str;
    std::string current_str;
    std::cout<<"Enter word to find is: ";
    std::cin >> request_str;
    std::ifstream file_name;
    file_name.open(path);

    if(file_name.is_open()) {
        while(!file_name.eof()) {            
            file_name >> current_str;
            if(current_str == request_str) {
                ++count;
            }
        }
    }
    file_name.close(); 
    std::cout<<"Total words \""<<request_str<<"\" found: "<<count; 
}