//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    private:
    Node* createNode(int value)
    {
        Node* newNode=(Node*) malloc(sizeof(struct Node));
        newNode->data= value;
        newNode->left=newNode->right=NULL;
        return newNode;
    }
    Node* constructTree(vector<int> inOrder,vector<int>& preOrder)
    {
        if(inOrder.size()==0)
        {
            return NULL;
        }
        Node* root=createNode(preOrder[0]);
        bool stat=0;
        vector<int> leftPart,rightPart;
        for(int i=0;i<inOrder.size();i++)
        {
            if(inOrder[i]==preOrder[0])
            {
                stat=1;
                continue;
            }
            if(stat==0)
            {
                leftPart.push_back(inOrder[i]);
            }
            if(stat==1)
            {
                rightPart.push_back(inOrder[i]);
            }
        }
        preOrder.erase(preOrder.begin());
        root->left= constructTree(leftPart,preOrder);
        root->right=constructTree(rightPart,preOrder);
        return root;
    }
    public:
    Node* buildTree(int in[],int pre[], int n)
    {
        vector<int> inOrder,preOrder;
        for(int i=0;i<n;i++)
        {
            inOrder.push_back(in[i]);
            preOrder.push_back(pre[i]);
        }
        return constructTree(inOrder,preOrder);
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends