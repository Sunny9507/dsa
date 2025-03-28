class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        sort(skill.begin(), skill.end()); 
        
        int teamSkill = skill[0] + skill[n - 1]; 
        long long totalChemistry = 0;
        
        for (int i = 0; i < n / 2; i++) {
            if (skill[i] + skill[n - 1 - i] != teamSkill) {
                return -1; 
            }
            totalChemistry += (long long)skill[i] * skill[n - 1 - i]; 
        }
        
        return totalChemistry;
    }
};
