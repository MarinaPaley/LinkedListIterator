#include <iostream>
#include "LinkedList.h"

using namespace std;

/**
 * \brief Демонстрация работы с λ-функциями.
 */
void lambdaDemo();

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

    cout << endl << "for with const_iterator: ";
    for (auto it = list.cbegin(); it != list.cend(); ++it)
    {
        cout << *it << ", ";
    }
    cout << endl;

    return 0;
}

void lambdaDemo()
{
    // DE AD BE EF

    const int value = 42;
    const int* pointer = &value;

    std::string str = "Hello world!";
    auto* ptr = &str;

    std::cout << "define lambda:" << std::endl;
    auto lambda = [](const int item) { std::cout << item << std::endl; };

    std::cout << "invoke lambda:" << std::endl;
    lambda(42);
}
