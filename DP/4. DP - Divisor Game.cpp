// https://leetcode.com/problems/divisor-game/

class Solution {
public:
    bool divisorGame(int n) {
        // notice the pattern of who wins
        return n%2==0;
    }
};