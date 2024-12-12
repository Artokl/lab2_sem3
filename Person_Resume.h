#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <utility>

class Person {
    std::string firstName;
    std::string lastName;
    int birthYear;
    double height;
    double weight;

public:
    Person() = default;

    Person(std::string firstName, std::string lastName, const int birthYear, const double height, const double weight) :
        firstName(std::move(firstName)), lastName(std::move(lastName)),
        birthYear(birthYear), height(height), weight(weight) {}

    Person(const Person&) = default;
    Person(Person&&) noexcept = default;
    Person& operator=(const Person&) = default;
    Person& operator=(Person&&) noexcept = default;

    [[nodiscard]] std::string getFirstName() const { return firstName; }
    [[nodiscard]] std::string getLastName() const { return lastName; }
    [[nodiscard]] int getAge() const { return 2024 - birthYear; }
    [[nodiscard]] double getHeight() const { return height; }
    [[nodiscard]] double getWeight() const { return weight; }

    void setFirstName(const std::string& firstName) { this->firstName = firstName; }
    void setLastName(const std::string& lastName) { this->lastName = lastName; }
    void setBirthYear(const int birthYear) { this->birthYear = birthYear; }
    void setHeight(const double height) { this->height = height; }
    void setWeight(const double weight) { this->weight = weight; }

    ~Person() = default;

};

class Resume : public Person {
    std::string desiredPosition;
    std::string skills;
    std::string education;
    double desiredSalary;
    double yearsOfExperience;
    int certificationsCount;

public:
    Resume() = default;

    Resume(std::string firstName, std::string lastName, const int birthYear, const double height, const double weight,
           std::string desiredPosition, std::string skills, std::string education,
           const double desiredSalary, const double yearsOfExperience, const int certificationsCount)
        : Person(std::move(firstName), std::move(lastName), birthYear, height, weight),
          desiredPosition(std::move(desiredPosition)), skills(std::move(skills)), education(std::move(education)),
          desiredSalary(desiredSalary), yearsOfExperience(yearsOfExperience), certificationsCount(certificationsCount) {}

    Resume(const Resume&) = default;
    Resume(Resume&&) noexcept = default;
    Resume& operator=(const Resume&) = default;
    Resume& operator=(Resume&&) noexcept = default;

    [[nodiscard]] std::string getDesiredPosition() const { return desiredPosition; }
    [[nodiscard]] std::string getSkills() const { return skills; }
    [[nodiscard]] std::string getEducation() const { return education; }
    [[nodiscard]] double getDesiredSalary() const { return desiredSalary; }
    [[nodiscard]] double getYearsOfExperience() const { return yearsOfExperience; }
    [[nodiscard]] int getCertificationsCount() const { return certificationsCount; }

    void setDesiredPosition(const std::string& position) { desiredPosition = position; }
    void setSkills(const std::string& skills) { this->skills = skills; }
    void setEducation(const std::string& education) { this->education = education; }
    void setDesiredSalary(const double salary) { desiredSalary = salary; }
    void setYearsOfExperience(const double years) { yearsOfExperience = years; }
    void setCertificationsCount(const int count) { certificationsCount = count; }

    ~Resume() = default;
};
#endif // PERSON_H
