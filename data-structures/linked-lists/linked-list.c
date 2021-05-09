#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node * next;
    void (*add)(struct Node * n, int pos, int data);
}node;

node * createLinkedList(int length); 
void displayList(node *);
void add_at(struct Node * n, int pos, int data);
void app();

int main() {

    app();
    return 0;
}
void app() {
    int n = 0;
    puts("How many elements does your list have: ");
    scanf("%d", &n);
    node * HEAD = createLinkedList(n);
    displayList(HEAD);


    while (1) {
        int elem = 0;
        int index = 0;
        fputs("\nInsert one element please: ", stdout);
        scanf("%d", &elem);
        fputs("\nIndex one element please: ", stdout);
        scanf("%d", &index);

        HEAD->add(HEAD, index, elem);
        printf("HEAD: %d\n", HEAD->data);
        printf("%p\n",HEAD);
        puts("");
        displayList(HEAD);
    }
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
    head->add = add_at;
    return head;
}
void displayList(node * list){
    node * p = list;

        while (p) {
            printf("%d -> ", p->data);
            p = p->next;

        }
        
}
void add_at(struct Node * head, int pos, int data) 
{
    node * new = (node*)malloc(sizeof(node));
    new->data = data;
    new->next = NULL;

    if (!head) {
        head = new;
        return;
    }

    // Only if it's not empty
    int count = 0;
    node * p = head;
    node * temp = NULL;

    printf("%p\n\n",head);
    if (pos == 0) {
        temp = head;
        new->next = temp;
        head = new;
        printf("\n%p\n",head);
        printf("%d\n",temp->next->data);
        printf("%d\n",new->data);
    }
    printf("\n%p\n",head);

    while (p) 
    {
        // 45->6->34->3->34
        if (count + 1 == pos) 
        {
            if(!p->next) // If its the last one
            {
                new->next = NULL; // NULL
            }
            else
            {
                temp = p->next; // NULL
                new->next = temp; // NULL
            }

            p->next = new;
        }

        p = p->next;
        count++;
    }

}
