#pragma once
#include <initializer_list>

template <class T>
class LinkedList;

template<class T>
class ListItem
{
    friend class LinkedList<T>;

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
    LinkedList(const LinkedList& list);

    LinkedList<T>& operator= (const LinkedList<T>& other);

    ~LinkedList();

    T& GetFirst();
    const T& GetFirst() const;
    void Add(const T& value);
    void RemoveFirst();

    bool IsEmpty() const;
private:
    ListItem<T>* head;
    ListItem<T>* tail;
    void Destroy();
    void CopyElements(const LinkedList&);
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
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& other)
{
    if (*this != other)
    {
        this->CopyElements(other);
    }
    return *this;
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
    auto newItem = new ListItem<T>(value);;
    if (this->IsEmpty())
    {
        this->head = newItem;
        this->tail = newItem;
    }
    else
    {
        this->tail->next= newItem;
        this->tail = newItem;
    }
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
void LinkedList<T>::CopyElements(const LinkedList& other)
{
    auto current = other.head;
    while(current != nullptr)
    {
        this->Add(current->value);
        current = current->next;
    }
}
