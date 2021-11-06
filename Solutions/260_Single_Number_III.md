* [Discussion Link](https://leetcode.com/problems/single-number-iii/discuss/1561914) 
# Simple Bit Manipulation
* Given that the arrray contains every element appearing twice except two numbers. We need to find those two numbers.
* If we xor all the numbers, then result = a^b where 'a' and 'b' are those numbers appearing once.
* We know that 'a' and 'b' are two distinct number, so their xor have atleast one set bit.
* We can group the entire numbers in the array by checking whether this particular bit is set or not.

For eg : concider the array : [1, 2, 1, 3, 2, 5]
```
0 0 1
0 1 0
0 0 1
0 1 1
0 1 0
1 0 1
xor = 1 1 0
```
* We can group the array by either taking any of the set bit. For the sake of convenience i am taking the right most set bit for grouping. 
* Then 1st set = [001, 001, 101] = [1, 1, 5] and 2nd set = [010, 011, 010] = [2, 3, 2]. 
* Now you can see that 'a' and 'b' are in different sets and everything else are present twice. Now xor whole set to obtain 'a' and 'b'. ie., 001 ^ 001 ^ 101 = 101,   010 ^ 011 ^ 010 = 011
------------------------------------------------------------------------------------------------------------------
```
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int XOR = 0, a = 0, b = 0;
        for(int x : nums)
            XOR ^= x;
        int mask = 1;
        for(int i=0; i<32; i++){
            if(XOR & mask)
                break;
            mask <<= 1;
        }
        for(int x : nums){
            if(x & mask)
                a ^= x;
            else
                b ^= x;
        }
        return {a, b};
    }
};
```
* **Time Complexity = O(N)**
* **Space Complexity  = O(1)**
**IF YOU FIND IT HELPFUL, DON'T FORGET TO UPVOTE**
