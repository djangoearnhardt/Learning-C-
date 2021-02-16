//
//  main.cpp
//  RankUserInput
//
//  Created by Sam LoBue on 2/16/21.
//

#include <iostream>
#include <vector>
/*
 Pancake Glutton
 Requires:
 variables, data types, and numerical operators
 basic input/output
 logic (if statements, switch statements)
 loops (for, while, do-while)
 arrays

 Write a program that asks the user to enter the number of pancakes eaten for breakfast by 10 different people (Person 1, Person 2, ..., Person 10)
 Once the data has been entered the program must analyze the data and output which person ate the most pancakes for breakfast.

 ★ Modify the program so that it also outputs which person ate the least number of pancakes for breakfast.

 ★★★★ Modify the program so that it outputs a list in order of number of pancakes eaten of all 10 people.
 i.e.
 Person 4: ate 10 pancakes
 Person 3: ate 7 pancakes
 Person 8: ate 4 pancakes
 ...
 Person 5: ate 0 pancakes
 */

class Person
{
public:
    int number = 0, pancakesEaten = 0;
};

std::vector<int> pancakesEaten(10); // create an array with 10 items
/// Ask the user to input the amount of pancakes each Person consumed
std::vector<int> receiveUserInputForPancakesEaten()
{
    std::cout << "Please enter the amount of pancakes eaten for 10 people:\n";
    int x;
    for (int i = 0; i < 10; i++) {
        std::cout << "Person " << i + 1 << "'s amount: ";
        std::cin >> x;
        while(!std::cin)
        {
            std::cout << "That was no integer! Please enter an integer: ";
            std::cin.clear();
            std::cin.ignore();
            std::cin >> x;
        }
        pancakesEaten[i] = x;
    }
    return pancakesEaten;
};

/// Assign each person the appropriate amount of pancakes eaten
std::vector<Person> createPeopleVector()
{
    std::vector<Person> vector(10);
    for (int i = 0; i < vector.size(); i++) {
        vector[i].number = i + 1;
        vector[i].pancakesEaten = pancakesEaten[i];
    }
    return vector;
}

/// Sort the People vector, and print the results to the console
void rankPeopleByMostPancakesEaten(std::vector<Person> people) {
    sort(people.begin(), people.end(), [ ]( const auto& lhs, const auto& rhs )
    {
       return lhs.pancakesEaten > rhs.pancakesEaten;
    });
    std::cout << "\nThe results are in\n";
    for (int i = 0; i < 10; i++) {
        std::cout << "Person " << people[i].number << ": ate " << people[i].pancakesEaten << " pancakes\n";
    }
    std::cout  << "Person " << people[9].number << " ate the least amount of pancakes.\n";
}

int main(int argc, const char * argv[]) {
    receiveUserInputForPancakesEaten();
    std::vector<Person> people = createPeopleVector();
    rankPeopleByMostPancakesEaten(people);
    return 0;
}
