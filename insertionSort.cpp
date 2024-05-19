#include "function.h"
#include <iostream>

using std::cout;
using std::endl;

void insertionSort(Node* head) {
    if (head == nullptr)
    {
        cout << "Lista vazia: Não é possível realizar insertionSort" << endl;
        return;
    }
    
    if (head->ptrPrev != nullptr)
    {
        cout << "Meio ou Fim da Lista: Não é possível realizar insertionSort" << endl;
        return;
    }
    
    // Node que irá passar uma vez por cada node, do segundo ao útlimo    
    Node* ptrOuter = head->ptrNext;

    while(ptrOuter != nullptr)
    {
        // Esses 2 nodes andaram de pares, para checar o Inner é maior que o current
        Node* ptrInner = ptrOuter->ptrPrev;
        Node* current = ptrOuter;
        
        while(ptrInner != nullptr && ptrInner->iPayload > current->iPayload) {
            int temp = current->iPayload;
            current->iPayload = ptrInner->iPayload;
            ptrInner->iPayload = temp;
            
            current = ptrInner;
            ptrInner = ptrInner->ptrPrev;
        }
        
        ptrOuter = ptrOuter->ptrNext;
    }
}

void optimizedInsertionSort(Node*& head) {
    if (head == nullptr) {
        cout << "Lista vazia: Não é possível realizar insertionSort" << endl;
        return;
    }

    if (head->ptrPrev != nullptr) {
        cout << "Meio ou Fim da Lista: Não é possível realizar insertionSort" << endl;
        return;
    }

    Node* ptrOuter = head->ptrNext;

    while (ptrOuter != nullptr) {
        Node* current = ptrOuter;
        ptrOuter = ptrOuter->ptrNext;

        Node* ptrInner = current->ptrPrev;

        // Check if the current node is already in the correct position
        if (ptrInner != nullptr && ptrInner->iPayload > current->iPayload) {
            // Remove the current node from its position
            current->ptrPrev->ptrNext = current->ptrNext;
            if (current->ptrNext != nullptr) {
                current->ptrNext->ptrPrev = current->ptrPrev;
            }

            // Find the correct position for the current node
            Node* search = ptrInner;
            while (search->ptrPrev != nullptr && search->iPayload > current->iPayload) {
                search = search->ptrPrev;
            }

            // Insert the current node in its correct position
            if (search->iPayload > current->iPayload) {
                current->ptrNext = search;
                current->ptrPrev = search->ptrPrev;
                if (search->ptrPrev != nullptr) {
                    search->ptrPrev->ptrNext = current;
                } else {
                    head = current; // Update the head if necessary
                }
                search->ptrPrev = current;
            } else {
                current->ptrNext = search->ptrNext;
                if (search->ptrNext != nullptr) {
                    search->ptrNext->ptrPrev = current;
                }
                search->ptrNext = current;
                current->ptrPrev = search;
            }
        }
    }
}



