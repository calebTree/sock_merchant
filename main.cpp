//#include <iostream>
//#include <vector>
#include <bits/stdc++.h>
using namespace std;

vector<string> split_string(string);

int sockMerchant(int n, vector<int> ar) {
    int pair = 0;
    bool paired[n] {}; // initialize all parallel paired elements to false

    // pick all elements one by one
    for (int i = 0; i <= n - 1; i++) {
        // see if there is a pair for the picked element
        for (int j = i + 1; j <= n - 1; j++) {
            // advance comparison until picked element has not already been paired
            while (paired[i] == true) {
                i++;
                // prevent out-of-bounds
                if (j < n - 1)
                    j++;
            }
            // compare if not last element to itself
            if (ar[i] == ar[j] && i != n - 1) {
                pair++;
                paired[j] = true;
                break;
            }
        }
    }
    return pair;
}

int main()
{
    cout << "Hello world!" << endl;

    int n;
    cout << "Input n number of elements: ";
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string ar_temp_temp;
    cout << "Input string of n numbers seperated by a space: ";
    getline(cin, ar_temp_temp);

    vector<string> ar_temp = split_string(ar_temp_temp);

    vector<int> ar(n);

    for (int i = 0; i < n; i++) {
        int ar_item = stoi(ar_temp[i]);

        ar[i] = ar_item;
    }

    int result = sockMerchant(n, ar);

    cout << "There were " << result << " pairs in your string.\n";

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
