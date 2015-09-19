#include "sorted_list.h"

template<typename Type, typename Value> sorted_list<Type, Value>::sorted_list()
{
    size_ = 0;
    first_ = nullptr;
    last_ = nullptr;
}

template<typename Type, typename Value> void sorted_list<Type, Value>::push_back(Type & object, Value & value)
{
    size_++;
    Node * buffer = new Node();
    buffer->object_ = object;
    buffer->value_ = value;
    // is the element only one in list?
    if(last_ == nullptr)
    {
        last_ = buffer;
        last_->next_ = nullptr;
        last_->previous_ = nullptr;
        first_ = last_;
        return;
    }
    // if not, then iterate over list
    // to find its place
    Node * iterator = last_;
    while(buffer->value < iterator->value)
    {
        if(iterator->previous == nullptr)
        {
            iterator->previous = buffer;
        }
    }

}

template<typename Type, typename Value> void sorted_list<Type, Value>::push_back(std::pair<Type, Value> object_value)
{

}

template<typename Type, typename Value> void sorted_list<Type, Value>::push_front(Type & object, Value & value)
{

}

template<typename Type, typename Value> void sorted_list<Type, Value>::push_front(std::pair<Type, Value> object_value)
{

}

template<typename Type, typename Value> Type sorted_list<Type, Value>::pop_back()
{

}

template<typename Type, typename Value> Type sorted_list<Type, Value>::pop_front()
{

}

template<typename Type, typename Value> Type sorted_list<Type, Value>::front()
{
    if(first_ != nullptr)
    {
        Node * buffer = first_;
        if(first_->next != nullptr)
        {
            first_->next->previous = nullptr;
            first_->next = first_;
        }
        else
        {
            first_ = nullptr;
            last_ = nullptr;
        }
        Type returned = buffer->object;
        delete buffer;
        return move(returned);
    }
}

template<typename Type, typename Value> Type sorted_list<Type, Value>::back()
{

}

template<typename Type, typename Value> int sorted_list<Type, Value>::size()
{
    return size_;
}
