// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};
vector<vector<int>> levelOrder(struct Node* node);

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // for(string i:ip)
    //     cout<<i<<" ";
    // cout<<endl;
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


int main() {
    int t;
    scanf("%d ",&t);
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);

        vector<vector<int>> vec = levelOrder(root);
        for(vector<int> v : vec){
            for(int value : v){
                cout<<value<<" ";
            }
            cout<<"$ ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends


/* A binary tree Node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

//Function to return the level order traversal line by line of a tree.

void nodeAtK(vector<int> &v,Node* node,int k)
{
    if(node==NULL)
        return;
    if(k==0)
    {
        v.push_back(node->data);
    }
    else
    {
        nodeAtK(v,node->left,k-1);
        nodeAtK(v,node->right,k-1);
    }
}

int heightOfTree(Node* node)
{
    if(node==NULL)
        return 0;
    else
    {
        return max(heightOfTree(node->left),heightOfTree(node->right))+1;
    }
}

vector<vector<int>> levelOrder(Node* node)
{
    vector<vector<int>> op;
    int h = heightOfTree(node);
    
    for(int k=0 ;k<h;k++)
    {
        vector<int> v;
        nodeAtK(v,node,k);
        op.push_back(v);
    }
    return op;
}