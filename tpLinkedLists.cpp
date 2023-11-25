#include<stdio.h>
#include<stdlib.h>

typedef struct element {
    int data;
    struct element* next;
} element;

// Function to create an empty list
element* creeListeVide() {
    return NULL;
}

// Function to add an element at the beginning of the list
element* ajoutDebut(element* head, int newdata) {
    element* newElement = (element*)malloc(sizeof(element));
    newElement->data = newdata;
    newElement->next = head;
    return newElement;
}

// Function to delete the first element of the list
element* suprimmeDebut(element* head) {
    if (head == NULL) {
        printf("The list is empty; nothing to be deleted.\n");
    } else {
        element* curr = head->next;
        free(head);
        return curr;
    }
}

// Function that returns the number of elements in the list
int taille(element* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

// Function to add an element at a specific position in the list
element* ajoutAuPosition(element* head, int newdata, int position) {
    if (position < 0 || position > taille(head)) {
        return head;
    }

    if (position == 0) {
        return ajoutDebut(head, newdata);
    }

    element* curr = head;
    for (int i = 0; i < position - 1; i++) {
        curr = curr->next;
    }

    element* newElement = (element*)malloc(sizeof(element));
    newElement->data = newdata;
    newElement->next = curr->next;
    curr->next = newElement;
    return head;
}

// Function to print the data of any position in the list
int positionData(element* head, int position) {
    if (position < 0 || position >= taille(head) || head == NULL) {
        printf("The position you want to get data from is invalid.\n");
        return -1; 
    }

    for (int i = 0; i < position; i++) {
        head = head->next;
    }

    return head->data;
}

// Function to print the data of all elements in the list
void afficher(element* head) {
    while (head != NULL) {
        printf("%d\n", head->data);
        head = head->next;
    }
}

int main() {
    int choice,data,position;
    element* head = creeListeVide();
     printf("\nChoose which function you want to call:\n");
        printf("1. Add an element at the beginning of the linked list\n");
        printf("2. Add an element at a specific position in the linked list\n");
        printf("3. Print all elements in the linked list\n");
        printf("4. Get data of an element at a specific position\n");
        printf("5. Delete the first element of the linked list\n");
        printf("6. Get the number of elements in the linked list\n");
        printf("0. Exit\n");

    do {
       
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 0:
            printf("Exiting the program. Goodbye!\n");
            break;
       case 1:          
            printf("Enter the data you want to put in the element: ");
            scanf("%d", &data);
            head = ajoutDebut(head, data);
            printf("Element added successfully.\n");

            break;

        case 2:
            
            printf("Enter the position where you want to create an element: ");
            scanf("%d", &position);
            printf("Enter the data you want to put in the element: ");
            scanf("%d", &data);
            head = ajoutAuPosition(head, data, position);
            printf("Element added successfully.\n");

            break;

       case 3:
            printf("The linked list elements are:\n");
            afficher(head);
            break;
        case 4:
            printf("Enter the position you want to get its element data: ");
            scanf("%d", &position);
            printf("The data at position %d is: %d\n", position, positionData(head, position));
            break;

        case 5:
            head = suprimmeDebut(head);
            printf("Element deleted successfully.\n");
            break;

        case 6:
            printf("The number of elements in the linked list is: %d\n", taille(head));
            break;
            
        default:
            printf("Invalid choice. Please enter a valid option.\n");
            break;
        }
    } while (choice != 0);
    return 0;
}
