// In The Name Of ALlah, The most Gracious The Most Merciful
#include <bits/stdc++.h>
#define ll long long
#define shoot                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define tc \
    int t; \
    cin >> t;
#define vi vector<int>
#define pp pair<int, int>
#define cy cout << "YES" \
                << "\n"
#define cn cout << "NO" \
                << "\n"
using namespace std;

class Node
{
public:
    int data;
    Node *right;
    Node *left;

    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

void BuildTree(Node *root)
{
    cout << "Enter the data :" << endl;
    int data;
    cin >> data;
    root = new Node(data);

    if (data == -1)
    {
        return;
    }

    cout << "Enter data for inserting in left of " << data << endl;

    BuildTree(root->left);

    cout << "Enter data for inserting in the right of " << data << endl;
    BuildTree(root->right);
}

void PreOrderTraversal(Node *root, vector<int> &preOrder)
{
    if (root == NULL)
        return;

    preOrder.push_back(root->data);
    PreOrderTraversal(root->left, preOrder);
    PreOrderTraversal(root->right, preOrder);
}

void InOrderTraversal(Node *root, vector<int> &inOrder)
{
    if (root == NULL)
        return;

    InOrderTraversal(root->left, inOrder);
    inOrder.push_back(root->data);
    InOrderTraversal(root->right, inOrder);
}

void PostOrderTraversal(Node *root, vector<int> &postOrder)
{
    if (root == NULL)
        return;

    PostOrderTraversal(root->left, postOrder);
    PostOrderTraversal(root->right, postOrder);
    postOrder.push_back(root->data);
}

vector <vector<int>> levelorder(Node* root){
    vector <vector<int>>ans;

    if(root==NULL) return ans;

    queue<Node*>q;
    q.push(root);

    while(!q.empty()){
        int size = q.size();
        vector<int>level;

        for(int i=0;i<size;i++){
            Node* temp = q.front();
            q.pop();
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
            level.push_back(temp->data);
        }
        ans.push_back(level);
    }

    return ans;

}

vector<vector<int>>path (Node* root){
    vector<vector<int>> ans;
    if (root == NULL)
        return ans;
    vector<int> height;

    stack<Node*> st;
    Node* temp = root;
    while (temp->left) {
        st.push(temp);
        height.push_back(temp->data);
        temp = temp->left;
    }
    if (temp)
        height.push_back(temp->data);

    ans.push_back(height);

   while(!st.empty()){
      
   }



}

int main()
{
    shoot;

    // Node* root =NULL ;
    //  BuildTree(root);

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(8);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->right->left = new Node(9);
    root->right->right->right = new Node(10);

    //    vector < int > preOrder;
    //   PreOrderTraversal(root, preOrder );

    //   vector < int > inOrder;
    //   InOrderTraversal(root, inOrder );

    // vector<int> postOrder;
    // PostOrderTraversal(root, postOrder);

    // // cout << "The postOrder Traversal is : ";
    // for (int i = 0; i < postOrder.size(); i++)
    // {
    //     cout << postOrder[i] << " ";
    // }

    //    cout << "The inOrder Traversal is : ";
    //   for (int i = 0; i < inOrder.size(); i++) {
    //     cout << inOrder[i] << " ";
    //   }


    vector<vector<int>>v;
    v= levelorder(root);

    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
    
} 