// Given the coordinates of the endpoints(p1,q1, and p2,q2) of the two line segments. Check if they intersect or not. If the Line intersects return true otherwise return false.

// Examples

// Input: p1=(1,1), q1=(10,1), p2=(1,2), q2=(10,2)
// Output: false
// Explanation:The two line segments formed by p1-q1 and p2-q2 do not intersect.
// Input: p1=(10,0), q1=(0,10), p2=(0,0), q2=(10,10)
// Output: true
// Explanation: The two line segments formed by p1-q1 and p2-q2 intersect.
// Expected Time Complexity: O(1)
// Expected Auxillary Space: O(1)

// Constraints:
// -106<=X,Y(for all points)<=106

int orientation(int p[], int q[], int r[]) {
    long long val = 1LL * (q[1] - p[1]) * (r[0] - q[0]) - 1LL * (q[0] - p[0]) * (r[1] - q[1]);
    if (val == 0) return 0;  // Collinear
    return (val > 0) ? 1 : 2; // Clockwise or Counterclockwise
}

// Function to check if point q lies on line segment pr
bool onSegment(int p[], int q[], int r[]) {
    if (q[0] <= max(p[0], r[0]) && q[0] >= min(p[0], r[0]) &&
        q[1] <= max(p[1], r[1]) && q[1] >= min(p[1], r[1]))
        return true;
    return false;
}

// Function to check if two line segments intersect
string doIntersect(int p1[], int q1[], int p2[], int q2[]) {
    // Find the four orientations needed for the general and special cases
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);
    
    // General case
    if (o1 != o2 && o3 != o4)
        return "true";
    
    // Special cases
    // p1, q1 and p2 are collinear and p2 lies on segment p1q1
    if (o1 == 0 && onSegment(p1, p2, q1)) return "true";
    
    // p1, q1 and q2 are collinear and q2 lies on segment p1q1
    if (o2 == 0 && onSegment(p1, q2, q1)) return "true";
    
    // p2, q2 and p1 are collinear and p1 lies on segment p2q2
    if (o3 == 0 && onSegment(p2, p1, q2)) return "true";
    
    // p2, q2 and q1 are collinear and q1 lies on segment p2q2
    if (o4 == 0 && onSegment(p2, q1, q2)) return "true";
    
    // Doesn't fall in any of the above cases
    return "false";
}
