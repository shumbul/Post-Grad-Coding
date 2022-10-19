// https://leetcode.com/problems/minimum-hours-of-training-to-win-a-competition/

class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        int ans=0;
        for(int i=0;i<energy.size();i++){
            if(initialEnergy<=energy[i]){
                ans+=(energy[i]-initialEnergy+1);
                initialEnergy+=(energy[i]-initialEnergy+1);
            }
            if(initialExperience<=experience[i]){
                ans+=(experience[i]-initialExperience+1);
                initialExperience+=(experience[i]-initialExperience+1);
            }
            initialEnergy-=energy[i];
            initialExperience+=experience[i];
        }
        return ans;
    }
};

/*
    Time Complexity: O(n)
    Space Complexity: O(n)
*/