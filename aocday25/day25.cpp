#include <bits/stdc++.h>
using namespace std;
int f=0;
void print(vector<vector<char>> &nums){
    for(int i=0;i<nums.size();i++){
        for(int j=0;j<nums[0].size();j++){
            cout<<nums[i][j]<<" ";
        }
        cout<<endl;
        
    }
    cout<<endl;
    cout<<endl;
}
void dfs(vector<vector<char>>&nums,  vector<vector<char>> &copy){
    for(int i=0;i<nums.size();i++){
        for(int j=0;j<nums[i].size();j++){
            copy[i][j]=nums[i][j];
        }
    }
    int i=0;
    int j=0;
    for(i=0;i<nums.size();i++){
        for(j=0;j<nums[0].size()-1;j++){
            if(nums[i][j]=='>'){
                int k=j+1;
                if(k>=nums[i].size()){
                    k=0;
                }

                if(nums[i][k]=='.'){
                    nums[i][j]='.';
                    nums[i][k]='>';
                     j++;
                    f=1;
                }
            }
        }
        if(j!=nums[0].size()-1){
            continue;
        }
        int k=0;
        if(copy[i][0]=='.' && nums[i][0]=='.' && nums[i][nums[0].size()-1]=='>'){
                    nums[i][nums[0].size()-1]='.';
                    nums[i][0]='>';
                 
                    f=1;
        }
    }
    for(int i=0;i<nums.size();i++){
        for(int j=0;j<nums[i].size();j++){
            copy[i][j]=nums[i][j];
        }
    }
    // print(nums);
    i=0;
    j=0;
    for( j=0;j<nums[0].size();j++){
        for(i=0;i<nums.size()-1;i++){
            if(nums[i][j]=='v'){
                int k=i+1;
                

                if(nums[k][j]=='.'){
                    nums[i][j]='.';
                    nums[k][j]='v';
                    i++;
                    f=1;
                }
            }
        }
        if(i!=nums.size()-1){
            continue;
        }
        int k=0;
        if(copy[0][j]=='.' && nums[0][j]=='.' && nums[nums.size()-1][j]=='v'){
                    nums[nums.size()-1][j]='.';
                    nums[0][j]='v';
                    
                    f=1;
        }
        
    }
    // print(nums);
}
int main() {
    vector<vector<char>> nums;
    vector<vector<char>> copy;
    for(int pp=0;pp<137;pp++){
        string s;
        cin>>s;
        vector<char> a;
        for(int i=0;i<s.size();i++){
            a.push_back(s[i]);
        }
        nums.push_back(a);
        copy.push_back(a);
    }
    long long int ret=0;
     
    while(1==1){
        f=0;
        dfs(nums,copy);
        if(f==0){
            break;
        }
        
        ret++;
        // print(nums);
    }
    cout<<ret+1;
}
