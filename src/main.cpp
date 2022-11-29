#include <iostream>
#include <gtest/gtest.h>
#include "bst.h"


int main(int argc, char **argv)
{
    if (false) // make false to run unit-tests
    {
        BST bst{};
        bst.add_node(5);
        bst.add_node(10);
        bst.add_node(50);
        
        BST equal{};
        bst.add_node(51);
        bst.add_node(66);
        bst.add_node(10);
        equal = bst;
        EXPECT_EQ(bst.length(), equal.length());
        EXPECT_EQ(bst.get_root()->right->right->value, equal.get_root()->right->right->value);
    }
    else
    {
        ::testing::InitGoogleTest(&argc, argv);
        std::cout << "RUNNING TESTS ..." << std::endl;
        int ret{RUN_ALL_TESTS()};
        if (!ret)
            std::cout << "<<<SUCCESS>>>" << std::endl;
        else
            std::cout << "FAILED" << std::endl;
    }
    return 0;   
}