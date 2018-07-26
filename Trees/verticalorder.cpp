#include<iostream>
#include<map>
#include<utility>
#include<vector>
#include<queue>
using namespace std;

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

void verticalorder(TreeNode* root){
	if(root==NULL){
		return;
	}
	map<int,vector<TreeNode*> >m;
	queue<pair<int,TreeNode*> > q;
	q.push(make_pair(0,root));

	while(!q.empty()){
		TreeNode* cur = q.front().second;
		int hd = q.front().first;
		q.pop();

		m[hd].push_back(cur);

		if(cur->left){
			q.push(make_pair(hd-1,cur->left));
		}	
		if(cur->right){
			q.push(make_pair(hd+1,cur->right));
		}
	}

		map<int,vector<TreeNode*> >:: iterator it;

		for(it = m.begin();it!=m.end();++it){
			cout<<it->first<<": ";
			for(int i = 0;i<it->second.size();++i){
				cout<<it->second[i]->data<<" ";
			}
			cout<<endl;
		}
		

		// it = m.begin();
		// vector<vector<int> >ans;
		// int currr = 0;

		// while(it!=m.end()){
		// 	for(int i = 0;i<it->second.size();++i){
		// 		ans[currr].push_back(it->second[i]->data);
		// 	}
		// 	currr++;
		// 	it++;
		// }
	/* FOR IB */

}
int main(){
	TreeNode* cur = createtree();
	verticalorder(cur);
}