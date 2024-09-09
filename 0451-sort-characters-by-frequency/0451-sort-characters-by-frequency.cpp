class Solution {
public:
    std::string frequencySort(std::string s) {
        std::unordered_map<char, int> frequencyMap;
        for (char c : s) {
            frequencyMap[c]++;
        }

        // Step 2: Create a vector of pairs to sort by frequency
        std::vector<std::pair<char, int>> freqVec(frequencyMap.begin(), frequencyMap.end());

        // Sort the vector based on frequency in decreasing order
        std::sort(freqVec.begin(), freqVec.end(), [](const std::pair<char, int>& a, const std::pair<char, int>& b) {
            return a.second > b.second; // Sort by frequency
        });

        // Step 3: Build the result string
        std::string result;
        for (const auto& pair : freqVec) {
            result += std::string(pair.second, pair.first); // Append character 'pair.first' 'pair.second' times
        }

        return result;
    }
};