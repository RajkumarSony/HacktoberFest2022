class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) 
    {
        vector<string> ans;
        unordered_map<string, int> m;    //store every string with length 10
        int n = s.size(), i=0, j=9;      //window size = 10
        
        while(j<n)
        {
            m[s.substr(i, j-i+1)]++;     //store the string from i to j in map
            i++;                         //slide the window one index right to maintain window size = 10
            j++;
        }
        for(auto i: m)
            if(i.second > 1)             //the string which has frequency > 1 will be in answer
                ans.push_back(i.first);
        return ans;
    }
};
