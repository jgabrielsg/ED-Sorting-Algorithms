#include "function.h"
#include <iostream>

using std::cout;
using std::endl;
using namespace node_operations;

namespace sorting_algorithms {
    template <typename T>
    void selectionSort(Node<T>* head)
    {
        if (head == nullptr)
        {
            cout << "Lista vazia: Não é possível realizar SelectionSort" << endl;
            return;
        }
        
        if (head->ptrPrev != nullptr)
        {
            cout << "Meio ou Fim da Lista: Não é possível realizar SelectionSort" << endl;
            return;
        }
        
        Node<T>* ptrOuter = head;
        Node<T>* ptrInner = nullptr;
    
        while(ptrOuter != nullptr && ptrOuter->ptrNext != nullptr)
        {
            ptrInner = ptrOuter->ptrNext;
            
            while (ptrInner != nullptr)
            {
                if (ptrInner->iPayload < ptrOuter->iPayload)
                {
                    swapPayload(ptrInner, ptrOuter);
                }
                ptrInner = ptrInner->ptrNext;
            }
            
            ptrOuter = ptrOuter->ptrNext;
        }
    }
    
    template <typename T>
    void optimizedSelectionSort(Node<T>* head)
    {
        if (head == nullptr)
        {
            cout << "Lista vazia: Não é possível realizar SelectionSort" << endl;
            return;
        }
        
        if (head->ptrPrev != nullptr)
        {
            cout << "Meio ou Fim da Lista: Não é possível realizar SelectionSort" << endl;
            return;
        }
        
        Node<T>* ptrOuter = head;
        Node<T>* ptrInner = nullptr;
    
        while(ptrOuter != nullptr && ptrOuter->ptrNext != nullptr)
        {
            ptrInner = ptrOuter->ptrNext;
            
            Node<T>* ptrMinPayload = ptrOuter;
            
            while (ptrInner != nullptr)
            {
                if (ptrInner->iPayload < ptrMinPayload->iPayload)
                {
                    ptrMinPayload = ptrInner;
                }
                ptrInner = ptrInner->ptrNext;
            }
            
            if (ptrMinPayload != ptrOuter)
            {
                swapPayload(ptrMinPayload, ptrOuter);
            }
            
            ptrOuter = ptrOuter->ptrNext;
        }
    }
    
    // Explicit instantiation of templates
    template void selectionSort<int>(Node<int>* head);
    template void optimizedSelectionSort<int>(Node<int>* head);
}