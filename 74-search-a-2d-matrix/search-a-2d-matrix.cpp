class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // m*n matrix 
        // bss index ko represent krne ka tarika anna chahiye ki kaise row 2 k indices ko access krenge
        int low =0;
        int n = matrix.size();
        int m = matrix[0].size();
        int high = n*m-1;
        while(low<=high){
            int mid = low +(high-low)/2;
            int row = mid/m;
            int col = mid%m;
            int ele = matrix[row][col];
            if(ele == target){
                return true;
            }
            else if(target>ele){
                low = mid+1;
            } else{
                high = mid-1;
            }

        }
        return false;

    }
};