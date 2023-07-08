// Let there are 6 people, their heights are given by array "Height' [5, 3, 2, 6, 1, 4], and the number of people in front of them is given by array 'Infront': [8, 1, 2, 0, 3, 2]

// Thus the actual order of people's height in the queue will be [5, 3, 2, 1, 6, 4]

// In this order, the first person in a queue i.e a person with a height of 5, has no person in front of them who is taller than him. The second person in a queue i.e a person with a height of 3 has 1 person (person with height 5) in front of them who is taller than him.

// The third person in a queue 1.e a person with a height of 2 has 2

// people (people with height 5 and 3) in front of them who are taller

// than him. The fourth person in a queue 1.e a person with a height of 1 has 3 people (people with height 5, 3, 2) in front of them who are taller

// than him.

// The fifth person in a queue i.e a person with a height of 6 has no

// person in front of them who is taller than him. The sixth person in a queue i.e a person with a height of 4 has 2 people (people with height 5, and 6) in front of them who are taller than him.

// We can observe this is the only possible order that is possible according to the array 'InfrontSample Input 1 :
// 2
// 5
// 5 4 3 2 1
// 0 0 0 0 0
// 6
// 5 3 2 6 1 4
// 0 1 2 0 3 2
// Sample Output 1 :
// 1 2 3 4 5
// 5 3 2 1 6 4
// Explanation Of Sample Input 1 :
// Test case 1:
// There is no person in front of any person who is taller than him, Thus all of them must be present in the queue in increasing order of their height.

// Test case 2:
// See the problem statement for an explanation.
// Sample Input 2 :
// 2
// 2
// 2 3
// 1 0
// 5
// 1 2 3 4 5
// 4 3 2 1 0
// Sample Output 2 :
// 3 2
// 5 4 3 2 1 


  
std::vector<int> findOrder(std::vector<int>& height, std::vector<int>& infront) {
    // Create a vector of pairs
    std::vector<std::pair<int, int>> people;
    for (int i = 0; i < height.size(); i++) {
        people.push_back(std::make_pair(height[i], infront[i]));
    }

    // Sort the vector in descending order based on height
    std::sort(people.begin(), people.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
        return a.first > b.first;
    });

    // Insert each person at the position indicated by the number of people in front of them
    std::vector<int> result;
    for (const auto& person : people) {
        result.insert(result.begin() + person.second, person.first);
    }

    return result;
}
