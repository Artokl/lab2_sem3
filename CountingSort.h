#ifndef COUNTINGSORTER_H
#define COUNTINGSORTER_H

#include "iSorter.h"
#include <stdexcept>
#include <vector>

template<typename T>
class CountingSorter final : public ISorter<T> {
public:
    Sequence<T>* Sort(Sequence<T>& sequence, int (*cmp)(const T&, const T&)) const override {
        if (sequence.GetLength() == 0) return &sequence;

        static_assert(std::is_integral_v<T>, "CountingSort поддерживает только целые числа");

        T minVal = sequence[0];
        T maxVal = sequence[0];
        for (int i = 1; i < sequence.GetLength(); ++i) {
            if (cmp(sequence[i], minVal) < 0) minVal = sequence[i];
            if (cmp(sequence[i], maxVal) > 0) maxVal = sequence[i];
        }

        const int range = maxVal - minVal + 1;
        if (range <= 0) throw std::overflow_error("Диапазон значений слишком велик");

        std::vector count(range, 0);

        for (int i = 0; i < sequence.GetLength(); ++i) {
            ++count[sequence[i] - minVal];
        }

        for (int i = 1; i < range; ++i) {
            count[i] += count[i - 1];
        }

        std::vector<T> sorted(sequence.GetLength());
        for (int i = sequence.GetLength() - 1; i >= 0; --i) {
            sorted[--count[sequence[i] - minVal]] = sequence[i];
        }

        for (int i = 0; i < sequence.GetLength(); ++i) {
            sequence[i] = sorted[i];
        }

        return &sequence;
    }
};

#endif // COUNTINGSORTER_H
