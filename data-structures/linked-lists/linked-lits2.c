#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node * next;
}node;

node * createLinkedList(int length); 
void displayList(node *);

int main() {

    int n = 0;
    puts("How many elements does your list have: ");
    scanf("%d", &n);
    node * HEAD = createLinkedList(n);
    displayList(HEAD);
    return 0;
}

node * createLinkedList(int length)
{
    node * head = NULL;
    node * new = NULL;
    node * p = NULL;

    for (int i = 0 ; i < length ; i++) {

        new = (node*)malloc(sizeof(node));

        printf("Value for index %d: ", i+1);
        scanf("%d", &(new->data));
        new -> next = NULL;

        if(!head)
            head = new;
        else {
            p = head;
            while (p->next) 
                p = p -> next;
            p->next = new;
        }

    }
    // 45->6->34->
    return head;
}
void displayList(node * list){
    node * p = list;

        while (p) {
            printf("%d -> ", p->data);
            p = p->next;

        }
        
}
