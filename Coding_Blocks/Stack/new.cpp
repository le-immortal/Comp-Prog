#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define test(t) while(t--)
#define fo(i,a,n) for(int i = a; i < n; i++)
#define pb push_back
#define popb pop_back
#define MOD 1000000007
#define newline <<'\n';

int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    stack <int> s;
    int area = heights[0];
    s.push(0);
    for(int i = 1; i < n; i++){
        if(s.empty()){
            s.push(i);
        }
        else if(heights[i] >= heights[s.top()]){
            s.push(i);
            continue;
        } else {
            while(!s.empty() && heights[s.top()] > heights[i]){
                int h_min =heights[s.top()];
                int left = s.top();
                s.pop();
                if(s.empty()){
                    area = max(area, h_min*i);
                    break;
                }
                area = max(area, h_min*(i-s.top()-1));
            }
            s.push(i);
        }
    }
    while(!s.empty()){
                int x =heights[s.top()];
                s.pop();
                if(s.empty()){
                    area = max(area, x*n);
                    continue;
                }
                area = max(area, x*(n-s.top()-1));
            }
    return area;
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt","r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	vector <int> v{2,4,1,5,6,2,3};

	cout << largestRectangleArea(v);

	return 0;
} 