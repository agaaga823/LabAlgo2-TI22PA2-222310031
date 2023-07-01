#include <iostream>
using namespace std;

struct Node {
  int data;
  Node *left;
  Node *right;
};

Node *createNode(int data) {
  Node *newNode = new Node();
  if (!newNode) {
    cout << "Gagal membuat node baru." << endl;
    return NULL;
  }
  newNode->data = data;
  newNode->left = newNode->right = NULL;
  return newNode;
}

Node *insertNode(Node *root, int data) {
  if (root == NULL) {
    root = createNode(data);
    return root;
  }
  if (data < root->data)
    root->left = insertNode(root->left, data);
  else if (data >= root->data)
    root->right = insertNode(root->right, data);
  return root;
}

void preOrderTraversal(Node *root) {
  if (root == NULL)
    return;

  cout << root->data << " ";
  preOrderTraversal(root->left);
  preOrderTraversal(root->right);
}
void inOrderTraversal(Node *root) {
  if (root == NULL)
    return;

  inOrderTraversal(root->left);
  cout << root->data << " ";
  inOrderTraversal(root->right);
}
void postOrderTraversal(Node *root) {
  if (root == NULL)
    return;

  postOrderTraversal(root->left);
  postOrderTraversal(root->right);
  cout << root->data << " ";
}

int main() {
  Node *root = NULL;
  root = insertNode(root, 12);
  root = insertNode(root, 16);
  root = insertNode(root, 20);
  root = insertNode(root, 24);
  root = insertNode(root, 32);
  cout << "Hasil pre-order traversal: ";
  preOrderTraversal(root);
  cout << endl;
  cout << "Hasil in-order traversal: ";
  inOrderTraversal(root);
  cout << endl;
  cout << "Hasil post-order traversal: ";
  postOrderTraversal(root);
  cout << endl;
  return 0;
}
