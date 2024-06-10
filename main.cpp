#include "function.h"
#include <iostream>
#include <chrono>
#include <ctime>
#include <fstream>

using namespace std::chrono;
using std::cout;
using std::endl;
using std::ofstream;
using namespace node_operations;
using namespace nodetree_operations;
using namespace sorting_algorithms;
using namespace tree_search;

int main() {
    // Valores teste
    const int listSize = 10000;
    const int numberOfLists = 100;
    
    // Abre os CSV's para salvar os tempos
    ofstream bubbleSortFile("bubbleSort.csv");
    ofstream optimizedBubbleSortFile("bubbleSortOtimizado.csv");
    ofstream selectionSortFile("selectionSort.csv");
    ofstream optimizedSelectionSortFile("selectionSortOtimizado.csv");
    ofstream insertionSortFile("insertionSortOtimizado.csv");
    ofstream bucketSortFile("bucketSort.csv");
    
    for (int i = 0; i < numberOfLists; i++)
    {
        Node<int>* head1 = nullptr;
        Node<int>* head2 = nullptr;
        Node<int>* head3 = nullptr;
        Node<int>* head4 = nullptr;
        Node<int>* head5 = nullptr;
        Node<int>* head6 = nullptr;
        
        // Preenchendo listas com dados aleatórios
        for(int j = 0; j < listSize; j++) {
            int payload = rand() % 100; // Gera um número aleatório entre 0 e 100
            insertEnd(&head1, payload);
            insertEnd(&head2, payload);
            insertEnd(&head3, payload);
            insertEnd(&head4, payload);
            insertEnd(&head5, payload);
            insertEnd(&head6, payload);
        }
        
        cout << "Época: " << i << endl;
        
        // Bubble Sort
        auto timeStart = high_resolution_clock::now();
        bubbleSort(head1);
        auto timeEnd = high_resolution_clock::now();
        auto timeDuration = duration_cast<nanoseconds>(timeEnd - timeStart);
        bubbleSortFile << timeDuration.count() << endl;

        // Bubble Sort Otimizado
        auto timeStart2 = high_resolution_clock::now();
        optimizedBubbleSort(head2);
        auto timeEnd2 = high_resolution_clock::now();
        auto timeDuration2 = duration_cast<nanoseconds>(timeEnd2 - timeStart2);
        optimizedBubbleSortFile << timeDuration2.count() << endl;
        
        // Selection Sort
        auto timeStart5 = high_resolution_clock::now();
        selectionSort(head5);
        auto timeEnd5 = high_resolution_clock::now();
        auto timeDuration5 = duration_cast<nanoseconds>(timeEnd5 - timeStart5);
        selectionSortFile << timeDuration5.count() << endl;
        
        // Selection Sort Otimizado
        auto timeStart6 = high_resolution_clock::now();
        optimizedSelectionSort(head6);
        auto timeEnd6 = high_resolution_clock::now();
        auto timeDuration6 = duration_cast<nanoseconds>(timeEnd6 - timeStart6);
        optimizedSelectionSortFile << timeDuration6.count() << endl;
        
        // Insertion Sort
        auto timeStart3 = high_resolution_clock::now();
        insertionSort(head3);
        auto timeEnd3 = high_resolution_clock::now();
        auto timeDuration3 = duration_cast<nanoseconds>(timeEnd3 - timeStart3);
        insertionSortFile << timeDuration3.count() << endl;
        
        // Bucket Sort
        auto timeStart4 = high_resolution_clock::now();
        bucketSort(head4);
        auto timeEnd4 = high_resolution_clock::now();
        auto timeDuration4 = duration_cast<nanoseconds>(timeEnd4 - timeStart4);
        bucketSortFile << timeDuration4.count() << endl;
        
        // Liberando memória
        deleteList(&head1);
        deleteList(&head2);
        deleteList(&head3);
        deleteList(&head4);
        deleteList(&head5);
        deleteList(&head6);
    }
    
    // Salva os csvs
    bubbleSortFile.close();
    optimizedBubbleSortFile.close();
    selectionSortFile.close();
    optimizedSelectionSortFile.close();
    insertionSortFile.close();
    bucketSortFile.close();

    // Exemplo de bucket sort:
    Node<int>* head_teste = nullptr;
    insertEnd(&head_teste, 30);
    insertEnd(&head_teste, 40);
    insertEnd(&head_teste, 34);
    insertEnd(&head_teste, 5);
    insertEnd(&head_teste, 14);
    insertEnd(&head_teste, 15);
    insertEnd(&head_teste, 7);
    insertEnd(&head_teste, 8);
    insertEnd(&head_teste, 38);
    insertEnd(&head_teste, 17);
    
    displayList(head_teste);
    
    cout << "--------------------" << endl;
    
    // Cria 5 buckets
    Node<int>* buckets[5] = {nullptr};
    // Cada bucket vai ser uma lista que vai conter valores de um certo intervalo. No caso do exemplo,
    // Os interavalos serão: 0-9, 10-19, 20-29, 30-39 e 40-49
    
    // Distribui os valores nos buckets
    Node<int>* current = head_teste;
    while (current != nullptr) {
        int value = current->iPayload;
        int bucketIndex = value / 10;
        insertEnd(&buckets[bucketIndex], value);
        current = current->ptrNext;
    }
    
    // Cada bucket agora possui valores que estão num range de apenas 10:
    // Printando todos os buckets
    for (int i = 0; i < 5; ++i) 
    {
        cout << "Bucket " << i;
        displayList(buckets[i]);
    }
    
     cout << "--------------------" << endl;
    
    // Agora ordenaremos todos os buckets
    for (int i = 0; i < 5; ++i) {
        insertionSort(buckets[i]);
    }
    
     cout << "--------------------" << endl;
    
    for (int i = 0; i < 5; ++i) 
    {
        cout << "Bucket " << i << " ";
        displayList(buckets[i]);
    }
    
    // E basta passar os buckets ordenados para uma lista nova! 
    Node<int>* lista_ordenada_teste = nullptr;
    for (int i = 0; i < 5; ++i) {
        passValuesToList(&lista_ordenada_teste, buckets[i]);
        deleteList(&buckets[i]);
    }
    
     cout << "--------------------" << endl;

    // Na nossa função passaríamos essa lista ordenada para a lista original!
    displayList(lista_ordenada_teste);

    monitorTreeAndListCreation();

    return 0;
}
