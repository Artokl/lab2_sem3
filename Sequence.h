#ifndef SEQUENCE_H
#define SEQUENCE_H

template <typename T>
class Sequence {
public:
    virtual ~Sequence() = default;

    virtual T GetFirst() const = 0;
    virtual T GetLast() const = 0;
    virtual T Get(int index) const = 0;
    [[nodiscard]] virtual int GetLength() const = 0;

    virtual void Append(const T& item) = 0;
    virtual void Prepend(const T& item) = 0;
    virtual T& operator[](int index) = 0;
};

#endif //SEQUENCE_H
