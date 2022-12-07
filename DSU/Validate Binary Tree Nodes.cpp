// https://leetcode.com/problems/validate-binary-tree-nodes

// basic DSU problem
class Solution {
    class DSU{
    public:
        vector<int> par;
        DSU(int n) {
            par.resize(n, 0);
            for(int i=0;i<n;i++)
                par[i]=i;
        }
        void union_(int &a, int &b){
            par[b]=find(a);
        }
        int find(int a){
            if(par[a]==a)
                return a;
            return par[a]=find(par[a]);
        }
    };
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        DSU dsu(n);
        for(int i=0;i<n;i++){
            // cout<<i<<"->";
            int par=dsu.find(i);
            // cout<<par<<" ";

            if(leftChild[i]!=-1){
                int left=dsu.find(leftChild[i]);
                if(par!=left)
                    dsu.union_(par, left);
                else
                    return false;
            }
            if(rightChild[i]!=-1){
                int right=dsu.find(rightChild[i]);
                if(par!=right)
                    dsu.union_(par, right);
                else
                    return false;
            }
        }
        // make sure all are connected and only 1 node is there with indegree 0
        vector<int> inDeg(n, 0);
        for(int i=0;i<n;i++){
            if(leftChild[i]!=-1)
                inDeg[leftChild[i]]++;
            if(rightChild[i]!=-1)
                inDeg[rightChild[i]]++;
        }
        bool foundRoot=false;
        for(int i=0;i<n;i++){
            if(inDeg[i]==0){
                if(foundRoot)
                    return false;
                foundRoot=true;
            }
            if(inDeg[i]>1)
                return false;
        }
        return true;
    }
};

/* 
Time: O(n)
Space: O(n)
*/