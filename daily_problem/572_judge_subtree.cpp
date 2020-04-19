
// 2020/4/9 //

#include <iostream>
#include <cstdlib>

#include "0_binary_tree.h"

template <typename T = int>
bool IsSameTree(BNode<T>* s, BNode<T>* t)
{
    if(s == nullptr && t == nullptr)
    {
        return true;
    }
    else
    {
        std::cout << "S: " << s->data_ << " T: " << t->data_ << std::endl;
        // this equation will be judge one by one, so it will not certainly enter recursion
        return s && t && s->data_ == t->data_ && IsSameTree(s->left_, t->left_) && IsSameTree(s->right_, t->right_);
    }
}

template <typename T = int>
bool IsSubTree(BNode<T>* s, BNode<T>* t)
{
    if(s == nullptr && t == nullptr)
    {
        return true;
    }
    else if(s == nullptr && t != nullptr)
    {
        return false;
    }
    else
    {
        std::cout << "Judge: S: " << s->data_ << " T: " << t->data_ << std::endl; 
        return IsSameTree(s, t) || IsSubTree(s->left_, t) || IsSubTree(s->right_, t);   
    }
}

int main()
{
    std::vector<int> vec1 = {3, 5, -1, -1, 4, 1, -1, -1, 2};
    std::vector<int> vec2 = {4, 1, -1, -1, 2};
    BTree<int> mainTree(vec1, -1);
    BTree<int> subTree(vec2, -1);

    if(IsSubTree(mainTree.GetRoot(), subTree.GetRoot()) == true)
    {
        std::cout << "True" << std::endl;
    }
    else
    {
        std::cout << "False" << std::endl;
    }

    system("pause");
    return 0;
}