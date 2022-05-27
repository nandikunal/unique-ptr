#include <cassert>
#include <iostream>
#include "exclusive_ptr.hpp"

int main() {
    myptr::exclusive_ptr<int> ptr = myptr::exclusive_ptr<int>(new int(100));
    myptr::exclusive_ptr<int> ptr1{std::move(ptr)};

    std::cout << *ptr1 << std::endl;

    ptr1.reset();

    if(ptr1) {
        std::cout << *ptr1 << std::endl;
    } else {
        std::cout << "ptr1 is null!\n";
    }

    myptr::exclusive_ptr<int> ptr2{new int(200)};
    std::cout << *ptr2 << std::endl;

    myptr::exclusive_ptr<int> ptr3;
    ptr3 = std::move(ptr2);

    std::cout << *ptr3 << std::endl;

    // myptr::exclusive_ptr<int> ptr4 = ptr2; //this should give compilation error

    return 0;
}
