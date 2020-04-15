#include <iostream>
#include "20.cpp"

#define _20_EASY_

int main()
{
    #ifdef _20_EASY_
    CreateLists();

    std::cout << FindIntersect(list_A, list_B);
    #endif
}
