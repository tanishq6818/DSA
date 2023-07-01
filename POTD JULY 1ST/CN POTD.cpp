//Watering Flowers
int totalSteps(int n, int k, vector<int> &flowers) {
    //    Write your code here
    int step=0;
    int c=k;
    for(int i=0;i<n;i++){
        if(flowers[i] <= c) {
        step++;
        c-=flowers[i];
        }
        else {
            step+=2*i+1;
            c=k-flowers[i];
        }
    }
    return step;
}
