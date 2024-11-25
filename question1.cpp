//Name: Kelly Huang
//Student ID: 1123526
//Date of submission: 2024/11/26

#include <iostream>
#include <queue>
#include <vector>
#include <sstream>
using namespace std;

// Definition of a TreeNode
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to build a binary tree from level-order input
TreeNode* buildTree(const vector<int>& values) {
    if (values.empty() || values[0] == -1) return nullptr;

    TreeNode* root = new TreeNode(values[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;

    while (!q.empty() && i < values.size()) {
        TreeNode* current = q.front();
        q.pop();

        // Add left child
        if (i < values.size() && values[i] != -1) {
            current->left = new TreeNode(values[i]);
            q.push(current->left);
        }
        i++;

        // Add right child
        if (i < values.size() && values[i] != -1) {
            current->right = new TreeNode(values[i]);
            q.push(current->right);
        }
        i++;
    }

    return root;
}

// Helper function to calculate the diameter and height simultaneously
int calculateDiameter(TreeNode* root, int& diameter) {
    if (!root) return 0;

    // Calculate left and right heights
    int leftHeight = calculateDiameter(root->left, diameter);
    int rightHeight = calculateDiameter(root->right, diameter);

    // Update the diameter: left height + right height (number of edges)
    diameter = max(diameter, leftHeight + rightHeight);  // This line calculates correctly

    // Return the height of the current node
    return 1 + max(leftHeight, rightHeight);
}

// Function to calculate the diameter of a binary tree
int diameterOfBinaryTree(TreeNode* root) {
    int diameter = 0;
    calculateDiameter(root, diameter);
    return diameter;
}

// Function to parse user input string into an integer array
vector<int> parseInput(string input) {
    vector<int> values;
    stringstream ss(input);
    string temp;
    while (getline(ss, temp, ',')) {
        values.push_back(temp == "-1" ? -1 : stoi(temp));
    }
    return values;
}

int main() {
    string input;
    getline(cin, input);

    // Parse input
    vector<int> values = parseInput(input);

    // Build the binary tree
    TreeNode* root = buildTree(values);

    // Calculate and print the diameter
    int diameter = diameterOfBinaryTree(root);
    cout << diameter << endl;

    return 0;
}
