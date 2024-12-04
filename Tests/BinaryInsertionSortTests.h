#ifndef BINARYINSERTIONSORTTESTS_H
#define BINARYINSERTIONSORTTESTS_H

#include <string>
#include "../Generator.h"
#include "../BinaryInsertionSort.h"
#include "../Person.h"
#include "../ArraySequence.h"
#include "../PersonComparators.h"

inline bool BinaryInsertionSortDescAgeTest(const std::string& path) {
    ArraySequence<Person> persons;
    GettingDataFromFile(path, persons);
    const BinaryInsertionSorter<Person> sorter;
    sorter.Sort(persons, DescendingComparatorByAge);
    for (int i = 0; i < persons.GetLength() - 1; ++i) {
        if (persons[i].getAge() < persons[i + 1].getAge()) {
            return false;
        }
    }
    return true;
}

inline bool BinaryInsertionSortAscAgeTest(const std::string& path) {
    ArraySequence<Person> persons;
    GettingDataFromFile(path, persons);
    const BinaryInsertionSorter<Person> sorter;
    sorter.Sort(persons, AscendingComparatorByAge);
    for (int i = 0; i < persons.GetLength() - 1; ++i) {
        if (persons[i].getAge() > persons[i + 1].getAge()) {
            return false;
        }
    }
    return true;
}

inline bool BinaryInsertionSortDescWeightTest(const std::string& path) {
    ArraySequence<Person> persons;
    GettingDataFromFile(path, persons);
    const BinaryInsertionSorter<Person> sorter;
    sorter.Sort(persons, DescendingComparatorByWeight);
    for (int i = 0; i < persons.GetLength() - 1; ++i) {
        if (persons[i].getWeight() < persons[i + 1].getWeight()) {
            return false;
        }
    }
    return true;
}

inline bool BinaryInsertionSortAscWeightTest(const std::string& path) {
    ArraySequence<Person> persons;
    GettingDataFromFile(path, persons);
    const BinaryInsertionSorter<Person> sorter;
    sorter.Sort(persons, AscendingComparatorByWeight);
    for (int i = 0; i < persons.GetLength() - 1; ++i) {
        if (persons[i].getWeight() > persons[i + 1].getWeight()) {
            return false;
        }
    }
    return true;
}

inline bool BinaryInsertionSortDescHeightTest(const std::string& path) {
    ArraySequence<Person> persons;
    GettingDataFromFile(path, persons);
    const BinaryInsertionSorter<Person> sorter;
    sorter.Sort(persons, DescendingComparatorByHeight);
    for (int i = 0; i < persons.GetLength() - 1; ++i) {
        if (persons[i].getHeight() < persons[i + 1].getHeight()) {
            return false;
        }
    }
    return true;
}

inline bool BinaryInsertionSortAscHeightTest(const std::string& path) {
    ArraySequence<Person> persons;
    GettingDataFromFile(path, persons);
    const BinaryInsertionSorter<Person> sorter;
    sorter.Sort(persons, AscendingComparatorByHeight);
    for (int i = 0; i < persons.GetLength() - 1; ++i) {
        if (persons[i].getHeight() > persons[i + 1].getHeight()) {
            return false;
        }
    }
    return true;
}

#endif // BINARYINSERTIONSORTTESTS_H
