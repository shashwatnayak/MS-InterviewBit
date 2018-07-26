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

void inorder(TreeNode* root){
	if(root==NULL)return;

	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

void inorder2(TreeNode* root){
	stack<TreeNode*> s;
	bool loop = true;
	TreeNode* cur = root;

	while(loop){

		if(cur!=NULL){
			s.push(cur);
			cur = cur->left;
		}else if(cur==NULL && s.empty()==false){
			cur = s.top();
			s.pop();
			cout<<cur->data<<" ";
			cur = cur->right;
		}else{
			loop = false;
		}
	}
}
int main(){
	TreeNode* root = createtree();
	inorder(root);
	cout<<endl;
	inorder2(root);
}