#ifndef TREENODE_H_INCLUDED
#define TREENODE_H_INCLUDED

template <typename T>
struct TreeNode
{
    TreeNode* parent;
    TreeNode* leftchild;
    TreeNode* rightchild;
    T data;
}

#endif // TREENODE_H_INCLUDED
