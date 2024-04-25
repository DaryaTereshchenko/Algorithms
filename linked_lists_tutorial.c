#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    struct node *next;
};


void print_list(struct node *head){
    struct node *p = head;
    while(p != NULL){
        printf("%d\t", p->val);
        p = p->next;
    }
}

void free_months(struct node *head) {
    /* free month linked list */
    struct node *p = head;
    struct node *q = head->next;
    while (q) {
        free(p);
        p = q;
        q = q->next;
    }
    free(p);
}


void count_of_nodes(struct node *head){
     int count = 0;
     struct node *p = head;
     if(head == NULL){
        printf("Linked list is ampty");
     }
     while(p != NULL){
        count ++;
        p = p->next;
     }
     printf("Count %d", count);
}


struct node *get_previous_month(struct node *head, struct node *a) {
    struct node *p = head;
    if (p == NULL || a == NULL){
        return NULL;
    }else if (p->next == a){
        return p;
    }

    while(p->next != a){
        p = p->next;
    }
    return p;
}

void swap(struct node *head, struct node *a, struct node *b){
    struct node *a_prev = get_previous_month(head, a);
    struct node *b_prev = get_previous_month(head, b);
    struct node *tmp = b->next;
    
    if(a_prev == head){
        a_prev->next = b;
        b->next = a->next;
        a->next = tmp;
        b_prev->next = a;
    }
    if(head == a){
        if(a->next == b){
            a->next = b->next;
            b_prev->next = a;
        } else {
            struct node *tmp_a_next = a->next;
            a->next = b->next;
            b->next = tmp_a_next;
            b_prev->next = a;
        }
    }
    head = b;

}

int main(){
    struct node *head = malloc(sizeof(struct node));
    head->val = 95;
    head->next = NULL;

    struct node *current = malloc(sizeof(struct node));
    current->val = 60;
    current->next = NULL;
    head->next = current;

    current = malloc(sizeof(struct node));
    current->val = 48;
    current->next = NULL;
    head->next->next = current;

    current = malloc(sizeof(struct node));
    current->val = 75;
    current->next = NULL;
    head->next->next->next = current;

    current = malloc(sizeof(struct node));
    current->val = 88;
    current->next = NULL;
    head->next->next->next->next = current;

    current = malloc(sizeof(struct node));
    current->val = 15;
    current->next = NULL;
    head->next->next->next->next->next = current;

    struct node *a = head;
    struct node *b = head->next->next;

    swap(head, a, b);
    print_list(head);

        // Free the memory
    while(head != NULL) {
        struct node *temp = head;
        head = head->next;
        free(temp);
    }
}
