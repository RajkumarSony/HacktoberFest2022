// C++ program to delete middle of a linked list
#include <bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node {
	int data;
	struct Node* next;
};
// count of nodes
int countOfNodes(struct Node* head)
{
	int count = 0;
	while (head != NULL) {
		head = head->next;
		count++;
	}
	return count;
}

// Deletes middle node and returns
// head of the modified list
struct Node* deleteMid(struct Node* head)
{
	// Base cases
	if (head == NULL)
		return NULL;
	if (head->next == NULL) {
		delete head;
		return NULL;
	}
	struct Node* copyHead = head;
	// Find the count of nodes
	int count = countOfNodes(head);
	// Find the middle node
	int mid = count / 2;
	// Delete the middle node
	while (mid-- > 1)
		head = head->next;
	// Delete the middle node
	head->next = head->next->next;
	return copyHead;
}

// A utility function to print
// a given linked list
void printList(struct Node* ptr)
{
	while (ptr != NULL) {
		cout << ptr->data << "->";
		ptr = ptr->next;
	}
	cout << "NULL\n";
}

// Utility function to create a new node.
Node* newNode(int data)
{
	struct Node* temp = new Node;
	temp->data = data;
	temp->next = NULL;
	return temp;
}

/* Driver program to test above function*/
int main()
{
	/* Start with the empty list */
	struct Node* head = newNode(1);
	head->next = newNode(2);
	head->next->next = newNode(3);
	head->next->next->next = newNode(4);

	cout << "Given Linked List\n";
	printList(head);
	head = deleteMid(head);
	cout << "Linked List after deletion of middle\n";
	printList(head);
	return 0;
}

// This code is contributed by Aditya Kumar (adityakumar129)
