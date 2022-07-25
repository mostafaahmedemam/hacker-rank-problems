class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        vector<int> target_row;
        for(int i=0;i<matrix.size();i++){
            if(target<matrix[i][matrix.size()] && target > matrix[i][0]){
             target_row.push_back(i);    
            }
        }
        for(int it=0;it<target_row.size();it++){
            for(int i=0;i<matrix.size();i++){
                if(target == matrix[target_row[it]][i]){
                 return true;    
                }
            }
        }
        return false;
    }
};
