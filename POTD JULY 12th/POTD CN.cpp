int middleOfThree(int a, int b, int c)
{
    // Write your code here   
    if ((a > b && a < c) || (a < b && a > c))
        return a;
    else if ((b > a && b < c) || (b < a && b > c))
        return b;
    else
        return c;
}
