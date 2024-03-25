#include <stdio.h>
#include <stdlib.h>

struct Node {
    int date;
    struct Node *next;
};
struct Node *first = NULL;

void create(int array[] ,int n){
    int i;
    struct Node *node , *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->date = array[0];
    first->next = NULL;
    last = first;

    for(int i = 1 ; i < n ; i++){
        node  = (struct Node *)malloc(sizeof(struct Node));
        node->date = array[i];
        node->next = NULL;
        last->next = node;
        last = node;
    }
}

void display(struct Node *p){
    while (p != 0) {
        printf("%d\n",p->date);
        p = p->next;
    }
}

int main(void){
    int array[] = {1,4,32,22,42};
    create(array, 5);
    display(first);
    return 0;
}
