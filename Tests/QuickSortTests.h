#ifndef QUICKSORTTESTS_H
#define QUICKSORTTESTS_H

#include <string>
#include "../Generator.h"
#include "../QuickSort.h"
#include "../Person_Resume.h"
#include "../ArraySequence.h"
#include "../ResumeComparators.h"

inline bool QuickSortAscAgeTest(const std::string& path) {
    ArraySequence<Resume> resumes;
    GettingDataFromFile(path, resumes);
    const QuickSorter<Resume> sorter;
    sorter.Sort(resumes, DescendingComparatorByAge);
    for (int i = 0; i < resumes.GetLength() - 1; ++i) {
        if (resumes[i].getAge() > resumes[i + 1].getAge()) {
            return false;
        }
    }
    return true;
}

inline bool QuickSortDescAgeTest(const std::string& path) {
    ArraySequence<Resume> resumes;
    GettingDataFromFile(path, resumes);
    const QuickSorter<Resume> sorter;
    sorter.Sort(resumes, AscendingComparatorByAge);
    for (int i = 0; i < resumes.GetLength() - 1; ++i) {
        if (resumes[i].getAge() < resumes[i + 1].getAge()) {
            return false;
        }
    }
    return true;
}

inline bool QuickSortAscSalaryTest(const std::string& path) {
    ArraySequence<Resume> resumes;
    GettingDataFromFile(path, resumes);
    const QuickSorter<Resume> sorter;
    sorter.Sort(resumes, AscendingComparatorByDesiredSalary);
    for (int i = 0; i < resumes.GetLength() - 1; ++i) {
        if (resumes[i].getDesiredSalary() > resumes[i + 1].getDesiredSalary()) {
            return false;
        }
    }
    return true;
}

inline bool QuickSortDescSalaryTest(const std::string& path) {
    ArraySequence<Resume> resumes;
    GettingDataFromFile(path, resumes);
    const QuickSorter<Resume> sorter;
    sorter.Sort(resumes, DescendingComparatorByDesiredSalary);
    for (int i = 0; i < resumes.GetLength() - 1; ++i) {
        if (resumes[i].getDesiredSalary() < resumes[i + 1].getDesiredSalary()) {
            return false;
        }
    }
    return true;
}

inline bool QuickSortAscExperienceTest(const std::string& path) {
    ArraySequence<Resume> resumes;
    GettingDataFromFile(path, resumes);
    const QuickSorter<Resume> sorter;
    sorter.Sort(resumes, AscendingComparatorByYearsOfExperience);
    for (int i = 0; i < resumes.GetLength() - 1; ++i) {
        if (resumes[i].getYearsOfExperience() > resumes[i + 1].getYearsOfExperience()) {
            return false;
        }
    }
    return true;
}

inline bool QuickSortDescExperienceTest(const std::string& path) {
    ArraySequence<Resume> resumes;
    GettingDataFromFile(path, resumes);
    const QuickSorter<Resume> sorter;
    sorter.Sort(resumes, DescendingComparatorByYearsOfExperience);
    for (int i = 0; i < resumes.GetLength() - 1; ++i) {
        if (resumes[i].getYearsOfExperience() < resumes[i + 1].getYearsOfExperience()) {
            return false;
        }
    }
    return true;
}

inline bool QuickSortAscCertificationsTest(const std::string& path) {
    ArraySequence<Resume> resumes;
    GettingDataFromFile(path, resumes);
    const QuickSorter<Resume> sorter;
    sorter.Sort(resumes, AscendingComparatorByCertificationsCount);
    for (int i = 0; i < resumes.GetLength() - 1; ++i) {
        if (resumes[i].getCertificationsCount() > resumes[i + 1].getCertificationsCount()) {
            return false;
        }
    }
    return true;
}

inline bool QuickSortDescCertificationsTest(const std::string& path) {
    ArraySequence<Resume> resumes;
    GettingDataFromFile(path, resumes);
    const QuickSorter<Resume> sorter;
    sorter.Sort(resumes, DescendingComparatorByCertificationsCount);
    for (int i = 0; i < resumes.GetLength() - 1; ++i) {
        if (resumes[i].getCertificationsCount() < resumes[i + 1].getCertificationsCount()) {
            return false;
        }
    }
    return true;
}

inline bool QuickSortAscHeightTest(const std::string& path) {
    ArraySequence<Resume> resumes;
    GettingDataFromFile(path, resumes);
    const QuickSorter<Resume> sorter;
    sorter.Sort(resumes, AscendingComparatorByHeight);
    for (int i = 0; i < resumes.GetLength() - 1; ++i) {
        if (resumes[i].getHeight() > resumes[i + 1].getHeight()) {
            return false;
        }
    }
    return true;
}

inline bool QuickSortDescHeightTest(const std::string& path) {
    ArraySequence<Resume> resumes;
    GettingDataFromFile(path, resumes);
    const QuickSorter<Resume> sorter;
    sorter.Sort(resumes, DescendingComparatorByHeight);
    for (int i = 0; i < resumes.GetLength() - 1; ++i) {
        if (resumes[i].getHeight() < resumes[i + 1].getHeight()) {
            return false;
        }
    }
    return true;
}

inline bool QuickSortAscWeightTest(const std::string& path) {
    ArraySequence<Resume> resumes;
    GettingDataFromFile(path, resumes);
    const QuickSorter<Resume> sorter;
    sorter.Sort(resumes, AscendingComparatorByWeight);
    for (int i = 0; i < resumes.GetLength() - 1; ++i) {
        if (resumes[i].getWeight() > resumes[i + 1].getWeight()) {
            return false;
        }
    }
    return true;
}

inline bool QuickSortDescWeightTest(const std::string& path) {
    ArraySequence<Resume> resumes;
    GettingDataFromFile(path, resumes);
    const QuickSorter<Resume> sorter;
    sorter.Sort(resumes, DescendingComparatorByWeight);
    for (int i = 0; i < resumes.GetLength() - 1; ++i) {
        if (resumes[i].getWeight() < resumes[i + 1].getWeight()) {
            return false;
        }
    }
    return true;
}

#endif //QUICKSORTTESTS_H
