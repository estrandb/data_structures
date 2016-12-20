#ifndef TREENODE_H_INCLUDED
#define TREENODE_H_INCLUDED

template <typename T>
struct TreeNode
{
    uint32_t sortByValue;
    T data;
    TreeNode(T nodeData, uint32_t sortValue) : sortByValue(sortValue), data(nodeData){}
};

#endif // TREENODE_H_INCLUDED
