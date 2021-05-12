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
    while (1) {
        int n = 0;
        puts("\nHow many elements does your list have: ");
        scanf("%d", &n);

        if (n <= 0 ){
            printf("\nNumbers below or equal 0 are not valid");
            continue;
        }

        node * HEAD = createLinkedList(n);
        displayList(HEAD);

        while (1) {

            printf("\n%p",HEAD);

            int elem = 0;
            int index = 0;

            fputs("\nInsert one element please: ", stdout);
            scanf("%d", &elem);

            fputs("\nIndex one element please: ", stdout);
            scanf("%d", &index);

            printf("%p\n",HEAD);
            HEAD->add(HEAD, index, elem);

            puts("");
            displayList(HEAD);

            printf("\n%p",HEAD);
        }
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
void remove_at(struct Node * head, int pos, int data) {
    //header
    node * temp = malloc(sizeof(node));
    temp = head->next; 

    *head = *temp;
}

    
void add_at(struct Node * head, int pos, int data) 
{
    node * new = (node*)malloc(sizeof(node));
    node * temp = malloc(sizeof(node));
    new->data = data;
    new->next = NULL;

    if(!pos)
   {
        new->next = malloc(sizeof(node));
        *new->next = *head; 
        *head = *new;
       
        printf("%p\n",head);

       return;
   }

    // Only if it's not empty
    int count = 0;
    node * p = head;
    /*temp = NULL;*/

    printf("%p\n\n",head);
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

