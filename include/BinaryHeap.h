#ifndef BINARYHEAP_H
#define BINARYHEAP_H

#include <vector>
#include "TreeNode.h"

const int minHeap = 0;
const int maxHeap = 1;

template <typename T>
class BinaryHeap
{
    public:
        BinaryHeap(int type);
        virtual ~BinaryHeap();

        void InsertNode(T node, uint32_t sortByValue);
        void DeleteTop();
        void DeleteAt(uint32_t index);
        T GetTop();
        bool Empty();

    protected:

    private:
        std::vector<TreeNode<T> > Tree;
        int heapType;

        void BubbleDown(uint32_t index);
        void BubbleUp(uint32_t index);
        void Heapify();
};

template<typename T>
BinaryHeap<T>::BinaryHeap(int type) : Tree(std::vector<TreeNode<T> >()), heapType(type)
{
    //ctor
}

template<typename T>
BinaryHeap<T>::~BinaryHeap()
{
    delete[] &Tree;
}

template<typename T>
bool BinaryHeap<T>::Empty()
{
    if (Tree.size() == 0)
        return true;
    return false;
}

template<typename T>
void BinaryHeap<T>::Heapify()
{
    int length = Tree.size();
    for(int i=length/2-1; i>=0; --i)
        BubbleDown(i);
}

template<typename T>
T BinaryHeap<T>::GetTop()
{
    return Tree[0].data;
}

template<typename T>
void BinaryHeap<T>::DeleteTop()
{
    int length = Tree.size();

    if(length == 0)
    {
        return;
    }

    Tree[0] = Tree[length - 1];
    Tree.pop_back();

    BubbleDown(0);
}

template<typename T>
void BinaryHeap<T>::DeleteAt(uint32_t index)
{
    if (index == 0)
        DeleteTop();
    if (index >= Tree.size())
        return;

    int length = Tree.size();
    if (length == 0)
        return;

    Tree[index] = Tree[length - 1];
    Tree.pop_back();
    BubbleDown(index);
}

template<typename T>
void BinaryHeap<T>::InsertNode(T node, uint32_t sortByValue)
{
    TreeNode<T>* treeNode = new TreeNode<T>(node, sortByValue);
    Tree.push_back(*treeNode);
    uint32_t length = Tree.size();
    BubbleUp(length - 1);
}

template<typename T>
void BinaryHeap<T>::BubbleUp(uint32_t index)
{
    if (index == 0)
    {
        return;
    }

    uint32_t parentIndex = (index-1)/2;

    if (heapType)
    {//max heap
        if (Tree[parentIndex].sortByValue < Tree[index].sortByValue)
        {
            auto temp = Tree[parentIndex];
            Tree[parentIndex] = Tree[index];
            Tree[index] = temp;
            BubbleUp(parentIndex);
        }
    }
    else
    {//min heap
        if (Tree[parentIndex].sortByValue > Tree[index].sortByValue)
        {
            auto temp = Tree[parentIndex];
            Tree[parentIndex] = Tree[index];
            Tree[index] = temp;
            BubbleUp(parentIndex);
        }
    }
}

//TODO: need to implement heap type
template<typename T>
void BinaryHeap<T>::BubbleDown(uint32_t index)
{
    uint32_t length = Tree.size() - 1;
    uint32_t rightChildIndex = 2*index + 2;
    uint32_t leftChildIndex = 2*index + 1;

    if (leftChildIndex >= length)
        return;//index is a leaf. already at bottom

    uint32_t minIndex = index;

    if (Tree[index].sortByValue > Tree[leftChildIndex].sortByValue)
    {
        minIndex = leftChildIndex;
    }

    if ((rightChildIndex < length) && (Tree[index].sortByValue > Tree[minIndex].sortByValue))
    {
        minIndex = rightChildIndex;
    }

    if(minIndex != index)
    {
        //need to swap
        auto temp = Tree[index];
        Tree[index] = Tree[minIndex];
        Tree[minIndex] = temp;
        BubbleDown(minIndex);
    }
}

#endif // BINARYHEAP_H
