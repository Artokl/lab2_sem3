#ifndef BINARYINSERTIONSORTTESTS_H
#define BINARYINSERTIONSORTTESTS_H

#include <string>
#include "../Generator.h"
#include "../BinaryInsertionSort.h"
#include "../Person_Resume.h"
#include "../ArraySequence.h"
#include "../ResumeComparators.h"

inline bool BinaryInsertionSortAscAgeTest(const std::string& path) {
    ArraySequence<Resume> resumes;
    GettingDataFromFile(path, resumes);
    const BinaryInsertionSorter<Resume> sorter;
    sorter.Sort(resumes, DescendingComparatorByAge);
    for (int i = 0; i < resumes.GetLength() - 1; ++i) {
        if (resumes[i].getAge() > resumes[i + 1].getAge()) {
            return false;
        }
    }
    return true;
}

inline bool BinaryInsertionSortDescAgeTest(const std::string& path) {
    ArraySequence<Resume> resumes;
    GettingDataFromFile(path, resumes);
    const BinaryInsertionSorter<Resume> sorter;
    sorter.Sort(resumes, AscendingComparatorByAge);
    for (int i = 0; i < resumes.GetLength() - 1; ++i) {
        if (resumes[i].getAge() < resumes[i + 1].getAge()) {
            return false;
        }
    }
    return true;
}

inline bool BinaryInsertionSortAscSalaryTest(const std::string& path) {
    ArraySequence<Resume> resumes;
    GettingDataFromFile(path, resumes);
    const BinaryInsertionSorter<Resume> sorter;
    sorter.Sort(resumes, AscendingComparatorByDesiredSalary);
    for (int i = 0; i < resumes.GetLength() - 1; ++i) {
        if (resumes[i].getDesiredSalary() > resumes[i + 1].getDesiredSalary()) {
            return false;
        }
    }
    return true;
}

inline bool BinaryInsertionSortDescSalaryTest(const std::string& path) {
    ArraySequence<Resume> resumes;
    GettingDataFromFile(path, resumes);
    const BinaryInsertionSorter<Resume> sorter;
    sorter.Sort(resumes, DescendingComparatorByDesiredSalary);
    for (int i = 0; i < resumes.GetLength() - 1; ++i) {
        if (resumes[i].getDesiredSalary() < resumes[i + 1].getDesiredSalary()) {
            return false;
        }
    }
    return true;
}

inline bool BinaryInsertionSortAscExperienceTest(const std::string& path) {
    ArraySequence<Resume> resumes;
    GettingDataFromFile(path, resumes);
    const BinaryInsertionSorter<Resume> sorter;
    sorter.Sort(resumes, AscendingComparatorByYearsOfExperience);
    for (int i = 0; i < resumes.GetLength() - 1; ++i) {
        if (resumes[i].getYearsOfExperience() > resumes[i + 1].getYearsOfExperience()) {
            return false;
        }
    }
    return true;
}

inline bool BinaryInsertionSortDescExperienceTest(const std::string& path) {
    ArraySequence<Resume> resumes;
    GettingDataFromFile(path, resumes);
    const BinaryInsertionSorter<Resume> sorter;
    sorter.Sort(resumes, DescendingComparatorByYearsOfExperience);
    for (int i = 0; i < resumes.GetLength() - 1; ++i) {
        if (resumes[i].getYearsOfExperience() < resumes[i + 1].getYearsOfExperience()) {
            return false;
        }
    }
    return true;
}

inline bool BinaryInsertionSortAscCertificationsTest(const std::string& path) {
    ArraySequence<Resume> resumes;
    GettingDataFromFile(path, resumes);
    const BinaryInsertionSorter<Resume> sorter;
    sorter.Sort(resumes, AscendingComparatorByCertificationsCount);
    for (int i = 0; i < resumes.GetLength() - 1; ++i) {
        if (resumes[i].getCertificationsCount() > resumes[i + 1].getCertificationsCount()) {
            return false;
        }
    }
    return true;
}

inline bool BinaryInsertionSortDescCertificationsTest(const std::string& path) {
    ArraySequence<Resume> resumes;
    GettingDataFromFile(path, resumes);
    const BinaryInsertionSorter<Resume> sorter;
    sorter.Sort(resumes, DescendingComparatorByCertificationsCount);
    for (int i = 0; i < resumes.GetLength() - 1; ++i) {
        if (resumes[i].getCertificationsCount() < resumes[i + 1].getCertificationsCount()) {
            return false;
        }
    }
    return true;
}

inline bool BinaryInsertionSortAscHeightTest(const std::string& path) {
    ArraySequence<Resume> resumes;
    GettingDataFromFile(path, resumes);
    const BinaryInsertionSorter<Resume> sorter;
    sorter.Sort(resumes, AscendingComparatorByHeight);
    for (int i = 0; i < resumes.GetLength() - 1; ++i) {
        if (resumes[i].getHeight() > resumes[i + 1].getHeight()) {
            return false;
        }
    }
    return true;
}

inline bool BinaryInsertionSortDescHeightTest(const std::string& path) {
    ArraySequence<Resume> resumes;
    GettingDataFromFile(path, resumes);
    const BinaryInsertionSorter<Resume> sorter;
    sorter.Sort(resumes, DescendingComparatorByHeight);
    for (int i = 0; i < resumes.GetLength() - 1; ++i) {
        if (resumes[i].getHeight() < resumes[i + 1].getHeight()) {
            return false;
        }
    }
    return true;
}

inline bool BinaryInsertionSortAscWeightTest(const std::string& path) {
    ArraySequence<Resume> resumes;
    GettingDataFromFile(path, resumes);
    const BinaryInsertionSorter<Resume> sorter;
    sorter.Sort(resumes, AscendingComparatorByWeight);
    for (int i = 0; i < resumes.GetLength() - 1; ++i) {
        if (resumes[i].getWeight() > resumes[i + 1].getWeight()) {
            return false;
        }
    }
    return true;
}

inline bool BinaryInsertionSortDescWeightTest(const std::string& path) {
    ArraySequence<Resume> resumes;
    GettingDataFromFile(path, resumes);
    const BinaryInsertionSorter<Resume> sorter;
    sorter.Sort(resumes, DescendingComparatorByWeight);
    for (int i = 0; i < resumes.GetLength() - 1; ++i) {
        if (resumes[i].getWeight() < resumes[i + 1].getWeight()) {
            return false;
        }
    }
    return true;
}

#endif // BINARYINSERTIONSORTTESTS_H
