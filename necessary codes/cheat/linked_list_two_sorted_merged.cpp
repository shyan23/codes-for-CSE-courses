#include <iostream>

// Node structure for a singly linked list
struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

// Function to merge two sorted linked lists
Node* mergeSortedLists(Node* head1, Node* head2) {
    Node* mergedHead = nullptr;
    Node* current = nullptr;

    while (head1 != nullptr && head2 != nullptr) {
        if (head1->data <= head2->data) {
            if (mergedHead == nullptr) {
                mergedHead = current = head1;
            } else {
                current->next = head1;
                current = current->next;
            }
            head1 = head1->next;
        } else {
            if (mergedHead == nullptr) {
                mergedHead = current = head2;
            } else {
                current->next = head2;
                current = current->next;
            }
            head2 = head2->next;
        }
    }

    // If any of the lists is not fully processed
    if (head1 != nullptr) {
        current->next = head1;
    } else {
        current->next = head2;
    }

    return mergedHead;
}

// Function to print the linked list
void printList(Node* head) {
    while (head->next != nullptr) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

// Function to build a sorted linked list from input stream
// Function to build a sorted linked list from input stream
Node* buildSortedListFromStream() {
    Node* head = nullptr;
    Node* current = nullptr;

    int value;
    while (std::cin >> value && std::cin.peek() != '\n') {
        if (head == nullptr) {
            head = current = new Node(value);
        } else {
            current->next = new Node(value);
            current = current->next;
        }
    }

    // Handle the last element after newline
    if (head == nullptr) {
        head = new Node(value);
    } else {
        current->next = new Node(value);
    }

    return head;
}


int main() {
    // Reading two sorted linked lists from input streams
    Node* list1 = buildSortedListFromStream();
    Node* list2 = buildSortedListFromStream();

    // Merging and printing the result
    Node* mergedList = mergeSortedLists(list1, list2);
    std::cout << "Merged List: ";
    printList(mergedList);

    // Cleanup - free memory
    while (mergedList != nullptr) {
        Node* temp = mergedList;
        mergedList = mergedList->next;
        delete temp;
    }

    return 0;
}
