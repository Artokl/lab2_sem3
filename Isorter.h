#ifndef ISORTER_H
#define ISORTER_H

#include "Sequence.h"

template<class T>
class ISorter {
public:
    virtual Sequence<T>* Sort(Sequence<T>& sequence, int (*cmp)(const T&, const T&)) const = 0;
    virtual ~ISorter() = default;
};

#endif // ISORTER_H

