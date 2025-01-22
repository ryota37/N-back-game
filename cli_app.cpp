#include <iostream>
#include <random>
#include <string>
#include <vector>
#include <utility>

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



std::vector<std::pair<std::string, int>> generate_questions(int number_of_questions, int number_of_operators) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> number_generator(0, 9);
    std::uniform_int_distribution<> operator_generator(0, number_of_operators - 1);
    int num1;
    int num2;
    int answer;
    int arithmetic_operator_id;
    std::string arithmetic_operator;
    std::vector<std::pair<std::string, int>> questions;

    for (int i = 0; i < number_of_questions; i++) {
        // Generate two random numbers and an arithmetic operator
        num1 = number_generator(gen);
        num2 = number_generator(gen);

        // Generate an arithmetic operator
        // 0: +, 1: -, 2: *, 3: /
        arithmetic_operator_id = operator_generator(gen);
        switch (arithmetic_operator_id) {
            case 0:
                arithmetic_operator = "+";
                answer = num1 + num2;
                break;
            case 1:
                arithmetic_operator = "-";
                answer = num1 - num2;
                break;
            case 2:
                arithmetic_operator = "×";
                answer = num1 * num2;
                break;
            case 3:
                arithmetic_operator = "÷";
                answer = num1 / num2;
                break;
        }

        std::string question = std::to_string(num1) + arithmetic_operator + std::to_string(num2) + "=?";

        questions.emplace_back(question, answer);
    }
    return questions;
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

    std::vector<std::pair<std::string, int>> questions = generate_questions(number_of_questions, 2);

    console_io(questions, number_of_n_back);

    return 0;
}