class Solution {
public:
    void merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp; 
    int left = low;      
    int right = mid + 1;  
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
    }
    void mergesort(vector<int> &nums, int low , int high)
    {
        if(low>=high) return ;
        int mid = (low+high)/2;
        mergesort(nums, mid+1 , high);
        mergesort(nums , low ,mid);
        merge(nums, low ,mid, high);
    }
    vector<int> sortArray(vector<int>& nums) {
        
        // // ALL the sorting ALgorithm 
        // // Selection sort
        // sort and put smallest at the starting 
        int n = nums.size();
        // for(int i =0; i<n; i++){
        //     int mini = INT_MAX;
        //     for(int j = i; j<n; j++){
        //         if(mini>nums[j]){
        //             mini = min(mini, nums[j]);
        //             swap(nums[j], nums[i]);
        //         }
        //     }
            
        // }
        // return nums;
        // insertion sort:
        // for(int i =0 ; i<n; i++){
        //     int j =i;
        //     while(j >0 && nums[j-1]>nums[j]){
        //         swap(nums[j-1], nums[j]);
        //         j--;
        //     }

        // }
        // return nums;
        // bubble sort:
        // for(int i = n-1; i>=0; i--){
        //     for(int j = i; j>=0; j--){
        //         if(nums[j]>nums[i]){
        //             swap(nums[j],nums[i]);
        //         }
        //     }
        // }
        // return nums;

        // Merge Sort 
        mergesort(nums, 0,n-1);
        return nums;
    }

};