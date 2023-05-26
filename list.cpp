#include "list.hpp"

int main(){
    list_container<int> lc;
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