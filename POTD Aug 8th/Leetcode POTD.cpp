// Search in a Rotated Array

class Solution {
public:
    int getpivot(vector<int> &arr,int n){
    int start=0,end=n-1;
    int mid;
    while(start<end){
        mid=(start+end)/2;
        if(arr[0]<=arr[mid])    start=mid+1;
        else    end=mid;
    }return start;
}
int binarySearch(vector<int>& arr,int s,int e,int k){
    int start=s,end=e,mid;
    while(start<=end){
        mid=(start+end)/2;
        if(arr[mid]==k) return mid;
        else if(arr[mid]<k) start=mid+1;
        else    end=mid-1;
    }
    return -1;
}
    int search(vector<int>& nums, int target) {
        int pivot=getpivot(nums,nums.size());
        if(target>=nums[pivot] && target<=nums[nums.size()-1]){
            return binarySearch(nums,pivot,nums.size()-1,target);
        }
        else    
            return binarySearch(nums,0,pivot-1,target);
    }
};
