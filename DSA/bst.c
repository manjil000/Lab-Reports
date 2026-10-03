#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

// Create new node
struct Node* newNode(int value) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = value;
    temp->left = temp->right = NULL;
    return temp;
}

// Insert into BST
struct Node* insert(struct Node* root, int value) {
    if (root == NULL)
        return newNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

// Preorder traversal
void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Search a value
struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->data == key)
        return root;

    if (key < root->data)
        return search(root->left, key);

    return search(root->right, key);
}

// Find minimum node
struct Node* findMin(struct Node* root) {
    while (root != NULL && root->left != NULL)
        root = root->left;
    return root;
}

// Delete a node from BST
struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL) return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);

    else if (key > root->data)
        root->right = deleteNode(root->right, key);

    else {
        // Node with only one child or no child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children
        struct Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

int main() {
    struct Node* root = NULL;
    int choice, value, key;

    while (1) {
        printf("\n--- BST MENU ---\n");
        printf("1. Create/Insert Node\n");
        printf("2. Preorder Traversal\n");
        printf("3. Search a Value\n");
        printf("4. Delete a Node\n");
        printf("5. Find Minimum Node\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;

            case 2:
                printf("Preorder Traversal: ");
                preorder(root);
                printf("\n");
                break;

            case 3:
                printf("Enter value to search: ");
                scanf("%d", &key);
                if (search(root, key))
                    printf("Value found in BST.\n");
                else
                    printf("Value NOT found.\n");
                break;

            case 4:
                printf("Enter value to delete: ");
                scanf("%d", &key);
                root = deleteNode(root, key);
                printf("Node deleted (if existed).\n");
                break;

            case 5:
                if (root == NULL)
                    printf("Tree is empty.\n");
                else
                    printf("Minimum value in BST: %d\n", findMin(root)->data);
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid Choice!\n");
        }
    }

    return 0;
}