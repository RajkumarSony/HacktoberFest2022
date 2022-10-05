// Longest substring in a given string
// using Maps in C++

// input -> santhosh

// output -> length is = 6
//        -> String is = santho

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cout<<"Enter a String"<<endl;
    cin >> s;
    int ans = 0, len = 0, left = 0, r,p,q;
    map<char, int> m;

    // Check if the character in present in current longest substrig
    for (r = 0; r < s.length(); r++)
    {
        if (m.find(s[r]) == m.end())
        {
            m[s[r]] = r;
            len++;
        }
        else
        // if the character is present remove the character, until the repeat character is present
        {
            while (left <= m[s[r]])
            {
                m.erase(s[left]);
                left++;
            }
            m[s[r]] = r;
            len = r - left + 1;
        }
      if(len>ans)
      {
          ans=len;
          p=left;
          q=r+1;
          
      }
    }
    cout<<"Length of a longest string = "<<ans<<endl;
    cout<<"Longest Substring is = "<<s.substr(p,q)<<endl;
    return 0;
}