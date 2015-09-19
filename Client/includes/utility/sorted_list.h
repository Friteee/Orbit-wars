#ifndef SORTED_LIST_H_INCLUDED
#define SORTED_LIST_H_INCLUDED

#include <utility>

template<typename Type, typename Value> class sorted_list
{
public:
    sorted_list();
    void push_back(Type & object, Value & value);
    void push_back(std::pair<Type, Value> object_value);
    void push_front(Type & object, Value & value);
    void push_front(std::pair<Type, Value> object_value);
    Type pop_back();
    Type pop_front();
    Type front();
    Type back();
    int size();
private:
    struct Node
    {
        Node * next_;
        Node * previous_;
        Type object_;
        Value value_;
    };
    int size_;
    Node * first_;
    Node * last_;
};

#endif // SORTED_LIST_H_INCLUDED
