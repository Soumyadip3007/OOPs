#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* back;
    
    Node(int data) {
        this->data = data;
        this->next = nullptr;
        this->back = nullptr;
    }
    
    Node(int data, Node* next, Node* back) {
        this->data = data;
        this->next = next;
        this->back = back;
    }
};

// Function to print the Doubly Linked List
void printDll(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data;
        if (temp->next != nullptr) {
            cout << " <-> ";
        }
        temp = temp->next;
    }
    cout << endl;
}

// Function to delete the k-th node in a Doubly Linked List
Node* Delete_kth(Node* head, int k) {
    if (head == nullptr || k <= 0) {
        return head;
    }

    int cnt = 1;  // Start count from 1
    Node* temp = head;

    // Traverse to the k-th node
    while (temp != nullptr && cnt < k) {
        temp = temp->next;
        cnt++;
    }

    // If k is greater than the length of the list, return head
    if (temp == nullptr) {
        cout << "Invalid k: Out of range" << endl;
        return head;
    }

    Node* prev = temp->back;
    Node* front = temp->next;

    // Case 1: Only one node in the list
    if (prev == nullptr && front == nullptr) {
        delete temp;
        return nullptr;
    }
    // Case 2: Deleting the head
    else if (prev == nullptr) {
        head = front;
        front->back = nullptr;
    }
    // Case 3: Deleting the last node
    else if (front == nullptr) {
        prev->next = nullptr;
    }
    // Case 4: Deleting a middle node
    else {
        prev->next = front;
        front->back = prev;
    }

    delete temp;
    return head;
}

int main() {
    vector<int> arr = {1, 2, 3, 4};
    
    // Creating the Doubly Linked List
    Node* head = new Node(arr[0]);
    Node* prev = head;
    
    for (size_t i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }

    cout << "Before Deletion: ";
    printDll(head);

    int k = 3;  // Deleting the third node
    head = Delete_kth(head, k);

    cout << "After Deletion: ";
    printDll(head);

    return 0;
}