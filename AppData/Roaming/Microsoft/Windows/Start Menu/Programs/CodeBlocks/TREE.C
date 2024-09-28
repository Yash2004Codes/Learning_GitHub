#include <stdio.h>
#include <stdlib.h>

// Define the structure for the Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new Node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a new Node in the BST
struct Node* insert(struct Node* node, int data) {
    if (node == NULL) {
        return newNode(data);
    }

    if (data < node->data) {
        node->left = insert(node->left, data);
    } else if (data > node->data) {
        node->right = insert(node->right, data);
    }

    return node;
}

// Function to find the minimum value Node in the right subtree
struct Node* findmin(struct Node* node) {
    //struct Node* curr = node;

    while(node !=NULL && node->left !=NULL)
        node = node->left;

    return node;
}
struct Node* findmax(struct Node* node) {
    struct Node* curr = node;

    while(curr !=NULL && curr->right !=NULL)
        curr = curr->right;

    return curr;
}
// Function to delete a Node in the BST
struct Node* deleteNode(struct Node* root, int x) {

    struct Node* curr  = root; // curr is optional
    if(root == NULL)
        return root;
    else if(curr->data > x)
        curr->left = deleteNode(curr->left,x);
    else if(curr->data < x)
        curr->right = deleteNode(curr->right,x);
    else{

        // curr->data == x
        if(curr->right == NULL && curr->left== NULL)
            return NULL;

        else if(curr->right == NULL)
        return curr->left;

        else if(curr->left == NULL)
        return curr->right;

        else{
             // replace with min in right subtree
            if(curr->right !=NULL)
            {
               // two childrens
            struct Node* min=findmin(root->right);
            // min will replace curr
            curr->data = min->data;
            // delete min in right subtree
            curr->right=deleteNode(curr->right,min->data);
            return root;
            }
            else{
                // no right subtree
                // find max in left subtree

                struct Node* max =findmax(curr->left);
                curr->data = max->data;
                curr->left=deleteNode(curr->left,max->data);
                return root;
            }
        }


    }
}

void maxNode(struct Node* root)
{
    if(root !=NULL && root->right !=NULL)
        root = root->right;

    printf("max element is %d \n",root->data);
}
void minNode(struct Node* root)
{
    if(root !=NULL && root->left !=NULL)
        root = root->left;

    printf("min element is %d \n",root->data);
}
// Inorder traversal of the BST
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Main function
int main() {
    struct Node* root = NULL;
    root = insert(root, 45);
root = insert(root, 23);
root = insert(root, 34);
root = insert(root, 37);
root = insert(root, 36);
root = insert(root, 38);
root = insert(root, 54);


    //printf("Inorder traversal of the tree before deletion:\n");
    inorder(root);
    printf("\n");

    // Deleting a node
    maxNode(root);
    minNode(root);
    //inorder(root);


}
