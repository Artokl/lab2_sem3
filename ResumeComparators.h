#ifndef ResumeCOMPARATORS_H
#define ResumeCOMPARATORS_H

#include "DefaultComparators.h"
#include "Person_Resume.h"

inline int AscendingComparatorByAge(const Resume& a, const Resume& b) {
    return DescendingComparator(a.getAge(), b.getAge());
}

inline int DescendingComparatorByAge(const Resume& a, const Resume& b) {
    return AscendingComparator(a.getAge(), b.getAge());
}

inline int AscendingComparatorByHeight(const Resume& a, const Resume& b) {
    return AscendingComparator(a.getHeight(), b.getHeight());
}

inline int DescendingComparatorByHeight(const Resume& a, const Resume& b) {
    return DescendingComparator(a.getHeight(), b.getHeight());
}

inline int AscendingComparatorByWeight(const Resume& a, const Resume& b) {
    return AscendingComparator(a.getWeight(), b.getWeight());
}

inline int DescendingComparatorByWeight(const Resume& a, const Resume& b) {
    return DescendingComparator(a.getWeight(), b.getWeight());
}

inline int AscendingComparatorByDesiredSalary(const Resume& a, const Resume& b) {
    return AscendingComparator(a.getDesiredSalary(), b.getDesiredSalary());
}

inline int DescendingComparatorByDesiredSalary(const Resume& a, const Resume& b) {
    return DescendingComparator(a.getDesiredSalary(), b.getDesiredSalary());
}

inline int AscendingComparatorByYearsOfExperience(const Resume& a, const Resume& b) {
    return AscendingComparator(a.getYearsOfExperience(), b.getYearsOfExperience());
}

inline int DescendingComparatorByYearsOfExperience(const Resume& a, const Resume& b) {
    return DescendingComparator(a.getYearsOfExperience(), b.getYearsOfExperience());
}

inline int AscendingComparatorByCertificationsCount(const Resume& a, const Resume& b) {
    return AscendingComparator(a.getCertificationsCount(), b.getCertificationsCount());
}

inline int DescendingComparatorByCertificationsCount(const Resume& a, const Resume& b) {
    return DescendingComparator(a.getCertificationsCount(), b.getCertificationsCount());
}

#endif //ResumeCOMPARATORS_H
