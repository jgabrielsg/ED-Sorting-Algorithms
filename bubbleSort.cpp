#include "function.h"
#include <iostream>

using std::cout;
using std::endl;
using namespace node_operations;


namespace sorting_algorithms {
    template <typename T>
    void bubbleSort(Node<T>* node)
    {
        if (node == nullptr)
        {
            cout << "Lista vazia: Não é possível realizar bubbleSort" << endl;
            return;
        }
        
        if (node->ptrPrev != nullptr)
        {
            cout << "Meio ou Fim da Lista: Não é possível realizar bubbleSort" << endl;
            return;
        }
        
        Node<T>* outerLoop = node;
        
        while (outerLoop != nullptr && outerLoop->ptrNext != nullptr)
        {
            Node<T>* current = node;
            while (current != nullptr && current->ptrNext != nullptr)
            {
                if (current->iPayload > current->ptrNext->iPayload)
                {
                    swapPayload(current, current->ptrNext);
                }
                current = current->ptrNext;
            }
            outerLoop = outerLoop->ptrNext;
        }
    }
    
    template <typename T>
    void optimizedBubbleSort(Node<T>* head) {
        if (head == nullptr) {
            cout << "Lista vazia: Não é possível realizar bubbleSort" << endl;
            return;
        }
    
        if (head->ptrPrev != nullptr) {
            cout << "Meio ou Fim da Lista: Não é possível realizar bubbleSort" << endl;
            return;
        }
    
        bool swapped;
        Node<T>* current;
        Node<T>* lastPtr = nullptr;
    
        do {
            swapped = false;
            current = head;
    
            while (current->ptrNext != lastPtr) {
                if (current->iPayload > current->ptrNext->iPayload) {
                    swapPayload(current, current->ptrNext);
                    swapped = true;
                }
                current = current->ptrNext;
            }
            lastPtr = current; // Update the lastPtr to the last swapped element
        } while (swapped);
    }
    
    // Explicit instantiation of templates
    template void bubbleSort<int>(Node<int>* node);
    template void optimizedBubbleSort<int>(Node<int>* head);
}