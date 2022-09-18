// https://practice.geeksforgeeks.org/problems/detect-cycle-using-dsu/1?page=1&status[]=unsolved&category[]=union-find&category[]=Disjoint%20Set&sortBy=submissions

class Solution
{
    int find(int a, vector<int> &par){
        // finding parent
        if(a==par[a]){
            return a;
        }
        return par[a]=find(par[a], par);
    }
    void union_(int a, int b, vector<int> &par){
        par[a]=b;
    }
    public:
    //Function to detect cycle using DSU in an undirected graph.
	int detectCycle(int V, vector<int>adj[])
	{
	    // Code here
	    vector<int> par(V);
	    for(int i=0;i<V;i++)
	        par[i]=i;
	        
	    for(int i=0;i<V;i++){
	        for(int j: adj[i]){
	           // cout<<i<<" "<<j<<"\n";
                int a=find(i, par);
                int b=find(j, par);
                // because the graph is undirected, we are checking for i<j to make sure cycle is not detected unnecessarily
	            if(a==b && i<j){
	                return true;
	            }
	            union_(a, b, par);
	        }
	    }
	    return false;
	}
};

/*
Time Complexity: O(V + E)
Space Complexity: O(V)
*/