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
        const int heapType;
        typedef sortType;

        void BubbleDown(uint32_t index);
        void BubbleUp(uint32_t index);
        void Heapify();
};

template<typename T>
BinaryHeap<T>::BinaryHeap(int type) : Tree(std::vector<TreeNode<T>()), heapType(type)
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
    uint32_t length = Tree.size();
    Tree[length] = node;

    BubbleUp(length);
}

template<typename T>
BinaryHeap<T>::BubbleUp(uint32_t index)
{
    if (index == 0)
    {
        return;
    }

    uint32_t parentIndex = (index-1)/2;

    if (heapType)
    {//max heap

    }
    else
    {//min heap

    }
}

#endif // BINARYHEAP_H
