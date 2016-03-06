#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;


int searchInsert(vector<string>& a, string target) {
    int lo = 0;
    int hi = a.size() - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (target < a[mid]) hi = mid - 1;
        else if (target > a[mid]) lo = mid + 1;
        else return mid;
    }
    return lo;
	
}

int main()
{
	vector<string> strs = {"eat", "tea","bc","ad", "tan", "ate", "nat", "bat"};
	
	vector<vector<string>> ans;
    unordered_map<string, int> hash;
    string ori;
    for(int i=0; i<strs.size(); i++){
        ori = strs[i];
        sort(ori.begin(), ori.end());
        if(hash.count(ori)>0) {
            int idx = hash[ori];
            int pos = searchInsert(ans[idx], strs[i]); //find specific location
            vector<string>::iterator it = ans[idx].begin()+pos;
            ans[idx].insert(it, strs[i]);
        }
        else {
            hash[ori]=ans.size();
            ans.push_back(vector<string>(1, strs[i]));
        }
    }            
    

		
	for (auto i : ans){
		for (auto j : i){
			cout << j <<' ';
		}
		cout << endl;
	}
}



/*
vector<vector<string>> ans;
    unordered_map<string, int> hash;
    string ori;
    for(int i=0; i<strs.size(); i++){
        ori = strs[i];
        sort(ori.begin(), ori.end());
        if(hash.count(ori)>0) {
            ans[hash[ori]].push_back(strs[i]);
        }
        else {
            hash[ori]=ans.size();
            ans.push_back(vector<string>(1, strs[i]));
        }
    }            
    for(int i=0; i<ans.size(); i++){
        sort(ans[i].begin(), ans[i].end()); //can use other method
    }
*/
