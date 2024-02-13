#ifndef __BST_HPP__
#define __BST_HPP__

#include "bst.h"
#include "errors.h"

template <typename Type>
BST<Type>::BST() {
    head = nullptr;
}

template <typename Type>
BST<Type>::BST(Type &t) {
    head = std::make_shared<Node>(t);
}

template <typename Type>
template <convertable_type<Type> Type1>
BST<Type>::BST(const BST<Type1> &t) {
    head = t.head;
    auto cur = t.begin();
    while (cur != t.end())
        this->add(static_cast<Type>(*cur));
}

template <typename Type>
template <iterator_type Type1>
BST<Type>::BST(const Type1 &i1, const Type1 &i2) {
    head = nullptr;
    auto i = i1;
    while (i != i2) {
        this->add(static_cast<Type>(*i));
        ++i;
    }
}

template <typename Type>
BST<Type>::BST(Type *, int n) {
    head = nullptr;
    for (int i = 0; i < n; i++)
        this->add(static_cast<Type>(i));
}

template <typename Type>
template <container_type Type1>
BST<Type>::BST(const Type1 &t) {
    head = nullptr;
    auto cur = t.begin();
    while (cur != t.end()) {
        this->add(static_cast<Type>(*cur));
        ++cur;
    }
}

template <typename Type>
BST<Type>::BST(std::initializer_list<Type> list) {
    head = nullptr;
    auto i = list.begin();
    while (i != list.end()) {
        this->add(static_cast<Type>(*i));
        ++i;
    }
}

template <typename Type>
BST<Type>::BST(BST<Type> &&t) {
    head = t.head;
    auto cur = t.begin();
    while (cur != t.end())
        this->add(static_cast<Type>(*cur));
}

template <typename Type>
BST<Type> &BST<Type>::operator =(const BST<Type> &t) {
    head = t.head;
    auto cur = t.begin();
    while (++cur)
        this->add(*cur);

    return *this;
}

template <typename Type>
template <convertable_type<Type> Type1>
BST<Type> &BST<Type>::operator =(const BST<Type1> &t) {
    head = t.head;
    auto cur = t.begin();
    while (++cur)
        this->add(static_cast<Type>(*cur));

    return *this;
}

template <typename Type>
template <container_type Type1>
BST<Type> &BST<Type>::operator =(const Type1 &t) {
    head = std::make_shared<Node>(*t.begin());
    auto cur = t.begin();
    while (cur != t.end()) {
        this->add(static_cast<Type>(*cur));
        ++cur;
    }
    
    return *this;
}

template <typename Type>
BST<Type> &BST<Type>::operator =(const BST<Type> &&t) {
    head = std::make_shared<Node>(*t.begin());
    auto cur = t.begin();
    while (cur != t.end()) {
        this->add(static_cast<Type>(*cur));
        ++cur;
    }
    
    return *this;
}

template <typename Type>
Iterator<Type> BST<Type>::begin() const noexcept {
    return Iterator<Type>(this->head);
}

template <typename Type>
Iterator<Type> BST<Type>::end() const noexcept {
    Iterator<Type> cur = this->begin();
    while (cur.cur_elem != nullptr)
        cur++;

    return cur;
}

template <typename Type>
ReverseIterator<Type> BST<Type>::rbegin() const noexcept {
    ReverseIterator<Type> cur = this->rend();
    while (cur.cur_elem != nullptr)
        cur++;

    return cur;
}

template <typename Type>
ReverseIterator<Type> BST<Type>::rend() const noexcept {
    return ReverseIterator<Type>(*this->head);
}

template <typename Type>
ConstIterator<Type> BST<Type>::cbegin() const noexcept {
    return ConstIterator<Type>(*this->head);
}

template <typename Type>
ConstIterator<Type> BST<Type>::cend() const noexcept {
    ConstIterator<Type> cur = this->cbegin();
    while (cur.cur_elem != nullptr)
        cur++;

    return cur;
}

template <typename Type>
ConstReverseIterator<Type> BST<Type>::crbegin() const noexcept {
    ConstReverseIterator<Type> cur = this->crend();
    while (cur.cur_elem != nullptr)
        cur++;

    return cur;
}

template <typename Type>
ConstReverseIterator<Type> BST<Type>::crend() const noexcept {
    return ConstReverseIterator<Type>(*this->head);
}

template <typename Type>
bool BST<Type>::add(const Type &t) {
    bool success = true;

    std::shared_ptr<Node> new_node = std::make_shared<Node>(t);
    if (!head)
        head = new_node;
    else {
        std::shared_ptr<Node> cur = head, prev = nullptr;

        while (cur) {
            prev = cur;
            if (new_node->elem > cur->elem)
                cur = cur->left;
            else if (new_node->elem < cur->elem)
                cur = cur->right;
            else
                success = false;
        }

        if (new_node->elem > prev->elem)
            prev->left = new_node;
        else if (new_node->elem < prev->elem)
            prev->right = new_node;
        else
            success = false;
    }

    return success;
}

template <typename Type>
Iterator<Type> BST<Type>::find(const Type &value) {
    Iterator<Type> cur = this->begin();
    while (cur != this->end() && *cur != value)
        ++cur;

    return cur;
}

template <typename Type>
void BST<Type>::merge(const BST<Type> &add_tree) {
    Iterator<Type> cur = add_tree.begin();
    while (cur != add_tree.end()) {
        this->add(*cur);
        cur++;
    }
}

template <typename Type>
bool BST<Type>::del(const Type &value) {
    bool success = true;

    Iterator<Type> cur = this->begin();
    Iterator<Type> prev;
    while (cur != this->end() && *cur != value) {
        prev = cur;
        ++cur;
    }

    if (cur != this->end()) {
        // у удаляемого элемента 2 потомка
        if (cur.cur_elem->left != nullptr && cur.cur_elem->right != nullptr) {
            Node min_node = cur.cur_elem->right;
            Iterator<Type> cur_iter = cur.cur_elem->right;
            while (cur_iter != this->end()) {
                if (cur_node.elem < min_node.elem)
                    min_node = *cur_iter.cur_elem;
                ++cur_iter;
            }
            if (*prev > value)
                prev.cur_elem->left = min_node;
            else
                prev.cur_elem->right = min_node;
        }
        // у удаляемого элемента 1 потомок
        else if (cur.cur_elem->left != nullptr) {
            if (*prev > value)
                prev.cur_elem->left = cur.cur_elem->left;
            else
                prev.cur_elem->right = cur.cur_elem->left;
        }
        else if (cur.cur_elem->right != nullptr) {
            if (*prev > value)
                prev.cur_elem->left = cur.cur_elem->right;
            else
                prev.cur_elem->right = cur.cur_elem->right;
        }
        // у удаляемого элемента нет потомков
        else {
            if (*prev > value)
                prev.cur_elem->left = nullptr;
            else
                prev.cur_elem->right = nullptr;
        }
    }
    else
        success = false;

    return success;
}

template <typename Type>
void BST<Type>::cross(const BST<Type> &cross_tree) {
    Iterator<Type> cur = this->begin();
    Type value_to_del; 

    while (cur != this->end()) {
        if (cross_tree.find(*cur) == cross_tree.end()) {
            value_to_del = *cur;
            ++cur;
            this->del(value_to_del);
        }
        else
            ++cur;
    }
}

template <typename Type>
BST<Type> &BST<Type>::operator +=(Type &t) {
    this->add(t);

    return *this;
}

template <typename Type>
BST<Type> BST<Type>::operator +(Type &t) {
    BST<Type> copy_tree(*this);

    return copy_tree += t;
}

template <typename Type>
BST<Type> &BST<Type>::operator -=(Type &t) {
    this->del(t);

    return *this;
}

template <typename Type>
BST<Type> BST<Type>::operator -(Type &t) {
    BST<Type> copy_tree(*this);

    return copy_tree -= t;
}

template <typename Type>
BST<Type> &BST<Type>::operator *=(BST<Type> &t) {
    this->cross(t);

    return *this;
}

template <typename Type>
BST<Type> BST<Type>::operator *(BST<Type> &t) {
    BST<Type> copy_tree(*this);

    return copy_tree *= t;
}

template <typename Type>
BST<Type> &BST<Type>::operator +=(BST<Type> &t) {
    this->merge(t);

    return *this;
}

template <typename Type>
BST<Type> BST<Type>::operator +(BST<Type> &t) {
    BST<Type> copy_tree(*this);

    return copy_tree += t;
}

template <typename Type>
BST<Type> &BST<Type>::copy() {
    BST<Type> copy_tree(*this);

    return copy_tree;
}

template <typename Type>
bool BST<Type>::operator ==(BST<Type> &t) {
    bool success = true;

    Iterator<Type> cur1 = this->begin();
    Iterator<Type> cur2 = t.begin();
    while (cur1 != this->end() || cur2 != t.end() || !success) {
        if (cur1 != cur2)
            success = false;
    }
        
    return success;
}

template <typename Type>
bool BST<Type>::operator !=(BST<Type> &t) {
    return !(*this == t);
}

template <typename Type>
bool BST<Type>::operator >(BST<Type> &t) {
    bool success = true;

    if (this->size < t.size)
        success = false;
    else if (this->size == t.size) {
        Iterator<Type> cur1 = this->begin();
        Iterator<Type> cur2 = t.begin();
        while (cur1 != this->end() || cur2 != t.end() || !success) {
            if (cur1 < cur2)
                success = false;
        }
    }
        
    return success;
}

template <typename Type>
bool BST<Type>::operator <(BST<Type> &t) {
    return !(*this > t);
}

template <typename Type>
bool BST<Type>::operator >=(BST<Type> &t) {
    return *this > t || *this == t;
}

template <typename Type>
bool BST<Type>::operator <=(BST<Type> &t) {
    return *this < t || *this == t;
}

template <typename Type>
void BST<Type>::difference(const BST<Type> &t) {
    Iterator<Type> cur = this->begin();
    Iterator<Type> found;
    Type to_del;

    while (cur != this.end()) {
        found = t.find(*cur);
        if (found != t.end()) {
            to_del = *cur;
            cur++;
            this->del(to_del);
        }
        else
            cur++;
    }

}

template <typename Type>
void BST<Type>::symmetric_difference(const BST<Type> &t) {
    BST<Type> copy_tree(t);

    this->difference(t);
    copy_tree.difference(this);

    this->merge(copy_tree);
}

template <typename Type>
void BST<Type>::fill(Type &value) {
    BST<Type> copy_tree(*this);

    Iterator<Type> cur = copy_tree->begin();
    while (cur != copy_tree->end) {
        cur.cur_elem->elem = value;
        cur++;
    }
}

template <typename Type>
void BST<Type>::fill(Type &&value) {
    BST<Type> copy_tree(*this);

    Iterator<Type> cur = copy_tree->begin();
    while (cur != copy_tree->end) {
        cur.cur_elem->elem = value;
        cur++;
    }
}

template <typename Type>
BST<Type> &BST<Type>::operator -=(BST<Type> &t) {
    this->difference(t);

    return *this;
}

template <typename Type>
BST<Type> BST<Type>::operator -(BST<Type> &t) {
    BST<Type> copy_tree(*this);

    return copy_tree -= t;
}

template <typename Type>
BST<Type> &BST<Type>::operator ^=(BST<Type> &t) {
    this->symmetric_difference(t);

    return *this;
}

template <typename Type>
BST<Type> &BST<Type>::operator ^(BST<Type> &t) {
    BST<Type> copy_tree(*this);

    return copy_tree ^= t;
}


#endif