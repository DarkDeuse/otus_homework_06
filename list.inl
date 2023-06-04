#include <iostream>
#include <math.h>


template <class T>
Node<T>::Node() = default;
template <class T>
Node<T>::Node(int value, Node<T>* &previos, Node<T>* &next_): val{value}, prev{previos}, next{next_}{};
template <class T>
Node<T>::Node(int value, Node<T>* &previos): val{value}, prev{previos}, next{nullptr} {};
template <class T>
Node<T>::Node(int value): val{value}, prev{nullptr}, next{nullptr}{};
template <class T>
Node<T>::~Node() = default;


template <class T>
list_container<T>::list_container(): first{nullptr}, last{nullptr}, size_{0}{}
template <class T>
list_container<T>::~list_container(){
    if(first == last){
        delete first;
    }
    else{
    delete first;
    delete last;
    }
};
template <class T>
int list_container<T>::size(){
            return size_;
        };
template <class T>        
Node<T>* list_container<T>::find_from_beginning(Node<T>* element, int count_iter){
            for (size_t i=0; i < count_iter; ++i){
                            element = element->next;
            }
            return element;
        };
template <class T>  
Node<T>* list_container<T>::find_from_end(Node<T>* element, int count_iter){
            for (size_t i=1; i < count_iter; ++i){
                            element = element->prev;
            }
            return element;
        }

template <class T>
Node<T>* list_container<T>::find_element(int count){
            int middle = (size_ / 2);
            Node<T>* elem = first;
            if (count >=0){
                if (count <= size_){
                    if (count < middle){
                        elem = find_from_beginning(first, count);
                    }
                    else{
                        int find_count = size_ - count;
                        elem = find_from_end(last, find_count);
                    }
                }
                else{
                    elem = last;
                }
            }
            else{
                int abs_count = abs(count);
                if (abs_count <= size_){
                    if (abs_count < middle){
                        elem = find_from_end(last, abs_count);
                    }
                    else{
                        int find_count = size_ - abs_count;
                        elem = find_from_beginning(first, find_count);
                    }
                }
                else{
                    elem = first;
                }
            }
            return elem;
        }
template <class T>
T list_container<T>::operator[](const int index){
            Node<T>* elem = find_element(index);
            return elem->val;
        }
template <class T>
void list_container<T>::push_back(int val){
            Node<T>* elem = new Node<T>(val);
            if(first == nullptr){
                elem->next = elem;
                elem->prev = elem;
                first = elem;
                last = elem;
                ++size_;
            }
            else{
                elem->prev = last;
                elem->next = first;
                last->next = elem;
                last = elem;
                ++size_;
            };
        }
template <class T>
void list_container<T>::erase(int index){
            Node<T>* del_elem = find_element(index);
            if (del_elem == first){
                Node<T>* next_del_elem = del_elem->next;
                next_del_elem->prev = last;
                first = next_del_elem;
            }
            else if (del_elem == last){
                Node<T>* prev_del_elem = del_elem->prev;
                prev_del_elem->next = first;
                last = prev_del_elem;
            }
            else{
                Node<T>* next_del_elem = del_elem->next;
                Node<T>* prev_del_elem = del_elem->prev;
                prev_del_elem->next = next_del_elem;
                next_del_elem->prev = prev_del_elem;
            }
            delete del_elem;
            --size_;
        }
template <class T>
void list_container<T>::insert(int index, int value){
            int max_val = size();
            if (index == 0){
                Node<T>* moving_element = first;
                Node<T>* insert_element = new Node<T>(value);
                insert_element->prev = last;
                insert_element->next = moving_element;
                first = insert_element;
            }
            else if(index >= max_val){
                push_back(value);
            }
            else{
                Node<T>* moving_element = find_element(index);
                Node<T>* prev_moving_element = moving_element->prev;
                Node<T>* insert_element = new Node<T>(value, prev_moving_element, moving_element);
                prev_moving_element->next = insert_element;
                moving_element->prev = insert_element;
            }
            ++size_;
            
        }
template <class T>
void list_container<T>::print(){
            Node<T>* elem = first;
            while(elem != last){
                std::cout<<elem->val<<", ";
                elem = elem->next;
            }
            std::cout<<elem->val<<std::endl;
        }
