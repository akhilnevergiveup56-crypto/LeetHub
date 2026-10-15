
class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) return "";

        unordered_map<char, int> need, window;

        for (char c : t) {
            need[c]++;
        }

        int required = need.size();
        int formed = 0;

        int left = 0;
        int minLen = INT_MAX;
        int start = 0;

        for (int right = 0; right < s.size(); right++) {
            char c = s[right];

            // Expand the window
            if (need.count(c)) {
                window[c]++;

                if (window[c] == need[c]) {
                    formed++;
                }
            }

            // Shrink the window while it remains valid
            while (formed == required) {
                int len = right - left + 1;

                if (len < minLen) {
                    minLen = len;
                    start = left;
                }

                char removed = s[left];

                if (need.count(removed)) {
                    if (window[removed] == need[removed]) {
                        formed--;
                    }

                    window[removed]--;
                }

                left++;
            }
        }

        return minLen == INT_MAX
                   ? ""
                   : s.substr(start, minLen);
    }
};
