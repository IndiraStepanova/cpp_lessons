#include <cstddef>

template <typename T>
class Array
{
    public:
    // Список операций:
    //
    //   конструктор класса, который создает
    //   Array размера size, заполненный значениями
    //   value типа T. Считайте что у типа T есть
    //   конструктор, который можно вызвать без
    //   без параметров, либо он ему не нужен.
    explicit Array(size_t size = 0, const T &value = T()) : size_(size), data_(new T[size])
    {
        for (size_t i = 0; i != size; ++i)
        {
            data_[i] = value;
        }
    }

    //   конструктор копирования, который создает
    //   копию параметра. Считайте, что для типа
    //   T определен оператор присваивания.
    Array(const Array &other) : size_(other.size_), data_(new T[other.size_])
    {
        for (size_t i = 0; i != size_; ++i)
        {
            data_[i] = other.data_[i];
        }
    }

    //   деструктор, если он вам необходим.
    ~Array()
    {
        delete[] data_;
    }

    //   оператор присваивания.
    Array &operator=(Array const &other)
    {
        if (this != &other)
        {
            delete[] data_;
            size_ = other.size_;
            data_ = new T[size_];
            for (size_t i = 0; i != size_; ++i)
            {
                data_[i] = other.data_[i];
            }
            return *this;
        }
    }

    //   возвращает размер массива (количество элементов).
    size_t size() const
    {
        return size_;
    }
    
    //   две версии оператора доступа по индексу.
    T& operator[](size_t i)
    {
        return data_[i];
    }
    const T& operator[](size_t i) const
    {
        return data_[i];
    }
    

private:
    size_t size_;
    T *data_;
};