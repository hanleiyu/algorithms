#include <iostream>
using namespace std;


struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param head ListNode类 
     * @return ListNode类
     */
    ListNode* formatList(ListNode* head) {
        // write code here
        ListNode* temp = head;
        while(temp != nullptr){
            temp = temp->next;
            if(temp != nullptr){
                ListNode* pre = temp;
                temp = temp->next;
                if(temp != nullptr){
                    pre->next = temp->next;
                    temp->next = head;
                    head = temp;
                    temp = pre;
                }
            }   
        }
        return head;
    }
};