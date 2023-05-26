#pragma once
#include <cstddef>

template <typename T>
struct Node{
Node* prev;
Node* next;
T val;
Node();
Node(int value, Node* &previos, Node* &next_);
Node(int value, Node* &previos);
Node(int value);
~Node();
};


template <typename T>
class list_container{
    public:
        list_container();
        ~list_container();
        
        int size();
        
        Node<T>* find_from_beginning(Node<T>* element, int count_iter);

        Node<T>* find_from_end(Node<T>* element, int count_iter);


        Node<T>* find_element(int count);


        T operator[](const int index);
        void push_back(int val);
        void erase(int index);

        void insert(int index, int value);
        void print();
        

    private:
        Node<T>* first;
        Node<T>* last;
        int size_;

};
# include "list.inl"