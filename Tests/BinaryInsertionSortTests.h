#ifndef BINARYINSERTIONSORTTESTS_H
#define BINARYINSERTIONSORTTESTS_H

#include <string>
#include "../Generator.h"
#include "../BinaryInsertionSort.h"
#include "../Person_Student.h"
#include "../ArraySequence.h"
#include "../StudentComparators.h"

inline bool BinaryInsertionSortAscAgeTest(const std::string& path) {
    ArraySequence<Student> students;
    GettingDataFromFile(path, students);
    const BinaryInsertionSorter<Student> sorter;
    sorter.Sort(students, AscendingComparatorByAge);
    for (int i = 0; i < students.GetLength() - 1; ++i) {
        if (students[i].getAge() < students[i + 1].getAge()) {
            return false;
        }
    }
    return true;
}

inline bool BinaryInsertionSortDescAgeTest(const std::string& path) {
    ArraySequence<Student> students;
    GettingDataFromFile(path, students);
    const BinaryInsertionSorter<Student> sorter;
    sorter.Sort(students, DescendingComparatorByAge);
    for (int i = 0; i < students.GetLength() - 1; ++i) {
        if (students[i].getAge() > students[i + 1].getAge()) {
            return false;
        }
    }
    return true;
}

inline bool BinaryInsertionSortAscGPATest(const std::string& path) {
    ArraySequence<Student> students;
    GettingDataFromFile(path, students);
    const BinaryInsertionSorter<Student> sorter;
    sorter.Sort(students, AscendingComparatorByGPA);
    for (int i = 0; i < students.GetLength() - 1; ++i) {
        if (students[i].getGPA() > students[i + 1].getGPA()) {
            return false;
        }
    }
    return true;
}

inline bool BinaryInsertionSortDescGPATest(const std::string& path) {
    ArraySequence<Student> students;
    GettingDataFromFile(path, students);
    const BinaryInsertionSorter<Student> sorter;
    sorter.Sort(students, DescendingComparatorByGPA);
    for (int i = 0; i < students.GetLength() - 1; ++i) {
        if (students[i].getGPA() < students[i + 1].getGPA()) {
            return false;
        }
    }
    return true;
}

inline bool BinaryInsertionSortAscYearsOfStudyTest(const std::string& path) {
    ArraySequence<Student> students;
    GettingDataFromFile(path, students);
    const BinaryInsertionSorter<Student> sorter;
    sorter.Sort(students, AscendingComparatorByYearsOfStudy);
    for (int i = 0; i < students.GetLength() - 1; ++i) {
        if (students[i].getYearsOfStudy() > students[i + 1].getYearsOfStudy()) {
            return false;
        }
    }
    return true;
}

inline bool BinaryInsertionSortDescYearsOfStudyTest(const std::string& path) {
    ArraySequence<Student> students;
    GettingDataFromFile(path, students);
    const BinaryInsertionSorter<Student> sorter;
    sorter.Sort(students, DescendingComparatorByYearsOfStudy);
    for (int i = 0; i < students.GetLength() - 1; ++i) {
        if (students[i].getYearsOfStudy() < students[i + 1].getYearsOfStudy()) {
            return false;
        }
    }
    return true;
}

inline bool BinaryInsertionSortAscCompletedCreditsTest(const std::string& path) {
    ArraySequence<Student> students;
    GettingDataFromFile(path, students);
    const BinaryInsertionSorter<Student> sorter;
    sorter.Sort(students, AscendingComparatorByCompletedCredits);
    for (int i = 0; i < students.GetLength() - 1; ++i) {
        if (students[i].getCompletedCredits() > students[i + 1].getCompletedCredits()) {
            return false;
        }
    }
    return true;
}

inline bool BinaryInsertionSortDescCompletedCreditsTest(const std::string& path) {
    ArraySequence<Student> students;
    GettingDataFromFile(path, students);
    const BinaryInsertionSorter<Student> sorter;
    sorter.Sort(students, DescendingComparatorByCompletedCredits);
    for (int i = 0; i < students.GetLength() - 1; ++i) {
        if (students[i].getCompletedCredits() < students[i + 1].getCompletedCredits()) {
            return false;
        }
    }
    return true;
}

inline bool BinaryInsertionSortAscHeightTest(const std::string& path) {
    ArraySequence<Student> students;
    GettingDataFromFile(path, students);
    const BinaryInsertionSorter<Student> sorter;
    sorter.Sort(students, AscendingComparatorByHeight);
    for (int i = 0; i < students.GetLength() - 1; ++i) {
        if (students[i].getHeight() > students[i + 1].getHeight()) {
            return false;
        }
    }
    return true;
}

inline bool BinaryInsertionSortDescHeightTest(const std::string& path) {
    ArraySequence<Student> students;
    GettingDataFromFile(path, students);
    const BinaryInsertionSorter<Student> sorter;
    sorter.Sort(students, DescendingComparatorByHeight);
    for (int i = 0; i < students.GetLength() - 1; ++i) {
        if (students[i].getHeight() < students[i + 1].getHeight()) {
            return false;
        }
    }
    return true;
}

inline bool BinaryInsertionSortAscWeightTest(const std::string& path) {
    ArraySequence<Student> students;
    GettingDataFromFile(path, students);
    const BinaryInsertionSorter<Student> sorter;
    sorter.Sort(students, AscendingComparatorByWeight);
    for (int i = 0; i < students.GetLength() - 1; ++i) {
        if (students[i].getWeight() > students[i + 1].getWeight()) {
            return false;
        }
    }
    return true;
}

inline bool BinaryInsertionSortDescWeightTest(const std::string& path) {
    ArraySequence<Student> students;
    GettingDataFromFile(path, students);
    const BinaryInsertionSorter<Student> sorter;
    sorter.Sort(students, DescendingComparatorByWeight);
    for (int i = 0; i < students.GetLength() - 1; ++i) {
        if (students[i].getWeight() < students[i + 1].getWeight()) {
            return false;
        }
    }
    return true;
}

#endif // BINARYINSERTIONSORTTESTS_H
