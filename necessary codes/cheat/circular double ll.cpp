#include <iostream>

// Node structure for the circular doubly linked list
struct Node {
    int data;
    Node* next;
    Node* prev;
};

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return newNode;
}

// Function to insert a new node at the beginning of the list
Node* insertAtBeginning(Node* head, int value) {
    Node* newNode = createNode(value);

    if (!head) {
        // If the list is empty, make the new node the only node in the list
        head = newNode;
        head->next = head;
        head->prev = head;
    } else {
        // If the list is not empty, insert the new node at the beginning
        newNode->next = head;
        newNode->prev = head->prev;
        head->prev->next = newNode;
        head->prev = newNode;
        head = newNode;
    }

    return head;
}

// Function to delete a node with a given value from the list
Node* deleteNode(Node* head, int value) {
    if (!head) {
        // List is empty, nothing to delete
        return nullptr;
    }

    Node* currentNode = head;

    // Traverse the list to find the node with the given value
    while (currentNode->data != value) {
        if (currentNode->next == head) {
            // Node with the given value not found
            std::cout << "Node with value " << value << " not found in the list." << std::endl;
            return head;
        }
        currentNode = currentNode->next;
    }

    // If the node to be deleted is the only node in the list
    if (currentNode->next == currentNode) {
        delete currentNode;
        return nullptr;
    } else {
        // If the node to be deleted is not the only node
        currentNode->prev->next = currentNode->next;
        currentNode->next->prev = currentNode->prev;
        if (currentNode == head) {
            head = currentNode->next;
        }
        delete currentNode;
    }

    std::cout << "Node with value " << value << " deleted from the list." << std::endl;
    return head;
}

// Function to display the circular doubly linked list
void display(Node* head) {
    if (!head) {
        std::cout << "List is empty." << std::endl;
        return;
    }

    Node* currentNode = head;
    do {
        std::cout << currentNode->data << " ";
        currentNode = currentNode->next;
    } while (currentNode != head);
    std::cout << std::endl;
}

int main() {
    Node* head = nullptr;

    head = insertAtBeginning(head, 10);
    head = insertAtBeginning(head, 20);
    head = insertAtBeginning(head, 30);
    display(head);

    head = deleteNode(head, 20);
    display(head);

    head = deleteNode(head, 40); // Trying to delete a non-existent node
    display(head);

    return 0;
}
