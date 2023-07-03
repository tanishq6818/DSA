/*Given an array arr[] of n positive integers. The task is to find the maximum of j - i subjected to the constraint of arr[i] <= arr[j].*/

int maxIndexDiff(int arr[], int n) {
        // code here
        vector<int> ldif(n);
        vector<int> rdif(n);
        ldif[0]=arr[0];
        rdif[n-1]=arr[n-1];
        for(int i=1;i<n;i++){
            ldif[i]=min(arr[i],ldif[i-1]);
        }
        for(int i=n-2;i>=0;i--){
            rdif[i]=max(arr[i],rdif[i+1]);
        }
        int i=0,j=0,maxdif=0;
        while(i<n && j<n){
            if(ldif[i]<=rdif[j]){
                maxdif=max(j-i,maxdif);
                ++j;
            }
            else{
                ++i;
            }
        }
        return maxdif;
    }
