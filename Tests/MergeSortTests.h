#ifndef MERGESORTTESTS_H
#define MERGESORTTESTS_H

#include <string>
#include "../Generator.h"
#include "../MergeSort.h"
#include "../Person_Student.h"
#include "../ArraySequence.h"
#include "../StudentComparators.h"

inline bool MergeSortAscAgeTest(const std::string& path) {
    ArraySequence<Student> students;
    GettingDataFromFile(path, students);
    const MergeSorter<Student> sorter;
    sorter.Sort(students, AscendingComparatorByAge);
    for (int i = 0; i < students.GetLength() - 1; ++i) {
        if (students[i].getAge() < students[i + 1].getAge()) {
            return false;
        }
    }
    return true;
}

inline bool MergeSortDescAgeTest(const std::string& path) {
    ArraySequence<Student> students;
    GettingDataFromFile(path, students);
    const MergeSorter<Student> sorter;
    sorter.Sort(students, DescendingComparatorByAge);
    for (int i = 0; i < students.GetLength() - 1; ++i) {
        if (students[i].getAge() > students[i + 1].getAge()) {
            return false;
        }
    }
    return true;
}

inline bool MergeSortAscGPATest(const std::string& path) {
    ArraySequence<Student> students;
    GettingDataFromFile(path, students);
    const MergeSorter<Student> sorter;
    sorter.Sort(students, AscendingComparatorByGPA);
    for (int i = 0; i < students.GetLength() - 1; ++i) {
        if (students[i].getGPA() > students[i + 1].getGPA()) {
            return false;
        }
    }
    return true;
}

inline bool MergeSortDescGPATest(const std::string& path) {
    ArraySequence<Student> students;
    GettingDataFromFile(path, students);
    const MergeSorter<Student> sorter;
    sorter.Sort(students, DescendingComparatorByGPA);
    for (int i = 0; i < students.GetLength() - 1; ++i) {
        if (students[i].getGPA() < students[i + 1].getGPA()) {
            return false;
        }
    }
    return true;
}

inline bool MergeSortAscYearsOfStudyTest(const std::string& path) {
    ArraySequence<Student> students;
    GettingDataFromFile(path, students);
    const MergeSorter<Student> sorter;
    sorter.Sort(students, AscendingComparatorByYearsOfStudy);
    for (int i = 0; i < students.GetLength() - 1; ++i) {
        if (students[i].getYearsOfStudy() > students[i + 1].getYearsOfStudy()) {
            return false;
        }
    }
    return true;
}

inline bool MergeSortDescYearsOfStudyTest(const std::string& path) {
    ArraySequence<Student> students;
    GettingDataFromFile(path, students);
    const MergeSorter<Student> sorter;
    sorter.Sort(students, DescendingComparatorByYearsOfStudy);
    for (int i = 0; i < students.GetLength() - 1; ++i) {
        if (students[i].getYearsOfStudy() < students[i + 1].getYearsOfStudy()) {
            return false;
        }
    }
    return true;
}

inline bool MergeSortAscCompletedCreditsTest(const std::string& path) {
    ArraySequence<Student> students;
    GettingDataFromFile(path, students);
    const MergeSorter<Student> sorter;
    sorter.Sort(students, AscendingComparatorByCompletedCredits);
    for (int i = 0; i < students.GetLength() - 1; ++i) {
        if (students[i].getCompletedCredits() > students[i + 1].getCompletedCredits()) {
            return false;
        }
    }
    return true;
}

inline bool MergeSortDescCompletedCreditsTest(const std::string& path) {
    ArraySequence<Student> students;
    GettingDataFromFile(path, students);
    const MergeSorter<Student> sorter;
    sorter.Sort(students, DescendingComparatorByCompletedCredits);
    for (int i = 0; i < students.GetLength() - 1; ++i) {
        if (students[i].getCompletedCredits() < students[i + 1].getCompletedCredits()) {
            return false;
        }
    }
    return true;
}

inline bool MergeSortAscHeightTest(const std::string& path) {
    ArraySequence<Student> students;
    GettingDataFromFile(path, students);
    const MergeSorter<Student> sorter;
    sorter.Sort(students, AscendingComparatorByHeight);
    for (int i = 0; i < students.GetLength() - 1; ++i) {
        if (students[i].getHeight() > students[i + 1].getHeight()) {
            return false;
        }
    }
    return true;
}

inline bool MergeSortDescHeightTest(const std::string& path) {
    ArraySequence<Student> students;
    GettingDataFromFile(path, students);
    const MergeSorter<Student> sorter;
    sorter.Sort(students, DescendingComparatorByHeight);
    for (int i = 0; i < students.GetLength() - 1; ++i) {
        if (students[i].getHeight() < students[i + 1].getHeight()) {
            return false;
        }
    }
    return true;
}

inline bool MergeSortAscWeightTest(const std::string& path) {
    ArraySequence<Student> students;
    GettingDataFromFile(path, students);
    const MergeSorter<Student> sorter;
    sorter.Sort(students, AscendingComparatorByWeight);
    for (int i = 0; i < students.GetLength() - 1; ++i) {
        if (students[i].getWeight() > students[i + 1].getWeight()) {
            return false;
        }
    }
    return true;
}

inline bool MergeSortDescWeightTest(const std::string& path) {
    ArraySequence<Student> students;
    GettingDataFromFile(path, students);
    const MergeSorter<Student> sorter;
    sorter.Sort(students, DescendingComparatorByWeight);
    for (int i = 0; i < students.GetLength() - 1; ++i) {
        if (students[i].getWeight() < students[i + 1].getWeight()) {
            return false;
        }
    }
    return true;
}


#endif //MERGESORTTESTS_H
