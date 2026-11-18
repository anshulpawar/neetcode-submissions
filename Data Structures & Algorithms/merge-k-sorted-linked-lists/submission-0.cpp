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
struct compare {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> p;
        // push head of all linked list
        for(int i=0; i<lists.size(); i++)
        {
            if(lists[i] != nullptr)
                p.push(lists[i]);
        }
        
        if(p.empty()) return nullptr;

        ListNode* head = new ListNode(p.top()->val);

        if(p.top()->next != nullptr)
            p.push(p.top()->next);
        p.pop();

        ListNode* temp = head;
        while(!p.empty())
        {
            temp->next = p.top();

            if(p.top()->next != nullptr)
                p.push(p.top()->next);  
            p.pop();

            temp = temp->next;
        }

        return head;
        
    }
};