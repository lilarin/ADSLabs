//
// Created by User on 20.06.2022.
//

#ifndef MAIN_CPP_ADDITIONASTASKS_H
#define MAIN_CPP_ADDITIONASTASKS_H

ListNode* reverse(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    ListNode* node = head;
    ListNode* nextNode = head->next;
    head->next = nullptr;

    while (nextNode != nullptr) {
        ListNode* temp = nextNode->next;
        nextNode->next = node;
        node = nextNode;
        nextNode = temp;
    }
    return node;
}

int hasCycle(ListNode *head) {
    ListNode* turtle = head;
    ListNode* rabbit = head;
    while (rabbit != nullptr && rabbit->next != nullptr) {
        turtle = turtle->next;
        rabbit = rabbit->next->next;
        if (turtle == rabbit) {
            return 1;
        }
    }
    return 0;
}

#endif //MAIN_CPP_ADDITIONASTASKS_H
