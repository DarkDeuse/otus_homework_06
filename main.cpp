#include <iostream>

template<typename T>
class serial_container{
    public:
        serial_container():
            size_{0},
            capacity{1},
            array(new T[capacity]){};
        ~serial_container(){delete [] array;};
        serial_container(const serial_container& other) = default;

        void add_memory(){
            T* tmp = array;
            capacity += 1;
            array = new T[capacity];
            for (size_t i = 0; i < size_; ++i) array[i] = tmp[i];
            delete[] tmp;
            }

        void push_back(const int value){
            if (size_>=capacity){
                add_memory();
            }
            array[size_++] = value;
        };

        int operator [] (const size_t index) const{
            if (index>size_){
                std::string val = "Out of lenght";
                return;
            }
            else{
            int val = array[index];
            return val;}
        }

         void erase(size_t index) {
      for (size_t i = index + 1; i < size_; ++i) {
          array[i - 1] = array[i];
      }
      --size_;
    }
    
    void insert(size_t index, int value){
        ++size_;
        if (size_ >= capacity) add_memory();
        for (size_t i = size_; i > index; --i) {
    		array[i] = array[i-1];
        }
        array[index] = value;
    }

    size_t size(){
        return size_;
    }

    void print(){
        for (size_t i = 0; i < size_; ++i){
            if (i!=0){std::cout<<"," << " ";};
            int val = array[i];
            std::cout<<val;
        }
        std::cout<<std::endl;
    }


    private:
        size_t size_;
        size_t capacity;
        T* array;
};



int main(){
    std::cout<< "serail container:"<<std::endl;
    serial_container<int> sc;
    std::cout<<"push_back:"<<std::endl;
    sc.push_back(0);
    sc.push_back(1);
    sc.push_back(2);
    sc.push_back(3);
    sc.push_back(4);
    sc.push_back(5);
    sc.push_back(6);
    sc.push_back(7);
    sc.push_back(8);
    sc.push_back(9);
    sc.print();
    std::cout<<"size:"<<std::endl;
    std::cout<<sc.size()<<std::endl;
    std::cout<<"erase"<<std::endl;
    sc.erase(2);
    sc.erase(3);
    sc.erase(4);
    sc.print();
    std::cout<<"insert"<<std::endl;
    sc.insert(0, 10);
    sc.print();
    sc.insert(4, 20);
    sc.print();
    sc.insert(9, 30);
    sc.print();
    std::cout<<"-----------------------------------------------------"<<std::endl;
    std::cout<<"list container:"<<std::endl;
    return 0;
}