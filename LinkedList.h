#pragma once
#include <ostream>
#include <algorithm>
#include <sstream>

template <class T>
class LinkedList;

template <class Type>
std::ostream& operator<<(std::ostream&, const LinkedList<Type>&);

template <class Type>
std::wostream& operator<<(std::wostream&, const LinkedList<Type>&);

template <class T>
std::wstring ToString(const LinkedList<T>& obj);

template <class Type>
bool operator==(const LinkedList<Type>& lha, const LinkedList<Type>& rha);

template <class T>
class Iterator;

template<class T>
class ListItem
{
    friend class LinkedList<T>;
    friend class Iterator<T>;

    friend std::ostream& operator<< <T> (std::ostream&, const LinkedList<T>&);
    friend std::wostream& operator<< <T> (std::wostream&, const LinkedList<T>&);

    friend bool operator== <T> (const LinkedList<T>& lha, const LinkedList<T>& rha);

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
    friend std::wostream& operator<< <T> (std::wostream&, const LinkedList<T>&);

    friend bool operator== <T> (const LinkedList<T>& lha, const LinkedList<T>& rha);

    ~LinkedList();

    T& GetFirst() const;
    void Add(const T& value);
    LinkedList<T>& AddBack(const T& value);
    void RemoveFirst();

    bool IsEmpty() const;

    Iterator<T> begin();
    Iterator<T> end();

    Iterator<const T> cbegin();
    Iterator<const T> cend();

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
LinkedList<T>::LinkedList(const LinkedList& list)
    : LinkedList()
{
    this->CopyElements(list);
}

template <class T>
LinkedList<T>::LinkedList(std::initializer_list<T> other)
    : LinkedList()
{
   std::for_each(other.begin(), other.end(), [this](const T item) { this->Add(item); });
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
bool operator==(LinkedList<T>& lha, LinkedList<T>& rha)
{
    // TODO: если |lha| > |rha|, то будет БУМ!
    return std::equal(lha.begin(), lha.end(), rha.begin());
}

template <class T>
bool operator==(const LinkedList<T>& lha, const LinkedList<T>& rha)
{
    auto current_lha = lha.head;
    auto current_rha = rha.head;
    while (current_lha != nullptr && current_rha != nullptr)
    {
        if (current_lha->value != current_rha->value)
        {
            return false;
        }

        current_lha = current_lha->next;
        current_rha = current_rha->next;
    }
    return current_lha == current_rha;
}

template <class T>
std::ostream& operator<< (std::ostream& out, const LinkedList<T>& list)
{
    if (list.IsEmpty())
    {
        return out << "{ }";
    }

    out << "{ ";
    auto current = list.head;
    while (current->next != nullptr)
    {
        out << current->value << ", ";
        current = current->next;
    }
    return out << current->value << " }";
}

template <class T>
std::wostream& operator<< (std::wostream& out, const LinkedList<T>& list)
{
    if (list.IsEmpty())
    {
        return out << L"{ }";
    }

    out << L"{ ";
    auto current = list.head;
    while (current->next != nullptr)
    {
        // TODO: проблема с wostream << string
        out << current->value << L", ";
        current = current->next;
    }
    // TODO: проблема с wostream << string
    return out << current->value << L" }";
}

template <class T>
std::wstring ToString(const LinkedList<T>& obj)
{
    std::wstringstream out;
    out << obj;
    return out.str();
}

template <class T>
LinkedList<T>::~LinkedList()
{
    this->Destroy();
}

template <class T>
T& LinkedList<T>::GetFirst() const
{
    if (this->IsEmpty())
    {
        throw std::exception("Collection is empty!");
    }

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
LinkedList<T>& LinkedList<T>::AddBack(const T& value)
{
    this->Add(value);
    return *this;
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
Iterator<T> LinkedList<T>::begin()
{
    return Iterator<T>(this->head);
}

template <class T>
Iterator<T> LinkedList<T>::end()
{
    return Iterator<T>(this->tail->next);
}

template <class T>
Iterator<const T> LinkedList<T>::cbegin()
{
    return Iterator<const T>(reinterpret_cast<ListItem<const T>*>(this->head));
}


template <class T>
Iterator<const T> LinkedList<T>::cend()
{
    return Iterator<const T>(reinterpret_cast<ListItem<const T>*>(this->tail->next));
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

template <class T>
class Iterator
{
public:
    explicit Iterator(ListItem<T>* item);
    Iterator(const Iterator<T>& other);

    bool operator == (Iterator<T> const& other) const;
    bool operator != (Iterator<T> const& other) const;
    Iterator<T> operator++();
    T& operator *();
    T& operator *() const;

    friend class LinkedList<T>;

private:
    ListItem<T>* current;
};

template <class T>
Iterator<T>::Iterator(ListItem<T>* item)
{
    this->current = item;
}

template<class T>
Iterator<T>::Iterator(const Iterator<T> & other)
{
    this->current = other.current;
}

template <class T>
bool Iterator<T>::operator==(Iterator<T> const& other) const
{
    return (this->current == other.current);
}

template <class T>
bool Iterator<T>::operator!=(Iterator<T> const& other) const
{
    return (this->current != other.current);
}

template <class T>
Iterator<T> Iterator<T>::operator++()
{
    this->current = this->current->next;
    return Iterator<T>(this->current);
}

template <class T>
T& Iterator<T>::operator*()
{
    return this->current->value;
}

template <class T>
T& Iterator<T>::operator*() const
{
    return this->current->value;
}
