#ifndef BINARYHEAP_H
#define BINARYHEAP_H

#include <vector>
#include "TreeNode.h"

template <typename T>
class BinaryHeap
{
    public:
        BinaryHeap(int type);
        virtual ~BinaryHeap();

        void insertNode(TreeNode<T> node);
        void deleteTop();
        TreeNode<T> peekTop();



    protected:

    private:
        std::vector<TreeNode<T> > Tree;

        const int treeType;
};

#endif // BINARYHEAP_H
