//
// Created by Oliver on 8/3/24.
//


#pragma once
#include <stdlib.h>

typedef struct Node {
    void *data;
    size_t size;
    struct Node *next;
} Node;

typedef struct Path {
    Node *node;
} Path;

void addNode(Path *path, const void *data, size_t size);
int removeNode(Path *path, const void *data, size_t size);
void freePath(Path *path);
void insertFirst(Path *path, const void *data, size_t size);
Node * popLastNode(Path * path);

