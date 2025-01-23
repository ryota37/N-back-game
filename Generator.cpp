#include "Generator.h"

#include <iostream>
#include <random>
#include <string>
#include <vector>
#include <utility>

int Generator::number_generator(int min, int max) {
    std::uniform_int_distribution<> num(min, max);
    return num(gen);
}

std::vector<std::pair<std::string, int>> Generator::generate_questions(int number_of_questions, int number_of_operators) {
    for (int i = 0; i < number_of_questions; i++) {
        // Generate two random numbers and an arithmetic operator
        num1 = number_generator(1,9);
        num2 = number_generator(1,9);

        // Generate an arithmetic operator
        // 0: +, 1: -, 2: *, 3: /
        arithmetic_operator_id = number_generator(0, number_of_operators - 1);
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

        // Generate a question string
        std::string question = std::to_string(num1) + arithmetic_operator + std::to_string(num2) + "=?";

        // Store the question and answer in a vector
        questions.emplace_back(question, answer);
    }
    return questions;
}