 #include<bits/stdc++.h>
#include<climits>
using namespace std;
#define ll long long
#define test(t) while(t--)
#define fo(i,a,n) for(int i = a; i < n; i++)

int solve(int n,int x,int y,int z, int dp[]){
    dp[0] = 0;
    dp[1] = 0;
    for(int i = 2; i <=n; i++){
        if(i&1){
            dp[i] = min((dp[i-1] +y),(dp[i+1]/2 + x +z) );
        }else{
            dp[i] = min(dp[i/2] +x, dp[i-1]+y);
        }
    }
    return dp[n];
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    int i,x,y,z;
    cin >> i >> x >> y >> z;
    int dp[100] = {0};
    dp[0] = 0;
    cout << solve(i,x,y,z,dp);

 	return 0;
}