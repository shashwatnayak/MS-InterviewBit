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

void postorder(TreeNode* root){
	if(root==NULL)return;
	
	
	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<" ";
}

void postorder2(TreeNode* root){
	stack<TreeNode*> s,ss;
	TreeNode* cur;
	s.push(root);
	
	while(!s.empty()){
		cur = s.top();
		
		ss.push(s.top());
		s.pop();


		if(cur->left){
			s.push(cur->left);
		}
		if(cur->right){
			s.push(cur->right);
		}
	}
	TreeNode* cur2;
	while(!ss.empty()){
		cur2 = ss.top();
		ss.pop();
		cout<<cur2->data<<" ";
	}	
}
int main(){
	TreeNode* root = createtree();
	postorder(root);
	cout<<endl;
	postorder2(root);
}