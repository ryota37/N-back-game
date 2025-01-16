# What is this code?

- A prototype of n-back task game working in a comman-line interface(CUI)

# How to use

- Execute the command below.

```shell
g++ -std=c++17 cli_app.cpp
./a.out
```

- Then folow the instructions shown on your console.

## The example of the cosole output

```
5+1=?
Press Enter: 
2+0=?
Press Enter: 
8-5=?
Enter your answer: 6
The answer is: 6
Correct!
9-2=?
Enter your answer: 2
The answer is: 2
Correct!
7-9=?
Enter your answer: 3
The answer is: 3
Correct!
Enter your answer: 7
The answer is: 7
Correct!
Enter your answer: -2
The answer is: -2
Correct!
```

# Future development plan

- In the current implementation, answers of the question sometimes have minus value.
  - But it's too difficult. I will fix it later.
- In the current implementatoin, the number of questions and the number of n-back is fixed(5,2 for each).
  - I will fix it so that you specifty the both value from command option.
