#include<bits/stdc++.h>

using namespace std;

//Here is the code to find the longest palindrome centered at every index in a string in linear time using Manacher's Algo.

vector<int> oddPalin(string& s){
  int n = s.size();
  vector<int> d(n);
  for (int i = 0, l = 0, r = -1; i < n; i++) {
      int k = (i > r) ? 1 : min(d[l + r - i], r - i + 1);
      while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
          k++;
      }
      d[i] = k--;
      if (i + k > r) {
          l = i - k;
          r = i + k;
      }
  }
  return d;
}

vector<int> evenPalin(string& s){
  int n = s.size();
  vector<int> d(n);
  for (int i = 0, l = 0, r = -1; i < n; i++) {
      int k = (i > r) ? 0 : min(d[l + r - i + 1], r - i + 1);
      while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) {
          k++;
      }
      d[i] = k--;
      if (i + k > r) {
          l = i - k - 1;
          r = i + k ;
      }
  }
  return d;
}


int main(){
  string s = "abacabacabb";
  vector<int> d1 = oddPalin(s);
  vector<int> d2 = evenPalin(s);
  return 0;
}
