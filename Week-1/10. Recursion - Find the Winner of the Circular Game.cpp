https://leetcode.com/problems/find-the-winner-of-the-circular-game/

class Solution {
    int help(int n, int &k) {
        if(n==1){
            return 0;
        }
        return ((help(n-1, k)+k)%n);
    }
public:
    int findTheWinner(int n, int k) {
        return help(n, k) +1;
    }
};