#ifndef __REVERSE_ITERATOR_H__
#define __REVERSE_ITERATOR_H__

#include <stack>

template <comparable_type Type>
class ReverseIterator {
public:
    ReverseIterator() = default;
    ReverseIterator(std::shared_ptr<typename BST<Type>::Node> &);
    ReverseIterator(const ReverseIterator<Type> &iter) = default;

    bool operator ==(const ReverseIterator<Type> &) const;
    bool operator !=(const ReverseIterator<Type> &) const;

    ReverseIterator<Type> & operator =(const ReverseIterator<Type> &);

    ReverseIterator<Type> & operator ++();
    ReverseIterator<Type>   operator ++(int);
    ReverseIterator<Type> & operator --();
    ReverseIterator<Type>   operator --(int);

    Type& operator *();
    Type* operator ->();
    const Type& operator *() const;
    const Type* operator ->() const;

protected:
    void check_obj_exist(int line) const;
    
private:
    std::weak_ptr<typename BST<Type>::Node> cur_elem;
    std::stack<std::shared_ptr<typename BST<Type>::Node>> stack;
};

#include "reverse_iterator.hpp"

#endif