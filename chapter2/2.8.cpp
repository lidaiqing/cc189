#include <bits/stdc++.h>
#include "linkedlist.h"

using namespace std;

Node* findCollide(Node* head)
{
	Node* p1 = head;
	Node* p2 = head;
	// find meeting point in the loop
	while (p1 != p2 || p1 == head)
	{
		p1 = p1->next;
		p2 = p2->next->next; // fast pointer
	}

	Node* C = p1; // collide point
	p1 = head;
	while (p1 != C) 
	{
		C = C->next;
		p1 = p1->next;
	}

	// now p1 meet C at the start of the loop
	return p1;
}

int main()
{
	int a[] = {1,2,3,4,5,6,7,8,9};
	int n = 9;
	Node* listHead = LinkedList_builder(a, n);
	Node* cur = listHead;
	while (cur->next) cur = cur->next;
	cur->next = listHead->next->next->next->next;
	cout << "Testing List: ";
	int cnt = 10;
	cur = listHead;
	while (cnt--)
	{
		cout << cur->val << " ";
		cur = cur->next;
	}
	cout << endl;
	Node* collideNode = findCollide(listHead);
	cout << "Result: " << collideNode->val << endl;
	return 0;
}	















