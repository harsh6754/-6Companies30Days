#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* newNode(int data) {
    Node* new_node = new Node;
    new_node->data = data;
    new_node->next = nullptr;
    return new_node;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node* linkdelete(Node* head, int n, int m) {
    if (head == nullptr) {
        return nullptr; 
    }

    Node* curr = head;
    Node* prev = nullptr;

    while (curr != nullptr) {
        // Skip m nodes
        for (int i = 0; i < m && curr != nullptr; i++) {
            prev = curr;
            curr = curr->next;
        }

        // Delete n nodes
        for (int i = 0; i < n && curr != nullptr; i++) {
            Node* temp = curr;
            curr = curr->next;
            delete temp;
        }

        // Connect previous node to the current node
        if (prev != nullptr) {
            prev->next = curr;
        } else {
            head = curr; // If no nodes were skipped
        }
    }

    return head;
}

int main() {
    Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);
    head->next->next->next->next->next = newNode(6);
    head->next->next->next->next->next->next = newNode(7);

    cout << "Original List: ";
    printList(head);

    int m = 2, n = 2; 
    head = linkdelete(head, n, m);

    cout << "Modified List: ";
    printList(head);

    return 0;
}