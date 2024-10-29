#include <stdio.h>
#include <stdlib.h>

typedef struct dnode{
    int data;
    struct dnode *next , *prev;

}*DNODE;

typedef struct dll {
    DNODE head,tail;
    int size;
}*DLL;

DLL createDLL(){
    DLL d = (DLL) malloc(sizeof(struct dll));
    d->head = d->tail = NULL;
    d->size = 0;
    return d;
}

void printDLL(DLL list){

    DNODE p = list->head;

    while(p!=NULL){
        printf("%d->", p->data);
        p = p->next;
    }
    printf("\n");
    p=list->tail;
    while(p!=NULL){
        printf("%d->", p->data);
        p = p->prev;
    }

    printf("\n(%d)\n", list->size);
}

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

SLL createSLLD(DLL list)
{
    SLL out = (SLL) malloc(sizeof(struct sll));
    if(list==NULL){
        
        out->head = NULL;
        out->size = 0;
        return out;
    }
    
    DNODE temp = list->head;
    
    out->head = (SNODE) malloc(sizeof(struct snode));
    out->head->val = list->head->data;
    out->head->next = NULL;
    out->size = list->size;
    
    SNODE p = out->head;
    temp = temp->next;
    while(temp!= NULL){
        p->next = (SNODE) malloc(sizeof(struct snode));
        p= p->next;
        p->val = temp->data;
        p->next = NULL;

        
        temp = temp->next;
    }

    return out;
}

int main(){
    return 1;
}
