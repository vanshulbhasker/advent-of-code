#include <bits/stdc++.h>

using namespace std;
int kk=0;
int ret=0;
int ans=INT_MAX;
int visited[10][10];
int visited2[10][10];
void azad(){
    memset(visited,0,sizeof(visited));
}
void azad2(){
    memset(visited2,0,sizeof(visited2));
}
bool check(vector<vector<int>>& nums){
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(nums[i][j]!=1){
                return 0;
            }
        }
    }
    return 1;
}
void dfs2(vector<vector<int>>& nums, int i, int j){
    if(i<0 || i>9 || j<0 || j>9){
        return;
    }
    if(visited[i][j]==1 || visited2[i][j]==1)
    {
        return;
    }
    
    visited[i][j]=1;
    if(i-1>=0){
        nums[i-1][j]++;
        if(nums[i-1][j]>9){
             dfs2(nums,i-1,j);
             visited2[i-1][j]=1;
        }
    }
    if(i+1<=9){
        nums[i+1][j]++;
        if(nums[i+1][j]>9){
            dfs2(nums,i+1,j);
            visited2[i+1][j]=1;
        }
        
    }
    if(j+1<=9){
        nums[i][j+1]++;
        if(nums[i][j+1]>9){
            dfs2(nums,i,j+1);
            visited2[i][j+1]=1;
        }
    }
    if(j-1>=0){
        nums[i][j-1]++;
        if(nums[i][j-1]>9){
            dfs2(nums,i,j-1);
            visited2[i][j-1]=1;
        }
    }
    if(i-1>=0 && j-1>=0){
        nums[i-1][j-1]++;
        if(nums[i-1][j-1]>9){
            dfs2(nums,i-1,j-1);
            visited2[i-1][j-1]=1;
        }
    }
    if(i-1>=0 && j+1<=9){
        nums[i-1][j+1]++;
        if(nums[i-1][j+1]>9){
             dfs2(nums,i-1,j+1);
             visited2[i-1][j+1]=1;
        }
    }
    if(i+1<=9 && j-1>=0){
        nums[i+1][j-1]++;
        if(nums[i+1][j-1]>9){
            dfs2(nums,i+1,j-1);
            visited2[i+1][j-1]=1;
        }
    }
    if(i+1<=9 && j+1<=9){
        nums[i+1][j+1]++;
        if(nums[i+1][j+1]>9){
            dfs2(nums,i+1,j+1);
            visited2[i+1][j+1]=1;
        }
    }
}
void dfs(vector<vector<int>>& nums){
    for(int i=0;i<nums.size();i++){
        for(int j=0;j<nums[i].size();j++){
            if(nums[i][j]>9){
                if(visited2[i][j]==1){
                    continue;
                }
                dfs2(nums,i,j);
                visited2[i][j]=1;
                azad();
            }
        }
    }

    for(int i=0;i<nums.size();i++){
        for(int j=0;j<nums[i].size();j++){
            if(nums[i][j]>9){
                nums[i][j]=0;
                visited2[i][j]=0;
                ret++;
            }
        }

    }

}
int main() {
    
    
    vector<vector<int>> nums;
    for(int j=0;j<10;j++){
        string s;
        cin>>s;
        vector<int> a;
        for(int i=0;i<s.size();i++){
            string k="";
            k+=s[i];
            a.push_back(stoi(k));
        }
       nums.push_back(a);
    }

    for(int k=0;k<100000;k++){
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums[i].size();j++){
                nums[i][j]++;
            }
        }
        dfs(nums);

        if (check(nums)){
            ans=min(ans, kk);
            break;
        }
        azad2();
        kk++;
    }
 
    cout<<ans;
    
    return 0;
}
