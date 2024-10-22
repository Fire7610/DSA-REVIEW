#include <stdio.h>
#include <stdlib.h>
typedef struct ListNode {
    int val;
    struct ListNode *next;
    }*SNODE;

SNODE createList(){
    return NULL;
}

typedef struct sll{
    SNODE head;
    int size;
}*SLL;

SLL createSLL(){
    SLL x = (SLL) malloc(sizeof(struct sll));
    x->head = NULL;
    x->size = 0;
    return x;
}

void addLast(SNODE* l2, int newData){
    SNODE new = (SNODE) malloc(sizeof(struct ListNode));
    new->val = newData;
    new->next = NULL;


    if(*l2 == NULL){
        *l2 = new;
        return;
    }
    SNODE Last = *l2;
    while(Last->next!=NULL){
        Last = Last->next;
    }
    Last->next = new;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* temp = (struct ListNode*) malloc(sizeof(struct ListNode));
    struct ListNode* temp1 = temp;
    int carry = 0;  

    while(l1 != NULL || l2 != NULL){
        int x = (l1 != NULL) ? l1 -> val : 0;
        int y = (l2 != NULL) ? l2 -> val : 0;
        
        int sum = x+y+carry;
        carry = sum/10;
        temp1->val = sum%10;
        
        if (l1!=NULL) l1 = l1->next;
        if (l2!=NULL) l2 = l2->next;

        if(l1 != NULL||l2 != NULL){
            temp1->next = (struct ListNode*) malloc(sizeof(struct ListNode));
            temp1 = temp1->next;
        }
        else
            temp1->next = NULL;        
    }
    if(carry > 0){
        temp1 -> next = (struct ListNode*) malloc(sizeof(struct ListNode));
        temp1 = temp1->next;
        temp1 -> val = carry;
        temp1->next = NULL;
    }
    
    return temp;
}

void print(SNODE l1){
    while(l1 != NULL){
        printf("%d ", l1->val);
        l1 = l1->next;
    }
    //printf("\n");
}

int main(){
    SNODE l1 = createList();
    SNODE l2 = createList();
    addLast(&l1, 1);
    addLast(&l1, 2);
    addLast(&l1, 3);
    
    addLast(&l2, 1);
    addLast(&l2, 2);
    addLast(&l2, 3);
    
    SNODE l3 = createList();
    l3 = addTwoNumbers(l1,l2);
    
    print(l3);
}