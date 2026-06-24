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
class compare {
    public: 
    bool operator()(ListNode* a, ListNode* b){
        return a->val>b->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,
        vector<ListNode*>, compare> pq;
        ListNode* ans = new ListNode(0);
        ListNode* temp = ans;
        int n = lists.size();
        for(int i=0; i<n; i++){
            if(lists[i]!=nullptr) 
            pq.push(lists[i]);
        }
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            temp->next= it;
            temp = temp->next;
            if(it->next!= nullptr){
                pq.push(it->next);
            }
        }
        return ans->next;
    }
};