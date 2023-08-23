pair < int , int > findMinMax(int a , int b) 
{
	// Write Your Code here   
	int minimum = min(a, b);
    int maximum = max(a, b);
    return make_pair(minimum, maximum);     
}
