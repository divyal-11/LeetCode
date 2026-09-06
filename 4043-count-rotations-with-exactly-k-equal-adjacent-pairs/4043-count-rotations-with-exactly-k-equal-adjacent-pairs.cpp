class Solution {
public:
    int countRotations(string s, int k) {
        int n = s.size();
        int answer = 0;
        int score = 0;

        for (int rotation = 0; rotation < n; rotation++) {
            score = 0;
            // calc score of curr rotationn
            for (int i = 0; i <n ; i++) {
                if (s[i] == s[i + 1])
                    score++;
            }

            if (score == k)
                answer++;

            string rotated = "";
            rotated += s.substr(1, n - 1);
            rotated += s[0];

            s = rotated;
        }
        return answer;
    }
};