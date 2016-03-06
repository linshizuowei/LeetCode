#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main()
{
	string s = "aaaaaaaa";
	vector<string> words = {"aa","aa"};
	
	if ( s.empty() || words.empty() )
		return {};
	
	int bit = 0;
	int slen = s.length();
	int wsize = words.size();
	int elen = words.front().size();
	string sub;
	vector<int> index;
	int count = 0;
	
	unordered_map<string,size_t> word_cnt;
	for ( auto word : words ){
		word_cnt[word]++;
	}
	
	int twsize = wsize;
	unordered_map<string,size_t> tmp_cnt = word_cnt;
	
	for ( bit=0;bit < elen;bit++ ){
		twsize = wsize;
		tmp_cnt = word_cnt;
		count = 0;
		for ( int i = bit;i <= slen-elen;i+=elen ){
			sub = s.substr(i,elen);
			
			if ( tmp_cnt.find(sub) == tmp_cnt.end() ){
				tmp_cnt = word_cnt;
				twsize = wsize;
				count = 0;
			}
			else {
				count++;
				if ( tmp_cnt[sub] > 0 ){
					tmp_cnt[sub]--;
					if( --twsize == 0 ){
						int indice = i-(wsize-1)*elen;						
						index.push_back(indice);
						tmp_cnt = word_cnt;
						twsize = wsize;
						i = i-(count-1)*elen;
						count = 0;
					}
				}
				else {
					tmp_cnt = word_cnt;
					twsize = wsize;				
					i = i-(count-1)*elen;
					count = 0;
				}
			}
		}
		
	}
	for (auto i : index)
		cout << i <<' ';
	
//	int j = 0;
//	sort(index.begin(),index.end());
//	for (int i=1;i<index.size();i++){
//		if (index[i] != index[i-1]){
//			index[++j] = index[i];
//		}
//	}
//	for (int i=0;i<j+1;i++)
//		cout << index[i] <<' ';
}
