#include <iostream>
#include <vector>

#include "bst.h"

int main(void) {
    std::vector<int> a = {1, 2, 3, 4, 5};
    BST<int> t1(a);

    BST<int> t2(2);
    BST<float> t3(4);

    BST<int> t4(a.begin(), a.end());
    BST<int> t5({7, 8, 9, 4, 5});

    Iterator<int> i1_b = t1.begin();
    i1_b++;
    Iterator<int> i1_e = t1.end();

    // Iterator<int> i2 = t5.find(9);


    return 0;
}