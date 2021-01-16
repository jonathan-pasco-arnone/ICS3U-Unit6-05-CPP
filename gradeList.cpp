// Copyright (c) 2020 Jonathan Pasco-Arnone all rights reserved
//
// Created by Jonathan Pasco-Arnone
// Created on January 2021
// This program finds the lowest number in a list of random numbers

#include <iostream>
#include <list>

float averageOfList(std::list<float> list) {
    // This function gets the average of the numbers in the list

    float average = 0;

    for (float loopCounter : list) {
        average += loopCounter;
    }
    average = average / list.size();
}


main() {
    /*  This function gets any amount of inputed grades from the user and
        gives them to the average function */

    std::list<float> list;
    std::string newGradeStr;
    float newGrade;
    int counter = 2;
    float average = 0;

    std::cout << "" << std::endl;
    std::cout << "Please enter all the grades of the students."
          " Enter -1 when finished." << std::endl;
    std::cout << "" << std::endl;

    std::cout << "Grade 1: ";
    std::cin >> newGradeStr;

    try {
       newGrade = std::stof(newGradeStr);
       if (newGrade <= 100 && newGrade >= -1) {
        list.push_back(newGrade);
       } else {
            std::cout << "This was not a valid grade";
            std::cout << "" << std::endl;
       }
    } catch (std::invalid_argument) {
        std::cout << "This was not a valid grade";
        std::cout << "" << std::endl;
    }

    while (newGrade != -1) {
        std::cout << "Grade " << counter << ": ";
        std::cin >> newGradeStr;

        try {
            newGrade = std::stof(newGradeStr);
            if (newGrade <= 100 && newGrade >= -1) {
                list.push_back(newGrade);
            } else {
                std::cout << "This was not a valid grade";
                std::cout << "" << std::endl;
            }
        } catch (std::invalid_argument) {
            std::cout << "This was not a valid grade";
            std::cout << "" << std::endl;
        }
        counter += 1;
    }
    if (list.size() != 1) {
        list.pop_back();
        average = averageOfList(list);
    }
    std::cout << "The average is " << average << std::endl;
}
