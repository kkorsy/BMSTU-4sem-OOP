#ifndef __CONST_ITERATOR_H__
#define __CONST_ITERATOR_H__

#include <stack>
#include <iostream>

template <comparable_type Type>
class ConstIterator {
public:
    ConstIterator() = default;
    ConstIterator(std::shared_ptr<typename BST<Type>::Node> &);
    ConstIterator(const ConstIterator<Type> &iter) = default;

    bool operator ==(const ConstIterator<Type> &) const;
    bool operator !=(const ConstIterator<Type> &) const;

    ConstIterator<Type> & operator =(const ConstIterator<Type> &);

    ConstIterator<Type> & operator ++();
    ConstIterator<Type>   operator ++(int);
    ConstIterator<Type> & operator --();
    ConstIterator<Type>   operator --(int);

    const Type& operator *() const;
    const Type* operator ->() const;

protected:
    void check_obj_exist(int line) const;

private:
    std::weak_ptr<typename BST<Type>::Node> cur_elem;
    std::stack<std::shared_ptr<typename BST<Type>::Node>> stack;

    friend class BST<Type>;
};

#include "const_iterator.hpp"

#endif