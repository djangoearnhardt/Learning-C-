//
//  main.cpp
//  GradingSystem
//
//  Created by Sam LoBue on 2/15/21.
//

#include <iostream>
/*
 Write a program that allows the user to enter the grade scored in a programming class (0-100).
 If the user scored a 100 then notify the user that they got a perfect score.

 ★ Modify the program so that if the user scored a 90-100 it informs the user that they scored an A

 ★★ Modify the program so that it will notify the user of their letter grade
 0-59 F 60-69 D 70-79 C 80-89 B 90-100 A
 */


void determineGrade(int grade) {
    if (grade == 100) {
        std::cout << "You got a perfect score!\n";
    } else {
        std::cout << "Nice work\n";
    }
}

void determineLetterGrade(int grade) {
    std::cout << "You letter grade is ";
    switch (grade) {
        case 0 ... 59:
            std::cout << "an F :(\n";
            break;
        case 60 ... 69:
            std::cout << "a D :(\n";
            break;
        case 70 ... 79:
            std::cout << "a C :/\n";
            break;
        case 80 ... 89:
            std::cout << "a B :)\n";
            break;
        case 90 ... 100:
            std::cout << "an A :)\n";
            break;
        default:
            break;
    }
}

int main(int argc, const char * argv[]) {
    int grade;
    std::cout << "Enter the grade you got in programming class this term\n";
    std::cin >> grade;
    determineLetterGrade(grade);
    return 0;
}

