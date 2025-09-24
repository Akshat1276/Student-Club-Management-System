#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <stdexcept>
using namespace std;
template <typename T>
class Vector {
private:
    T* arr;          // pointer to dynamic array
    int Size;        //  number of elements
    int Capacity;    //  capacity

    void resize(int new_capacity) {
        T* newArr = new T[new_capacity];
        for (int i = 0; i < Size; i++) {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
        Capacity = new_capacity;
    }

public:
    // Constructor
    Vector(int initial_capacity = 2) {
        Size = 0;
        Capacity = initial_capacity;
        arr = new T[Capacity];
    }

    // Destructor
    ~Vector() {
        delete[] arr;
    }

 
    void add(const T& element) {
        if (Size == Capacity) {
            resize(Capacity * 2);
        }
        arr[Size++] = element;
    }

   
    void remove(int index) {
        if (index < 0 || index >= Size) {
            throw out_of_range("Index out of range");
        }
        for (int i = index; i < Size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        Size--;
    }

   
    T get(int index) const {
        if (index < 0 || index >= Size) {
            throw out_of_range("Index out of range");
        }
        return arr[index];
    }

   
    void set(int index, const T& element) {
        if (index < 0 || index >= Size) {
            throw out_of_range("Index out of range");
        }
        arr[index] = element;
    }

   
    int length() const {
        return Size;
    }
};

#endif 