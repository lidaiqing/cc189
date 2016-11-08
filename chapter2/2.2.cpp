#include <bits/stdc++.h>
#include "linkedlist.h"

using namespace std;

Node* kthToLast(Node* head, int k)
{
	Node* p1 = head;
	Node* p2 = head; // fast pointer

	// move p2 to the kth position in the list
	while (k--)
	{
		if (p2 == NULL) return NULL; // out of bound
		p2 = p2->next;
	}

	while (p2->next)
	{
		p2 = p2->next;
		p1 = p1->next;
	}
	return p1;
}

int main()
{
	// Testing
	int a[] = {1,2,3,4,5,6,7,8}, n = 8;
	int k = 3;
	Node* listHead = LinkedList_builder(a, n);
	cout << "Testing list: ";
	printList(listHead);
	cout << "Finding 3 to last element" << endl;
	int result = kthToLast(listHead, k)->val;
	cout << "Result: " << result << endl;
	return 0;
}	
