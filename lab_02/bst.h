#ifndef __BST_H__
#define __BST_H__

#include <iostream>
#include <concepts>
#include <memory>

#include "base_tree.h"
#include "iterator.h"
#include "reverse_iterator.h"
#include "const_iterator.h"
#include "const_reverse_iterator.h"

template <typename Type1, typename Type2>
concept convertable_type = requires(Type1 a, Type2 b) {
    a = b;
    std::convertible_to<Type1, Type2>;
};

template <typename Type1>
concept container_type = requires (Type1 a) {
    typename Type1::value_type;
    typename Type1::size_type;
    typename Type1::const_iterator;

    { a.begin() } -> std::same_as<typename Type1::const_iterator>;
    { a.end() } -> std::same_as<typename Type1::const_iterator>;
    { a.empty() } -> std::same_as<bool>;
};

template <typename Type>
concept iterator_type = requires(Type a)
{
    typename Type::const_iterator_category;
    typename Type::value_type;
    typename Type::difference_type;
    typename Type::pointer;
    typename Type::reference;

    *a;
    a = a;
    a++;
    ++a;
    a == a;
    a != a;
};

template <typename Type>
concept comparable_type = requires(Type a, Type b)
{
    std::is_constructible<Type, typename std::add_lvalue_reference<typename std::add_const<Type>::type>::type> {};

    {a <=> b} -> std::same_as<std::weak_ordering>;
};

template <comparable_type Type>
class BST: public Tree {
private:
    class Node;
public:
    friend class Iterator<Type>;

    // Конструкторы
    BST();                                                      // пустой
    explicit BST(Type &);                                       // один элемент

    template <convertable_type <Type> Type1>                      // копирования
    explicit BST(const BST<Type1> &);

    template <iterator_type Type1>
    BST(const Type1 &i1, const Type1 &i2);                      // по 2м итераторам

    template <container_type Type1>
    explicit BST(const Type1 &t);                               // контейнер

    explicit BST(std::initializer_list<Type>);
    explicit BST(BST<Type> &&);
    BST(Type *, int n);


    // Деструктор
    virtual ~BST() = default;

    // Присваивание
    BST<Type> &operator =(const BST<Type> &);
    BST<Type> &operator =(const BST<Type> &&);

    template <convertable_type<Type> Type1>
    BST<Type> &operator =(const BST<Type1> &);
    
    template <container_type Type1>
    BST<Type> &operator =(const Type1 &);

    // Итераторы
    ConstIterator<Type> begin() const noexcept;
    ConstIterator<Type> end() const noexcept;
    ConstReverseIterator<Type> rbegin() const noexcept;
    ConstReverseIterator<Type> rend() const noexcept;

    ConstIterator<Type> cbegin() const noexcept;
    ConstIterator<Type> cend() const noexcept;
    ConstReverseIterator<Type> crbegin() const noexcept;
    ConstReverseIterator<Type> crend() const noexcept;

    // Операции

    // добавить элемент
    BST<Type> operator +(Type &);
    BST<Type> &operator +=(Type &);
    bool add(const Type &);

    // удалить элемент
    BST<Type> operator -(Type &);      
    BST<Type> &operator -=(Type &);
    bool del(const Type &);

    // конъюнкция
    BST<Type> operator *(BST<Type> &);     
    BST<Type> &operator *=(BST<Type> &);
    void cross(const BST<Type> &);

    // дизъюнкция
    BST<Type> operator +(BST<Type> &);     
    BST<Type> &operator +=(BST<Type> &);
    void merge(const BST<Type> &);

    // логическая разность
    BST<Type> operator -(BST<Type> &);     
    BST<Type> &operator -=(BST<Type> &);
    void difference(const BST<Type> &);

    // симметрическая разность
    BST<Type> operator ^(BST<Type> &);     
    BST<Type> &operator ^=(BST<Type> &); 
    void symmetric_difference(const BST<Type> &);

    // сравнение
    bool operator ==(BST<Type> &);
    bool operator !=(BST<Type> &);
    bool operator >(BST<Type> &);
    bool operator >=(BST<Type> &);
    bool operator <(BST<Type> &);
    bool operator <=(BST<Type> &);

    BST<Type> &copy();     // копирование
    void fill(Type &);      //заполнить одинаковыми значениями
    Iterator<Type> find(const Type &);

private:
    class Node {
    public:
        Node(Type t): elem(t), right(nullptr), left(nullptr) {}
        Node(const Node &n): elem(n.elem), right(n.right), left(n.left){}

        Type elem;
        std::shared_ptr<Node> right;
        std::shared_ptr<Node> left;
    };

    std::shared_ptr<Node> head = nullptr;
};

#include "bst.hpp"

#endif