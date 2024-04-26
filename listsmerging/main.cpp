class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) {
            return list2;
        }
        if (list2 == nullptr) {
            return list1;
        }

        ListNode* wrk;
        ListNode* save_list1 = list1;
        ListNode* save_list2 = list2;

        if (save_list1->val < save_list2->val) {
            wrk = new ListNode(save_list1->val);
            save_list1 = save_list1->next;
        } else {
            wrk = new ListNode(save_list2->val);
            save_list2 = save_list2->next;
        }

        ListNode* result = wrk;

        while ((save_list1 != nullptr) && (save_list2 != nullptr)) {
            if (save_list1->val < save_list2->val) {
                wrk->next = new ListNode(save_list1->val);
                save_list1 = save_list1->next;
            } else {
                wrk->next = new ListNode(save_list2->val);
                save_list2 = save_list2->next;
            }
            wrk = wrk->next;
        }

        if (save_list1 != nullptr) {
            wrk->next = new ListNode(save_list1->val, save_list1->next);
        } else if (save_list2 != nullptr) {
            wrk->next = new ListNode(save_list2->val, save_list2->next);
        }
        return result;
    }
};
