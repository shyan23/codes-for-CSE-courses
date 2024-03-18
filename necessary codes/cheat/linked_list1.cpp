#include <iostream>
using namespace std;

struct node {
    int data;
    node* next_address;
};

node* create_node(int data, node* next_address) {
    node* new_node = new node;
    if (new_node == NULL) exit(1);

    new_node->data = data;
    new_node->next_address = next_address;

    return new_node;
}

node* delete_node(node* head, int data) {
    if (head == NULL) return NULL;

    if (data == head->data) {
        node* temp = head;
        head = head->next_address;
        delete temp;
        return head;
    }

    node* traversing_node = head;
    while (traversing_node->next_address != NULL && traversing_node->next_address->data != data) {
        traversing_node = traversing_node->next_address;
    }

    if (traversing_node->next_address == NULL) return head;

    node* temp = traversing_node->next_address;
    traversing_node->next_address = temp->next_address;
    delete temp;

    return head;
}

node* add_node_first(node* head, int data) {
    node* new_node = create_node(data, head);
    return new_node;
}

node* add_node_last(node* head, int data) {
    node* new_node = create_node(data, NULL);
    if (head == NULL) return new_node;

    node* traversing_node = head;
    while (traversing_node->next_address != NULL) {
        traversing_node = traversing_node->next_address;
    }

    traversing_node->next_address = new_node;
    return head;
}

void add_node_after_item(node* head, int item, int new_data) {
    node* traversing_node = head;
    while (traversing_node != NULL && traversing_node->data != item) {
        traversing_node = traversing_node->next_address;
    }

    if (traversing_node == NULL) return;

    node* new_node = create_node(new_data, traversing_node->next_address);
    traversing_node->next_address = new_node;
}

void display_list(node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next_address;
    }
    cout << endl;
}

int main() {
    // Creating a linked list with some arbitrary data
    node* head = create_node(10, NULL);

    for(int i = 0 ; i < 10;i++)
    {
        head = add_node_last(head,i);
        display_list(head);
    }
    
    add_node_after_item(head, 10, 100); // Adding 12 after 10

    // Displaying the linked list
    cout << "Linked List: ";
    display_list(head);

    // Deleting node with data 10
    int k = 100;
    while(k >=0)
    {
    head = delete_node(head,k);
    display_list(head);
    k--;
    }
    
    cout <<"\n";
    // Displaying the modified linked list
    cout << "Modified Linked List after deleting node with data 10: ";
    display_list(head);

    // adding node in the first secton
    cout << "adding node in the first order\n";
    for(int i = 0 ; i < 10;i++)
    {
        head = add_node_first(head,i);
        display_list(head);
    }
    cout << "\n";
    
    // Clean up - Free memory
    while (head != NULL) {
        node* temp = head;
        head = head->next_address;
        delete temp;
    }

    return 0;
}
