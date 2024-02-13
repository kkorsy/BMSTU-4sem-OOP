#ifndef __BASE_TREE_HPP__
#define __BASE_TREE_HPP__

#include "base_tree.h"

bool Tree::is_empty() const noexcept {
    return size == 0;
}

size_t Tree::get_size() const  noexcept{
    return size;
}

#endif
