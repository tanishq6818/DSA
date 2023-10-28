void sort012(int *arr, int n)
{
   //   Write your code here
   int curr=0,zero=0,two=n-1;
    while(curr<=two){
        if(arr[curr]==0 ){
            swap(arr[curr],arr[zero]);
            zero++;curr++;
        }
        else if(arr[curr]==2){
            swap(arr[curr],arr[two]);
            two--;
        }
        else{
           curr++; 
        }
    }
}
