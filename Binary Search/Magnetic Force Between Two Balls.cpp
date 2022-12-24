class Solution {
    int calculateMinDist(vector<int>& position, int dist){
        int ans=1;
        int prevPos=position[0];
        for(int i=1;i<position.size();i++){
            if(position[i]>=(prevPos+dist)){
                ans++;
                prevPos=position[i];
            }
        }
        return ans;
    }
public:
    int maxDistance(vector<int>& position, int m) {
        int n=position.size();
        sort(position.begin(), position.end());
        int s=1; // minimum magnetic force
        int e=position[n-1]-position[0];
        int ans=-1;
        while(s<=e){
            int mid=(e-s)/2+s;
            int baskets=calculateMinDist(position, mid);
            cout<<baskets<<" "<<mid<<"\n";
            if(baskets>=m){
                ans=max(mid, ans);
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        return ans;
    }
};