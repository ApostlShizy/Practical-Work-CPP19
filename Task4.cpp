#include<iostream>
#include<fstream>
#include<cstring>

int main() {
    char array[4];    
    std::string path;
    std::ifstream file_name;

    do {
        std::cout << "\nEnter path to file, dont forget use double \\\\: ";
        std::cin >> path;
        file_name.open(path, std::ios::binary);
    } while (!file_name.is_open());

    file_name.read(array, sizeof(array));  
    /*substr не хочет принимать массив char если я что то не так делаю напишите пожалуйста.По этому я создал временную строку которой передал значения массива*/
    if (((std::string(array)).substr(1, 3) == "PNG") && (array[0] == (-119))) {
        std::cout << "\nIts PNG";
    }
    else {
        std::cout << "\nIts not PNG";
    }
    file_name.close();
}