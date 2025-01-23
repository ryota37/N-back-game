#include <iostream>
#include <random>
#include <string>
#include <vector>
#include <utility>

#include "Generator.h"

int determine_number_of_questions() {
    int number_of_questions;
    
    std::cout << "Enter the number of questions: ";
    std::cin >> number_of_questions;

    return number_of_questions;
}

int detemine_number_of_N_back() {
    int number_of_n_back;
    std::cout << "Enter the number of backs: ";
    std::cin >> number_of_n_back;

    return number_of_n_back;
}

void console_io(std::vector<std::pair<std::string, int>> questions, int number_of_n_back) {
    int number_of_questions = questions.size();
    for (int i = 0; i < number_of_questions+number_of_n_back; i++) {
        if (i < number_of_n_back){
            std::cout << questions[i].first << std::endl;
            std::cout << "Press Enter: ";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin.get();
        } else if (i >= number_of_n_back && i < number_of_questions) {
            std::cout << questions[i].first << std::endl;
            std::cout << "Enter your answer: ";
            int user_answer;
            std::cin >> user_answer;
            std::cout << "The answer is: " << questions[i-number_of_n_back].second << std::endl;
            if (user_answer == questions[i-number_of_n_back].second) {
                std::cout << "Correct!" << std::endl;
            } else {
                std::cout << "Incorrect!" << std::endl;
            }
        } else {
            std::cout << "Enter your answer: ";
            int user_answer;
            std::cin >> user_answer;
            std::cout << "The answer is: " << questions[i-number_of_n_back].second << std::endl;
            if (user_answer == questions[i-number_of_n_back].second) {
                std::cout << "Correct!" << std::endl;
            } else {
                std::cout << "Incorrect!" << std::endl;
            }
        }
    }
}

int main() {

    int number_of_questions = determine_number_of_questions();
    int number_of_n_back = detemine_number_of_N_back();

    Generator generator;

    std::vector<std::pair<std::string, int>> questions = generator.generate_questions(number_of_questions, 2);

    console_io(questions, number_of_n_back);

    return 0;
}