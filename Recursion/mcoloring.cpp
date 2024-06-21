//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    bool isSafe(int node, int color[], bool graph[101][101], int n, int col ) {
        for(int k = 0; k < n; k++) {
            // checking every adjacent node
            if(k != node && graph[k][node] == 1 && color[k] == col) {
                return false;
            }
        }
        return true;
    }
    
    bool solve(int node, int color[],int m, int n, bool graph[101][101] ){
        if(node==n) return true;
        for(int col=1;col<=m;col++) {
            if(isSafe(node, color, graph, n, col)) {
                color[node]=col;
                if(solve(node+1,color,m,n,graph)== true)
                return true;
            }
        }
        return false;
    }
    
    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
        int color[n]={0};
        return solve(0,color,m,n,graph);
    }
};
