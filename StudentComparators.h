#ifndef STUDENT_COMPARATORS_H
#define STUDENT_COMPARATORS_H

#include "DefaultComparators.h"
#include "Person_Student.h"

inline int AscendingComparatorByAge(const Student& a, const Student& b) {
    return DescendingComparator(a.getAge(), b.getAge());
}

inline int DescendingComparatorByAge(const Student& a, const Student& b) {
    return AscendingComparator(a.getAge(), b.getAge());
}

inline int AscendingComparatorByHeight(const Student& a, const Student& b) {
    return AscendingComparator(a.getHeight(), b.getHeight());
}

inline int DescendingComparatorByHeight(const Student& a, const Student& b) {
    return DescendingComparator(a.getHeight(), b.getHeight());
}

inline int AscendingComparatorByWeight(const Student& a, const Student& b) {
    return AscendingComparator(a.getWeight(), b.getWeight());
}

inline int DescendingComparatorByWeight(const Student& a, const Student& b) {
    return DescendingComparator(a.getWeight(), b.getWeight());
}

inline int AscendingComparatorByGPA(const Student& a, const Student& b) {
    return AscendingComparator(a.getGPA(), b.getGPA());
}

inline int DescendingComparatorByGPA(const Student& a, const Student& b) {
    return DescendingComparator(a.getGPA(), b.getGPA());
}

inline int AscendingComparatorByYearsOfStudy(const Student& a, const Student& b) {
    return AscendingComparator(a.getYearsOfStudy(), b.getYearsOfStudy());
}

inline int DescendingComparatorByYearsOfStudy(const Student& a, const Student& b) {
    return DescendingComparator(a.getYearsOfStudy(), b.getYearsOfStudy());
}

inline int AscendingComparatorByCompletedCredits(const Student& a, const Student& b) {
    return AscendingComparator(a.getCompletedCredits(), b.getCompletedCredits());
}

inline int DescendingComparatorByCompletedCredits(const Student& a, const Student& b) {
    return DescendingComparator(a.getCompletedCredits(), b.getCompletedCredits());
}

#endif // STUDENT_COMPARATORS_H
