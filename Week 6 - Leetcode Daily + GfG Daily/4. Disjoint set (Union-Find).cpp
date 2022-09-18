// https://practice.geeksforgeeks.org/problems/disjoint-set-union-find/1?page=1&category[]=union-find&category[]=Disjoint%20Set&sortBy=submissions

/*Complete the functions below*/
int find(int par[],int a)
{
       //add code here
        if(a==par[a])
            return a;
        return par[a]=find(par, par[a]);
}
void unionSet(int par[],int a,int b)
{
	//add code here.
    int par_a=find(par, par[a]);
    int par_b=find(par, par[b]);
    if(par_a!=par_b){
        par[par_a]=par_b;
    }
}

/*
Time Complexity:
Space Complexity:
*/