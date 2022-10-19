// https://practice.geeksforgeeks.org/problems/get-minimum-element-from-stack/1?page=1&difficulty[]=0&difficulty[]=1&difficulty[]=2&category[]=Stack&category[]=Queue&sortBy=submissions

class Solution{
    int minEle;
    stack<pair<int, int>> s;
    public:
    
       /*returns min element from stack*/
       int getMin(){
           
           //Write your code here
           if(s.empty())
            return -1;
           return s.top().second;
       }
       
       /*returns poped element from stack*/
       int pop(){
           
           //Write your code here
           if(s.empty())
            return -1;
           auto a=s.top();
           s.pop();
           return a.first;
       }
       
       /*push element x into the stack*/
       void push(int x){
           
           //Write your code here
           if(s.empty()){
               s.push({x, x});
           }
           else if(s.top().second>=x){
               s.push({x,x});
           }
           else{
               s.push({x, s.top().second});
           }
       }
};

/*
Time: O(1)
Space: O(1)
*/