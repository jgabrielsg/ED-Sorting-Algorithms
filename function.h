template <typename T>
struct Node {
    T iPayload;
    Node* ptrNext;
    Node* ptrPrev;
};
typedef struct NodeTree
{
    int iPayload;
    NodeTree* ptrLeft;
    NodeTree* ptrRight;
} NodeTree;
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

namespace node_operations {
    template <typename T>
    Node<T>* createNode(T iPayload);

    template <typename T>
    void insertEnd(Node<T>** head, T iPayload);

    template <typename T>
    void displayList(Node<T>* head);

    template <typename T>
    void deleteList(Node<T>** head);

    template <typename T>
    void swapPayload(Node<T>* node1, Node<T>* node2);

    template <typename T>
    void passValuesToList(Node<T>**, Node<T>*);
}

namespace sorting_algorithms {
    template <typename T>
    void bubbleSort(Node<T>* head);

    template <typename T>
    void optimizedBubbleSort(Node<T>* head);

    template <typename T>
    void insertionSort(Node<T>* head);

    template <typename T>
    void bucketSort(Node<T>* head);

    template <typename T>
    void selectionSort(Node<T>* head);

    template <typename T>
    void optimizedSelectionSort(Node<T>* head);
}

namespace nodetree_operations {
    NodeTree* searchNode(NodeTree* startingNode, int iData);

    NodeTree* lesserLeaf(NodeTree* startingNode);

    void enqueue(Queue* q, NodeTree* treeNode);

    NodeTree* dequeue(Queue* q);

    Queue* createQueue();

    NodeTree* createNode(int iValue);

    NodeTree* insertNode(NodeTree* startingNode, int iData);
}

namespace tree_search {
    void bfsTraversal(NodeTree* startingNode);

    bool bfsSearch(NodeTree* startingNode, int target);

    bool dfsSearch(NodeTree* startingNode, int target);

    int treeHeight(NodeTree* startingNode);

    void monitorTreeAndListCreation();
}