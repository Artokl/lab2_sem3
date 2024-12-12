#ifndef GENERATOR_H
#define GENERATOR_H

#include <fstream>
#include <ctime>
#include <random>
#include <string>

#include "Person_Resume.h"

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

inline std::string PositionList[10] = {
    "Engineer", "Manager", "Analyst", "Developer", "Designer",
    "Technician", "Consultant", "Scientist", "Architect", "Director"
};

inline std::string SkillsList[10] = {
    "C++", "Python", "Java", "SQL", "Leadership",
    "Communication", "Project Management", "Machine Learning", "Data Analysis", "UX Design"
};

inline std::string EducationList[5] = {
    "High School", "Associate Degree", "Bachelor's Degree", "Master's Degree", "PhD"
};

inline void GenerateResumes(std::string& filename, int count) {
    std::ofstream outFile(filename, std::ios::out);

    if (!outFile) {
        throw std::ios_base::failure("Failed to open file for writing");
    }

    std::mt19937 generator(static_cast<unsigned int>(std::time(nullptr)));
    std::uniform_int_distribution yearDist(1960, 2005);
    std::uniform_real_distribution heightDist(140.0, 200.0);
    std::uniform_real_distribution weightDist(40.0, 120.0);
    std::uniform_real_distribution salaryDist(30000.0, 400000.0);
    std::uniform_real_distribution experienceDist(0.0, 40.0);
    std::uniform_int_distribution certificationDist(0, 10);
    std::uniform_int_distribution firstNameDist(0, 19);
    std::uniform_int_distribution secondNameDist(0, 19);
    std::uniform_int_distribution positionDist(0, 9);
    std::uniform_int_distribution skillsDist(0, 9);
    std::uniform_int_distribution educationDist(0, 4);

    outFile << "FirstName,SecondName,BirthYear,Height,Weight,DesiredPosition,Skills,Education,DesiredSalary,YearsOfExperience,CertificationsCount\n";

    for (int i = 0; i < count; ++i) {
        std::string firstName = FirstNameList[firstNameDist(generator)];
        std::string secondName = SecondNameList[secondNameDist(generator)];
        int birthYear = yearDist(generator);
        double height = heightDist(generator);
        double weight = weightDist(generator);
        std::string desiredPosition = PositionList[positionDist(generator)];
        std::string skills = SkillsList[skillsDist(generator)];
        std::string education = EducationList[educationDist(generator)];
        double desiredSalary = salaryDist(generator);
        double yearsOfExperience = experienceDist(generator);
        int certificationsCount = certificationDist(generator);

        outFile << firstName << "," << secondName << ","
                << birthYear << "," << height << "," << weight << ","
                << desiredPosition << "," << skills << "," << education << ","
                << desiredSalary << "," << yearsOfExperience << "," << certificationsCount << "\n";
    }

    outFile.close();
}

inline void GettingDataFromFile(const std::string& name, ArraySequence<Resume>& resumes) {
    std::ifstream inFile(name);

    if (!inFile) {
        throw std::ios_base::failure("Failed to open file for reading");
    }

    Resume tmp;
    std::string firstName, lastName, desiredPosition, skills, education;
    int birthYear;
    double height, weight, desiredSalary, yearsOfExperience, certificationsCount;

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
        std::getline(inFile, desiredPosition, ',');
        std::getline(inFile, skills, ',');
        std::getline(inFile, education, ',');
        inFile >> desiredSalary;
        inFile.ignore(1);
        inFile >> yearsOfExperience;
        inFile.ignore(1);
        inFile >> certificationsCount;
        inFile.ignore(1);

        if (!inFile) {
            break;
        }

        tmp.setFirstName(firstName);
        tmp.setLastName(lastName);
        tmp.setBirthYear(birthYear);
        tmp.setHeight(height);
        tmp.setWeight(weight);
        tmp.setDesiredPosition(desiredPosition);
        tmp.setSkills(skills);
        tmp.setEducation(education);
        tmp.setDesiredSalary(desiredSalary);
        tmp.setYearsOfExperience(yearsOfExperience);
        tmp.setCertificationsCount(certificationsCount);

        resumes.Append(tmp);
    }
}

inline void PuttingDataToFile(const std::string& name, const ArraySequence<Resume>& resumes) {
    std::ofstream outFile(name, std::ios::out);

    if (!outFile) {
        throw std::ios_base::failure("Failed to open file for writing");
    }

    outFile << "FirstName,LastName,BirthYear,Height,Weight,DesiredPosition,Skills,Education,DesiredSalary,YearsOfExperience,CertificationsCount\n";
    for (int i = 0; i < resumes.GetLength(); ++i) {
        const Resume& resume = resumes[i];
        outFile << resume.getFirstName() << ","
                << resume.getLastName() << ","
                << 2024 - resume.getAge() << ","
                << resume.getHeight() << ","
                << resume.getWeight() << ","
                << resume.getDesiredPosition() << ","
                << resume.getSkills() << ","
                << resume.getEducation() << ","
                << resume.getDesiredSalary() << ","
                << resume.getYearsOfExperience() << ","
                << resume.getCertificationsCount() << "\n";
    }
}

#endif //GENERATOR_H
