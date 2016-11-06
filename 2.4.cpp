#include <bits/stdc++.h>
#include "linkedlist.h"

using namespace std;

Node* partition(Node* head, int v)
{
	// trick: record next node and set cur->next to NULL

	Node* leftStart = NULL;
	Node* leftEnd = NULL;
	Node* rightStart = NULL;
	Node* rightEnd = NULL;
	
	Node* cur = head;
	while (cur)
	{
		Node* next = cur->next;
		cur->next = NULL; // in case it becomes an end node
		if (cur->val < v)
		{
			if (leftStart == NULL)
			{
				leftStart = cur;
				leftEnd = cur;
			} else {
				leftEnd->next = cur;
				leftEnd = leftEnd->next;
			}
		} else {
			if (rightStart == NULL)
			{
				rightStart = cur;
				rightEnd = cur;
			} else {
				rightEnd->next = cur;
				rightEnd = rightEnd->next;
			}
		}
		cur = next;
	}
	// connect left and right
	leftEnd->next = rightStart;
	return leftStart;
}

int main()
{
	int a[] = {2,3,4,1,5,2,3,9,9,7,7};
	int n = 11;
	Node* listHead = LinkedList_builder(a, n);
	cout << "Testing list: ";
	printList(listHead);
	cout << "Resulting list: ";
	Node* newHead = partition(listHead, 5);
	printList(newHead);
	return 0;
}
