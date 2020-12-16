#include <fstream>
#include <iostream>
#include "LinkedList.h"

using namespace std;

/**
 * \brief Демонстрация работы с λ-функциями.
 */
void lambdaDemo();

template <typename T>
int file_output_demo(const string& filename, const LinkedList<T>& data);

void old_demo();

void file_output_commented_demo();

void stream_input_demo();

int file_input_demo();

/**
 * \brief Точка входа в программу.
 * \return Код ошибки. 0 -- всё хорошо.
 */
int main()
{
    file_output_commented_demo();

    file_input_demo();

    return 0;
}

template <typename T>
int file_output_demo(const string& filename, const LinkedList<T>& data)
{
    ofstream out_file(filename.c_str(), ios_base::out);

    if (!out_file.is_open())
    {
        cerr << "Error! Unable to open output file: " << filename << endl;
        // C-style!
        return -1;
    }

    out_file << data << endl;

    /*for (auto item : data)
    {
        out_file << item << ", ";
    }*/

    // out_file.flush();
    out_file.close();

    return 0;
}

void stream_input_demo()
{
    LinkedList<int> tmp;
    cout << "input list: ";
    cin >> tmp;
    cout << "list = " << tmp << ";" << endl;
}

int file_input_demo()
{
    LinkedList<int> tmp;
    const auto* const filename = "result.txt";

    ifstream in_file(filename, ios_base::in);

    if (!in_file.is_open())
    {
        cerr << "Error! Unable to open output file: " << filename << endl;
        // C-style!
        return -1;
    }

    in_file >> tmp;

    in_file.close();

    cout << "list = " << tmp << ";" << endl;
}

void old_demo()
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
}

void file_output_commented_demo()
{
    const LinkedList<int> tmp = { 1, 2, 3, 4, 5 };
    cout << tmp << endl;

    const auto code = file_output_demo("result.txt", tmp);
    cout << "code = " << code << endl;

    cout << "END!" << endl;
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
