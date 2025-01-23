# ifndef GENERATOR_H
# define GENERATOR_H

#include <iostream>
#include <random>
#include <string>
#include <vector>
#include <utility>

class Generator {

private:
    std::random_device rd;
    std::mt19937 gen;
    int num1;
    int num2;
    int answer;
    int arithmetic_operator_id;
    std::string arithmetic_operator;
    std::vector<std::pair<std::string, int>> questions;

public:
    int number_generator(int min, int max);
    std::vector<std::pair<std::string, int>> generate_questions(int number_of_questions, int number_of_operators);

};

# endif // GENERATOR_H