#include "function.h"
#include <iostream>

using std::cout;
using std::endl;

void BucketSort(Node* head) 
{
    if (head == nullptr)
    {
        cout << "Lista vazia: Não é possível realizar bucketSort" << endl;
        return;
    }
    
    if (head->ptrPrev != nullptr)
    {
        cout << "Meio ou Fim da Lista: Não é possível realizar bucketSort" << endl;
        return;
    }
    
    // Cria os buckets
    Node* buckets[10] = {nullptr};
    
    // Distribui os valores nos nodes
    Node* current = head;
    while (current != nullptr) {
        int value = current->iPayload;
        int bucketIndex = value / 10;
        
        if (bucketIndex >= 10) bucketIndex = 9; // Caso seja 100/10

        insertEnd(&buckets[bucketIndex], value);
        current = current->ptrNext;
    }
    
    for (int i = 0; i < 10; ++i) {
        insertionSort(buckets[i]);
    }
    
    Node* orderedList = nullptr;
    for (int i = 0; i < 10; ++i) {
        passValuesToList(&orderedList, buckets[i]);
        deleteList(&buckets[i]);
    }
    
    Node* current1 = head;
    Node* current2 = orderedList;
    
    while (current1 != nullptr && current2 != nullptr)
    {
        swapPayload(current1, current2);
        current1 = current1->ptrNext;
        current2 = current2->ptrNext;
    }
    
    if (current1 != nullptr || current2 != nullptr) cout << "Algo deu errado Bucket Sort!" << endl;
}
