#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Functions already implemented */
struct month *init_months(struct month *head);
void free_months(struct month *head);

/* given month struct */
struct month {
    int month_number;
    char *month_name;
    struct month *next;
};

void print_months(struct month *head) {
    struct month *p = head;
    while (p) {
        printf("Month %d: %s\n", p->month_number, p->month_name);
        p = p->next;
    }
}

struct month *get_previous_month(struct month *head, struct month *m) {
    struct month *p = head;
    while (p) {
        if (p->next == m) {
            return p;
        }
        p = p->next;
    }
}

struct month* swap_month(struct month *head, struct month *a, struct month *b) {
    // If either a or b is NULL, return head
    if (!a || !b) {
        return head;
    }

    // If a and b are the same, no need to swap
    if (a == b) {
        return head;
    }

    // Find the node before a
    struct month *prev_a = NULL;
    struct month *curr = head;
    while (curr && curr != a) {
        prev_a = curr;
        curr = curr->next;
    }

    // Find the node before b
    struct month *prev_b = NULL;
    curr = head;
    while (curr && curr != b) {
        prev_b = curr;
        curr = curr->next;
    }

    // If a or b is not found in the list, return head
    if (!prev_a || !prev_b) {
        return head;
    }

    // Swap the nodes
    if (prev_a) {
        prev_a->next = b;
    } else {
        head = b; // if a is the head node
    }

    if (prev_b) {
        prev_b->next = a;
    } else {
        head = a; // if b is the head node
    }

    struct month *temp = a->next;
    a->next = b->next;
    b->next = temp;

    return head;
}

struct month *selection_sort(struct month *head) {
    struct month *p = head;
    struct month *q = head;
    struct month *min = head;
    while (p) {
        q = p->next;
        min = p;
        while (q) {
            if (q->month_number < min->month_number) {
                min = q;
            }
            q = q->next;
        }
        head = swap_month(head, p, min);
        p = p->next;
    }

    return head;
}

int main(int argc, char *argv[]) {
    /* Init month linked list */
    struct month *head;
    head = init_months(head);

    /* Print the linked list as it is after initialization */
    //print_months(head);

    /* Sort the linked list */
    head = selection_sort(head);
    /* head = selection_sort(head); */
    print_months(head);

    /* Cleanup */
    free_months(head);
    return 0;
}

struct month *init_months(struct month *head) {
    int n = 12;
    int init_order[n];
    char *month_strings[] = {"January",   "February", "March",    "April",
                             "May",       "June",     "July",     "August",
                             "September", "Oktober",  "November", "Dezember"};
    struct month *h;
    struct month *p; /* trailing pointer */

    /* create random order with fisher-yates shuffle */
    for (int i = 0; i < n; ++i) {
        init_order[i] = i + 1;
    }
    srand(time(0));
    for (int i = n - 1; i > 0; --i) {
        int j = rand() % (i + 1); /* generate random index below i */
        /* swap a[i] with a[j] */
        int tmp = init_order[i];
        init_order[i] = init_order[j];
        init_order[j] = tmp;
    }

    /* create month linked list */
    h = malloc(sizeof(struct month)); /* first node, gets returned */
    h->month_number = init_order[0];  /*  */
    h->month_name = month_strings[h->month_number - 1];
    p = h; /* pointer that goes through list */
    for (int i = 1; i < n; ++i) {
        struct month *m = malloc(sizeof(struct month));
        /* printf("create month %d\n", i); */
        m->month_number = init_order[i];
        m->month_name = month_strings[m->month_number - 1];
        p->next = m; /* previous node points now to this */

        p = m; /* increment trailing pointer */
    }
    p->next = NULL;
    return h;
}

void free_months(struct month *head) {
    /* free month linked list */
    struct month *p = head;
    struct month *q = head->next;
    while (q) {
        free(p);
        p = q;
        q = q->next;
    }
    free(p);
}
