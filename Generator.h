# ifndef GENERATE_QUESTIONS_H
# define GENERATE_QUESTIONS_H

class Generate_questions {

private:
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

public:
    std::vector<std::pair<std::string, int>> generate_questions(int number_of_questions, int number_of_operators);

};

# endif // GENERATE_QUESTIONS_H