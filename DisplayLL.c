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

void recussive_display(struct Node *p){
    if(p != 0){
        printf("%d\n",p->date);
        recussive_display(p->next);
    }
}

void display(struct Node *p){
    while (p != 0) {
        printf("%d\n",p->date);
        p = p->next;
    }
}

int Rcount(struct Node *p){
    if(!p){
        return 0;
    }else {
        return 1 + Rcount(p->next);
    }
}

int count(struct Node *p){
    int i = 0;
    while(p){
        ++i;
        p = p->next;
    }
    return i;
}

int sum (struct Node *p){
    int sum = 0;
    while (p) {
        sum += p->date;
        p=p->next;
    }
    return sum;
}

int main(void){
    int array[] = {1,1,2,2,2};
    create(array, 5);
    //display(first);
    //recussive_display(first);
    //printf("%d\n",Rcount(first));
    printf("%d\n",sum(first));
    return 0;
}
