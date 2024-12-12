#ifndef MERGESORTTESTS_H
#define MERGESORTTESTS_H

#include <string>
#include "../Generator.h"
#include "../MergeSort.h"
#include "../Person_Resume.h"
#include "../ArraySequence.h"
#include "../ResumeComparators.h"

inline bool MergeSortAscAgeTest(const std::string& path) {
    ArraySequence<Resume> resumes;
    GettingDataFromFile(path, resumes);
    const MergeSorter<Resume> sorter;
    sorter.Sort(resumes, DescendingComparatorByAge);
    for (int i = 0; i < resumes.GetLength() - 1; ++i) {
        if (resumes[i].getAge() > resumes[i + 1].getAge()) {
            return false;
        }
    }
    return true;
}

inline bool MergeSortDescAgeTest(const std::string& path) {
    ArraySequence<Resume> resumes;
    GettingDataFromFile(path, resumes);
    const MergeSorter<Resume> sorter;
    sorter.Sort(resumes, AscendingComparatorByAge);
    for (int i = 0; i < resumes.GetLength() - 1; ++i) {
        if (resumes[i].getAge() < resumes[i + 1].getAge()) {
            return false;
        }
    }
    return true;
}

inline bool MergeSortAscSalaryTest(const std::string& path) {
    ArraySequence<Resume> resumes;
    GettingDataFromFile(path, resumes);
    const MergeSorter<Resume> sorter;
    sorter.Sort(resumes, AscendingComparatorByDesiredSalary);
    for (int i = 0; i < resumes.GetLength() - 1; ++i) {
        if (resumes[i].getDesiredSalary() > resumes[i + 1].getDesiredSalary()) {
            return false;
        }
    }
    return true;
}

inline bool MergeSortDescSalaryTest(const std::string& path) {
    ArraySequence<Resume> resumes;
    GettingDataFromFile(path, resumes);
    const MergeSorter<Resume> sorter;
    sorter.Sort(resumes, DescendingComparatorByDesiredSalary);
    for (int i = 0; i < resumes.GetLength() - 1; ++i) {
        if (resumes[i].getDesiredSalary() < resumes[i + 1].getDesiredSalary()) {
            return false;
        }
    }
    return true;
}

inline bool MergeSortAscExperienceTest(const std::string& path) {
    ArraySequence<Resume> resumes;
    GettingDataFromFile(path, resumes);
    const MergeSorter<Resume> sorter;
    sorter.Sort(resumes, AscendingComparatorByYearsOfExperience);
    for (int i = 0; i < resumes.GetLength() - 1; ++i) {
        if (resumes[i].getYearsOfExperience() > resumes[i + 1].getYearsOfExperience()) {
            return false;
        }
    }
    return true;
}

inline bool MergeSortDescExperienceTest(const std::string& path) {
    ArraySequence<Resume> resumes;
    GettingDataFromFile(path, resumes);
    const MergeSorter<Resume> sorter;
    sorter.Sort(resumes, DescendingComparatorByYearsOfExperience);
    for (int i = 0; i < resumes.GetLength() - 1; ++i) {
        if (resumes[i].getYearsOfExperience() < resumes[i + 1].getYearsOfExperience()) {
            return false;
        }
    }
    return true;
}

inline bool MergeSortAscCertificationsTest(const std::string& path) {
    ArraySequence<Resume> resumes;
    GettingDataFromFile(path, resumes);
    const MergeSorter<Resume> sorter;
    sorter.Sort(resumes, AscendingComparatorByCertificationsCount);
    for (int i = 0; i < resumes.GetLength() - 1; ++i) {
        if (resumes[i].getCertificationsCount() > resumes[i + 1].getCertificationsCount()) {
            return false;
        }
    }
    return true;
}

inline bool MergeSortDescCertificationsTest(const std::string& path) {
    ArraySequence<Resume> resumes;
    GettingDataFromFile(path, resumes);
    const MergeSorter<Resume> sorter;
    sorter.Sort(resumes, DescendingComparatorByCertificationsCount);
    for (int i = 0; i < resumes.GetLength() - 1; ++i) {
        if (resumes[i].getCertificationsCount() < resumes[i + 1].getCertificationsCount()) {
            return false;
        }
    }
    return true;
}

inline bool MergeSortAscHeightTest(const std::string& path) {
    ArraySequence<Resume> resumes;
    GettingDataFromFile(path, resumes);
    const MergeSorter<Resume> sorter;
    sorter.Sort(resumes, AscendingComparatorByHeight);
    for (int i = 0; i < resumes.GetLength() - 1; ++i) {
        if (resumes[i].getHeight() > resumes[i + 1].getHeight()) {
            return false;
        }
    }
    return true;
}

inline bool MergeSortDescHeightTest(const std::string& path) {
    ArraySequence<Resume> resumes;
    GettingDataFromFile(path, resumes);
    const MergeSorter<Resume> sorter;
    sorter.Sort(resumes, DescendingComparatorByHeight);
    for (int i = 0; i < resumes.GetLength() - 1; ++i) {
        if (resumes[i].getHeight() < resumes[i + 1].getHeight()) {
            return false;
        }
    }
    return true;
}

inline bool MergeSortAscWeightTest(const std::string& path) {
    ArraySequence<Resume> resumes;
    GettingDataFromFile(path, resumes);
    const MergeSorter<Resume> sorter;
    sorter.Sort(resumes, AscendingComparatorByWeight);
    for (int i = 0; i < resumes.GetLength() - 1; ++i) {
        if (resumes[i].getWeight() > resumes[i + 1].getWeight()) {
            return false;
        }
    }
    return true;
}

inline bool MergeSortDescWeightTest(const std::string& path) {
    ArraySequence<Resume> resumes;
    GettingDataFromFile(path, resumes);
    const MergeSorter<Resume> sorter;
    sorter.Sort(resumes, DescendingComparatorByWeight);
    for (int i = 0; i < resumes.GetLength() - 1; ++i) {
        if (resumes[i].getWeight() < resumes[i + 1].getWeight()) {
            return false;
        }
    }
    return true;
}

#endif //MERGESORTTESTS_H
