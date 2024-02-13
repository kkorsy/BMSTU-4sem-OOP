#ifndef __CONST_REVERSE_ITERATOR_H__
#define __CONST_REVERSE_ITERATOR_H__

#include <stack>

template <comparable_type Type>
class ConstReverseIterator {
public:
    ConstReverseIterator() = default;
    ConstReverseIterator(std::shared_ptr<typename BST<Type>::Node> &);
    ConstReverseIterator(const ConstReverseIterator<Type> &iter) = default;

    bool operator ==(const ConstReverseIterator<Type> &) const;
    bool operator !=(const ConstReverseIterator<Type> &) const;

    ConstReverseIterator<Type> & operator =(const ConstReverseIterator<Type> &);

    ConstReverseIterator<Type> & operator ++();
    ConstReverseIterator<Type>   operator ++(int);
    ConstReverseIterator<Type> & operator --();
    ConstReverseIterator<Type>   operator --(int);

    const Type& operator *() const;
    const Type* operator ->() const;
    
protected:
    void check_obj_exist(int line) const;

private:
    std::weak_ptr<typename BST<Type>::Node> cur_elem;
    std::stack<std::shared_ptr<typename BST<Type>::Node>> stack;
};

#include "const_reverse_iterator.hpp"

#endif