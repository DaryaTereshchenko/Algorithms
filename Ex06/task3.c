#include <stdio.h>
#include <stdlib.h>

struct node{
    int val; 
    struct node *next;
    struct node *prev;
};

void printList(struct node *head) {
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

struct node *merge(struct node *list1, struct node *list2) {

    if (list1 == NULL) {
        return list2;
    } else if (list2 == NULL) {
        return list1;
    }

    /* pointer to the head of the new merged list */
    struct node *head = malloc(sizeof(struct node));
    head->next = NULL;
    head->prev = NULL;

    /* traveling pointers */
    struct node *headMerged = head;      /* for the merge list */
    struct node *runner1 = list1;    /* for the list 1 */
    struct node *runner2 = list2;    /* for the list 2 */

    /* while both lists have elements */
    while (runner1!=NULL && runner2!=NULL) {
        if (runner1->val <= runner1->val) {
            headMerged->next = runner1;       /* link p1 to merged trailing */
            runner1->prev = headMerged;
            runner1 = runner1->next;      /* move traveling p1 */
        } else {
            headMerged->next = runner2;       /* link p2 to merged trailing */
            runner2->prev =headMerged;
            runner2 = runner2->next;      /* mvoe traveling p2 */
        }
        headMerged = headMerged->next;            /* move traveling p of merged to recently added */
    }

    /* once one list is finished, handle remaining in the other */
    /* AHA: no list is needed */
    /* AHA: here also if, because might finish at the same time */
    if (runner1 != NULL) {
        headMerged->next = runner1;
        runner1->prev = headMerged;
    } else if (runner2 != NULL) {
        headMerged->next = runner2;
        runner2->prev = headMerged;
    }

    /* return pointer to new head */
    return head->next;
}


int main(int argc, char *argv[]){
    struct node *list1 = NULL;
    struct node *list2 = NULL;

    /* populate the lists with sorted values */
    int list1Values[] = {1, 3, 5, 7, 9};
    int list2Values[] = {2, 4, 6, 8, 10};
    /* fill in reversed order to not loose the head list1 or list2 */
    for (int i = 4; i >= 0; --i) {
        struct node *newNode = malloc(sizeof(struct node));
        newNode->val = list1Values[i];
        newNode->next = list1;
        newNode->prev = NULL;
        if (list1 != NULL) {
            list1->prev = newNode;
        }
        list1 = newNode;
    }
    for (int i = 4; i >= 0; --i) {
        struct node *newNode = malloc(sizeof(struct node));
        newNode->val = list2Values[i];
        newNode->next = list2;
        newNode->prev = NULL;
        if (list2 != NULL) {
            list2->prev = newNode;
        }
        list2 = newNode;
    }

    printf("List 1: ");
    printList(list1);

    printf("List 2: ");
    printList(list2);

    struct node *mergedList = merge(list1, list2);
    printf("Merged List: ");
    printList(mergedList);

    /* free */
    struct node *tmp;
    while (mergedList != NULL) {
        tmp = mergedList;
        mergedList= mergedList->next;
        free(tmp);
    }
    return 0;
}