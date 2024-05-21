#include "function.h"
#include <iostream>

using std::cout;
using std::endl;
using namespace node_operations;

namespace sorting_algorithms {

    template <typename T>
    void bucketSort(Node<T>* head) {
        if (head == nullptr) {
            cout << "Lista vazia: Não é possível realizar bucketSort" << endl;
            return;
        }

        if (head->ptrPrev != nullptr) {
            cout << "Meio ou Fim da Lista: Não é possível realizar bucketSort" << endl;
            return;
        }

        // Cria os buckets
        Node<T>* buckets[10] = {nullptr};

        // Distribui os valores nos nodes
        Node<T>* current = head;
        while (current != nullptr) {
            T value = current->iPayload;
            int bucketIndex = value / 10;

            if (bucketIndex >= 10) bucketIndex = 9; // Caso seja 100/10

            node_operations::insertEnd(&buckets[bucketIndex], value);
            current = current->ptrNext;
        }

        for (int i = 0; i < 10; ++i) {
            insertionSort(buckets[i]);
        }

        Node<T>* orderedList = nullptr;
        for (int i = 0; i < 10; ++i) {
            node_operations::passValuesToList(&orderedList, buckets[i]);
            node_operations::deleteList(&buckets[i]);
        }

        Node<T>* current1 = head;
        Node<T>* current2 = orderedList;

        while (current1 != nullptr && current2 != nullptr) {
            node_operations::swapPayload(current1, current2);
            current1 = current1->ptrNext;
            current2 = current2->ptrNext;
        }

        if (current1 != nullptr || current2 != nullptr) cout << "Algo deu errado Bucket Sort!" << endl;
    }

    // Explicit instantiation
    template void bucketSort<int>(Node<int>* head);

} // namespace sorting_algorithms
