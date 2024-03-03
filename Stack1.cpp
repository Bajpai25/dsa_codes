The Celebrity Problem
MediumAccuracy: 38.33%Submissions: 221K+Points: 4
Internship Alert
New month-> Fresh Chance to top the leaderboard and get SDE Internship! 

banner
A celebrity is a person who is known to all but does not know anyone at a party. If you go to a party of N people, find if there is a celebrity in the party or not.
A square NxN matrix M[][] is used to represent people at the party such that if an element of row i and column j  is set to 1 it means ith person knows jth person. Here M[i][i] will always be 0.
Return the index of the celebrity, if there is no celebrity return -1.
Note: Follow 0 based indexing.
Follow Up: Can you optimize it to O(N)
 

Example 1:

Input:
N = 3
M[][] = {{0 1 0},
         {0 0 0}, 
         {0 1 0}}
Output: 1
Explanation: 0th and 2nd person both
know 1. Therefore, 1 is the celebrity. 

Example 2:

Input:
N = 2
M[][] = {{0 1},
         {1 0}}
Output: -1
Explanation: The two people at the party both
know each other. None of them is a celebrity.

Your Task:
You don't need to read input or print anything. Complete the function celebrity() which takes the matrix M and its size N as input parameters and returns the index of the celebrity. If no such celebrity is present, return -1.


Expected Time Complexity: O(N^2)
Expected Auxiliary Space: O(1)


Constraints:
2 <= N <= 3000
0 <= M[][] <= 1


  Code in c++

  //{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    private:
    
    bool knows(vector<vector<int> >& M, int a,int b){
        if(M[a][b]==1){
            return true; // koi bhi kisi ko janta hh agar toh dikkat hh 
        }
        else{
            return false;
        }
    }
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
            stack<int>st;
            
            for(int i=0;i<n;i++){
                st.push(i);
            }
            
            while(st.size()>1){
                int a=st.top(); //pehla element pakdho
                st.pop();
                int b=st.top(); // doosra element pakdo 
                st.pop();
                
                if(knows(M,a,b)){ // a knows b so a is not celebrity so pop a and push b
                    st.push(b);
                }
                else {
                    st.push(a); // else b knows a so pop b and push a 
                }
            }
            int celebrity=st.top();
            
            bool rowcheck=false;
            bool colcheck=false;
            int colcount=0;
            int rowcount=0;
            
            for(int i=0;i<n;i++){
                if(M[celebrity][i]==0){ // row check that each element in row is 0 
                    rowcount++;
                }
            }
            
            if(rowcount==n){
                rowcheck=true;
            }
            for(int i=0;i<n;i++){
                if(M[i][celebrity]==1){ //col check that each element is 1 
                   colcount++; 
                }
            }
            
            if(colcount==n-1){ // n-1 because diagnal element is not taken in consideration as it can be zero  celebrity khud ko toh jaanta hh hoga
                colcheck=true;
            }
            
            if(rowcheck==true && colcheck==true){
                return celebrity;
            }
            else{
                return -1;
            }
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends
