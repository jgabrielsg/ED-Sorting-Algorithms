#include <iostream>
#include <cstdlib>
#include <chrono>
#include <vector>

using namespace std;
using namespace std::chrono;

typedef struct NodeTree
{
    int iPayload;
    NodeTree* ptrLeft;
    NodeTree* ptrRight;
} Node;

typedef struct QueueNode
{
    NodeTree* treeNode;
    QueueNode* next;
} QueueNode;

typedef struct Queue
{
    QueueNode* front;
    QueueNode* rear;
} Queue;

NodeTree* createNode(int);
NodeTree* insertNode(NodeTree*, int);
NodeTree* searchNode(NodeTree*, int);
NodeTree* lesserLeaf(NodeTree*);
NodeTree* deleteNode(NodeTree*, int);
void traversePreOrder(NodeTree*);
void traverseInOrder(NodeTree*);
void traversePostOrder(NodeTree*);
void bfsTraversal(NodeTree*);
int treeHeight(NodeTree*);
Queue* createQueue();
void enqueue(Queue*, NodeTree*);
NodeTree* dequeue(Queue*);

bool bfsSearch(NodeTree*, int);
bool dfsSearch(NodeTree*, int);
void monitorTreeAndListCreation();

int main()
{
    monitorTreeAndListCreation();
    return 0;
}

NodeTree* createNode(int iValue)
{
    NodeTree* tmp = (NodeTree*) malloc(sizeof(Node));
    if (tmp == nullptr)
    {
        cerr << "Error in createNode: malloc" << endl;
        exit(1);
    }
    tmp->iPayload = iValue;
    tmp->ptrLeft = nullptr;
    tmp->ptrRight = nullptr;
    return tmp;
}

NodeTree* insertNode(NodeTree* startingNode, int iData)
{
    if(startingNode == nullptr)
    {
        return createNode(iData);
    } 
    if(iData < startingNode->iPayload)
    {
        startingNode->ptrLeft = insertNode(startingNode->ptrLeft, iData);
    }
    else
    {
        startingNode->ptrRight = insertNode(startingNode->ptrRight, iData);
    }
    
    return startingNode;
}

NodeTree* searchNode(NodeTree* startingNode, int iData)
{
    if(startingNode == nullptr) return nullptr;
    else if(iData == startingNode->iPayload) return startingNode;
    else if(iData < startingNode->iPayload) return searchNode(startingNode->ptrLeft, iData);
    else return searchNode(startingNode->ptrRight, iData);
}

NodeTree* lesserLeaf(NodeTree* startingNode)
{
    NodeTree* ptrCurrent = startingNode;
    while (ptrCurrent && ptrCurrent->ptrLeft != nullptr) ptrCurrent = ptrCurrent->ptrLeft;
    return ptrCurrent;
}

Queue* createQueue()
{
    Queue* q = (Queue*)malloc(sizeof(Queue));
    if (q == nullptr)
    {
        cerr << "Error in createQueue: malloc" << endl;
        exit(1);
    }
    q->front = q->rear = nullptr;
    return q;
}

void enqueue(Queue* q, NodeTree* treeNode)
{
    QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
    if (temp == nullptr)
    {
        cerr << "Error in enqueue: malloc" << endl;
        exit(1);
    }
    temp->treeNode = treeNode;
    temp->next = nullptr;
    if (q->rear == nullptr)
    {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

NodeTree* dequeue(Queue* q)
{
    if (q->front == nullptr)
        return nullptr;
    QueueNode* temp = q->front;
    NodeTree* treeNode = temp->treeNode;
    q->front = q->front->next;
    if (q->front == nullptr)
        q->rear = nullptr;
    free(temp);
    return treeNode;
}

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
    return max(leftHeight, rightHeight) + 1;
}

void monitorTreeAndListCreation()
{
    vector<int> randomValues;
    vector<int> searchValues;

    // Generate 1,000,000 random values
    for (int i = 0; i < 1000000; i++)
    {
        randomValues.push_back(rand() % 1000000);
    }

    // Select 100 random values for searching
    for (int i = 0; i < 100; i++)
    {
        searchValues.push_back(rand() % 1000000);
    }

    // Monitor Tree Creation
    auto start = high_resolution_clock::now();

    NodeTree* root = nullptr;
    for (int value : randomValues)
    {
        root = insertNode(root, value);
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Tree Creation Time: " << duration.count() << "ms" << endl;

    // Monitor List Creation
    start = high_resolution_clock::now();

    Queue* q = createQueue();
    for (int value : randomValues)
    {
        NodeTree* treeNode = createNode(value);
        enqueue(q, treeNode);
    }

    stop = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(stop - start);
    cout << "List Creation Time: " << duration.count() << "ms" << endl;

    // Monitor Search Performance in Tree
    long long totalBfsTime = 0;
    long long totalDfsTime = 0;

    for (int target : searchValues)
    {
        start = high_resolution_clock::now();
        bfsSearch(root, target);
        stop = high_resolution_clock::now();
        totalBfsTime += duration_cast<nanoseconds>(stop - start).count();

        start = high_resolution_clock::now();
        dfsSearch(root, target);
        stop = high_resolution_clock::now();
        totalDfsTime += duration_cast<nanoseconds>(stop - start).count();
    }

    cout << "Average BFS Search Time in Tree: " << totalBfsTime / 100 << "ns" << endl;
    cout << "Average DFS Search Time in Tree: " << totalDfsTime / 100 << "ns" << endl;

    // Monitor Search Performance in List
    long long totalListSearchTime = 0;

    for (int target : searchValues)
    {
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

    cout << "Average Search Time in List: " << totalListSearchTime / 100 << "ns" << endl;

    // Cleanup
    free(q);
}
