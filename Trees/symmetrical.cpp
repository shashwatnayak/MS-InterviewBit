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
bool checksym(TreeNode* r1,TreeNode* r2){
	if(r1==NULL && r2==NULL){
		return true;
	}
	if(r1 && r2&& r1->data == r2->data){
		return checksym(r1->left,r2->right) && checksym(r1->right,r2->left);
	}
	return false;
}
int main(){
	TreeNode* root = createtree();

	cout<<checksym(root,root);
}