#include <stdio.h>
#include <stdlib.h>
typedef struct snode {
    int val;
    struct snode*next;
}*SNODE;

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

void printSLL(SLL sll){

    SNODE p = sll->head;

    while(p != NULL){
        printf("%d ", p->val);
        p = p->next;
    }
    printf("\n");
}

void addFirst(SLL sll, int val){
    SNODE p = sll->head;

    if(p == NULL){
        SNODE q = (SNODE) malloc(sizeof(struct snode));
        q->val = val;
        q->next = NULL;
        sll->head = q;
        sll->size++;
    } else {
        SNODE q = (SNODE) malloc(sizeof(struct snode));
        q->val = val;
        q->next = p;
        sll->head = q;
        sll->size++;
    }
}

void addLast(SLL sll, int val){

    SNODE p = sll->head;

    if(p == NULL){
        SNODE q = (SNODE) malloc(sizeof(struct snode));
        q->val = val;
        q->next = NULL;
        sll->head = q;
        sll->size++;
    } else {
        SNODE q = (SNODE) malloc(sizeof(struct snode));
        q->val = val;
        q->next = NULL;

        while(p->next != NULL){
            p = p->next;
        }

        p->next = q;
        sll->size++;
    }
}

void delVal(SLL sll, int val){

    while(sll->head != NULL && sll->head->val == val){
        SNODE q = sll->head;
        sll->head = sll->head->next;
        free(q); 
        sll->size--;    
    }

    if(sll->head == NULL)
        return;

    SNODE p = sll->head;

    while(p != NULL && p->next != NULL){
        if(p->next->val == val){
            SNODE q = p->next;
            p->next = p->next->next;
            free(q);
            sll->size--;
        } else {
            p = p->next;
        }
    }
}


void addValBetXY(SLL sll, int val,int x, int y){
    SNODE p = sll->head;


    while(p!=NULL && p->next->next != NULL){
        if(p->val == x && p->next->val == y){
            SNODE new = (SNODE) malloc(sizeof(struct snode));
            new->val = val;
            new->next = p->next;
            p->next = new;
            p = p->next;  
        }
        p = p->next;
    }
}

int main(){
    SLL sll = createSLL();

    addLast(sll, 1);
    addLast(sll, 3);
    addLast(sll, 4);
    addLast(sll, 5);
    printSLL(sll);

    addValBetXY(sll, 2,1,3);

    printSLL(sll);

}