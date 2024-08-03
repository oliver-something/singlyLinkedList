#include <stdio.h>
#include "linked_list.h"

int main(void) {
    Path path = {NULL}; // Initialize an empty path

    // Add nodes to the path
    const int value1 = 10;
    const int value2 = 23;
    const int value3 = 67;
    const int value4 = 78;
    const int value5 = 12;
    const int value6 = 89;

    addNode(&path, &value1, sizeof(int));
    addNode(&path, &value2, sizeof(int));
    addNode(&path, &value3, sizeof(int));
    addNode(&path, &value4, sizeof(int));
    addNode(&path,  &value5, sizeof(int));

    // Traverse the path and print the data
    const Node *current = path.node;
    while (current != NULL) {
        printf("Item: %d\n", *(int *)current->data);
        current = current->next;
    }

    const int valueToRemove = 23;
    const int removed = removeNode(&path, &valueToRemove, sizeof(int));
    if (removed) {
        printf("\nNode with value %d removed.\n", valueToRemove);
    } else {
        printf("\nNode with value %d not found.\n", valueToRemove);
    }
    // Deallocate the memory used by the path

    addNode(&path, &value2, sizeof(int));
    insertFirst(&path, &value6, sizeof(int));

    const Node *currentNode = path.node;
    while (currentNode != NULL) {
        printf("Item: %d\n", *(int *)currentNode->data);
        currentNode = currentNode->next;
    }

    freePath(&path);
    return 0;
}