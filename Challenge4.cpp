#include <iostream>
#include "BST.h"
#include "Linked_List.h"
#include <vector>
#include <ctime>
using namespace std;

vector<int> generateRandom(int size) {
    vector<int> vector(size);
    for (int i = 0; i < size; i++) {
        vector[i] = (rand() % 1000 + 1);
    }
    return vector;
}

vector<int> generateBackwards(int size) {
    vector<int> vector(size);
    for (int i = 0; i < size; i++) {
        vector[i] = size - i;
    }
    return vector;
}

vector<int> generateForwards(int size) {
    vector<int> vector(size);
    for (int i = 0; i < size; i++) {
        vector[i] = i + 1;
    }
    return vector;
}

void insertBST(BST& bst, vector<int>& vector) {
    for (int i = 0; i < vector.size(); i++) {
        bst.insert(vector[i]);
    }
}

void insertLL(LinkedList& ll, vector<int>& vector) {
    for (int i = 0; i < vector.size(); i++) {
        ll.append(to_string(vector[i]));
    }
}

bool search(LinkedList& ll, int searchValue) {
    clock_t start = clock();  // Start timing

    Node2* tmp = ll.head;
    while (tmp != nullptr) {
        if (tmp->data == to_string(searchValue)) {
            clock_t end = clock();  // Stop timing when found
            double duration = double(end - start) / CLOCKS_PER_SEC;
            cout << "Search Time for LinkedList: " << duration << " seconds" << endl;
            return true;  // Return true if value is found
        }
        tmp = tmp->next;
    }

    clock_t end = clock();  // Stop timing after the loop completes
    double duration = double(end - start) / CLOCKS_PER_SEC;
    cout << "Search Time for LinkedList: " << duration << " seconds" << endl;
    return false;  // Return false if value is not found
}

bool search(BST& bst, int searchValue) {
    clock_t start = clock();  // Start timing

    bool found = bst.find(searchValue);  // Perform the BST search

    clock_t end = clock();  // Stop timing after the search
    double duration = double(end - start) / CLOCKS_PER_SEC;
    cout << "Search Time for BST: " << duration << " seconds" << endl;

    return found;  // Return true if found, false otherwise
}


int main() {
    //clock_t start, end;
    //double duration;
    BST bst;
    LinkedList ll;
    int searchValue = 20;
    int size = 500000;
    vector<int> vector1 = generateRandom(500000);
    vector<int> vector = generateForwards(10000);
    insertBST(bst, vector);
    insertLL(ll, vector);
    cout << "Value " << searchValue << " in BST " << (search(bst, searchValue) ? "Found" : "Not Found") << endl;
    cout << "Value " << searchValue << " in LL " << (search(ll, searchValue) ? "Found" : "Not Found") << endl;


    return 0;
}

   /* start = clock();
    insertBST(bst, vector, size);  // Insert into BST
    end = clock();
    duration = double(end - start) / CLOCKS_PER_SEC;
    cout << "Insertion Time for BST: " << duration << " seconds" << endl;
    
    start = clock();
    bool found = bst.find(searchValue);  // Search in BST
    end = clock();
    duration = double(end - start) / CLOCKS_PER_SEC;
    cout << "Search Time for BST: " << duration << " seconds" << endl;
    cout << "Number " << (found ? "Found" : "Not Found") << endl << endl;

    start = clock();
    insertLL(ll, vector, size);  // Insert into LinkedList
    end = clock();
    duration = double(end - start) / CLOCKS_PER_SEC;
    cout << "Insertion Time for LinkedList: " << duration << " seconds" << endl;

    start = clock();
    bool foundLL = searchLL(ll, searchValue);  // Search in LinkedList
    end = clock();
    duration = double(end - start) / CLOCKS_PER_SEC;
    cout << "Search Time for LinkedList: " << duration << " seconds" << endl;
    cout << "Number " << (foundLL ? "Found" : "Not Found") << endl;
    */
  //  return 0;
//}



/*
    srand(time(0));

    BST bst1, bst2, bst3, bst4, bst5;
    LinkedList ll1, ll2, ll3, ll4, ll5;

    int searchValue = rand() % 1000 + 1;
    int size1 = 500000;
    int size2 = 1000000;
    int size3 = 2000000;
    vector<int> vectorOne = generateRandom(size1);
    vector<int> vectorTwo = generateRandom(size2);
    vector<int> vectorThree = generateRandom(size3);
    vector<int> vectorFour = generateBackwards();
    vector<int> vectorFive = generateForwards();

    clock_t start = clock();
    insertBST(bst1, vectorOne, size1);
    cout << "bst1" << endl;

    insertBST(bst2, vectorTwo, size2);
    cout << "bst2" << endl;
    insertBST(bst3, vectorThree, size3);
    cout << "bst3" << endl;
    insertBST(bst4, vectorFour, 1000);
    cout << "bst4" << endl;
    insertBST(bst5, vectorFive, 10000);
    cout << "bst5" << endl;

    insertLL(ll1, vectorOne, size1);
    insertLL(ll2, vectorTwo, size2);
    insertLL(ll3, vectorThree, size3);
    insertLL(ll4, vectorFour, 10000);
    insertLL(ll5, vectorFive, 10000);

    bool found1b = bst1.find(searchValue);
    bool found2b = bst2.find(searchValue);
    bool found3b = bst3.find(searchValue);
    bool found4b = bst4.find(searchValue);
    bool found5b = bst5.find(searchValue);

    bool found1ll = searchLL(ll1, searchValue);
    bool found2ll = searchLL(ll2, searchValue);
    bool found3ll = searchLL(ll3, searchValue);
    bool found4ll = searchLL(ll4, searchValue);
    bool found5ll = searchLL(ll5, searchValue);

    clock_t end = clock();
    double duration = double(end - start) / CLOCKS_PER_SEC;

    cout << "Time: " << duration << " seconds." << endl;

    cout << "Search Result for value " << searchValue << ": " << endl;
    cout << "BST 1: " << (found1b ? "Found" : "Not Found") << endl;
    cout << "BST 2: " << (found2b ? "Found" : "Not Found") << endl;
    cout << "BST 3: " << (found3b ? "Found" : "Not Found") << endl;
    cout << "BST 4: " << (found4b ? "Found" : "Not Found") << endl;
    cout << "BST 5: " << (found5b ? "Found" : "Not Found") << endl;

    cout << "LL 1: " << (found1ll ? "Found" : "Not Found") << endl;
    cout << "LL 2: " << (found2ll ? "Found" : "Not Found") << endl;
    cout << "LL 3: " << (found3ll ? "Found" : "Not Found") << endl;
    cout << "LL 4: " << (found4ll ? "Found" : "Not Found") << endl;
    cout << "LL 5: " << (found5ll ? "Found" : "Not Found") << endl;

    return 0;
}
*/