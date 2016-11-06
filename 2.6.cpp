#include <bits/stdc++.h>
#include "linkedlist.h"

using namespace std;

bool isPalindrome(Node* head)
{
	Node* p1 = head; // slow pointer
	Node* p2 = head; // fast pointer

	stack<int> st;
	while (p2 && p2->next)
	{
		st.push(p1->val);
		p1 = p1->next;
		p2 = p2->next->next;
	}

	if (p2 != NULL) // the size of the list is odd
	{
		p1 = p1->next;
	}
	//p1 = p1->next;
	while (p1)
	{
		if (p1->val != st.top()) return false;
		p1 = p1->next;
		st.pop();
	}
	return true;
}

int main()
{
	int a[] = {1,1,0,0,0,1,1};
	int n = 7;
	Node* listHead = LinkedList_builder(a, n);
	cout << "Testing List: ";
	printList(listHead);
	cout << "Result: " << isPalindrome(listHead) << endl;
	return 0;
}
