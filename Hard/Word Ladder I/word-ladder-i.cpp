//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        // Code here
        unordered_set<string> st(wordList.begin(),wordList.end());
        queue<pair<string,int>> pq;
        pq.push({startWord,1});
        st.erase(startWord);
        while(!pq.empty()){
            string cur=pq.front().first;
            int l=pq.front().second;
            if(cur==targetWord)return l;
            pq.pop();
            for(int i=0;i<cur.size();i++){
                char original=cur[i];
                for(char ch='a';ch<='z';ch++){
                    cur[i]=ch;
                   if(st.find(cur) !=st.end()){
                       st.erase(cur);
                       pq.push({cur,l+1});
                   }
                }
                cur[i]=original;
            }
        }
        return 0;
        
        
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends