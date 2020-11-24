#include <iostream>
#include "LinkedList.h"

using namespace std;

/**
 * \brief Точка входа в программу.
 * \return Код ошибки. 0 -- всё хорошо.
 */
int main()
{
    auto list = LinkedList<int>();
    list.Add(1);
    list.Add(2);
    list.Add(3);

    list.AddBack(4).AddBack(5);

    auto* ptr = &list;
    ptr->AddBack(6).AddBack(7);
    // x->y <=> (*x).y

    cout << list << endl;

    LinkedList<int> tmp = { 1, 2, 3, 4, 5 };
    cout << tmp << endl;

    cout << endl << "for: ";
    for (auto& it : list)
    {
        cout << it << ", ";
    }
    cout << endl;

    cout << endl << "for_each: ";
    for_each(tmp.begin(), tmp.end(), [](const int item) { cout << item << ", "; });
    cout << endl;

    return 0;
}
