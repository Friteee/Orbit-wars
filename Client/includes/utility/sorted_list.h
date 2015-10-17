#ifndef SORTED_LIST_H_INCLUDED
#define SORTED_LIST_H_INCLUDED

#include <utility>

namespace utility
{

namespace impl
{
    template<typename Type> struct Node
    {
        Node<Type> * next_;
        Node<Type> * previous_;
        Type object_;
    };
}

template<typename Type> class sorted_list
{
public:

    sorted_list()
    {
        size_ = 0;
        first_ = nullptr;
        last_ = nullptr;
    }

    void push_back(Type & object)
    {
        size_++;
        impl::Node <Type> * buffer ;
        buffer = new impl::Node<Type>();
        buffer->object_ = object;
        // is the list empty?
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
        impl::Node<Type> * node_iterator = last_;
        while(buffer->object_ < node_iterator->object_)
        {
            if(node_iterator->previous_ == nullptr)
            {
                //if node_iterator is at the start of the list, append it
                node_iterator->previous = buffer;
                first_ = buffer;
                buffer->next_ = node_iterator;
                buffer->previous_ = nullptr;
            }
            node_iterator = node_iterator->previous_;
        }
        // node_iterator is less or equal to buffer value, append the list
        if(node_iterator->next_ == nullptr)
        {
            //node_iterator is last
            node_iterator->next_ = buffer;
            buffer->next_ = nullptr;
            buffer->previous_ = node_iterator;
            last_ = buffer;
        }
        else
        {
            //node iterator is in the middle
            buffer->next_ = node_iterator->next_;
            buffer->previous_ = node_iterator;
            node_iterator->next_ = buffer;
        }

    }

    void push_front(Type & object)
    {
        size_++;
        impl::Node <Type> * buffer ;
        buffer = new impl::Node<Type>();
        buffer->object_ = object;
        // is the list empty?
        if(first_ == nullptr)
        {
            first_ = buffer;
            first_->next_ = nullptr;
            first_->previous_ = nullptr;
            last_ = last_;
            return;
        }
        // if not, then iterate over list
        // to find its place
        impl::Node<Type> * node_iterator = first_;
        while(buffer->object_ < node_iterator->object_)
        {
            if(node_iterator->next_ == nullptr)
            {
                //if node iterator is at the end of the list, append it
                node_iterator->next_ = buffer;
                last_ = buffer;
                buffer->next = nullptr;
                buffer->previous_ = node_iterator;
            }
            node_iterator = node_iterator->next_;
        }
        // node_iterator is less or equal to buffer value, append the list
        if(node_iterator->next_ == nullptr)
        {
            //node_iterator is last
            node_iterator->next_ = buffer;
            buffer->next_ = nullptr;
            buffer->previous_ = node_iterator;
            last_ = buffer;
        }
        else
        {
            //node iterator is in the middle
            buffer->next_ = node_iterator->next_;
            buffer->previous_ = node_iterator;
            node_iterator->next_ = buffer;
        }
    }

    void pop_back()
    {
        if(size > 1)
        {
            last_ = last_->previous_;
            delete last_->next_;
            last_->next = nullptr;
        }
        else if(size == 1)
        {
            delete last_;
            last_ = nullptr;
            first_ = nullptr;
        }
        else
        {
            //nothing to pop
            return;
        }
        size--;
    }

    void pop_front()
    {
        if(size > 1)
        {
            first_ = first_->next_;
            delete first_->previous_;
            first_->previous_ = nullptr;
        }
        else if(size == 1)
        {
            delete first_;
            last_ = nullptr;
            first_ = nullptr;
        }
        else
        {
            //nothing to pop
            return;
        }
        size--;
    }
    Type & front()
    {
        if(size!= 0)
            return first_->object_;
        else
            throw std::out_of_range("No object to pull from front of sorted list");
    }

    Type back()
    {
        if(size != 0)
            return last_->object_;
        else
            throw std::out_of_range("No object to pull from back of sorted list");
    }

    unsigned int size()
    {
        return size_;
    }

private:
    unsigned int size_;
    impl::Node<Type> * first_;
    impl::Node<Type> * last_;
};

#endif // SORTED_LIST_H_INCLUDED
