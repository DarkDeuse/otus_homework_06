#pragma once
#include <cstddef>

template<typename T>
class serial_container{
    public:
        serial_container();
        ~serial_container();

        void add_memory();

        void push_back(const int value);

        int operator [] (const size_t index) const;

         void erase(size_t index);
    
    void insert(size_t index, int value);

    size_t size();
    void print();


    private:
        size_t size_;
        size_t capacity;
        T* array;
};
#include "serial.inl"