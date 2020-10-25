#include<bits/stdc++.h>

using namespace std;

//Here comes the code to find prefix function for each index of a string using Knuth Morris Pratt

vector<int> prefix_function(string& s) {
    int n = s.size();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    
    return pi;
}


int main(){
  string s = "abababab";

  return 0;
}
