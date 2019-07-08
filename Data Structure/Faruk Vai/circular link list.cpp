#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int info;
} DATA;

typedef struct node {
    DATA data;
    struct node *next;
} NODE;

void insert(NODE *pointer, DATA data) {
    NODE *start = pointer;
    while (pointer->next != start) {
        pointer = pointer -> next;
    }
    pointer->next = (NODE *) malloc(sizeof (NODE));
    pointer = pointer->next;
    pointer->data = data;
    pointer->next = start;
}

int find(NODE *pointer, DATA key) {
    NODE *start = pointer;
    pointer = pointer -> next;
    while (pointer != start) {
        if (pointer->data.info == key.info) {
            return 1;
        }
        pointer = pointer -> next;
    }
    return 0;
}

void delete(NODE *pointer, DATA data) {
    NODE *temp;
    NODE *start = pointer;
    while (pointer->next != start &&
            (pointer->next)->data.info != data.info) {
        pointer = pointer -> next;
    }
    if (pointer->next == start) {
        printf("Element %d is not present in the list\n", data.info);
        return;
    }
    temp = pointer -> next;
    pointer->next = temp->next;
    free(temp);
    return;
}

void print(NODE *start, NODE *pointer) {
    if (pointer == start) {
        return;
    }
    printf("\n%d ", pointer->data.info);
    print(start , pointer->next);
}

int main() {
    int i, status;
    DATA data;
    NODE *start, *temp;
    start = (NODE *) malloc(sizeof (NODE));
    temp = start;
    temp -> next = start;

    for (i = 0; i < 20; i++) {
        data.info = i;
        insert(start, data);
    }
    do {
        printf("What would you like to do ?\n");
        printf("\t1 - Delete a node\n");
        printf("\t2 - Print the list\n");
        printf("\t3 - Search in the list\n");
        printf("\t4 - Quit\n");
        scanf("%d", &i);
        switch (i) {
            case 1: // DELETE
                printf("\nEnter data to delete:\n");
                scanf("%d", &data.info);
                delete(start, data);
                break;
            case 2: //print
                printf("The list is ");
                print(start, start->next);
                printf("\n");
                break;
            case 3: //find
                printf("\nEnter data to find:\n");
                scanf("%d", &data.info);
                status = find(start, data);
                if (status) {
                    printf("Element Found\n");
                } else {
                    printf("Element Not Found\n");
                }
        }
    } while (i < 4);

    return EXIT_SUCCESS;
}
