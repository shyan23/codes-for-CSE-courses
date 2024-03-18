#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
	Node(int value) {
		data = value;
		next = NULL;
	}
};

void convertToCircular(Node* head) {
	Node* current = head;
	while (current->next != NULL) {
		current = current->next;
	}
	current->next = head;
}

void printList(Node* head) {
	Node* current = head;
	do {
		cout << current->data << " ";
		current = current->next;
	} while (current != head);
}

int main() {
	Node* head = new Node(1);
	head->next = new Node(2);
	head->next->next = new Node(3);
	head->next->next->next = new Node(4);

	convertToCircular(head);

	cout << "The circular linked list is: ";
	printList(head);

	return 0;
}
