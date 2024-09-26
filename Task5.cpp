#include<iostream>
#include<fstream>
#include<string>

const std::string file_name_a = "answer.txt";
const std::string file_name_q = "questions.txt";

const std::string path_a = "answer.txt";
const std::string path_q = "questions.txt";

void check(std::string & file_answer) {
	std::string answer;
	do {
		if (answer == "0") {
			std::cout << "\nAnswer is: " << file_answer;
		}
		else if (!answer.empty()) {
			std::cout << "\nWrong answer!";
		}		
		std::cout << "\nEnter your answer in low register." << std::endl;
		std::cout << "If you need a clue enter (0).\nEnter: ";
		std::getline(std::cin >> std::ws , answer);
	} while (answer != file_answer);
	std::cout << "\nThat correct answer!" << std::endl;
	std::cout << '\n' + std::string(20, '-') + '\n';
}

int main() {
	std::ifstream file_name_a;
	std::ifstream file_name_q;
	file_name_a.open(path_a);
	file_name_q.open(path_q);

	if (!(file_name_a.is_open()) || !(file_name_q.is_open())) {
		std::cerr << "\nFailed to open files!!!";
		return 1;
	}
	else {
		std::string array(13, 'n');
		int shift = 0;
		do {
			std::string question;
			std::string answer_file;
			std::cout << "\nTo exit enter (-1)";
			std::cout << "\nEnter shift: ";
			std::cin >> shift;
			if (!std::cin) {
				std::cerr << "\nWrong input need a number!";
				return 1;
			}
			if (array[shift] == 'y' || shift >= array.length()) {
				int i = 0;
				do {
					if (i + shift >= array.length()) {
						shift = 0;
						i = 0;
					}
					++i;
				} while (array[shift + i] != 'n');
				shift += i;
			}
			file_name_a.seekg(0);
			file_name_q.seekg(0);			
			for (int i = 0; i <= shift;++i) {
				std::getline(file_name_a , answer_file);
				std::getline(file_name_q, question);				
			}
			std::cout << '\n' + std::string(20, '-') + '\n';
			std::cout << "\n" << question;				
			check(answer_file);
			array[shift] = 'y';						
		} while (shift != -1 && array != std::string(13,'y'));
	}
	file_name_a.close();
	file_name_q.close();
}