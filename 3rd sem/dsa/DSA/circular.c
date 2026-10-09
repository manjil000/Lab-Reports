#include <stdio.h>
#include <stdlib.h>

#define MAX 5
int cq[MAX];
int front = -1, rear = -1;

void enqueue(int val) {
    if ((rear + 1) % MAX == front) {
        printf("Circular Queue Overflow!\n");
        return;
    }
    if (front == -1)
        front = rear = 0;
    else
        rear = (rear + 1) % MAX;

    cq[rear] = val;
    printf("Enqueued %d\n", val);
}

void dequeue() {
    if (front == -1) {
        printf("Circular Queue Underflow!\n");
        return;
    }
    printf("Dequeued %d\n", cq[front]);

    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % MAX;
}

void display() {
    if (front == -1) {
        printf("Circular Queue is empty.\n");
        return;
    }

    printf("Circular Queue elements: ");
    int i = front;
    while (1) {
        printf("%d ", cq[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    int choice, val;

    while (1) {
        printf("\n--- CIRCULAR QUEUE MENU ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                enqueue(val);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}