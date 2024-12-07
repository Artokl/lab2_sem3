#ifndef MERGESORTTESTS_H
#define MERGESORTTESTS_H
#include <string>

#include "../Generator.h"
#include "../MergeSort.h"
#include "../Person.h"
#include "../ArraySequence.h"
#include "../PersonComparators.h"

inline bool MergeSortDescAgeTest(const std::string& path) {
    ArraySequence<Person> persons;
    GettingDataFromFile(path, persons);
    const MergeSorter<Person> sorter;
    sorter.Sort(persons, AscendingComparatorByAge);
    for (int i = 0; i < persons.GetLength() - 1; ++i) {
        if (persons[i].getAge() < persons[i + 1].getAge()) {
            return false;
        }
    }
    return true;
}

inline bool MergeSortAscAgeTest(const std::string& path) {
    ArraySequence<Person> persons;
    GettingDataFromFile(path, persons);
    const MergeSorter<Person> sorter;
    sorter.Sort(persons, DescendingComparatorByAge);
    for (int i = 0; i < persons.GetLength() - 1; ++i) {
        if (persons[i].getAge() > persons[i + 1].getAge()) {
            return false;
        }
    }
    return true;
}

inline bool MergeSortDescWeightTest(const std::string& path) {
    ArraySequence<Person> persons;
    GettingDataFromFile(path, persons);
    const MergeSorter<Person> sorter;
    sorter.Sort(persons, DescendingComparatorByWeight);
    for (int i = 0; i < persons.GetLength() - 1; ++i) {
        if (persons[i].getWeight() < persons[i + 1].getWeight()) {
            return false;
        }
    }
    return true;
}

inline bool MergeSortAscWeightTest(const std::string& path) {
    ArraySequence<Person> persons;
    GettingDataFromFile(path, persons);
    const MergeSorter<Person> sorter;
    sorter.Sort(persons, AscendingComparatorByWeight);
    for (int i = 0; i < persons.GetLength() - 1; ++i) {
        if (persons[i].getWeight() > persons[i + 1].getWeight()) {
            return false;
        }
    }
    return true;
}

inline bool MergeSortDescHeightTest(const std::string& path) {
    ArraySequence<Person> persons;
    GettingDataFromFile(path, persons);
    const MergeSorter<Person> sorter;
    sorter.Sort(persons, DescendingComparatorByHeight);
    for (int i = 0; i < persons.GetLength() - 1; ++i) {
        if (persons[i].getHeight() < persons[i + 1].getHeight()) {
            return false;
        }
    }
    return true;
}

inline bool MergeSortAscHeightTest(const std::string& path) {
    ArraySequence<Person> persons;
    GettingDataFromFile(path, persons);
    const MergeSorter<Person> sorter;
    sorter.Sort(persons, AscendingComparatorByHeight);
    for (int i = 0; i < persons.GetLength() - 1; ++i) {
        if (persons[i].getHeight() > persons[i + 1].getHeight()) {
            return false;
        }
    }
    return true;
}

#endif //MERGESORTTESTS_H
