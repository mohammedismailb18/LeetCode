class NumArray {
public:
    vector<int> num, st;
    int n;
    
    int constructSegmentTree(int sti, int l, int h){
        if(l == h){
            st[sti] = num[l];
            return st[sti];
        }
        int mid = (l+h)/2;
        st[sti] = constructSegmentTree(2*sti + 1, l, mid) + constructSegmentTree(2*sti + 2, mid+1, h);
        return st[sti];
    }
    
    void updateSegmentTree(int sti, int l, int h, int pos, int diff){
        if(pos > h || pos < l)
            return;
        st[sti] += diff;
        if(l != h){
            int mid = (l+h)/2;
            updateSegmentTree(2*sti + 1, l, mid, pos, diff);
            updateSegmentTree(2*sti + 2, mid+1, h, pos, diff);
        }
    }
    
    int rangeSum(int sti, int l, int h, int left, int right){
        if(l >= left && h <= right)
            return st[sti];
        else if(h < left || l > right)
            return 0;
        int mid = (l+h)/2;
        return rangeSum(2*sti + 1, l, mid, left, right) + rangeSum(2*sti + 2, mid + 1, h, left, right);
    }
    
    NumArray(vector<int>& nums) {
        num = nums;
        n = nums.size();      
        int height = ceil((double)log2(2*n - 1));
        int n_st = pow(2,height) - 1;
        if(n == 1)  n_st = 1;
        st.resize(n_st, 0);
        constructSegmentTree(0, 0, n-1);
    }
    
    void update(int index, int val) {
        int diff = val - num[index];
        num[index] = val;
        updateSegmentTree(0, 0, n-1, index, diff);
    }
    
    int sumRange(int left, int right) {
        return rangeSum(0, 0, n-1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
