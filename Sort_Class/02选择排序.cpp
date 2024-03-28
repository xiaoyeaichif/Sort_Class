#include<iostream>
#include<vector>
using namespace std;

void Insert_Sort(vector<int>& nums)
{
	int size = nums.size();
	for (int i = 0; i < size-1; i++)
	{
		int Min_Index = i;
		for (int j = i+1; j < size; j++)
		{
			if (nums[j] < nums[Min_Index])
			{
				Min_Index = j;
			}
			swap(nums[i], nums[Min_Index]);
		}
	}
}



int main02()
{
	vector<int>nums = { 10,1,2,3,5,1,0,5,4,0,50,3,0,40,6,0 };
	cout << "ÅÅÐòÇ°:";
	for (int num : nums)
	{
		cout << num << ' ';
	}
	cout << endl;
	Insert_Sort(nums);
	cout << "ÅÅÐòºó:";
	for (int num : nums)
	{
		cout << num << ' ';
	}
	cout << endl;
	return 0;
}