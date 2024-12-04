#ifndef BINARY_INSERTION_SORTER_H
#define BINARY_INSERTION_SORTER_H

#include "isorter.h"

template<typename T>
class BinaryInsertionSorter final : public ISorter<T> {
public:
    Sequence<T>* Sort(Sequence<T>& sequence, int (*cmp)(const T&, const T&)) const override {
        for (int i = 1; i < sequence.GetLength(); ++i) {
            T key = sequence[i];
            int left = 0;
            int right = i;
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (cmp(key, sequence[mid]) < 0) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }
            for (int j = i; j > left; --j) {
                sequence[j] = sequence[j - 1];
            }
            sequence[left] = key;
        }
        return &sequence;
    }
};

#endif // BINARY_INSERTION_SORTER_H
