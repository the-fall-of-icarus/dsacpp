#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;

        // Step 1: Detect if a cycle exists using Floyd’s Tortoise and Hare
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                // ✅ Cycle is detected
                slow = head;

                // Step 2: Find the node where the cycle begins
                while (slow != fast) {
                    slow = slow->next;
                    prev = fast;
                    fast = fast->next;
                }

                // ✅ Removing the cycle by making the last node point to NULL
                if (prev != NULL) prev->next = NULL;

                // ✅ Returning the node where the cycle begins
                return slow;
            }
        }

        // No cycle
        return NULL;
    }
};

// Helper function to print the linked list
void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// Test case in main
int main() {
    // Creating nodes
    ListNode* head = new ListNode(3);
    ListNode* node1 = new ListNode(2);
    ListNode* node2 = new ListNode(0);
    ListNode* node3 = new ListNode(-4);

    // Linking nodes
    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node1;  // ⚠️ Creating a cycle pointing back to node1

    Solution sol;
    ListNode* loopNode = sol.detectCycle(head);

    if (loopNode) {
        cout << "Cycle detected at node with value: " << loopNode->val << endl;
        cout << "After removing cycle, the list becomes:\n";
        printList(head);  // Now the cycle is removed
    } else {
        cout << "No cycle found in the list." << endl;
    }

    return 0;
}
