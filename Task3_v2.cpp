#include<iostream>
#include<fstream>

const std::string file_name = "statements.txt";
const std::string path = "statements.txt";

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
        std::string max_pay_str;        
        std::cout << "File opened.";
        while (!file_name.eof()) {
            int pay_buffer = 0;
            std::string fName_buffer;
            std::string lName_buffer;
            std::string date_buffer;
            file_name >> fName_buffer >> lName_buffer >> pay_buffer >> date_buffer;
            total_pay += pay_buffer;
            if (pay_buffer > max_pay) {
                max_pay = pay_buffer;
                max_pay_str = fName_buffer + ' ' + lName_buffer + ' ' + date_buffer;
            }
        }
        std::cout << "\nMax pay name and date is: " << max_pay_str<<"\nMax Payd sum is: " << max_pay <<std::endl;
        std::cout<<"Total pay is: "<< total_pay;
    }
    file_name.close();    
}