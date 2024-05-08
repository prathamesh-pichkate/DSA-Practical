#include <iostream>
#include <queue>
using namespace std;

/* Structure of a node in threaded binary tree */
struct Node {
    int key;
    Node *left, *right;
    bool isThreaded;
};

// Helper function to put the Nodes in inorder into queue
void populateQueue(Node* root, std::queue<Node*>* q) {
    if (root == NULL)
        return;
    if (root->left)
        populateQueue(root->left, q);
    q->push(root);
    if (root->right)
        populateQueue(root->right, q);
}

// Function to traverse queue, and make tree threaded
void createThreadedUtil(Node* root, std::queue<Node*>* q) {
    if (root == NULL)
        return;

    if (root->left)
        createThreadedUtil(root->left, q);
    q->pop();

    if (root->right)
        createThreadedUtil(root->right, q);
    else {
        root->right = q->front();
        root->isThreaded = true;
    }
}

// This function uses populateQueue() and createThreadedUtil()
// to convert a given binary tree to threaded tree.
void createThreaded(Node* root) {
    std::queue<Node*> q;
    populateQueue(root, &q);
    createThreadedUtil(root, &q);
}

// A utility function to find leftmost node in a binary tree
Node* leftMost(Node* root) {
    while (root != NULL && root->left != NULL)
        root = root->left;
    return root;
}

// Function to do inorder traversal of a threaded binary tree
void inOrder(Node* root) {
    if (root == NULL)
        return;

    Node* cur = leftMost(root);

    while (cur != NULL) {
        cout << cur->key << " ";
        if (cur->isThreaded)
            cur = cur->right;
        else
            cur = leftMost(cur->right);
    }
}

// A utility function to create a new node
Node* newNode(int key) {
    Node* temp = new Node;
    temp->left = temp->right = NULL;
    temp->key = key;
    return temp;
}

// Function to insert a new node into the binary tree
void insertNode(Node* root, int key) {
    if (root == NULL)
        return;
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (!temp->left) {
            temp->left = newNode(key);
            return;
        } else
            q.push(temp->left);

        if (!temp->right) {
            temp->right = newNode(key);
            return;
        } else
            q.push(temp->right);
    }
}

int main() {
    Node* root = NULL;

    // Inserting nodes dynamically
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;

    cout << "Enter the values of the nodes:\n";
    for (int i = 0; i < n; ++i) {
        int value;
        cin >> value;
        if (root == NULL)
            root = newNode(value);
        else
            insertNode(root, value);
    }

    createThreaded(root);

    cout << "Inorder traversal of created threaded tree is:\n";
    inOrder(root);

    return 0;
}

