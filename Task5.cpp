#include<iostream>
#include<fstream>
#include<string>

const std::string file_name_a = "answer.txt";
const std::string file_name_q = "questions.txt";

const std::string path_a = "answer.txt";
const std::string path_q = "questions.txt";

void check(std::string & file_answer,int & player_score,int & spectators_score) {
	std::string answer;	
	std::cout << "\nEnter your answer in low register." << std::endl;	
	std::cin >> answer;
    if(answer == file_answer) {
        std::cout << "\nThat correct answer!" << std::endl;
        ++player_score;
    }	
	else {
        std::cout<<"\nWrong answer, answer is: " << file_answer << ". Spectators gain point !";
        ++spectators_score;
    }
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
        int player_score = 0;
        int spectators_score =0;
		do {
			std::string question;
			std::string answer_file;
			std::cout << "\nEnter shift: ";
			std::cin >> shift;
			if (!std::cin) {
				std::cerr << "\nWrong input need a number!";
				return 1;
			}
			if (array[shift] != 'n' || shift >= array.length()) {
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
				file_name_a >> answer_file;
				std::getline(file_name_q, question);				
			}
			std::cout << '\n' + std::string(20, '-') + '\n';
			std::cout << "\n" << question;				
			check(answer_file,player_score,spectators_score);
			array[shift] = 'y';						
		} while (spectators_score < 6 && player_score < 6);
        if(player_score == 6) {
            std::cout<<"\nYou win !";
        }
        else {
            std::cout<<"\nSpeactotots win!";
        }
	}    
	file_name_a.close();
	file_name_q.close();
}