#include <vector>
#include <stdio.h>
using namespace std;
class Solution 
{
public:
	vector<int> findDuplicates(vector<int>& nums) 
	{
		int slen = nums.size();
		vector<int> res;
		if(slen == 0)
		{
			return res;
		}
        int flag = 1;
        for(int i=0;i<slen;)
        {
            if(nums[nums[i]-1]!=nums[i])
            {
                int tmp = nums[nums[i]-1];
                nums[nums[i]-1] = nums[i];
                nums[i] = tmp;
            }
            else
                i++;
        }

        for(int i=0;i<slen;i++)
        {
            if(nums[i]!=i+1)
            {
               res.push_back(nums[i]);
            }

        }
        return res;
	}
};

int main()
{
	vector<int> nums = {4,3,2,7,8,6,3,1};
    auto res = Solution().findDuplicates(nums);
    for(auto& item:res)
    {
        printf("%d ",item);
    }

}