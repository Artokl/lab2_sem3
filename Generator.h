#ifndef GENERATOR_H
#define GENERATOR_H

#include <fstream>
#include <ctime>
#include <random>
#include <string>

#include "Person_Student.h"

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

inline std::string UniversityList[10] = {
    "MSU", "SPbSU", "MEPhI", "Bauman MSTU", "MIPT",
    "ITMO", "HSE", "RUDN", "Tomsk State University", "Kazan Federal University"
};

inline std::string FacultyList[10] = {
    "Computer Science", "Mathematics", "Physics", "Engineering", "Economics",
    "Biology", "Chemistry", "Literature", "History", "Philosophy"
};

inline std::string MajorList[10] = {
    "Software Engineering", "Data Science", "Theoretical Physics", "Civil Engineering", "Macroeconomics",
    "Genetics", "Organic Chemistry", "Comparative Literature", "Modern History", "Ethics"
};

inline void GenerateStudents(std::string& filename, int count) {
    std::ofstream outFile(filename, std::ios::out);

    if (!outFile) {
        throw std::ios_base::failure("Failed to open file for writing");
    }

    std::mt19937 generator(static_cast<unsigned int>(std::time(nullptr)));
    std::uniform_int_distribution yearDist(2000, 2010);
    std::uniform_real_distribution heightDist(140.0, 200.0);
    std::uniform_real_distribution weightDist(40.0, 120.0);
    std::uniform_real_distribution gpaDist(0.0, 4.0);
    std::uniform_int_distribution yearsOfStudyDist(1, 5);
    std::uniform_int_distribution completedCreditsDist(0, 150);
    std::uniform_int_distribution firstNameDist(0, 19);
    std::uniform_int_distribution secondNameDist(0, 19);
    std::uniform_int_distribution universityDist(0, 9);
    std::uniform_int_distribution facultyDist(0, 9);
    std::uniform_int_distribution majorDist(0, 9);

    outFile << "Имя,Фамилия,Год рождения,Рост,Вес,Университет,Факультет,Специальность,GPA,Годы обучения,Завершённые кредиты\n";

    for (int i = 0; i < count; ++i) {
        std::string firstName = FirstNameList[firstNameDist(generator)];
        std::string secondName = SecondNameList[secondNameDist(generator)];
        int birthYear = yearDist(generator);
        double height = heightDist(generator);
        double weight = weightDist(generator);
        std::string university = UniversityList[universityDist(generator)];
        std::string faculty = FacultyList[facultyDist(generator)];
        std::string major = MajorList[majorDist(generator)];
        double gpa = gpaDist(generator);
        int yearsOfStudy = yearsOfStudyDist(generator);
        int completedCredits = completedCreditsDist(generator);

        outFile << firstName << "," << secondName << ","
                << birthYear << "," << height << "," << weight << ","
                << university << "," << faculty << "," << major << ","
                << gpa << "," << yearsOfStudy << "," << completedCredits << "\n";
    }

    outFile.close();
}

inline void GettingDataFromFile(const std::string& name, ArraySequence<Student>& students) {
    std::ifstream inFile(name);

    if (!inFile) {
        throw std::ios_base::failure("Failed to open file for reading");
    }

    Student tmp;
    std::string firstName, lastName, university, faculty, major;
    int birthYear;
    double height, weight, gpa;
    int yearsOfStudy, completedCredits;

    inFile.ignore(1024, '\n');
    while (true) {
        std::getline(inFile, firstName, ',');
        std::getline(inFile, lastName, ',');
        inFile >> birthYear;
        inFile.ignore(1);
        inFile >> height;
        inFile.ignore(1);
        inFile >> weight;
        inFile.ignore(1);
        std::getline(inFile, university, ',');
        std::getline(inFile, faculty, ',');
        std::getline(inFile, major, ',');
        inFile >> gpa;
        inFile.ignore(1);
        inFile >> yearsOfStudy;
        inFile.ignore(1);
        inFile >> completedCredits;
        inFile.ignore(1);

        if (!inFile) {
            break;
        }

        tmp.setFirstName(firstName);
        tmp.setLastName(lastName);
        tmp.setBirthYear(birthYear);
        tmp.setHeight(height);
        tmp.setWeight(weight);
        tmp.setUniversityName(university);
        tmp.setFaculty(faculty);
        tmp.setMajor(major);
        tmp.setGPA(gpa);
        tmp.setYearsOfStudy(yearsOfStudy);
        tmp.setCompletedCredits(completedCredits);

        students.Append(tmp);
    }
}

inline void PuttingDataToFile(const std::string& name, const ArraySequence<Student>& students) {
    std::ofstream outFile(name, std::ios::out);

    if (!outFile) {
        throw std::ios_base::failure("Failed to open file for writing");
    }

    outFile << "Имя,Фамилия,Год рождения,Рост,Вес,Университет,Факультет,Специальность,GPA,Годы обучения,Завершённые кредиты\n";
    for (int i = 0; i < students.GetLength(); ++i) {
        const Student& student = students[i];
        outFile << student.getFirstName() << ","
                << student.getLastName() << ","
                << 2024 - student.getAge() << ","
                << student.getHeight() << ","
                << student.getWeight() << ","
                << student.getUniversityName() << ","
                << student.getFaculty() << ","
                << student.getMajor() << ","
                << student.getGPA() << ","
                << student.getYearsOfStudy() << ","
                << student.getCompletedCredits() << "\n";
    }
}

#endif // GENERATOR_H
