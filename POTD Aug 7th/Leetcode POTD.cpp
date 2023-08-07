// Search a 2D Matrix

bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size();
        int col=matrix[0].size();
        int i=0;
        int j=col-1;
        while(i<row && j>=0){
            int ele=matrix[i][j];
            if(ele==target){
                return 1;
            }
            if(ele<target){
                i++;
            }
            else{
                j--;
            }
        }
        return 0;
        
    }
