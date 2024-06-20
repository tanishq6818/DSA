Given three non-collinear points whose co-ordinates are p(p1, p2), q(q1, q2) and r(r1, r2) in the X-Y plane. Return the number of integral / lattice points strictly inside the triangle formed by these points.
Note: - A point in the X-Y plane is said to be an integral / lattice point if both its coordinates are integral.

Examples

Input: p = (0,0), q = (0,5), r = (5,0)
Output: 6
Explanation: 

As shown in figure, points (1,1) (1,2) (1,3) (2,1) (2,2) and (3,1) are the integral points inside the triangle. So total 6 are there.
Input: p = (62,-3), q = (5,-45), r = (-19,-23)
Output: 1129
Explanation: There are 1129 integral points in the triangle formed by p, q and r.
Expected Time Complexity: O(Log2109)
Expected Auxillary Space: O(1)

Constraints:
-109 ≤ x-coordinate, y-coordinate ≤ 109

  long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

long long int InternalCount(long long p[], long long q[], long long r[]) {
    long long x1 = p[0], y1 = p[1];
    long long x2 = q[0], y2 = q[1];
    long long x3 = r[0], y3 = r[1];
    
    // Calculate the area of the triangle
    long long A = abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));
    A /= 2;
    
    // Calculate the number of boundary lattice points
    long long B = gcd(abs(x2 - x1), abs(y2 - y1)) + gcd(abs(x3 - x2), abs(y3 - y2)) + gcd(abs(x3 - x1), abs(y3 - y1));
    
    // Calculate the number of interior lattice points using Pick's Theorem
    long long I = A - B / 2 + 1;
    
    return I;
}
