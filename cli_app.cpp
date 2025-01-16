#include <iostream>
#include <random>
#include <string>
#include <vector>
#include <utility>

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
            std::cin.ignore();
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

int main(int argc, char *argv[]) {

    // Check how argc and argv work

    // std::cout << argc << std::endl;
    
    // for (int i = 0; i < argc; ++i) {
    //     std::cout << "Argument " << i << ": " << argv[i] << std::endl;
    // }

    // Example:
    // ./a.out --god --and
    // 3
    // Argument 0: ./a.out
    // Argument 1: --god
    // Argument 2: --and

    std::vector<std::pair<std::string, int>> questions = generate_questions(5, 2);

    console_io(questions, 2);

    return 0;
}