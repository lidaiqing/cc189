#include <bits/stdc++.h>
#include "linkedlist.h"

using namespace std;

// copy next value and delete next node
void deleteMiddle(Node* mid)
{
	// if mid is the last node, delete it directly
	if (mid->next == NULL)
	{
		free(mid);
		mid = NULL;
	} else {
		Node* next = mid->next;
		mid->val = next->val;
		mid->next = next->next;
		free(next);
	}
}

int main()
{
	int a[] = {1,2,3,4,5,6,7};
	Node* listHead = LinkedList_builder(a, 7);
	Node* mid = listHead->next->next->next;
	cout << "Testing List: ";
	printList(listHead);
	deleteMiddle(mid);
	cout << "Resulting List: ";
	printList(listHead);
	return 0;
}
	

