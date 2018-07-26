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
bool flag;
int checkbalanced(TreeNode* root){
	if(flag==false)return 0;
	if(root==NULL)return 0;


	int lh = checkbalanced(root->left);
	int rt = checkbalanced(root->right);

	if(abs(lh-rt)>=2){
		flag = false;
		return 0;
	}
	return 1 + max(lh,rt);
}
int main(){
	TreeNode* root = createtree();
	flag = true;
	int ans = checkbalanced(root);
	cout<<flag;
}