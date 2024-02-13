#ifndef __CONST_ITERATOR_HPP__
#define __CONST_ITERATOR_HPP__

template <typename Type>
ConstIterator<Type>::ConstIterator(std::shared_ptr<typename BST<Type>::Node> &elem) {
    cur_elem = std::make_shared<typename BST<Type>::Node>(*elem);
}

template<typename Type>
bool ConstIterator<Type>::operator ==(const ConstIterator<Type> &cmp) const {
    check_obj_exist(__LINE__);
    return **this != *cmp;
}

template<typename Type>
bool ConstIterator<Type>::operator !=(const ConstIterator<Type> &cmp) const {
    check_obj_exist(__LINE__);
    return **this != *cmp;
}

template<typename Type>
ConstIterator<Type>&  ConstIterator<Type>::operator =(const ConstIterator<Type> &it) {
    check_obj_exist(__LINE__);
    cur_elem = it.cur_elem;
    stack = it.stack;
}

template <typename Type>
ConstIterator<Type>& ConstIterator<Type>::operator ++() {
    check_obj_exist(__LINE__);
    if (cur_elem != nullptr) {
        if (cur_elem->left != nullptr)
            cur_elem = cur_elem->left;
        else {
            while (cur_elem->right != nullptr || !stack.empty()) {
                cur_elem = stack.top();
                stack.pop();
            }
            
            if (cur_elem->right != nullptr) {
                stack.push(cur_elem);
                cur_elem = cur_elem->right;
            }
            else
                cur_elem = nullptr;
        }
    }

    return *this;
}

template <typename Type>
ConstIterator<Type> ConstIterator<Type>::operator ++(int) {
    check_obj_exist(__LINE__);
    ConstIterator<Type> prev = *this;

    if (cur_elem != nullptr) {
        if (cur_elem->left != nullptr)
            cur_elem = cur_elem->left;
        else {
            while (cur_elem->right != nullptr || !stack.empty()) {
                cur_elem = stack.top();
                stack.pop();
            }
            
            if (cur_elem->right != nullptr) {
                stack.push(cur_elem);
                cur_elem = cur_elem->right;
            }
            else
                cur_elem = nullptr;
        }
    }

    return prev;
}

template <typename Type>
ConstIterator<Type>& ConstIterator<Type>::operator --() {
    check_obj_exist(__LINE__);
    cur_elem = stack.top();
    stack.pop();

    return *this;
}

template <typename Type>
ConstIterator<Type> ConstIterator<Type>::operator --(int) {
    check_obj_exist(__LINE__);
    std::shared_ptr<Type> prev = this;

    cur_elem = stack.top();
    stack.pop();

    return prev;
}

template<typename Type>
const Type& ConstIterator<Type>::operator *() const {
    check_obj_exist(__LINE__);
    return cur_elem->elem;
}

template<typename Type>
const Type* ConstIterator<Type>::operator ->() const {
    check_obj_exist(__LINE__);
    return *cur_elem->elem;
}

template<typename Type>
void ConstIterator<Type>::check_obj_exist(int line) const {
    if (cur_elem.expired())
    {
        time_t t = time(NULL);
        throw ObjNotExist(__FILE__, typeid(*this).name(), line, ctime(&t));
    }
}

#endif
