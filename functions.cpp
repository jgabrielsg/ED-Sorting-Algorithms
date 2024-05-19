#include "function.h"
#include <iostream>
#include <cstdlib> // For malloc and free

using std::cout;
using std::endl;
using std::malloc;

Node* createNode(int iPayload) {
    Node* newNode = (Node*) malloc(sizeof(Node));

    newNode->iPayload = iPayload;
    newNode->ptrNext = nullptr;
    newNode->ptrPrev = nullptr;

    return newNode;
}

void swapPayload(Node* node1, Node* node2)
{
    int iTemp = node1->iPayload;
    node1->iPayload = node2->iPayload;
    node2->iPayload = iTemp;
}

void insertEnd(Node** head, int iPayload) {
    Node* newNode = createNode(iPayload);

    if (*head == nullptr) {
        *head = newNode;
        return;
    }

    Node* current = *head;

    while (current->ptrNext != nullptr) {
        current = current->ptrNext;
    }

    current->ptrNext = newNode;
    newNode->ptrPrev = current;
}

void displayList(Node* head) {
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }

    Node* current = head;

    cout << "List: [";
    while (current != nullptr) {
        cout << " " << current->iPayload;
        current = current->ptrNext;
    }
    cout << " ]" << endl;
}

void deleteLastNode(Node** head) {
    if (*head == nullptr) {
        cout << "List is already empty." << endl;
        return;
    }

    Node* nodeToDelete = *head;

    if ((*head)->ptrNext == nullptr) {
        free(nodeToDelete);
        *head = nullptr;
        return;
    }

    while (nodeToDelete->ptrNext != nullptr) {
        nodeToDelete = nodeToDelete->ptrNext;
    }

    nodeToDelete->ptrPrev->ptrNext = nullptr;
    free(nodeToDelete);
}
