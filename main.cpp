#include <iostream>
#include "serial.hpp"


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
    std::cout<<"erase:"<<std::endl;
    sc.erase(2);
    sc.erase(3);
    sc.erase(4);
    sc.print();
    std::cout<<"insert:"<<std::endl;
    sc.insert(0, 10);
    sc.print();
    sc.insert(4, 20);
    sc.print();
    sc.insert(9, 30);
    sc.print();
    return 0;
}