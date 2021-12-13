#include <bits/stdc++.h>
using namespace std;

void foldx(vector<vector<int>> &dp, int x){
    for(int i=0;i<2000;i++){
        for(int j=x+1;j<=2*x;j++){
            int d=abs(j-x);
            if(dp[i][j])      dp[i][j-d-d]=1;
        }
    }
}

void foldy(vector<vector<int>> &dp, int y){
    for(int i=y+1;i<=2*y;i++){
        for(int j=0;j<2000;j++){
            int d=abs(i-y);
            if(dp[i][j])         dp[i-d-d][j]=1;
        }
    }
}
vector<int> split(string s){
    string a="",b="";
    int i=0;
    for(i=0;i<s.size();i++){
        if(s[i]==','){
            break;
        }
        else{
            a+=s[i];
        }
    }
    i++;
    for(i;i<s.size();i++){
        b+=s[i];
    }
    vector<int> ret;
    ret.push_back(stoi(a));
    ret.push_back(stoi(b));
    return ret;
}
int main() {
    vector<vector<int>> dp(2500,vector<int>(2500));

    for(int pp=0;pp<715;pp++){
        string s;
        cin>>s;
        vector<int> nums=split(s);
        dp[nums[1]][nums[0]]=1;

    }
    int ret=0;    
    
    cout<<endl<<endl;
    
    foldx(dp,655);
    foldy(dp,447);
    foldx(dp,327);
    foldy(dp,223);
    foldx(dp,163);
    foldy(dp,111);
    foldx(dp,81);
    foldy(dp,55);
    foldx(dp,40);
    foldy(dp,27);
    foldy(dp,13);
    foldy(dp,6);

    
    for(int i=0;i<6;i++){
        for(int j=0;j<40;j++){
            
            if(dp[i][j]){
                ret++;
                cout<<"*";
            }
            else{
                cout<<" ";
            }
        }
        cout<<endl;
    }

}
