#include "function.h"
#include <iostream>
#include <cstdlib> // For malloc and free

using std::cout;
using std::endl;
using std::malloc;

namespace node_operations {

    template <typename T>
    Node<T>* createNode(T iPayload) {
        Node<T>* newNode = new Node<T>();
        newNode->iPayload = iPayload;
        newNode->ptrNext = nullptr;
        newNode->ptrPrev = nullptr;
        return newNode;
    }

    template <typename T>
    void insertEnd(Node<T>** head, T iPayload) {
        Node<T>* newNode = createNode(iPayload);
        if (*head == nullptr) {
            *head = newNode;
            return;
        }
        Node<T>* current = *head;
        while (current->ptrNext != nullptr) {
            current = current->ptrNext;
        }
        current->ptrNext = newNode;
        newNode->ptrPrev = current;
    }

    template <typename T>
    void displayList(Node<T>* head) {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        Node<T>* current = head;
        cout << "List: [";
        while (current != nullptr) {
            cout << " " << current->iPayload;
            current = current->ptrNext;
        }
        cout << " ]" << endl;
    }

    template <typename T>
    void deleteList(Node<T>** head) {
        Node<T>* current = *head;
        Node<T>* nextNode = nullptr;
        while (current != nullptr) {
            nextNode = current->ptrNext;
            delete current;
            current = nextNode;
        }
        *head = nullptr;
    }

    template <typename T>
    void swapPayload(Node<T>* node1, Node<T>* node2) {
        T temp = node1->iPayload;
        node1->iPayload = node2->iPayload;
        node2->iPayload = temp;
    }

    template <typename T>
    void passValuesToList(Node<T>** head, Node<T>* source) 
    {
        while (source != nullptr) 
        {
            insertEnd(head, source->iPayload);
            source = source->ptrNext;
        }
    }

    // Explicit instantiation of template functions for int type
    template Node<int>* createNode<int>(int iPayload);
    template void insertEnd<int>(Node<int>** head, int iPayload);
    template void displayList<int>(Node<int>* head);
    template void deleteList<int>(Node<int>** head);
    template void swapPayload<int>(Node<int>* node1, Node<int>* node2);
    template void passValuesToList(Node<int>** head, Node<int>* source);

} // namespace node_operations

namespace nodetree_operations {
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

    void enqueue(Queue* q, NodeTree* treeNode)
    {
        QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
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

    Queue* createQueue()
    {
        Queue* q = (Queue*)malloc(sizeof(Queue));
        q->front = q->rear = nullptr;
        return q;
    }

    NodeTree* createNode(int iValue)
    {
        NodeTree* tmp = (NodeTree*) malloc(sizeof(NodeTree));
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
}