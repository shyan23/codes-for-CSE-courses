#include <iostream>
using namespace std;

struct ll {
    struct node {
        node* prev;
        node* next;
        int data;
    };

    node* head = nullptr;
    node* tail = nullptr;

    node* create_node(int x, node* prev, node* next) {
        node* a = new node;
        a->data = x;
        a->next = next;
        a->prev = prev;
        return a;
    }

    void insert_at_first(int x) {
        node* new_node = create_node(x, nullptr, head);
        if (head == nullptr) {
            head = new_node;
            tail = new_node;
        } else {
            head->prev = new_node;
            head = new_node;
        }
    }

    void insert_at_last(int x) {
        node* n = create_node(x, tail, nullptr);
        if (tail == nullptr) {
            head = n;
            tail = n;
        } else {
            tail->next = n;
            tail = n;
        }
    }

    void delete_from_front() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        delete temp;
    }

    void delete_from_back() {
        if (tail == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        node* temp = tail;
        tail = tail->prev;
        if (tail != nullptr) {
            tail->next = nullptr;
        } else {
            head = nullptr;
        }
        delete temp;
    }

    void delete_at_position(int pos) {
    if (pos < 1) {
        cout << "Invalid position." << endl;
        return;
    }

    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    node* current = head;
    int count = 1;

    // Traverse to the node at the specified position
    while (current != nullptr && count < pos) {
        current = current->next;
        count++;
    }

    if (current == nullptr) {
        cout << "Position out of range." << endl;
        return;
    }

    if (current == head) { // Deleting from the front
        delete_from_front();
        return;
    }

    if (current == tail) { // Deleting from the back
        delete_from_back();
        return;
    }

    // Update neighboring nodes' pointers
    current->prev->next = current->next;
    current->next->prev = current->prev;

    // Delete the node
    delete current;
}


    void print_forward() {
        node* tr = head;
        while (tr != nullptr) {
            cout << tr->data << " ";
            tr = tr->next;
        }
        cout << endl;
    }

    void print_back() {
        node* tr = tail;
        while (tr != nullptr) {
            cout << tr->data << " ";
            tr = tr->prev;
        }
        cout << endl;
    }
};

int main() {
    ll l;
    l.insert_at_first(10);
    l.insert_at_first(12);
    l.insert_at_first(13);
    l.insert_at_last(1100);
    l.insert_at_first(213);
    l.insert_at_last(233);

    cout << "Original List: ";
    l.print_forward();
    l.print_back();

    l.delete_from_front();
    cout << "List after deleting from front: ";
    l.print_forward();

    l.delete_from_back();
    cout << "List after deleting from back: ";
    l.print_forward();

    l.delete_at_position(2);
    cout << "List after deleting at position 2: ";
    l.print_forward();

    return 0;
}
