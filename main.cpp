#include "function.h"
#include <iostream>
#include <chrono>
#include <ctime>

using namespace std::chrono;
using std::cout;
using std::endl;

int main() {
    Node* head1 = nullptr;
    Node* head2 = nullptr;
    Node* head3 = nullptr;
    Node* head4 = nullptr;
    Node* head5 = nullptr;
    Node* head6 = nullptr;

    // Preenchendo listas com dados aleatórios
    for(int i = 0; i < 500; i++) {
        int payload = rand() % 500; // Gera um número aleatório entre 0 e 49
        insertEnd(&head1, payload);
        insertEnd(&head2, payload);
        insertEnd(&head3, payload);
        insertEnd(&head4, payload);
        insertEnd(&head5, payload);
        insertEnd(&head6, payload);
    }

    cout << "------------------------------" << endl;

    // Bubble Sort
    cout << "\n### BubbleSort ###\n";
    auto timeStart = high_resolution_clock::now();
    bubbleSort(head1);
    auto timeEnd = high_resolution_clock::now();
    displayList(head1);
    auto timeDuration = duration_cast<nanoseconds>(timeEnd - timeStart);
    cout << "Tempo utilizado: " << timeDuration.count() << " nanosegundos" << endl;

    cout << "------------------------------" << endl;

    // Bubble Sort Otimizado
    cout << "\n### BubbleSort Otimizado ###\n";
    auto timeStart2 = high_resolution_clock::now();
    optimizedBubbleSort(head2);
    auto timeEnd2 = high_resolution_clock::now();
    displayList(head2);
    auto timeDuration2 = duration_cast<nanoseconds>(timeEnd2 - timeStart2);
    cout << "Tempo utilizado: " << timeDuration2.count() << " nanosegundos" << endl;

    cout << "------------------------------" << endl;

    // Selection Sort
    cout << "\n### SelectionSort ###\n";
    auto timeStart5 = high_resolution_clock::now();
    selectionSort(head5);
    auto timeEnd5 = high_resolution_clock::now();
    displayList(head5);
    auto timeDuration5 = duration_cast<nanoseconds>(timeEnd5 - timeStart5);
    cout << "Tempo utilizado: " << timeDuration5.count() << " nanosegundos" << endl;

    cout << "------------------------------" << endl;

    // Selection Sort Otimizado
    cout << "\n### SelectionSort Otimizado ###\n";
    auto timeStart6 = high_resolution_clock::now();
    optimizedSelectionSort(head6);
    auto timeEnd6 = high_resolution_clock::now();
    displayList(head6);
    auto timeDuration6 = duration_cast<nanoseconds>(timeEnd6 - timeStart6);
    cout << "Tempo utilizado: " << timeDuration6.count() << " nanosegundos" << endl;

    cout << "------------------------------" << endl;

    // Insertion Sort
    cout << "\n### InsertionSort ###\n";
    auto timeStart3 = high_resolution_clock::now();
    insertionSort(head3);
    auto timeEnd3 = high_resolution_clock::now();
    displayList(head3);
    auto timeDuration3 = duration_cast<nanoseconds>(timeEnd3 - timeStart3);
    cout << "Tempo utilizado: " << timeDuration3.count() << " nanosegundos" << endl;

    cout << "------------------------------" << endl;

    // Insertion Sort Otimizado
    cout << "\n### InsertionSort Otimizado ###\n";
    auto timeStart4 = high_resolution_clock::now();
    optimizedInsertionSort(head4);
    auto timeEnd4 = high_resolution_clock::now();
    displayList(head4);
    auto timeDuration4 = duration_cast<nanoseconds>(timeEnd4 - timeStart4);
    cout << "Tempo utilizado: " << timeDuration4.count() << " nanosegundos" << endl;

    cout << "------------------------------" << endl;

    return 0;
}
