class Solution {
public:
    void reversed(vector<int> & arr, int l , int r){
        while(l<r){
            swap(arr[l], arr[r]);
            l++;r--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;
        if(n!=1){
        reversed(nums , 0 ,n-1);
        reversed(nums , 0 ,k-1);
        reversed(nums , k, n-1);
        }
    }
};