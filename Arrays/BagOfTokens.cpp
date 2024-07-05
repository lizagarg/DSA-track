class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int left=0;
        int right= tokens.size()-1;
        int maxScore=0;
        int currentScore=0;

        while (left <= right) {
            if (power >= tokens[left]) {
                // Play the token face up
                currentScore++;
                power -= tokens[left];
                left++;
            } else if (currentScore > 0) {
                // Play the token face down
                currentScore--;
                power += tokens[right];
                right--;
            } else {
                // If we can't play a token face up and have no score to play face down
                break;
            }
            maxScore = max(maxScore, currentScore);
        }
        return maxScore;
    }
};