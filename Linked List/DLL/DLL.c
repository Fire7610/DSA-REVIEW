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

void addFirst(DLL list, int data){
    if(list->head == NULL){
        DNODE d = (DNODE) malloc(sizeof(struct dnode));
        d->data = data;
        d->next = d->prev = NULL;
        list->size++;
        list->head = list->tail = d;
        return;
    } else {
        DNODE d = (DNODE) malloc(sizeof(struct dnode));
        d->data = data;
        d->next = list->head;
        list->head->prev = d;
        d->prev = NULL;
        list->head = d;
        list->size++;
    }
}

void addLast(DLL list, int data){
    if(list->head == NULL){
        DNODE d = (DNODE) malloc(sizeof(struct dnode));
        d->data = data;
        d->next = d->prev = NULL;
        list->size++;
        list->head = list->tail = d;
        return;
    } else {
        DNODE d = (DNODE) malloc(sizeof(struct dnode));
        d->data = data;
        d->prev = list->tail;
        list->tail->next = d;
        d->next = NULL;

        list->tail = d;
        list->size++;
    }
}

void delElem(DLL list, int data){
    if(list->head == NULL){
        return;
    }

    while(list->head->data == data){
        DNODE d = list->head;
        list->head = list->head->next;
        list->head->prev = NULL;
        free(d);
        list->size--;
    }
    
    while(list->tail->data == data){
        DNODE d = list->tail;
        list->tail = list->tail->prev;
        list->tail->next = NULL;
        free(d);
        list->size--;
    }


    DNODE d = list->head;

    while(d->next != NULL){
        if(d->next->data == data){
            DNODE p = d->next;
            d->next = d->next->next;
            if (d->next != NULL) {
            d->next->prev = d;
            }
            free(p);
            list->size--;
        } else {
            d = d->next;
        }
    }
}

int main(){
    DLL list = createDLL();
    

    addFirst(list, 3);
    addFirst(list, 2);
    addFirst(list, 1);
    addLast(list, 4);
    addLast(list, 5);
    printDLL(list);

    delElem(list,1);
    printDLL(list);
    delElem(list,5);
    printDLL(list);
    delElem(list,3);
    printDLL(list);

}


