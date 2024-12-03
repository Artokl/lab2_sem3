#ifndef DEFAULTCOMPARATORS_H
#define DEFAULTCOMPARATORS_H

template <typename T>
int AscendingComparator(const T& a, const T& b) {
    if (a < b) return -1;
    if (a > b) return 1;
    return 0;
}
template<typename T>
int DescendingComparator(const T& a, const T& b)
{
    if (a < b) return 1;
    if (a > b) return -1;
    return 0;
}

#endif //DEFAULTCOMPARATORS_H
