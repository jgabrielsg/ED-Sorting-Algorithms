#ifndef FUNCTION_H
#define FUNCTION_H

struct Node {
    int iPayload;
    Node* ptrNext;
    Node* ptrPrev;
};

Node* createNode(int iPayload);
void insertEnd(Node** head, int iPayload);
void displayList(Node* head);
void deleteLastNode(Node** head);
void swapPayload(Node* node1, Node* node2);

// Sorting functions
void bubbleSort(Node* head);
void optimizedBubbleSort(Node* head);
void selectionSort(Node* head);
void optimizedSelectionSort(Node* head);
void insertionSort(Node* head);
void optimizedInsertionSort(Node*& head);

#endif // FUNCTION_H
