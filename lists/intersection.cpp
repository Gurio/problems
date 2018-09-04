/*
 *
 https://leetcode.com/problems/remove-duplicates-from-sorted-list
 *
 */


#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


bool isIntersecting1(ListNode* l1, ListNode* l2) {
    unordered_set<ListNode*> nodes;
    ListNode* cur = l1;
    while (cur){
        nodes.insert(cur);
        cur = cur->next;
    }
    cur = l2;
    while (cur){
        if (nodes.count(cur) > 0){return true;}
        cur = cur->next;
    }
    return false;
}

bool isIntersecting(ListNode* l1, ListNode* l2) {
    ListNode* last_l1 = l1;
    while (last_l1->next){
        last_l1 = last_l1->next;
    }
    ListNode* cur = l2;
    while (cur){
        if (cur == last_l1){return true;}
        cur = cur->next;
    }
    return false;
}

int main (){
    ListNode *l1 = new ListNode (1);
    l1->next = new ListNode (1);
    l1->next->next = new ListNode (3); 
    l1->next->next->next = new ListNode (4);
    l1->next->next->next->next = new ListNode (4);
    l1->next->next->next->next->next = new ListNode (4);
    l1->next->next->next->next->next->next = new ListNode (7);

    ListNode *l2= new ListNode (1);
    l2->next = new ListNode (1);
    l2->next->next = new ListNode (3); 
    l2->next->next->next = new ListNode (4);
    l2->next->next->next->next = new ListNode (4);
    l2->next->next->next->next->next = new ListNode (4);
    l2->next->next->next->next->next->next = new ListNode (7);


    ListNode *l3= new ListNode (1);
    l3->next = new ListNode (1);
    l3->next->next = new ListNode (3);
    l3->next->next->next = l1->next->next->next;

    cout << isIntersecting (l1, l2) << endl;
    cout << isIntersecting (l1, l3) << endl;
    cout << isIntersecting (l2, l3) << endl;
    
    return 0;
}