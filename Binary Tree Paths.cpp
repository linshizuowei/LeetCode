/* Given a binary tree, return all root-to-leaf paths.

For example, given the following binary tree:

   1
 /   \
2     3
 \
  5
All root-to-leaf paths are:

["1->2->5", "1->3"]
*/




#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };
		
vector<vector<int>> f(TreeNode *);
TreeNode* buildtree();

int main()
{
	
	cout << "here" << endl;
	TreeNode *root;
	root = buildtree();
	cout << "buildtree is down" << endl;
	
	cout << root->val << endl;
    cout << "root down" << endl;
    
	vector<vector<int>> tmp = f(root);
	vector<string> path;
	
	string s,singlenum;
	string arrow = "->";
	stringstream ss;
	auto iter1 = tmp.begin();
	while (iter1 != tmp.end()){
		s = "";
		ss << (*iter1).back();
		ss >> s;
		
		auto iter2 = (*iter1).end();
		--iter2;
		--iter2;
		while (iter2 >= (*iter1).begin()){
			ss << *iter2;
			ss >> singlenum;
			s = s+arrow+singlenum;
			--iter2;
		}
		
		path.push_back(s);
	}
	cout << path[0];
}

vector<vector<int>> f(TreeNode *root)
{
	vector<vector<int>> path;
	int sigal = 0;
	
	if ( root->left != NULL ){
		sigal = 1;
		
		vector<vector<int>> tmp;
		tmp = f(root->left);
		auto iter = tmp.begin();
		while ( iter != tmp.end()){
				(*iter).push_back(root->val);
				path.push_back(*iter);
				++iter;
		}
	}
	if (root->right != NULL){
		sigal = 1;
		
		vector<vector<int>> tmp;
		tmp = f(root->right);
		auto iter = tmp.begin();
		while ( iter != tmp.end()){
				(*iter).push_back(root->val);
				path.push_back(*iter);
				++iter;
		}
	}
	
	if (sigal == 0){
		vector<int> leaf;
		leaf.push_back(root->val);
		path.push_back(leaf);
	}
	
	return path;
}

TreeNode* buildtree()
{
	
	cout << "in buildtree" << endl;
	TreeNode *root,*tmp1,*tmp2,*tmp3,*tmp4;
	
	root->val = 1;
	
	tmp1->val = 2;
	tmp2->val = 3;
	tmp3->val = 4;
	tmp4->val = 5;
	
	root->left = tmp1;
	root->right = tmp2;
	tmp1->left = tmp3;
	tmp1->right = tmp4;
	
	return root;
}
