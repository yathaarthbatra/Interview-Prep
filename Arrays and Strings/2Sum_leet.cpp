class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        //Here we require indexes so we cant sort the elements
        //so we will require a hashmap to store the indexes of the pair of elements

        unordered_map<int, int> map;

        vector<int> ans; //for returning the vector

        //storing the elements with their indexes in the hashmap
        for (int i = 0; i < nums.size(); i++)
        {
            map[nums[i]] = i;
        }

        //traversing the nums array and checking for the pair
        for (int i = 0; i < nums.size(); i++)
        {
            int a = target - nums[i];
            //consideer this edge case:[3,2,4] target=6
            //in this case we will return [0,0]

            if (map.find(a) != map.end())
            {
                //check whether the index of a is not same as i
                if (i != map[a])
                {
                    ans.push_back(i);
                    ans.push_back(map[a]);
                    return ans;
                }
            }
        }

        return ans; //if none pair found
    }
};