// Shaw

#include "list.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>


// constructs a new (empty) list
List *list_create(void) {
    List *l = malloc(sizeof(List));
    l->first = l->last = NULL;
    return l;
}

// counts the items on a list
size_t list_count(const List *list) {
    size_t count = 0;

    ListNode *p=list->first;
    while(p!=NULL) {
        count++;
        p=p->next;
    }
    return count;
}

// inserts item_data at *end* of a list
void list_addlast(List *list, data_t item_data) {
    ListNode* item_to_add = malloc(sizeof(ListNode));
    item_to_add->data = item_data;
    item_to_add->prev = list->last;
    item_to_add->next = NULL;

    if(list->last == NULL){ //pas encore d'elements dans la liste donc list last = NULL
        list->first = item_to_add;
        list->last = item_to_add;
        return;
    }
    list->last->next = item_to_add;
    list->last = item_to_add;
    return;
}

// removes the item from *end* of the list and returns its value
data_t list_rmlast(List *list) {
    if(list==NULL || list_count(list)==0 || list->last == NULL){return -1;}
    ListNode* doomed_node = list->last;

    list->last->prev->next = NULL;
    free(list->last);
    list->last = NULL;

    if(doomed_node->prev != NULL){
        list->last = doomed_node->prev;
    }
    return doomed_node->data;
}

void list_print(List *list){
    if(list->first == NULL){ 
        printf("-- Fin de liste !\n");
        return;
    }
    printf("%d\t", list->first->data);
    List *smaller_list = malloc(sizeof(List));
    smaller_list->first = list->first->next;
    list_print(smaller_list);
}

int main(void) {

    List *l = list_create();

    assert(list_count(l)==0);
    list_addlast(l,10);
    list_addlast(l,20);
    list_addlast(l,30);
    list_addlast(l,40);

    assert(list_count(l)==4);

    list_print(l);

    data_t t =  list_rmlast(l);

    assert(t==40);

    list_print(l);

    return 0;
}