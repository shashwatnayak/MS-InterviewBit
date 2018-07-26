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

bool checksymmetry(TreeNode* root1, TreeNode* root2){
	if(root1 == NULL && root2==NULL)return true;

	if(root1 && root2 && root1->data==root2->data){
		return checksymmetry(root1->left,root2->left) && checksymmetry(root1->right,root2->right);
	}
	return false;
}
int main(){
	TreeNode* root1 = createtree();
	TreeNode* root2 = createtree();

	cout<<checksymmetry(root1,root2);
}