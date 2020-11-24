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

    list.AddBack(4).AddBack(5);

    auto* ptr = &list;
    ptr->AddBack(6).AddBack(7);
    // x->y <=> (*x).y

    std::cout << list << std::endl;

    LinkedList<int> tmp = { 1,2,3,4,5};
    std::cout << tmp << std::endl;

    auto it = list.cbegin();
    while (it != list.cend())
    {
        std::cout << *it << ", ";
        ++it;
    }
    std::cout << std::endl;

    std::for_each(tmp.cbegin(), tmp.cend(),
        [tmp](const int item) {std::cout << item << ","; });
    return 0;
}
