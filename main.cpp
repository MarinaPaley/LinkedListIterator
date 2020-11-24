#include <iostream>
#include "LinkedList.h"

int main()
{
    // LinkedList<int> list = { 1, 2, 3, 4, 5 };

    // LinkedList<int> l1;
    // LinkedList<int> l2 = l1;
    // LinkedList<int> l3(l1);

    auto list = LinkedList<int>();
    list.Add(1);
    list.Add(2);
    list.Add(3);
    list.AddBack(4)
        ->AddBack(5);

    std::cout << list << std::endl;

    const LinkedList<int> tmp = { 1,2,3,4,5};
    std::cout << tmp << std::endl;

    return 0;
}
