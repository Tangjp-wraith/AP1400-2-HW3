#include <iostream>
#include <gtest/gtest.h>
#include "bst.h"


int main(int argc, char **argv)
{
    if (false) // make false to run unit-tests
    {
        BST bst{};
        bst.add_node(25);
        bst.add_node(10);
        bst.add_node(50);
        bst.add_node(53);
        bst.add_node(15);
        bst.add_node(7);
        bst.add_node(8);
        bst.add_node(9);
        std::cout<<bst<<std::endl;
        BST::Node** node{bst.find_successor(10)};
        EXPECT_EQ((*node)->value, 9);
        EXPECT_EQ((*node)->left, nullptr);
        EXPECT_EQ((*node)->right, nullptr);
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