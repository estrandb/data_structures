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
    uint32_t procVert[numVertices] = {0};
    uint32_t nodeIndexInTree[numVertices] = {0};

    std::vector<uint32_t> computedShortestPaths(numVertices, 1000000);
    computedShortestPaths.at(source_vert) = 0;

    auto binheap = new BinaryHeap<AdjListNode>(0);

    std::unique_ptr<Utilities> util(new Utilities());
    util->AdjLengthListToVec(vertices, filePath);
    //util->PrintAdjList(vertices, numVertices);

    if (vertices.empty())
        return 0;

    auto node = new AdjListNode(0, numVertices);
    InitializeNode(vertices[0], node);
    binheap->InsertNode(*node, computedShortestPaths[0]);

    /*for (uint32_t i = 0; i < numVertices; i++)
    {
        auto node = new AdjListNode(i, numVertices);
        InitializeNode(vertices[i], node);
        binheap->InsertNode(*node, computedShortestPaths[i]);
    }*/

    while (!binheap->Empty())
    {
        auto currentNode = binheap->GetTop();
        binheap->DeleteTop();

        if (procVert[currentNode.index] == 1)
        {
            continue;
        }

        if (procVert[currentNode.index] == 0)
        {
            procVert[currentNode.index] = 1;
        }

        //calculate the greedy score for every adjacent vertex and insert into heap
        for (uint32_t i = 0; i < vertices[currentNode.index].size(); i++)
        {
            if ((i%2) == 0)
            {//need to delete a node somewhere.... pull proper node out of tree
                uint32_t adjNodeIndex = vertices[currentNode.index][i] - 1;

                if (procVert[adjNodeIndex] == 1)
                    continue;

                uint32_t adjNodeEdgeLength = vertices[currentNode.index][i+1];
                if (computedShortestPaths[adjNodeIndex] > (computedShortestPaths[currentNode.index] + adjNodeEdgeLength))
                {
                    computedShortestPaths[adjNodeIndex] = computedShortestPaths[currentNode.index] + adjNodeEdgeLength;
                }
                auto node = new AdjListNode(adjNodeIndex, numVertices);
                InitializeNode(vertices[adjNodeIndex], node);
                binheap->InsertNode(*node, computedShortestPaths[adjNodeIndex]);
            }
        }


    }
    //std::cout << computedShortestPaths[0] << ',' << computedShortestPaths[1] << ',' << computedShortestPaths[2] << ',' << computedShortestPaths[3] << std::endl;
    std::cout << computedShortestPaths[6] << ',' << computedShortestPaths[36] << ',' << computedShortestPaths[58] << ',' << computedShortestPaths[81] << ',' << computedShortestPaths[98] << ',' << computedShortestPaths[114] << ',' << computedShortestPaths[132] << ',' << computedShortestPaths[164] << ',' << computedShortestPaths[187] << ',' << computedShortestPaths[196] << ',' << std::endl;
    return 0;
}
