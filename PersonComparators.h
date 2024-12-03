#ifndef PERSONCOMPARATORS_H
#define PERSONCOMPARATORS_H

#include "Person.h"
#include "DefaultComparators.h"

inline int AscendingComparatorByAge(const Person& a, const Person& b) {
    return AscendingComparator(a.getAge(), b.getAge());
}

inline int DescendingComparatorByAge(const Person& a, const Person& b) {
    return DescendingComparator(a.getAge(), b.getAge());
}

inline int AscendingComparatorByHeight(const Person& a, const Person& b) {
    return AscendingComparator(a.getHeight(), b.getHeight());
}

inline int DescendingComparatorByHeight(const Person& a, const Person& b) {
    return DescendingComparator(a.getHeight(), b.getHeight());
}

inline int AscendingComparatorByWeight(const Person& a, const Person& b) {
    return AscendingComparator(a.getWeight(), b.getWeight());
}

inline int DescendingComparatorByWeight(const Person& a, const Person& b) {
    return DescendingComparator(a.getWeight(), b.getWeight());
}

#endif //PERSONCOMPARATORS_H
