class Solution {
public:
    // Function to generate all unique permutations of vector 'nums'.
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        // First, sort the array to handle duplicates.
        sort(nums.begin(), nums.end());
        // Get the size of the nums vector.
        int size = nums.size();
        // This will hold all the unique permutations.
        vector<vector<int>> permutations;
        // Temporary vector to hold current permutation.
        vector<int> current(size);
        // Visited array to keep track of used elements.
        vector<bool> visited(size, false);

        // Recursive lambda function to perform Depth-First Search.
        function<void(int)> dfs = [&](int depth) {
            // If the current permutation is complete, add to permutations.
            if (depth == size) {
                permutations.emplace_back(current);
                return;
            }
            // Iterate over all elements in 'nums'.
            for (int i = 0; i < size; ++i) {
                // Skip already visited elements or duplicates not in sequence.
                if (visited[i] || (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1])) {
                    continue;
                }
                // Place nums[i] in the current position.
                current[depth] = nums[i];
                // Mark this element as visited.
                visited[i] = true;
                // Recurse with next position.
                dfs(depth + 1);
                // Reset visited status for backtracking.
                visited[i] = false;
            }
        };
        // Start the recursive process with the first position.
        dfs(0);
        // Return the resulting permutations.
        return permutations;
    }
};
