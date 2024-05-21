template <typename T>
struct Node {
    T iPayload;
    Node* ptrNext;
    Node* ptrPrev;
};

namespace node_operations {
    template <typename T>
    Node<T>* createNode(T iPayload);

    template <typename T>
    void insertEnd(Node<T>** head, T iPayload);

    template <typename T>
    void displayList(Node<T>* head);

    template <typename T>
    void deleteList(Node<T>** head);

    template <typename T>
    void swapPayload(Node<T>* node1, Node<T>* node2);

    template <typename T>
    void passValuesToList(Node<T>**, Node<T>*);
}

namespace sorting_algorithms {
    template <typename T>
    void bubbleSort(Node<T>* head);

    template <typename T>
    void optimizedBubbleSort(Node<T>* head);

    template <typename T>
    void insertionSort(Node<T>* head);

    template <typename T>
    void bucketSort(Node<T>* head);

    template <typename T>
    void selectionSort(Node<T>* head);

    template <typename T>
    void optimizedSelectionSort(Node<T>* head);
}