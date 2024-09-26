#include<iostream>
#include<fstream>
#include<string>

std::string file_name = "statements.txt";
std::string path = "statements.txt";

int digits(const std::string& str_buffer) {
    std::string temp;
    for (int i = 0; i < str_buffer.length(); ++i) {       
        if (temp[0] != '\0' && str_buffer[i] == ' ') {
            return stoi(temp);
        }
        if (str_buffer[i] >= '0' && str_buffer[i] <= '9') {
            temp += str_buffer[i];
        }
    }
    return 0;
}

int main() {    
    std::ifstream file_name;
    file_name.open(path);
    if (!file_name.is_open()) {
        std::cerr << "Failed opens.";
        return 1;
    }
    else {
        int total_pay = 0;
        int max_pay = 0;
        int i_buffer = 0;
        std::string max_pay_name;
        std::string str_buffer;
        std::cout << "File opened.";
        while (std::getline(file_name, str_buffer)) {
            i_buffer = digits(str_buffer);
            total_pay += i_buffer;
            if (i_buffer > max_pay) {
                max_pay = i_buffer;
                max_pay_name = str_buffer;
            }
        }
        std::cout << "\nMax pay is: " << max_pay_name<<std::endl;
        std::cout<<"Total pay is: "<< total_pay;
    }
    file_name.close();    
}