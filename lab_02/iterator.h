#ifndef __ITERATOR_H__
#define __ITERATOR_H__

#include <stack>
#include <iostream>

template <comparable_type Type>
class Iterator {
public:
    Iterator() = default;
    Iterator(std::shared_ptr<typename BST<Type>::Node> &);
    Iterator(const Iterator<Type> &) = default;

    bool operator ==(const Iterator<Type> &) const;
    bool operator !=(const Iterator<Type> &) const;

    Iterator<Type> & operator =(const Iterator<Type> &);

    Iterator<Type> & operator ++();
    Iterator<Type>   operator ++(int);
    Iterator<Type> & operator --();
    Iterator<Type>   operator --(int);

    Type& operator *();
    Type* operator ->();
    const Type& operator *() const;
    const Type* operator ->() const;

protected:
    void check_obj_exist(int line) const;

private:
    std::weak_ptr<typename BST<Type>::Node> cur_elem;
    std::stack<std::shared_ptr<typename BST<Type>::Node>> stack;

    friend class BST<Type>;
};

#include "iterator.hpp"

#endif