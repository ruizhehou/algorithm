//
// Created by Ruizhe Hou on 2020/10/8.
//

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<string> cipher = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--",
                             "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--",
                             "--.."};

    int uniqueMorseRepresentations(vector<string> &words) {
        unordered_set<string> us;
        for (const string &word : words) {
            string t;
            for (char c : word) {
                t += cipher[c - 'a'];
            }
            us.insert(t);
        }
        return us.size();
    }
};

int main() {
    Solution sol;
    vector<string> words = {"gin", "zen", "gig", "msg"};
    cout << sol.uniqueMorseRepresentations(words) << endl; // 2
    return 0;
}