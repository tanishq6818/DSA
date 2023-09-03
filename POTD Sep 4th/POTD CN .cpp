//NUMBER TO WORDS

#include <bits/stdc++.h> 
string one[] = {"", "one ", "two ", "three ", "four ", "five ", "six ", "seven ", "eight ", "nine "};
string ten[] = {"", "", "twenty ", "thirty ", "forty ", "fifty ", "sixty ", "seventy ", "eighty ", "ninety "};

string handleAll(int n)
{
    if (n < 10)
        return one[n];
    else if (n < 20)
        return one[n] + " ";
    else if (n < 100)
        return ten[n / 10] + one[n % 10];
    else if (n < 1000)
    {
        if (n % 100 == 0)
            return one[n / 100] + "hundred ";
        else
            return one[n / 100] + "hundred and " + handleAll(n % 100);
    }
    else if (n < 100000)
    {
        if (n % 1000 == 0)
            return handleAll(n / 1000) + "thousand ";
        else
            return handleAll(n / 1000) + "thousand " + handleAll(n % 1000);
    }
    else if (n < 10000000)
    {
        if (n % 100000 == 0)
            return handleAll(n / 100000) + "lakh ";
        else
            return handleAll(n / 100000) + "lakh " + handleAll(n % 100000);
    }
    else
    {
        return "Number out of range";
    }
}
