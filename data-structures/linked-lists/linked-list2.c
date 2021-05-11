#include <stdio.h>
#include <stdlib.h>

typedef struct Single  {
    int data;
    struct Single *next;
}single_link;

typedef struct Double{
    int data;
    struct Double *next;
    struct Double *prev;
}double_link;

void prepend(int num, single_link **head);
void printDoubleList(double_link *head);
void single_append(int num, single_link **head);
void append(int num, double_link **head);
void printSingleList(single_link *head);

int main() {

    // This creates an LIFO data structure
    single_link * single_head = NULL;
    prepend(1, &single_head);
    prepend(3, &single_head);
    prepend(5, &single_head);
    single_append(343, &single_head);
    single_append(666, &single_head);
    single_append(123, &single_head);
    printSingleList(single_head);
    puts("");

    // This creates a FIFO data structure
    double_link *double_head = NULL;
    append(1, &double_head);
    append(2, &double_head);
    append(4, &double_head);
    printDoubleList(double_head);
return 0;
}

void printSingleList(single_link *head){
    single_link * p = head;
    while (p) {
        printf("%d -> ", p->data);
        p = p->next;
    }
}
void printDoubleList(double_link *head){
    double_link * p = head;
    while (p) {
        printf("%d -> ", p->data);
        p = p->next;
    }
}
void prepend(int num, single_link **head)
{
    single_link *new = NULL;
    new = (single_link*)malloc(sizeof(single_link));
    new->data = num;
    new->next = *head;
    *head = new;
}

void append(int num, double_link **head) 
{
    double_link *last = *head;
 
    double_link *new = (double_link*)malloc(sizeof(double_link*));
    new->data = num;
    new->next = NULL;
 
    /* If the Linked List is empty, then make the new node as head */
    if (*head == NULL) {
        new->prev = NULL;
        *head = new;
        return;
    }
 
    /* Else traverse till the last node */
    while (last->next != NULL)
        last = last->next;
 
    /* Change the next of last node */
    last->next = new;
 
    /* Make last node as previous of new node */
    new->prev = last;
}

void single_append(int num, single_link **head) 
{
    single_link *last = *head;
 
    single_link *new = (single_link*)malloc(sizeof(single_link*));
    new->data = num;
    new->next = NULL;
 
    /* If the Linked List is empty, then make the new node as head */
    if (*head == NULL) {
        *head = new;
        return;
    }
 
    /* Else traverse till the last node */
    while (last->next != NULL)
        last = last->next;
 
    /* Change the next of last node */
    last->next = new;
}
