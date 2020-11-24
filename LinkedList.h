#pragma once
#include <ostream>

template <class T>
class LinkedList;

template <class Type>
std::ostream& operator<<(std::ostream&, const LinkedList<Type>&);

template <class T>
class Iterator;

template<class T>
class ListItem
{
    friend class LinkedList<T>;
    friend class Iterator<T>;
    friend std::ostream& operator<< <T> (std::ostream&, const LinkedList<T>&);

    explicit ListItem(const T& value);
    T value;
    ListItem* next;
};

template <class T>
ListItem<T>::ListItem(const T& value) : value(value), next(nullptr)
{
}

template <class T>
class LinkedList
{
public:
    LinkedList();
    LinkedList(const LinkedList<T>& list);

    LinkedList(std::initializer_list<T> other);

    LinkedList<T>& operator= (const LinkedList<T>& other);

    friend std::ostream& operator<< <T> (std::ostream&, const LinkedList<T>&);

    ~LinkedList();

    T& GetFirst();
    const T& GetFirst() const;
    void Add(const T& value);
    LinkedList<T>* AddBack(const T& value);
    void RemoveFirst();

    bool IsEmpty() const;


private:
    ListItem<T>* head;
    ListItem<T>* tail;
    void Destroy();
    void CopyElements(const LinkedList<T>&);
};


template <class T>
LinkedList<T>::LinkedList(): head(nullptr), tail(nullptr)
{
}

template <class T>
LinkedList<T>::LinkedList(const LinkedList& list):
    head(nullptr),tail(nullptr)
{
    this->CopyElements(list);
}

template <class T>
LinkedList<T>::LinkedList(std::initializer_list<T> other)
{
    const auto* tmp = other.begin();
    while (tmp != other.end())
    {
        this->Add(*tmp);
        ++tmp;
    }
}

template <class T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& other)
{
    if (*this != other)
    {
        this->Destroy();
        this->CopyElements(other);
    }
    return *this;
}

template <class T>
std::ostream& operator<< (std::ostream& out, const LinkedList<T>& list)
{
    out << "{ ";
    auto current = list.head;
    while (current->next != nullptr)
    {
        out << current->value << ", ";
        current = current->next;
    }
    return out << current->value
               << " }"
               << std::endl;
}

template <class T>
LinkedList<T>::~LinkedList()
{
    this->Destroy();
}

template <class T>
T& LinkedList<T>::GetFirst()
{
    return this->head->value;
}

template <class T>
const T& LinkedList<T>::GetFirst() const
{
    return this->head->value;
}

template <class T>
void LinkedList<T>::Add(const T& value)
{
    auto item = new ListItem<T>(value);
    if (this->IsEmpty())
    {
        this->head = item;
        this->tail = item;
    }
    else
    {
        this->tail->next= item;
        this->tail = item;
    }
}

template <class T>
LinkedList<T>* LinkedList<T>::AddBack(const T& value)
{
    this->Add(value);
    return this;
}

template <class T>
void LinkedList<T>::RemoveFirst()
{
    if (!this->IsEmpty())
    {
        auto tmp = this->head;
        this->head = this->head->next;
        delete tmp;
    }
}

template <class T>
bool LinkedList<T>::IsEmpty() const
{
    return head == nullptr;
}

template <class T>
void LinkedList<T>::Destroy()
{
    while(!this->IsEmpty())
    {
        this->RemoveFirst();
    }
}

template <class T>
void LinkedList<T>::CopyElements(const LinkedList<T>& other)
{
    auto current = other.head;
    while(current != nullptr)
    {
        this->Add(current->value);
        current = current->next;
    }
}
