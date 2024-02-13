#ifndef __BASE_TREE_H__
#define __BASE_TREE_H__

#include <iostream>

class Tree {
public:
    virtual ~Tree() = default;

    size_t get_size() const noexcept;
    bool is_empty() const noexcept;

private:
    size_t size;
};

#include "base_tree.hpp"

#endif