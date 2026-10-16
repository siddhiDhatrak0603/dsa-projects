#include <iostream>
using namespace std;

class node {
    public:
    int data;
    node *left;
    node *right;
    
    node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

node *root = nullptr;

node *insert(node *root, int value) {
    if (root == nullptr) {
        return new node(value);
    }
    else if (value < root->data) {
        root->left = insert(root->left, value);
    }
    else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    else{
        cout<<"duplicate not allowed:"<<endl;
    }
    return root;
}

void display(node *root) {
    if (root != nullptr) {
        display(root->left);
        cout << root->data << " ";
        display(root->right);
    }
}

void create() {
    int value;
    cout << "enter value in BST" << endl;
    if (!(cin >> value)) {
        cout << "invalid input:" << endl;
        return;
    }
    root = insert(root, value);
    cout << "Value added successfully!" << endl;
}

int main() {
    int choice = 0;
    
    do {
        cout << ">>>>>>>>>>binary search tree menu<<<<<<<<<" << endl;
        cout << "1. Insert" << endl;
        cout << "2. Delete" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;
        cout << "enter your choice:" << endl;
        
        if (!(cin >> choice)) {
            cout << "invalid input:" << endl;
            break;
        }

        switch(choice) {
            case 1:
                create();
                break;
            case 3:
                
                if (root == nullptr) {
                    cout << "BST is empty!" << endl;
                } else {
                    cout << "BST elements (In-order): ";
                    display(root);
                    cout << endl;
                }
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
                
    } while(choice != 4);

    return 0;
}