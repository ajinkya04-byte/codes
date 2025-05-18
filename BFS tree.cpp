#include <iostream>
#include <cstdlib>
using namespace std;

struct queue {
    int size;
    int front;
    int back;
    int* arr;
};

// Enqueue function
void enqueue(struct queue* ptr, int data) {
    if (ptr->back == ptr->size - 1) {
        cout << "Queue is full" << endl;
    } else {
        ptr->back++;
        ptr->arr[ptr->back] = data;
    }
}

// Dequeue function
int dequeue(struct queue* ptr) {
    if (ptr->front > ptr->back) {
        cout << "Cannot dequeue from an empty queue" << endl;
        return -1; // Return -1 for empty queue
    } else {
        int data = ptr->arr[ptr->front];
        ptr->front++;
        return data;
    }
}

// Display function for debugging
void display(struct queue* q) {
    if (q->front > q->back) {
        cout << "Queue is empty" << endl;
    } else {
        cout << "Queue elements: ";
        for (int i = q->front; i <= q->back; i++) {
            cout << q->arr[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    // Initialize the queue
    struct queue* q = (struct queue*)malloc(sizeof(struct queue));
    q->size = 10; // Increased size for BFS operations
    q->front = 0;
    q->back = -1; // Start `back` at -1 to make enqueue logic consistent
    q->arr = (int*)malloc(q->size * sizeof(int));

    // BFS Implementation
    int i = 0;
    int visited[7] = {0, 0, 0, 0, 0, 0, 0};
    int a[7][7] = {
        {0, 1, 1, 1, 0, 0, 0},
        {1, 0, 0, 1, 0, 0, 0},
        {1, 1, 0, 1, 1, 0, 0},
        {1, 0, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0}
    };

    cout << "Starting BFS from node " << i << endl;
    visited[i] = 1;
    enqueue(q, i); // Enqueue the starting node for exploration

    while (q->front <= q->back) { // While the queue is not empty
        int u = dequeue(q);       // Dequeue a vertex
        cout << "Visited node: " << u << endl;

        // Check all adjacent nodes
        for (int j = 0; j < 7; j++) {
            if (a[u][j] == 1 && visited[j] == 0) {
                visited[j] = 1;
                enqueue(q, j); // Enqueue the adjacent node
            }
        }
    }

    // Free the allocated memory
    free(q->arr);
    free(q);

    return 0;
}
