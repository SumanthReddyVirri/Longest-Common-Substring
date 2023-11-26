#include <iostream>
#include <vector>
#include <string>
using namespace std;

string longest_common_substring(const string& str1, const string& str2, vector<vector<int>>& dp) {
    int n = str1.length(), m = str2.length();
    dp.assign(n + 1, vector<int>(m + 1, 0));
    int length = 0;  // Length of longest common substring
    int row, col;    // To store the end point of the longest common substring in str1

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (length < dp[i][j]) {
                    length = dp[i][j];
                    row = i;
                    col = j;
                }
            } else
                dp[i][j] = 0;
        }
    }

    if (length == 0) {
        return "";
    }

    string result;
    while (dp[row][col] != 0) {
        result = str1[row - 1] + result;
        --row;
        --col;
    }

    return result;
}

void print_table(const vector<vector<int>>& dp, const string& str1, const string& str2) {
    cout << "     ";
    for (int j = 0; j < str2.length(); j++) {
        cout << str2[j] << "   ";
    }
    cout << "\n";

    for (int i = 0; i < dp.size(); i++) {
        if (i > 0) cout << str1[i - 1] << " ";
        else cout << "  ";

        for (int j = 0; j < dp[0].size(); j++) {
            if (i > 0 && j > 0) {
                cout << dp[i][j] << "(" << str1.substr(0, i) << "," << str2.substr(0, j) << ") ";
            } else {
                cout << dp[i][j] << "   ";
            }
        }
        cout << "\n";
    }
}

int main() {
    string str1 = "ABAB";
    string str2 = "BABA";
    vector<vector<int>> dp;

    string lcs = longest_common_substring(str1, str2, dp);
    cout << "Longest Common Substring: " << lcs << endl;
    cout << "\nEnhanced Lookup Table:\n";
    print_table(dp, str1, str2);

    return 0;
}
