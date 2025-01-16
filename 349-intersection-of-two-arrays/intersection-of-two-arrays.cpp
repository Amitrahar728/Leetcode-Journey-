class Solution {
public:
    bool binarySearch(const vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return true;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return false;
    
    }

    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums2.begin(), nums2.end());

        set<int> resultSet;
        for (int num : nums1) {
            if (binarySearch(nums2, num)) {
                resultSet.insert(num);
            }
        }
        vector<int> result(resultSet.begin(), resultSet.end());
        return result;


    }
};