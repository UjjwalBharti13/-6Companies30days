/*
delete n nodes after m nodes
  The input list will have at least one element
  Node is defined as

struct Node {
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution {
  public:
    Node* linkdelete(Node* head, int n, int m) {
        // code here
         Node* current = head;

        while (current) {
            // Skip m nodes
            for (int i = 1; i < m && current; ++i) {
                current = current->next;
            }

            // If we've reached the end of the list, break
            if (!current) break;

            // Start deleting the next n nodes
            Node* temp = current->next;
            for (int i = 0; i < n && temp; ++i) {
                Node* toDelete = temp;
                temp = temp->next;
                delete toDelete;
            }

            // Link the m-th node to the node after the deleted nodes
            current->next = temp;

            // Move the current pointer to the next position
            current = temp;
        }

        return head;
    }
};
