#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
    ULListStr list;

    std::cout << "Push back and push front" << std::endl;
    list.push_back("1");
    list.push_back("2");
    list.push_back("3");
    list.push_front("4");
    list.push_front("5");
    list.push_front("6");

    std::cout << "Expected: 6 5 4 1 2 3" << std::endl;
    std::cout << "Result: ";
    for (size_t i = 0; i < list.size(); i++) {
        std::cout << list.get(i) << " ";
    }
    std::cout << std::endl;

    std::cout << "Pop front and pop back" << std::endl;
    list.pop_front(); 
    list.pop_back();

    std::cout << "Expected: 5 4 1 2" << std::endl;
    std::cout << "Result: ";
    for (size_t i = 0; i < list.size(); i++) {
        std::cout << list.get(i) << " ";
    }
    std::cout << std::endl;


    std::cout << "Set and Get" << std::endl;
    list.set(1, "123");
    std::cout << "Expected: 5 123 1 2" << std::endl;
    std::cout << "Result: ";
    for (size_t i = 0; i < list.size(); i++) {
        std::cout << list.get(i) << " ";
    }
    std::cout << std::endl;


    std::cout << "Empty list" << std::endl;
    ULListStr empty;
    if (empty.empty()){
         std::cout << "true" << std::endl;
    }else{
        std::cout << "false" << std::endl;
    }
    std::cout << "Size: " << empty.size() << std::endl;

    return 0;
}
