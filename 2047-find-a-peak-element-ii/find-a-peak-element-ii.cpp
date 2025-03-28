class Solution {
public:
    
    int maxele(vector<vector<int>> mat, int m , int n , int mid){
    int max =-1;
    int ind =-1;
    for(int i =0 ; i<n; i++){
        if(mat[i][mid]>max){
            max = mat[i][mid];
            ind = i;
        }
    }
    return ind;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
    int m = mat[0].size();
    int low =0; int high = m-1;
    while(low<=high){
        int mid = (low +high)/2;
        int row = maxele(mat , m , n , mid);
        // int left = mid -1;
        // int right = mid +1;
        int left = mid -1 >=0? mat[row][mid - 1] : -1;
        int right = mid+1<m ? mat[row][mid + 1] : -1;

        if (mat[row][mid] > left && mat[row][mid] > right) {
            return {row, mid};
        } else if (mat[row][mid] < left)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return {-1, -1
};
    }
};