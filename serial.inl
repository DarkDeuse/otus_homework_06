#include <iostream>

template <class T>
serial_container<T>::serial_container():
            size_{0},
            capacity{1},
            array(new T[capacity]){};
template <class T>
serial_container<T>::~serial_container(){delete [] array;};
template <class T>
void serial_container<T>::add_memory(){
            T* tmp = array;
            capacity += 1;
            array = new T[capacity];
            for (size_t i = 0; i < size_; ++i) array[i] = tmp[i];
            delete[] tmp;
            }
template <class T>
void serial_container<T>::push_back(const int value){
            if (size_>=capacity){
                add_memory();
            }
            array[size_++] = value;
        };
template <class T>
T serial_container<T>::operator [] (const size_t index) const{
            if (index>size_){
                std::cout<<"Out of lenght"<<std::endl;
                return false;
            }
            else{
            int val = array[index];
            return val;}
        }

template<class T>

T serial_container<T>::operator = (T& other){
    if (*this != &other){
        this = std::move(other);
        delete [] other;
    }
}

template <class T>
void serial_container<T>::erase(size_t index) {
      for (size_t i = index + 1; i < size_; ++i) {
          array[i - 1] = array[i];
      }
      --size_;
    }
template <class T>
void serial_container<T>::insert(size_t index, int value){
        ++size_;
        if (size_ >= capacity) add_memory();
        for (size_t i = size_; i > index; --i) {
    		array[i] = array[i-1];
        }
        array[index] = value;
    }
template <class T>
size_t serial_container<T>::size(){
        return size_;
    }
template <class T>
void serial_container<T>::print(){
        for (size_t i = 0; i < size_; ++i){
            if (i!=0){std::cout<<"," << " ";};
            int val = array[i];
            std::cout<<val;
        }
        std::cout<<std::endl;
    }