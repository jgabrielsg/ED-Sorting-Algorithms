#include "function.h"
#include <iostream>

using std::cout;
using std::endl;

void selectionSort(Node* head)
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
    
    Node* ptrOuter = head;
    Node* ptrInner = nullptr;

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

void optimizedSelectionSort(Node* head)
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
    
    Node* ptrOuter = head;
    Node* ptrInner = nullptr;

    while(ptrOuter != nullptr && ptrOuter->ptrNext != nullptr)
    {
        ptrInner = ptrOuter->ptrNext;
        
        Node* ptrMinPayload = ptrOuter;
        
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