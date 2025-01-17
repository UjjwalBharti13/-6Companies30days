/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* merge(ListNode* a, ListNode* b){
         ListNode* c = new ListNode(-1);
            ListNode* temp = c;
            while(a!=NULL && b!=NULL){
                if(a->val<=b->val){
                    temp->next=a;
                     a=a->next;
                     temp= temp->next;

                }else {
                    temp->next=b;
                    b=b->next;
                    temp=temp->next;
                }
            }
            if(a==NULL){
                temp->next=b;
            } else {
                temp->next=a;
            }
            return c->next;        
}

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL;
        while(lists.size()>1){
            ListNode* a = lists[lists.size()-1];
            lists.pop_back();
            ListNode* b = lists[lists.size()-1];
            lists.pop_back();
            ListNode* c = merge(a,b);
            lists.push_back(c);
        }
        return lists[0];
    }
};
