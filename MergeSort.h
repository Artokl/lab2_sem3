#ifndef MERGESORTER_H
#define MERGESORTER_H

#include "iSorter.h"
#include <vector>

template<typename T>
class MergeSorter final : public ISorter<T> {
    void merge(Sequence<T>& sequence, const int left, const int mid, const int right, int (*cmp)(const T&, const T&)) const {
        int leftSize = mid - left + 1;
        int rightSize = right - mid;

        std::vector<T> leftArray(leftSize);
        std::vector<T> rightArray(rightSize);

        for (int i = 0; i < leftSize; ++i)
            leftArray[i] = sequence[left + i];
        for (int i = 0; i < rightSize; ++i)
            rightArray[i] = sequence[mid + 1 + i];

        int i = 0;
        int j = 0;
        int k = left;

        while (i < leftSize && j < rightSize) {
            if (cmp(leftArray[i], rightArray[j]) <= 0) {
                sequence[k] = leftArray[i];
                ++i;
            } else {
                sequence[k] = rightArray[j];
                ++j;
            }
            ++k;
        }

        while (i < leftSize) {
            sequence[k] = leftArray[i];
            ++i;
            ++k;
        }
        while (j < rightSize) {
            sequence[k] = rightArray[j];
            ++j;
            ++k;
        }
    }

    void mergeSort(Sequence<T>& sequence, const int left, const int right, int (*cmp)(const T&, const T&)) const {
        if (left >= right) return;

        const int mid = left + (right - left) / 2;

        mergeSort(sequence, left, mid, cmp);
        mergeSort(sequence, mid + 1, right, cmp);

        merge(sequence, left, mid, right, cmp);
    }

public:
    Sequence<T>* Sort(Sequence<T>& sequence, int (*cmp)(const T&, const T&)) const override {
        mergeSort(sequence, 0, sequence.GetLength() - 1, cmp);
        return &sequence;
    }
};

#endif // MERGESORTER_H

