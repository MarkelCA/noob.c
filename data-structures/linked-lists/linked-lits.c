#include <stdlib.h>
#include <stdio.h>

typedef  struct node 
{
    int data;
    struct node * next;
}node;

node * createLinkedList(int n);
void displayList();

int main() 
{
    int n = 0;
    node * HEAD = NULL;
    printf("\nHow many nodes: ");
    scanf("%d", &n);
    HEAD = createLinkedList(n);
    puts("This is your linked list: ");
    displayList(HEAD);

    return 0;
}

node * createLinkedList(int n)
{
    node * head = NULL;
    node * new = NULL;
    node * p = NULL;

    for(int i = 0 ; i < n ; i++)
    {
        // let us create individual isolated data
        new = (node*)malloc(sizeof(node));
        printf("Enter the data for the number %d: ", i+1);
        scanf("%d", &(new->data));
        new -> next = NULL;

        // if the list is empty we set as the head
        if(!head){
            head = new;
        }
        // if its not we iterate till we finish and we put it after que last element
        else {
            p = head;
            while (p->next) 
                p = p->next; // go for the last element and atach the temporal value
            p->next = new;
        }
    }
    return head;
// 23->56->32->NULL    65->NULL
}
void displayList(node * head){

    node * p = head;
    /*printf("%d", p->data);*/

    while (p) {
        printf("%d -> ",p->data);
        p = p->next;
    }
}
