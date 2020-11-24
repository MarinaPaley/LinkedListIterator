#include "LinkedList.h"

int main()
{
    // LinkedList<int> list = { 1, 2, 3, 4, 5 };

    LinkedList<int> l1;
    LinkedList<int> l2 = l1;
    LinkedList<int> l3(l1);

    return 0;
}
