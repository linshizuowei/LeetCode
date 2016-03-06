#include <iostream>
#include <vector>

using namespace std;

void q_sort(vector<int>& nums,int l,int r);

int main()
{
	vector<int> nums = {1,1,2};
	int i,j,k;
	i = 0;
	j = nums.size()-1;
	
	while ( i < j ){
    		k = i+1;
    		while ( nums[i] == nums[k] ){
    			nums[k] = nums[j];
    			
    			do {
    			    j--;
    			} while (nums[k] == nums[j] && k <= j);
    			
    			if ( k >= j )
    			    break;
    			k++;
    		}
    		i = k-1;
    		i++;
    }
	
	for (auto i : nums)
		cout << i <<' ';
	cout << endl;

	
	q_sort(nums,0,j);
	
	cout << "length = "<< j+1 << endl;
	for (auto i : nums)
		cout << i <<' ';
}

void q_sort(vector<int>& nums,int l,int r)
{
	if ( l < r){
		
		int pivot = nums[r];
		int i = l;
		int j = r;
		int tmp;
	
		while (i < j){
			while ( i < j && nums[i] < pivot )
				i++;
			while ( i < j && nums[j] >= pivot )
				j--;
			
			if ( i < j ){
				tmp = nums[i];
				nums[i] = nums[j];
				nums[j] = tmp;
			}
			
		}
		tmp = nums[i];
		nums[i] = pivot;
		nums[r] = tmp;
		
		q_sort(nums,l,i-1);
		q_sort(nums,i+1,r);
	}
}



func()
{
		vector<int> nums = {1,1,2};
	
	int i,j,m,k,tmp;
	int s = 0;
	
	tmp = nums[0];
	int size = nums.size();
	
	for (i=1;i<size;++i){
		j = i;
		while ( nums[j] == tmp ){
			j++;
			s = 1;
		}
		
		if ( s == 1 ){
			nums[i] = nums[j];
			m = i+1;
			for ( k=j+1;k<size;++k,++m ){
				nums[m] = nums[k];
			}
			size = m;
		}
		
		tmp = nums[i];
	}
	
	cout << m << endl;
	for (auto i : nums)
		cout << i <<' ';

}
