//DP solution

class Solution {
public:

    int dp[1010][1010];
    string longestPalindrome(string s) {

        int len = s.length();

        if(len<2)
            return s;

        int begin = 0, end = 0;
        for(int r = 1;r<len;r++){
            for(int l=0;l<r;l++){

                bool isInnerWordPalindrome = dp[l+1][r-1] || r-l<=2;

                if(s[l]==s[r] && isInnerWordPalindrome){
                    dp[l][r] = 1;

                    if(end-begin< r-l){
                        begin = l;
                        end = r;
                    }
                }
            }
        }


        string retStr = s.substr(begin,end-begin+1);
        return retStr;


    }
};

//EXPANDING AROUND THE CENTER. MEMORY USAGE: O(1)
class Solution {
public:

    int ExpandAroundCenter(int l, int r, string s){

        int begin = l, end = r;

        while(begin>=0 && end<s.length() && s[begin]==s[end]){
            begin--;
            end++;
        }

        return end - begin - 1;
    }

    string longestPalindrome(string s) {

        int len = s.length();

        if(len<2)
            return s;

        int begin = 0, end = 0;

        for(int i=0;i<len; i++){

            int len1 = ExpandAroundCenter(i,i,s);
            int len2 = ExpandAroundCenter(i,i+1,s);

            int largerLen = max(len1,len2);
            int b = i - (largerLen-1)/2;
            int e = i + (largerLen)/2;

            if(end-begin< e-b){
                end = e;
                begin = b;
            }
        }


        string retStr = s.substr(begin,end-begin+1);
        return retStr;


    }
};

//MANACHER'S ALGO. TIME COMPLEXITY: O(N)
//i is trying to find the next center of the main palindrome
//C is the center of the current main palindrome
class Solution {
public:


    string longestPalindrome(string s) {

        int len = s.length();

        if(len<2)
            return s;

        string t = "$";
        int p[4000];
        //cout<<p.size()<" "<<t.length()<<endl;

        for(int i = 0;i<len;i++){
            t.append("#");
            t.append(string(1, s[i]));
        }
        t.append("#@");
        //cout<<t<<endl;

        int C = 0, R = 0;
        for(int i=1;i<t.length()-1;i++){
            int mirr = 2*C - i;

            if(i<R)
                p[i] = min(p[mirr], R-i);

            while(t[i+(1+p[i])] == t[i-(1+p[i])])
                p[i]++;

            if(i+p[i]>R){
                C = i;
                R = i+p[i];
            }
        }

        int center = -1, length = -1;
        for(int i=1;i<t.length()-1;i++){
            if(p[i]>length && (t[i] != '#' || t[i] != '@' ||t[i] != '$')){
                length = p[i];
                center = i/2 - 1;
            }
        }

        int begin = center - (length-1)/2;
        int end = center + length/2;

        string retStr = s.substr(begin,end-begin+1);
        return retStr;

        // return "";
    }
};
