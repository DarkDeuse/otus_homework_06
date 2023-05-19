#include <iostream>
#include <math.h>

struct Node{
    Node* prev;
    Node* next;
    int val;
    Node() = default;
    Node(int value, Node* &previos, Node* &next_): val{value}, prev{previos}, next{next_}{};
    Node(int value, Node* &previos): val{value}, prev{previos}, next{nullptr} {};
    Node(int value): val{value}, prev{nullptr}, next{nullptr}{};
    ~Node() = default;
};

class list_container{
    public:
        list_container(): first{nullptr}, last{nullptr}, size_{0}{}
        ~list_container() = default;
        
        int size(){
            return size_;
        }
        
        Node* find_from_beginning(Node* element, int count_iter){
            for (size_t i=0; i < count_iter; ++i){
                            element = element->next;
            }
            return element;
        }

        Node* find_from_end(Node* element, int count_iter){
            for (size_t i=1; i < count_iter; ++i){
                            element = element->prev;
            }
            return element;
        }


        Node* find_element(int count){
            int middle = (size_ / 2);
            Node* elem = first;
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


        int operator[](const int index){
            Node* elem = find_element(index);
            return elem->val;
        }

        void push_back(int val){
            Node* elem = new Node(val);
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
        void erase(int index){
            Node* del_elem = find_element(index);
            if (del_elem == first){
                Node* next_del_elem = del_elem->next;
                next_del_elem->prev = last;
                first = next_del_elem;
            }
            else if (del_elem == last){
                Node* prev_del_elem = del_elem->prev;
                prev_del_elem->next = first;
                last = prev_del_elem;
            }
            else{
                Node* next_del_elem = del_elem->next;
                Node* prev_del_elem = del_elem->prev;
                prev_del_elem->next = next_del_elem;
                next_del_elem->prev = prev_del_elem;
            }
            delete del_elem;
            --size_;
        }

        void insert(int index, int value){
            int max_val = size();
            if (index == 0){
                Node* moving_element = first;
                Node* insert_element = new Node(value);
                insert_element->prev = last;
                insert_element->next = moving_element;
                first = insert_element;
            }
            else if(index >= max_val){
                push_back(value);
            }
            else{
                Node* moving_element = find_element(index);
                Node* prev_moving_element = moving_element->prev;
                Node* insert_element = new Node(value, prev_moving_element, moving_element);
                prev_moving_element->next = insert_element;
                moving_element->prev = insert_element;
            }
            ++size_;
            
        }

        void print(){
            Node* elem = first;
            while(elem != last){
                std::cout<<elem->val<<", ";
                elem = elem->next;
            }
            std::cout<<elem->val<<std::endl;
        }

        

    private:
        Node* first;
        Node* last;
        int size_;

};

    


int main(){
    list_container lc;
    lc.push_back(0);
    lc.push_back(1);
    lc.push_back(2);
    lc.push_back(3);
    lc.push_back(4);
    lc.push_back(5);
    lc.push_back(6);
    lc.push_back(7);
    lc.push_back(8);
    lc.push_back(9);
    lc.print();
    std::cout<<lc.size()<<std::endl;
    lc.erase(2);
    lc.erase(3);
    lc.erase(4);
    lc.print();
    lc.insert(0, 10);
    lc.print();
    lc.insert(4, 20);
    lc.print();
    lc.insert(9, 30);
    lc.print();
    return 0;
}
