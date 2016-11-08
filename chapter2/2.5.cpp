#include <bits/stdc++.h>
#include "linkedlist.h"

using namespace std;

Node* addList(Node* l1, Node* l2, int carry)
{
	if (l1 == NULL && l2 == NULL && carry == 0) return NULL; // the end of recurse
	int value = carry;
	if (l1 != NULL) value += l1->val;
	if (l2 != NULL) value += l2->val;
	
	Node* result = new Node(value % 10);
	
	if (l1 != NULL || l2 != NULL)
	{
		result->next = 
			addList(l1 == NULL ? NULL : l1->next,
				l2 == NULL ? NULL : l2->next,
				carry = value / 10);
	}
	return result;
}

int main()
{
	int a[] = {1, 2, 3, 4};
	int b[] = {5, 6, 7};
	Node* l1 = LinkedList_builder(a, 4);
	Node* l2 = LinkedList_builder(b, 3);
	
	cout << "Testing 4321 + 765" << endl;
	Node* result = addList(l1, l2, 0);
	cout << "Resulting List: ";
	printList(result);
	return 0;
}
