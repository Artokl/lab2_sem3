#ifndef ARRAYSEQUENCE_H
#define ARRAYSEQUENCE_H

#include <stdexcept>
#include <concepts>

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

template <std::default_initializable T>
class ArraySequence final : public Sequence<T> {
private:
    ithru
    T* data_;
    int capacity_;
    int length_;

    void EnsureCapacity(const int newCapacity) {
        if (newCapacity <= capacity_) return;

        T* newData = new T[newCapacity];
        for (int i = 0; i < length_; ++i) {
            newData[i] = data_[i];
        }
        delete[] data_;
        data_ = newData;
        capacity_ = newCapacity;
    }

public:
    using value_type = T;
    using reference = T&;
    using const_reference = const T&;

    // Constructors and Destructor
    ArraySequence() : data_(nullptr), capacity_(0), length_(0) {}

    explicit ArraySequence(const int size) : data_(nullptr), capacity_(size + 1), length_(size) {
        if (size <= 0) throw std::out_of_range("Invalid size");
        data_ = new T[capacity_];
    }

    ArraySequence(const T* items, int count) : ArraySequence(count) {
        if (!items) throw std::out_of_range("Items cannot be null");
        for (int i = 0; i < count; ++i) {
            data_[i] = items[i];
        }
    }

    ~ArraySequence() override {
        delete[] data_;
    }

    // Sequence interface implementation
    T GetFirst() const override {
        if (length_ == 0) throw std::out_of_range("Sequence is empty");
        return data_[0];
    }

    T GetLast() const override {
        if (length_ == 0) throw std::out_of_range("Sequence is empty");
        return data_[length_ - 1];
    }

    T Get(int index) const override {
        if (index < 0 || index >= length_) throw std::out_of_range("Index out of range");
        return data_[index];
    }

    [[nodiscard]] int GetLength() const override {
        return length_;
    }

    void Append(const T& item) override {
        Resize(length_ + 1);
        data_[length_ - 1] = item;
    }

    void Prepend(const T& item) override {
        Resize(length_ + 1);
        for (int i = length_ - 1; i > 0; --i) {
            data_[i] = data_[i - 1];
        }
        data_[0] = item;
    }

    T& operator[](int index) override {
        if (index < 0 || index >= length_) throw std::out_of_range("Index out of range");
        return data_[index];
    }

    const T& operator[](int index) const {
        if (index < 0 || index >= length_) throw std::out_of_range("Index out of range");
        return data_[index];
    }

    bool operator==(const ArraySequence& other) const {
        if (length_ != other.length_) return false;
        for (int i = 0; i < length_; ++i) {
            if (data_[i] != other.data_[i]) return false;
        }
        return true;
    }

    // Resize the array
    void Resize(const int newSize) {
        if (newSize < 0) throw std::invalid_argument("Invalid size");
        if (newSize == 0) {
            delete[] data_;
            data_ = nullptr;
            capacity_ = 0;
        } else if (newSize > capacity_) {
            EnsureCapacity(newSize * 2);
        }
        length_ = newSize;
    }
};

#endif // ARRAYSEQUENCE_H
