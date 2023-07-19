Sample Input 1 :
2
4 4
1 2 3
2 3 2
1 3 1
3 4 2 
1 1
1 1 7
Sample output 1 :
4 6 5 2
7
Explanation For Sample Input 1 :
For the first test case,
Flight labels:               1   2   3   4
Booking 1 reserved:          3   3
Booking 2 reserved:              2   2
Booking 3 reserved:          1   1   1
Booking 4 reserved:                  2   2    
Total seats:                 4   6   5   2
Hence, answer = [4, 6, 5, 2].

For the second test case, there is only one flight and single booking detail. So, answer = [7].
Sample Input 2 :
2
3 2
1 2 2
2 3 3
2 1
1 2 1
Sample output 2 :
2 5 3
1 1
Explanation For Sample Input 2 :
For the first test case,
Flight labels:              1   2   3
Booking 1 reserved:         2   2
Booking 2 reserved:             3   3
Total seats:                2   5   3
Hence, answer = [2, 5, 3].

For the second test case, answer = [1, 1]. #include <bits/stdc++.h> 
vector< int > corpFlightBookings(vector< vector < int > > &bookings, int n) {
	// Write your code here.
  vector< int > corpFlightBookings(vector< vector < int > > &bookings, int n) {
	// Write your code here.
	vector<int> reservedSeats(n, 0);

    for (const std::vector<int>& booking : bookings) {
        int flightStart = booking[0] - 1;
        int flightEnd = booking[1] - 1;
        int seatsReserved = booking[2];

        for (int i = flightStart; i <= flightEnd; i++) {
            reservedSeats[i] += seatsReserved;
        }
    }

    return reservedSeats;
}
}
