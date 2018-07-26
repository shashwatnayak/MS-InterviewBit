#include<iostream>
#include<stack>
using namespace std;
class TreeNode{
public:
	int data;
	TreeNode* left,*right;
	TreeNode(int x){
		left = right = NULL;
		data = x;
	}
};

TreeNode* createtree(){
	int x;
	cin>>x;
	if(x==-1) return NULL;
	TreeNode* root = new TreeNode(x);

	root->left = createtree();
	root->right = createtree();

	return root;
}

void preorder(TreeNode* root){
	if(root==NULL)return;
	
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}

void preorder2(TreeNode* root){
	stack<TreeNode*> s;
	TreeNode* cur;
	s.push(root);
	while(!s.empty()){
		cur = s.top();
		s.pop();
		cout<<cur->data<<" ";

		if(cur->right){
			s.push(cur->right);
		}
		if(cur->left){
			s.push(cur->left);
		}
	}
	
}
int main(){
	TreeNode* root = createtree();
	preorder(root);
	cout<<endl;
	preorder2(root);
}