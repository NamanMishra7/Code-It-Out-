#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the solve function below.
int nCrModp(int n, int r, int p) 
{ 
    if (r > n - r) 
        r = n - r; 
    int C[r + 1]; 
    memset(C, 0, sizeof(C)); 
    C[0] = 1;
    for (int i = 1; i <= n; i++) { 
        for (int j = min(i, r); j > 0; j--) 
            C[j] = (C[j] + C[j - 1]) % p; 
    } 
    return C[r]; 
} 

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string nm_temp;
        getline(cin, nm_temp);

        vector<string> nm = split_string(nm_temp);

        int n = stoi(nm[0]);

        int m = stoi(nm[1]);

        int result = nCrModp(n+m, m, 1000000007);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
