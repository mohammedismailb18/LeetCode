class Solution {
public:
    int minOperations(int n) {
        int start = 0, end = n-1, operations = 0;
        while(start < end){
            operations += n - (2*start + 1);
            start++;
            end--;
        }
        return operations;
    }
};
