
// 2020/4/9 //

#pragma once

#include <iostream>
#include <cstdlib>
#include <vector>

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

typedef TreeNode* TreeRoot;

TreeRoot CreateTree_(TreeRoot root)
{
    if(root == nullptr)
    {
        return root;
    }
    else
    {
        TreeNode* node = new TreeNode()   
    }
}

TreeRoot CreateTree(const std::vector<int>& vec)
{
    TreeRoot root = nullptr;
    for(int i = 0; i < vec.size(); i++)
    {
        root = CreateTree_(root);
    }

    return root;
}



