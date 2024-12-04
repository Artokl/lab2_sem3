#ifndef GENERATOR_H
#define GENERATOR_H

#include <fstream>
#include <ctime>
#include <random>
#include <string>

#include "Person.h"

inline std::string FirstNameList[20] = {
    "Ivan", "Andrei", "Dmitri", "Alexei", "Nikolai",
    "Sergei", "Mikhail", "Pavel", "Vladislav", "Oleg",
    "Yaroslav", "Roman", "Artem", "Viktor", "Boris",
    "Maxim", "Konstantin", "Gennady", "Leonid", "Stanislav"
};

inline std::string SecondNameList[20] = {
    "Ivanov", "Petrov", "Sidorov", "Fedorov", "Kuznetsov",
    "Popov", "Smirnov", "Orlov", "Makarov", "Lebedev",
    "Egorov", "Morozov", "Volkov", "Novikov", "Pavlov",
    "Karpov", "Yakovlev", "Zaitsev", "Chernov", "Kalinin"
};

inline void GeneratePersons(std::string& filename, int count) {
    std::ofstream outFile(filename, std::ios::out);

    if (!outFile) {
        throw std::ios_base::failure("Failed to open file for writing");
    }

    std::mt19937 generator(static_cast<unsigned int>(std::time(nullptr)));
    std::uniform_int_distribution yearDist(1960, 2005);
    std::uniform_real_distribution heightDist(140.0, 200.0);
    std::uniform_real_distribution weightDist(40.0, 120.0);
    std::uniform_int_distribution firstNameDist(0, 19);
    std::uniform_int_distribution secondNameDist(0, 19);

    outFile << "FirstName,SecondName,BirthYear,Height,Weight\n";

    for (int i = 0; i < count; ++i) {
        std::string firstName = FirstNameList[firstNameDist(generator)];
        std::string secondName = SecondNameList[secondNameDist(generator)];
        int birthYear = yearDist(generator);
        double height = heightDist(generator);
        double weight = weightDist(generator);

        outFile << firstName << "," << secondName << ","
                << birthYear << "," << height << "," << weight << "\n";
    }

    outFile.close();
}

inline void GettingDataFromFile(const std::string& name, ArraySequence<Person>& persons) {
    std::ifstream inFile(name);

    if (!inFile) {
        throw std::ios_base::failure("Failed to open file for reading");
    }

    Person tmp;
    std::string firstName, lastName;
    int birthYear;
    double height, weight;

    inFile.ignore(63, '\n');
    while (true) {
        std::getline(inFile, firstName, ',');
        std::getline(inFile, lastName, ',');
        inFile >> birthYear;
        inFile.ignore(1);
        inFile >> height;
        inFile.ignore(1);
        inFile >> weight;
        inFile.ignore(1);

        if (!inFile) {
            break;
        }

        tmp.setFirstName(firstName);
        tmp.setLastName(lastName);
        tmp.setBirthYear(birthYear);
        tmp.setHeight(height);
        tmp.setWeight(weight);

        persons.Append(tmp);
    }
}

inline void PuttingDataToFile(const std::string& name, const ArraySequence<Person>& persons) {
    std::ofstream outFile(name, std::ios::out);

    if (!outFile) {
        throw std::ios_base::failure("Failed to open file for writing");
    }

    outFile << "FirstName,LastName,BirthYear,Height,Weight\n";
    for (int i = 0; i < persons.GetLength(); ++i) {
        const Person& person = persons[i];
        outFile << person.getFirstName() << ","
                << person.getLastName() << ","
                << 2024 - person.getAge() << ","
                << person.getHeight() << ","
                << person.getWeight() << "\n";
    }
}
#endif //GENERATOR_H
