#include <iostream>
#include <vector>

using namespace std;

struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
  };
  
int main()
{
	vector<Interval> res;
	
	for (auto block : intervals){
		auto iter = res.begin();
		while ( iter != res.end() ){
			if ( block.start < iter->start ){
				
				if ( res.begin() == iter || block.start > (iter-1)->end  ){
					int cnt = 0;
					while ( (iter+cnt) < res.end() && block.end > (iter+cnt)->end ){
						cnt++;
					}
					if ( cnt == res.size() || block.end < (iter+cnt)->start ){
							iter->start = block.start;
    						iter->end = block.end;
							//res.insert(iter,block);
							
							res.erase(iter,iter+cnt);
							break;
						}
					else {
						(iter+cnt)->start = blcok.start;
						res.erase(iter,iter+cnt);
						break;
					}
					
				}
				else {
					int acnt = 0;
					while ( (iter+acnt) < res.end() && block.end > (iter+cnt)->end ){
						acnt++;
					}
					if ( acnt == res.size() ){
						(iter-1)->end = block.end;
						res.erase(iter,iter+acnt);
					}
					else if ( block.end < (iter+acnt)->start ){
							(iter-1)->end = block.end;
							res.erase(iter,iter+acnt);
						}
					else {
						(iter-1)->end = (iter+acnt)->end;
						res.erase(iter,iter+acnt+1);
					}
					break;
					
				}
			}
		}
		if ( block.start > res.back().start && block.end > res.back().end )
			res.back().end = block.end;
		if (block.start > res.back().end)
			res.push_back(block);
	}
	return res;
	
}
