#include "function.h"
#include <iostream>
#include <cstdlib>
#include <chrono>
#include <ctime>
#include <fstream>
#include <algorithm>

using std::max;
using std::cout;
using std::endl;
using std::ofstream;
using namespace std::chrono;
using namespace nodetree_operations;

namespace tree_search {
    
    void bfsTraversal(NodeTree* startingNode)
    {
        if (startingNode == nullptr) return;
        
        Queue* q = createQueue();
        enqueue(q, startingNode);
        
        while (q->front != nullptr)
        {
            NodeTree* currentNode = dequeue(q);
            cout << currentNode->iPayload << " ";
            
            if (currentNode->ptrLeft != nullptr)
            {
                enqueue(q, currentNode->ptrLeft);
            }
            
            if (currentNode->ptrRight != nullptr)
            {
                enqueue(q, currentNode->ptrRight);
            }
        }
        free(q);
    }

    bool bfsSearch(NodeTree* startingNode, int target)
    {
        if (startingNode == nullptr) return false;

        Queue* q = createQueue();
        enqueue(q, startingNode);

        while (q->front != nullptr)
        {
            NodeTree* currentNode = dequeue(q);
            if (currentNode->iPayload == target)
            {
                free(q);
                return true;
            }

            if (target < currentNode->iPayload && currentNode->ptrLeft != nullptr)
            {
                enqueue(q, currentNode->ptrLeft);
            }
            else if (target > currentNode->iPayload && currentNode->ptrRight != nullptr)
            {
                enqueue(q, currentNode->ptrRight);
            }
        }

        free(q);
        return false;
    }

    bool dfsSearch(NodeTree* startingNode, int target)
    {
        if (startingNode == nullptr) return false;
        if (startingNode->iPayload == target) return true;
        if (target < startingNode->iPayload) return dfsSearch(startingNode->ptrLeft, target);
        return dfsSearch(startingNode->ptrRight, target);
    }

    int treeHeight(NodeTree* startingNode)
    {
        if (startingNode == nullptr) return 0;
        int leftHeight = treeHeight(startingNode->ptrLeft);
        int rightHeight = treeHeight(startingNode->ptrRight);
        return std::max(leftHeight, rightHeight) + 1;
    }

    void monitorTreeAndListCreation()
    {
        const int NUM_RANDOM_VALUES = 1000000;
        const int NUM_SEARCH_VALUES = 100;

        int randomValues[NUM_RANDOM_VALUES];
        int searchValues[NUM_SEARCH_VALUES];

        // Gera 1,000,000 números
        for (int i = 0; i < NUM_RANDOM_VALUES; i++)
        {
            randomValues[i] = rand() % 1000000;
        }

        // Seleciona 100 números para fazer a procura
        for (int i = 0; i < NUM_SEARCH_VALUES; i++)
        {
            searchValues[i] = rand() % 1000000;
        }

        // Monitora o tempo da árvore
        auto start = high_resolution_clock::now();

        NodeTree* root = nullptr;
        for (int i = 0; i < NUM_RANDOM_VALUES; i++)
        {
            root = insertNode(root, randomValues[i]);
        }

        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(stop - start);
        cout << "Tree Creation Time: " << duration.count() << "ms" << endl;

        // Monitora a da lista
        start = high_resolution_clock::now();

        Queue* q = createQueue();
        for (int i = 0; i < NUM_RANDOM_VALUES; i++)
        {
            NodeTree* treeNode = createNode(randomValues[i]);
            enqueue(q, treeNode);
        }

        stop = high_resolution_clock::now();
        duration = duration_cast<milliseconds>(stop - start);
        cout << "List Creation Time: " << duration.count() << "ms" << endl;

        // Agora veremos com o tempo de cada search
        // Monitoramos primeiro a árvore
        long long totalBfsTime = 0;
        long long totalDfsTime = 0;

        for (int i = 0; i < NUM_SEARCH_VALUES; i++)
        {
            int target = searchValues[i];

            start = high_resolution_clock::now();
            bfsSearch(root, target);
            stop = high_resolution_clock::now();
            totalBfsTime += duration_cast<nanoseconds>(stop - start).count();

            start = high_resolution_clock::now();
            dfsSearch(root, target);
            stop = high_resolution_clock::now();
            totalDfsTime += duration_cast<nanoseconds>(stop - start).count();
        }

        cout << "Average BFS Search Time in Tree: " << totalBfsTime / NUM_SEARCH_VALUES << "ns" << endl;
        cout << "Average DFS Search Time in Tree: " << totalDfsTime / NUM_SEARCH_VALUES << "ns" << endl;

        // Monitoramos a performance da lista agora
        long long totalListSearchTime = 0;

        for (int i = 0; i < NUM_SEARCH_VALUES; i++)
        {
            int target = searchValues[i];

            start = high_resolution_clock::now();
            QueueNode* current = q->front;
            while (current != nullptr)
            {
                if (current->treeNode->iPayload == target)
                {
                    break;
                }
                current = current->next;
            }
            stop = high_resolution_clock::now();
            totalListSearchTime += duration_cast<nanoseconds>(stop - start).count();
        }

        cout << "Average Search Time in List: " << totalListSearchTime / NUM_SEARCH_VALUES << "ns" << endl;

        // Free em tudo, não mais usaremos
        free(q);
    }
}