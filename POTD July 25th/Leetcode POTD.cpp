int peakIndexInMountainArray(vector<int>& arr) {
        int start=0,end=arr.size();
        int mid;
        while(start<end){
            mid=(start+end)/2;
            if(arr[mid]<arr[mid+1]) start=mid+1;
            else    end=mid;
        }
        return start;
    }
