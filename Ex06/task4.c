#include <stdio.h>
#include <stdlib.h>



struct node{
    int val;
    struct node *next;
    struct node *prev;
};

struct node *reverse(struct node *head){
    struct node *current = head;
    struct node *tmp = NULL;

    if (head == NULL || head->next == NULL) /* check for empty list or one elemement lists */
        return head;

    while(current != NULL){
        printf("current %d\n", current->val);
        tmp = current->prev;
        current->prev = current->next;
        current->next = tmp;
        current = current->prev;
    }

    return tmp->prev;  
}


void printList(struct node* node)
{
    while (node != NULL) {
        printf("%d ", node->val);
        node = node->next;
    }
}

int main() {
    /* Init list */
    struct node* head = NULL;
    struct node* second = NULL;
    struct node* third = NULL;
    struct node* fourth = NULL;

    head = (struct node*)malloc(sizeof(struct node));
    second = (struct node*)malloc(sizeof(struct node));
    third = (struct node*)malloc(sizeof(struct node));
    fourth = (struct node*)malloc(sizeof(struct node));

    head->val = 1;
    head->next = second;
    /* head->next = NULL; */
    head->prev = NULL;

    second->val = 2;
    second->next = third;
    second->prev = head;

    third->val = 3;
    third->next = fourth;
    third->prev = second;

    fourth->val = 5;
    fourth->next = NULL;
    fourth->prev = third;

    printf("Original Doubly linked list:\n");
    printList(head); printf("\n");

    /* REVERSING CALL(S) */
    head = reverse(head);       /* assign new head */
    /* head = reverseRecursive(head); */

    printf("\nReversed Doubly linked list \n");
    printList(head);
    printf("\ndone\n");

            // Free the memory
    while(head != NULL) {
        struct node *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
