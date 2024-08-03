//
// Created by Oliver on 8/3/24.
//

#include "linked_list.h"
#include <stdio.h>
#include <string.h>

void addNode(Path *path, const void *data, const size_t size) {
    // Allocate memory for the new node
    Node *newNode = malloc(sizeof(Node));
    if (newNode == NULL) {
        perror("Failed to allocate memory for new node");
        return;
    }

    // Allocate memory for the node's data
    newNode->data = malloc(size);
    if (newNode->data == NULL) {
        perror("Failed to allocate memory for node data");
        free(newNode); // Free the node itself if data allocation fails
        return;
    }

    // Copy the data to the node
    memcpy(newNode->data, data, size);
    newNode->size = size;
    newNode->next = NULL;

    // If the path is empty, the new node becomes the first node
    if (path->node == NULL) {
        path->node = newNode;
    } else {
        // Traverse to the end of the list and add the new node
        Node *current = path->node;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

int removeNode(Path *path, const void *data, const size_t size) {
    if (path->node == NULL) {
        return 0; // No nodes to remove
    }

    Node *current = path->node;
    Node *previous = NULL;

    // Traverse the list to find the node to remove
    while (current != NULL) {
        if (current->size == size && memcmp(current->data, data, size) == 0) {
            // Found the node to remove
            if (previous == NULL) {
                // The node to remove is the first node
                path->node = current->next;
            } else {
                // The node to remove is not the first node
                previous->next = current->next;
            }

            // Free the memory used by the node
            free(current->data);
            free(current);
            return 1; // Node removed successfully
        }

        previous = current;
        current = current->next;
    }

    return 0; // Node not found
}

Node* popLastNode(Path *path) {
    if (path->node == NULL) {
        return NULL; // No nodes to pop
    }

    Node *current = path->node;
    Node *previous = NULL;

    // Traverse to the last node
    while (current->next != NULL) {
        previous = current;
        current = current->next;
    }

    // If the last node is also the first node
    if (previous == NULL) {
        path->node = NULL;
    } else {
        previous->next = NULL;
    }

    // Return the last node
    return current;
}

void insertFirst(Path *path, const void *data, const size_t size) {
    // Allocate memory for the new node
    Node *newNode = malloc(sizeof(Node));
    if (newNode == NULL) {
        perror("Failed to allocate memory for new node");
        return;
    }

    // Allocate memory for the node's data
    newNode->data = malloc(size);
    if (newNode->data == NULL) {
        perror("Failed to allocate memory for node data");
        free(newNode); // Free the node itself if data allocation fails
        return;
    }

    // Copy the data to the node
    memcpy(newNode->data, data, size);
    newNode->size = size;

    // Insert the new node at the beginning of the list
    newNode->next = path->node;
    path->node = newNode;
}

void freePath(Path *path) {
    Node *current = path->node;
    while (current != NULL) {
        Node *next = current->next;
        free(current->data); // Free the data allocated for this node
        free(current);       // Free the node itself
        current = next;      // Move to the next node
    }
    path->node = NULL; // Ensure the path is set to NULL after freeing
}