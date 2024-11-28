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
    [[nodiscard]] int getBirthYear() const { return birthYear; }
    [[nodiscard]] double getHeight() const { return height; }
    [[nodiscard]] double getWeight() const { return weight; }

    void setFirstName(const std::string& firstName) { this->firstName = firstName; }
    void setLastName(const std::string& lastName) { this->lastName = lastName; }
    void setBirthYear(const int birthYear) { this->birthYear = birthYear; }
    void setHeight(const double height) { this->height = height; }
    void setWeight(const double weight) { this->weight = weight; }

    ~Person() = default;
};

#endif // PERSON_H
