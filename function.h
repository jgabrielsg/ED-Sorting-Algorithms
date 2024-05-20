struct Node {
    int iPayload;
    Node* ptrNext;
    Node* ptrPrev;
};

Node* createNode(int);
void insertEnd(Node**, int);
void displayList(Node*);
void deleteList(Node**);
void swapPayload(Node*, Node*);
void passValuesToList(Node**, Node*);

// Sorting functions
void bubbleSort(Node*);
void optimizedBubbleSort(Node*);
void selectionSort(Node*);
void optimizedSelectionSort(Node*);
void insertionSort(Node*);
void optimizedInsertionSort(Node*&);
void BucketSort(Node*);
