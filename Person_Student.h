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

class Student : public Person {
    std::string universityName;
    std::string faculty;
    std::string major;
    double GPA;
    double yearsOfStudy;
    int completedCredits;

public:
    // Конструктор по умолчанию
    Student() = default;

    // Конструктор со всеми параметрами
    Student(std::string firstName, std::string lastName, const int birthYear, const double height, const double weight,
            std::string universityName, std::string faculty, std::string major,
            const double GPA, const double yearsOfStudy, const int completedCredits)
        : Person(std::move(firstName), std::move(lastName), birthYear, height, weight),
          universityName(std::move(universityName)), faculty(std::move(faculty)), major(std::move(major)),
          GPA(GPA), yearsOfStudy(yearsOfStudy), completedCredits(completedCredits) {}

    // Конструкторы копирования и перемещения
    Student(const Student&) = default;
    Student(Student&&) noexcept = default;
    Student& operator=(const Student&) = default;
    Student& operator=(Student&&) noexcept = default;

    // Геттеры
    [[nodiscard]] std::string getUniversityName() const { return universityName; }
    [[nodiscard]] std::string getFaculty() const { return faculty; }
    [[nodiscard]] std::string getMajor() const { return major; }
    [[nodiscard]] double getGPA() const { return GPA; }
    [[nodiscard]] double getYearsOfStudy() const { return yearsOfStudy; }
    [[nodiscard]] int getCompletedCredits() const { return completedCredits; }

    // Сеттеры
    void setUniversityName(const std::string& name) { universityName = name; }
    void setFaculty(const std::string& faculty) { this->faculty = faculty; }
    void setMajor(const std::string& major) { this->major = major; }
    void setGPA(const double gpa) { GPA = gpa; }
    void setYearsOfStudy(const double years) { yearsOfStudy = years; }
    void setCompletedCredits(const int credits) { completedCredits = credits; }

    // Деструктор
    ~Student() = default;
};

#endif // PERSON_H



