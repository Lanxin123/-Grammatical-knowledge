/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
	vector<int> printListFromTailToHead(ListNode* head) {
		
		stack<int> temp;
		vector<int>tailtohead;
		while (head!=NULL)
		{
			temp.push(head->val);
			head = head->next;
		}
		while (!temp.empty())
		{
			tailtohead.push_back(temp.top());
			temp.pop();
		}
        return tailtohead;
	}
};