#include <bits/stdc++.h>
#include "linkedlist.h"

using namespace std;

void deleteDups(Node* head)
{
	Node* cur = head;
	while (cur)
	{
		Node* runner = cur;
		while (runner->next)
		{
			if (runner->next->val == cur->val)
			{
				Node* next = runner->next;
				runner->next = next->next;
				free(next);
			} else {
				runner = runner->next;
			}
		}
		cur = cur->next;
	}
}

int main()
{
	// Testing lisk 1->2->3->3->3->4->4->5
	int a[] = {1,2,3,3,3,4,4,5};
	Node* listHead = LinkedList_builder(a, 8);
	cout << "Testing List: ";
	printList(listHead);
	deleteDups(listHead);
	cout << "Result List: ";
	printList(listHead);
	return 0;
}















