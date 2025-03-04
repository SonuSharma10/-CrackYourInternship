// You are given a string s of lowercase English letters and an integer array shifts of the same length.

// Call the shift() of a letter, the next letter in the alphabet, (wrapping around so that 'z' becomes 'a').

// For example, shift('a') = 'b', shift('t') = 'u', and shift('z') = 'a'.
// Now for each shifts[i] = x, we want to shift the first i + 1 letters of s, x times.

// Return the final string after all such shifts to s are applied.

// Example 1:

// Input: s = "abc", shifts = [3,5,9]
// Output: "rpl"
// Explanation: We start with "abc".
// After shifting the first 1 letters of s by 3, we have "dbc".
// After shifting the first 2 letters of s by 5, we have "igc".
// After shifting the first 3 letters of s by 9, we have "rpl", the answer.
// Example 2:

// Input: s = "aaa", shifts = [1,2,3]
// Output: "gfd"

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string shiftingLetters(string s, vector<int> &shifts)
    {
        int loop = s.size();
        vector<int> arr(loop + 1, 0);
        for (int i = 0; i < loop; i++)
        {
            int start = 0;
            shifts[i] %= 26;
            arr[start] += shifts[i];
            arr[i + 1] -= shifts[i];
        }
        int sum = 0;
        for (int i = 0; i < loop; i++)
        {
            sum += arr[i];
            s[i] = 'a' + ((s[i] - 'a' + sum) % 26 + 26) % 26;
        }
        return s;
    }
};