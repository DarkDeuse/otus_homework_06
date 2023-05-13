#include <iostream>

struct Node{
    Node* prev;
    Node* next;
    int val;
    int current_count;
    Node(int value, Node* &previos, Node* &next_, int cur): val{value}, prev{previos}, next{next_}, current_count{cur} {};
    Node(int value, Node* &previos, int cur): val{value}, prev{previos}, next{nullptr}, current_count{cur} {};
    Node(int value): val{value}, prev{nullptr}, next{nullptr}, current_count{0} {};
    ~Node() = default;
};

class list_container{
    public:
        list_container(): first{nullptr}, prev{nullptr}, last{nullptr} {}
        ~list_container() = default;
        
        int size(){
            int lenght = last->current_count + 1;
            return lenght;
        }
        

        Node* find_element(int count){
            if (count > last->current_count){
                std::cout<<"Out of memory"<<std::endl;
                return nullptr;
            }
            Node* elem = first;
            while(elem->current_count != count){
                elem = elem->next;
            }
            return elem;
        }

        int operator[](const int index){
            Node* elem = find_element(index);
            return elem->val;
        }

        void correct_index(Node* element, char math){
            while(element != last){
                if(math == '+'){element->current_count += 1;}
                else{element->current_count -= 1;}
                element = element->next;
            }
            if(math == '+'){last->current_count += 1;}
            else{last->current_count -= 1;}
        }

        void push_back(int val){
            Node* elem = new Node(val);
            if(first == nullptr){
                first = elem;
                prev = elem;
                last = elem;
            }
            else{
                last->next = elem;
                prev = last;
                last = elem;
                last->prev = prev;
                last->current_count = prev->current_count + 1;
            };
        }
        void erase(int index){
            Node* del_elem = find_element(index);
            std::cout<<del_elem->val<<std::endl;
            if (del_elem == first){
                Node* next_del_elem = del_elem->next;
                std::cout<<next_del_elem->val<<std::endl;
                next_del_elem->prev = nullptr;
                first = next_del_elem;
                correct_index(next_del_elem, '-');
            }
            else if (del_elem == last){
                Node* prev_del_elem = del_elem->prev;
                prev_del_elem->next = nullptr;
                last = prev_del_elem;
            }
            else{
                Node* next_del_elem = del_elem->next;
                Node* prev_del_elem = del_elem->prev;
                prev_del_elem->next = next_del_elem;
                next_del_elem->prev = prev_del_elem;
                correct_index(next_del_elem, '-');
            }
            delete del_elem;
        }

        void insert(int index, int value){
            int size_ = size();
            if (index == 0){
                Node* moving_element = first;
                Node* insert_element = new Node(value);
                insert_element->prev = nullptr;
                insert_element->next = moving_element;
                first = insert_element;
                correct_index(moving_element, '+');
            }
            else if(index >= size_){
                push_back(value);
            }
            else{
                Node* moving_element = find_element(index);
                Node* prev_moving_element = moving_element->prev;
                Node* insert_element = new Node(value, prev_moving_element, moving_element, index);
                prev_moving_element->next = insert_element;
                moving_element->prev = insert_element;
                correct_index(moving_element, '+');
            }
            
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
        Node* prev;
        Node* last;

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
