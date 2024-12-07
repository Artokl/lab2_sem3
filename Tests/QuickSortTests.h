#ifndef QUICKSORTTESTS_H
#define QUICKSORTTESTS_H
#include <string>

#include <string>
#include "../Generator.h"
#include "../QuickSort.h"
#include "../Person.h"
#include "../ArraySequence.h"
#include "../PersonComparators.h"

inline bool QuickSortDescAgeTest(const std::string& path) {
    ArraySequence<Person> persons;
    GettingDataFromFile(path, persons);
    const QuickSorter<Person> sorter;
    sorter.Sort(persons, AscendingComparatorByAge);
    for (int i = 0; i < persons.GetLength() - 1; ++i) {
        if (persons[i].getAge() < persons[i + 1].getAge()) {
            return false;
        }
    }
    return true;
}

inline bool QuickSortAscAgeTest(const std::string& path) {
    ArraySequence<Person> persons;
    GettingDataFromFile(path, persons);
    const QuickSorter<Person> sorter;
    sorter.Sort(persons, DescendingComparatorByAge);
    for (int i = 0; i < persons.GetLength() - 1; ++i) {
        if (persons[i].getAge() > persons[i + 1].getAge()) {
            return false;
        }
    }
    return true;
}

inline bool QuickSortDescWeightTest(const std::string& path) {
    ArraySequence<Person> persons;
    GettingDataFromFile(path, persons);
    const QuickSorter<Person> sorter;
    sorter.Sort(persons, DescendingComparatorByWeight);
    for (int i = 0; i < persons.GetLength() - 1; ++i) {
        if (persons[i].getWeight() < persons[i + 1].getWeight()) {
            return false;
        }
    }
    return true;
}

inline bool QuickSortAscWeightTest(const std::string& path) {
    ArraySequence<Person> persons;
    GettingDataFromFile(path, persons);
    const QuickSorter<Person> sorter;
    sorter.Sort(persons, AscendingComparatorByWeight);
    for (int i = 0; i < persons.GetLength() - 1; ++i) {
        if (persons[i].getWeight() > persons[i + 1].getWeight()) {
            return false;
        }
    }
    return true;
}

inline bool QuickSortDescHeightTest(const std::string& path) {
    ArraySequence<Person> persons;
    GettingDataFromFile(path, persons);
    const QuickSorter<Person> sorter;
    sorter.Sort(persons, DescendingComparatorByHeight);
    for (int i = 0; i < persons.GetLength() - 1; ++i) {
        if (persons[i].getHeight() < persons[i + 1].getHeight()) {
            return false;
        }
    }
    return true;
}

inline bool QuickSortAscHeightTest(const std::string& path) {
    ArraySequence<Person> persons;
    GettingDataFromFile(path, persons);
    const QuickSorter<Person> sorter;
    sorter.Sort(persons, AscendingComparatorByHeight);
    for (int i = 0; i < persons.GetLength() - 1; ++i) {
        if (persons[i].getHeight() > persons[i + 1].getHeight()) {
            return false;
        }
    }
    return true;
}

#endif //QUICKSORTTESTS_H
