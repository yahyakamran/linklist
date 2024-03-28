#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};
struct Node *first = NULL;

void create(int array[] ,int n){
    int i;
    struct Node *node , *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = array[0];
    first->next = NULL;
    last = first;

    for(int i = 1 ; i < n ; i++){
        node  = (struct Node *)malloc(sizeof(struct Node));
        node->data = array[i];
        node->next = NULL;
        last->next = node;
        last = node;
    }
}

void recussive_display(struct Node *p){
    if(p != 0){
        printf("%d\n",p->data);
        recussive_display(p->next);
    }
}

void display(struct Node *p){
    while (p != 0) {
        printf("%d\n",p->data);
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
        sum += p->data;
        p=p->next;
    }
    return sum;
}

int Rsum(struct Node *p){
    if(!p){
        return 0;
    }else {
        return p->data + Rsum(p->next);
    }
}

int max (struct Node *p){
    int min = -2147483647;
    int max;
    while (p) {
        if(p->data > min){
            max = p->data;
            min = p->data;
        }
        p = p->next;
    }
    return max;
}

int Rmax(struct Node *p){
    int min = -2147483647;
    int max;
    if(!p){
        return min;
    }else {
        int temp = Rmax(p->next);
        return temp>p->data ? temp : p->data;
    }
}

int main(void){
    int array[] = {1,1,82,2,2};
    create(array, 5);
    //display(first);
    //recussive_display(first);
    //printf("%d\n",Rcount(first));
    //printf("%d\n",sum(first));
    //printf("%d\n",Rsum(first));
    //printf("%d\n",max(first));
    printf("%d\n",Rmax(first));
    return 0;
}
