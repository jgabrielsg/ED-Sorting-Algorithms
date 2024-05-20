#include "function.h"
#include <iostream>
#include <chrono>
#include <ctime>
#include <fstream>

using namespace std::chrono;
using std::cout;
using std::endl;
using std::ofstream;

int main() {
    // Valores teste
    const int listSize = 10000;
    const int numberOfLists = 100;
    
    // Abre os CSV's para salvar os tempos
    ofstream bubbleSortFile("bubble_sort_times.csv");
    ofstream optimizedBubbleSortFile("optimized_bubble_sort_times.csv");
    ofstream selectionSortFile("selection_sort_times.csv");
    ofstream optimizedSelectionSortFile("optimized_selection_sort_times.csv");
    ofstream insertionSortFile("insertion_sort_times.csv");
    ofstream optimizedInsertionSortFile("optimized_insertion_sort_times.csv");
    
    for (int i = 0; i < numberOfLists; i++)
    {
        Node* head1 = nullptr;
        Node* head2 = nullptr;
        Node* head3 = nullptr;
        Node* head4 = nullptr;
        Node* head5 = nullptr;
        Node* head6 = nullptr;
        
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
        
        // Insertion Sort Otimizado
        auto timeStart4 = high_resolution_clock::now();
        optimizedInsertionSort(head4);
        auto timeEnd4 = high_resolution_clock::now();
        auto timeDuration4 = duration_cast<nanoseconds>(timeEnd4 - timeStart4);
        optimizedInsertionSortFile << timeDuration4.count() << endl;
        
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
    optimizedInsertionSortFile.close();

    return 0;
}
