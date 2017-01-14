#include <iostream>

using namespace std;

struct TreeNode {
    string key;
    int value;
    TreeNode *parent;
    TreeNode *left;
    TreeNode *right;
};

TreeNode *createNode(const string &key, const int value, TreeNode *nodeParent) {
    TreeNode *node = new TreeNode;
    node->key = key;
    node->value = value;
    node->parent = nodeParent;
    node->left = node->right = NULL;
    return node;
}

void set(const string &key, const int value, TreeNode *&map) {
    if (map == NULL) {
        map = createNode(key, value, NULL);
    } else {
        TreeNode *node = map;
        TreeNode *nodeParent = node->parent;
        while ((node != NULL) and (node->key != key)) {
            nodeParent = node;
            if (key < node->key) {
                node = node->left;
            } else {
                node = node->right;
            }
        }
        if (node == NULL) {
            node = createNode(key, value, nodeParent);
            if (key < nodeParent->key) {
                nodeParent->left = node;
            } else {
                nodeParent->right = node;
            }
        } else {
            node->value = value;
        }
    }
}

TreeNode* find(const string &key, TreeNode *&map) {
    TreeNode *node = map;
    while ((node != NULL) and (node->key != key)) {
        if (key < node->key) {
            node = node->left;
        } else {
            node = node->right;
        }
    }
    return node;
}

TreeNode* findMin(TreeNode *node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}

void get(const string &key, TreeNode *&map) {
    TreeNode *node = find(key, map);
    if (node == NULL) {
        cout << "EMPTY" << endl;
    } else {
        cout << node->value << endl;
    }
}

void unset(const string &key, TreeNode *&map) {
    TreeNode *node = find(key, map);
    if (node == NULL) {
        return;
    } else {
        TreeNode *toDelete;
        if (node->left == NULL or node->right == NULL) { // less than two children
            toDelete = node;
        } else {
            toDelete = findMin(node->right); // find successor
        }

        TreeNode *child;
        if (toDelete->left != NULL) {
            child = toDelete->left;
        } else {
            child = toDelete->right;
        }

        if (child != NULL) {
            child->parent = toDelete->parent;
        }
        if (toDelete->parent == NULL) {
            map = child;
        } else if (toDelete == toDelete->parent->left) {
            toDelete->parent->left = child;
        } else {
            toDelete->parent->right = child;
        }

        if (toDelete != node) {
            node->key = toDelete->key;
            node->value = toDelete->value;
        }
        delete toDelete;
    }
}

int main() {
    int z;
    cin >> z;
    TreeNode *map = NULL;
    for (int i = 0; i < z; i++) {
        string operation, key;
        cin >> operation >> key;
        if (operation == "SET") {
            int v;
            cin >> v;
            set(key, v, map);
        } else if (operation == "UNSET") {
            unset(key, map);
        } else if (operation == "GET") {
            get(key, map);
        }
    }
    return 0;
}
