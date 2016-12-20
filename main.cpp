#include <iostream>
#include "BinaryHeap.h"
#include "AdjListNode.h"
#include "Utilities.h"

void InitializeNode(const std::vector<uint32_t>& sourceNode, AdjListNode* destNode)
{
    for (uint32_t i = 0; i < sourceNode.size(); i++)
    {
        if (i%2 == 0)
        {
            destNode->weightVector.at(sourceNode[i] - 1) = sourceNode[i+1];
        }
    }
}

int main()
{
    std::string const filePath = "/home/sig/projects/algorithms/graph.txt";
    int const numVertices = 200;
    int const source_vert = 0;

    std::vector<std::vector<uint32_t> > vertices;
    std::vector<std::vector<uint32_t> > processedVertices;

    std::vector<uint32_t> computedShortestPaths(numVertices, 1000000);
    computedShortestPaths.at(source_vert) = 0;

    auto binheap = new BinaryHeap<AdjListNode>(0);

    std::unique_ptr<Utilities> util(new Utilities());
    util->AdjLengthListToVec(vertices, filePath);
    //util->PrintAdjList(vertices, numVertices);

    if (vertices.empty())
        return 0;

    for (uint32_t i = 0; i < numVertices; i++)
    {
        auto node = new AdjListNode(i, numVertices);
        InitializeNode(vertices[i], node);
        binheap->InsertNode(*node, computedShortestPaths[i]);
    }

    while (!binheap->Empty())
    {
        //auto currentNode = binheap->GetTop();
        //processedVertices[currentNode]


    }

    return 0;
}
