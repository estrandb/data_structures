#ifndef BINARYHEAP_H
#define BINARYHEAP_H

#include <vector>
#include "TreeNode.h"

template <typename T>
class BinaryHeap
{
    public:
        //0 == min, 1 == max
        BinaryHeap(int type);
        virtual ~BinaryHeap();

        void InsertNode(TreeNode<T> node);
        void DeleteTop();
        TreeNode<T> GetTop();

    protected:

    private:
        std::vector<TreeNode<T> > Tree;
        const int treeType;

        void BubbleDown(TreeNode<T> node);
        void BubbleUp(TreeNode<T> node);
        void Heapify();
};

template<typename T>
BinaryHeap<T>::BinaryHeap(int type) : treeType(type)
{
    //ctor
}

template<typename T>
BinaryHeap<T>::~BinaryHeap()
{
    //dtor
}

template<typename T>
BinaryHeap<T>::InsertNode(TreeNode<T> node)
{

}


#endif // BINARYHEAP_H
