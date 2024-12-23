#ifndef QUICKSORTTESTS_H
#define QUICKSORTTESTS_H

#include <string>
#include "../Generator.h"
#include "../QuickSort.h"
#include "../Person_Student.h"
#include "../ArraySequence.h"
#include "../StudentComparators.h"

inline bool QuickSortAscAgeTest(const std::string& path) {
    ArraySequence<Student> students;
    GettingDataFromFile(path, students);
    const QuickSorter<Student> sorter;
    sorter.Sort(students, AscendingComparatorByAge);
    for (int i = 0; i < students.GetLength() - 1; ++i) {
        if (students[i].getAge() < students[i + 1].getAge()) {
            return false;
        }
    }
    return true;
}

inline bool QuickSortDescAgeTest(const std::string& path) {
    ArraySequence<Student> students;
    GettingDataFromFile(path, students);
    const QuickSorter<Student> sorter;
    sorter.Sort(students, DescendingComparatorByAge);
    for (int i = 0; i < students.GetLength() - 1; ++i) {
        if (students[i].getAge() > students[i + 1].getAge()) {
            return false;
        }
    }
    return true;
}

inline bool QuickSortAscGPATest(const std::string& path) {
    ArraySequence<Student> students;
    GettingDataFromFile(path, students);
    const QuickSorter<Student> sorter;
    sorter.Sort(students, AscendingComparatorByGPA);
    for (int i = 0; i < students.GetLength() - 1; ++i) {
        if (students[i].getGPA() > students[i + 1].getGPA()) {
            return false;
        }
    }
    return true;
}

inline bool QuickSortDescGPATest(const std::string& path) {
    ArraySequence<Student> students;
    GettingDataFromFile(path, students);
    const QuickSorter<Student> sorter;
    sorter.Sort(students, DescendingComparatorByGPA);
    for (int i = 0; i < students.GetLength() - 1; ++i) {
        if (students[i].getGPA() < students[i + 1].getGPA()) {
            return false;
        }
    }
    return true;
}

inline bool QuickSortAscHeightTest(const std::string& path) {
    ArraySequence<Student> students;
    GettingDataFromFile(path, students);
    const QuickSorter<Student> sorter;
    sorter.Sort(students, AscendingComparatorByHeight);
    for (int i = 0; i < students.GetLength() - 1; ++i) {
        if (students[i].getHeight() > students[i + 1].getHeight()) {
            return false;
        }
    }
    return true;
}

inline bool QuickSortDescHeightTest(const std::string& path) {
    ArraySequence<Student> students;
    GettingDataFromFile(path, students);
    const QuickSorter<Student> sorter;
    sorter.Sort(students, DescendingComparatorByHeight);
    for (int i = 0; i < students.GetLength() - 1; ++i) {
        if (students[i].getHeight() < students[i + 1].getHeight()) {
            return false;
        }
    }
    return true;
}

inline bool QuickSortAscWeightTest(const std::string& path) {
    ArraySequence<Student> students;
    GettingDataFromFile(path, students);
    const QuickSorter<Student> sorter;
    sorter.Sort(students, AscendingComparatorByWeight);
    for (int i = 0; i < students.GetLength() - 1; ++i) {
        if (students[i].getWeight() > students[i + 1].getWeight()) {
            return false;
        }
    }
    return true;
}

inline bool QuickSortDescWeightTest(const std::string& path) {
    ArraySequence<Student> students;
    GettingDataFromFile(path, students);
    const QuickSorter<Student> sorter;
    sorter.Sort(students, DescendingComparatorByWeight);
    for (int i = 0; i < students.GetLength() - 1; ++i) {
        if (students[i].getWeight() < students[i + 1].getWeight()) {
            return false;
        }
    }
    return true;
}

inline bool QuickSortAscYearsOfStudyTest(const std::string& path) {
    ArraySequence<Student> students;
    GettingDataFromFile(path, students);
    const QuickSorter<Student> sorter;
    sorter.Sort(students, AscendingComparatorByYearsOfStudy);
    for (int i = 0; i < students.GetLength() - 1; ++i) {
        if (students[i].getYearsOfStudy() > students[i + 1].getYearsOfStudy()) {
            return false;
        }
    }
    return true;
}

inline bool QuickSortDescYearsOfStudyTest(const std::string& path) {
    ArraySequence<Student> students;
    GettingDataFromFile(path, students);
    const QuickSorter<Student> sorter;
    sorter.Sort(students, DescendingComparatorByYearsOfStudy);
    for (int i = 0; i < students.GetLength() - 1; ++i) {
        if (students[i].getYearsOfStudy() < students[i + 1].getYearsOfStudy()) {
            return false;
        }
    }
    return true;
}

inline bool QuickSortAscCompletedCreditsTest(const std::string& path) {
    ArraySequence<Student> students;
    GettingDataFromFile(path, students);
    const QuickSorter<Student> sorter;
    sorter.Sort(students, AscendingComparatorByCompletedCredits);
    for (int i = 0; i < students.GetLength() - 1; ++i) {
        if (students[i].getCompletedCredits() > students[i + 1].getCompletedCredits()) {
            return false;
        }
    }
    return true;
}

inline bool QuickSortDescCompletedCreditsTest(const std::string& path) {
    ArraySequence<Student> students;
    GettingDataFromFile(path, students);
    const QuickSorter<Student> sorter;
    sorter.Sort(students, DescendingComparatorByCompletedCredits);
    for (int i = 0; i < students.GetLength() - 1; ++i) {
        if (students[i].getCompletedCredits() < students[i + 1].getCompletedCredits()) {
            return false;
        }
    }
    return true;
}

#endif //QUICKSORTTESTS_H
