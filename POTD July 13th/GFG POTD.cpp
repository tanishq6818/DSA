// Given an array arr of N integers, the task is to check whether the frequency of the elements in the array is unique or not. 
// Or in other words, there are no two distinct numbers in array with equal frequency. If all the frequency is unique then return true, else return false.

bool isFrequencyUnique(int n, int arr[]) {
        unordered_map<int, int> freqMap;
        unordered_set<int> uniqueFreqSet;
    
        // Calculate the frequency of each element
        for (int i = 0; i < n; i++) {
            freqMap[arr[i]]++;
        }
    
        // Check for unique frequencies
        for (const auto& pair : freqMap) {
            int frequency = pair.second;
            uniqueFreqSet.insert(frequency);
        }
    
        // Return true if all frequencies are unique, false otherwise
        return uniqueFreqSet.size() == freqMap.size();
    }
