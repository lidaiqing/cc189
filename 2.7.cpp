#include <bits/stdc++.h>
#include "linkedlist.h"

using namespace std;

pair<Node*, int> findTailAndSize(Node* head)
{
	int count = 1;
	Node* cur = head;
	while (cur->next)
	{
		count++;
		cur = cur->next;
	}
	return make_pair(cur, count);
}

Node* findIntersection(Node* l1, Node* l2)
{
	pair<Node*, int> p1 = findTailAndSize(l1);
	pair<Node*, int> p2 = findTailAndSize(l2);
	if (p1.first != p2.first) return NULL; // no intersection

	if (p1.second < p2.second) swap(l1, l2); // let p1 be longer list
	Node* cur1 = l1;
	Node* cur2 = l2;
	// advance cur1
	int diff = abs(p1.second - p2.second);
	while (diff--)
	{
		cur1 = cur1->next;
	}

	while (cur1)
	{
		if (cur1 == cur2)
		{
			// found the intersection point
			return cur1;
		}
		cur1 = cur1->next;
		cur2 = cur2->next;
	}
	return NULL;
}

int main()
{
	int a[] = {1, 2, 3, 4, 5, 6};
	int n = 6;
	Node* l1 = LinkedList_builder(a, n);
	Node* l2 = LinkedList_builder(a, n);
	Node* cur = l2;
	while (cur->next) cur = cur->next;
	cur->next = l1; // connect l2 to l1
	cout << "Testing list:" << endl;
	printList(l1);
	printList(l2);
	Node* inter = findIntersection(l1, l2);
	cout << "Result: " << inter->val << endl;
	return 0;
}
	
