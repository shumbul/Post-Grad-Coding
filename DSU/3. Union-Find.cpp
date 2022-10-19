// https://practice.geeksforgeeks.org/problems/union-find/1?page=1&category[]=union-find&category[]=Disjoint%20Set&sortBy=submissions

class Solution
{
    int find(int a, int par[]){
        if(a==par[a])
            return a;
        return par[a]=find(par[a], par);
    }
    
    public:
    //Function to merge two nodes a and b.
    void union_( int a, int b, int par[], int rank1[]) 
    {
        //code here
        int par_a=find(par[a], par);
        int par_b=find(par[b], par);
        if(par_a!=par[b]){
            if(rank1[par_a]<rank1[par_b]){
                // b has a bigger group -> b dominates
                rank1[par_b]++;
                par[par_a]=par_b;
            }
            else{
                // a dominates
                rank1[par_a]++;
                par[par_b]=par_a;
            }
        }
    }
    
    //Function to check whether 2 nodes are connected or not.
    bool isConnected(int x,int y, int par[], int rank1[])
    {
        //code here
        return find(x, par)==find(y, par);
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/