// https://leetcode.com/problems/find-median-from-data-stream/

class MedianFinder {
    priority_queue<int> lpq;
    priority_queue<int, vector<int>, greater<int>> hpq;
public:
    MedianFinder() {
    }
    
    void addNum(int num) {
        // we are always mainting such that we can directly fetch median
        // from the top of hpq if the count is odd
        hpq.push(num);
        
        // size diff is 2, making lpq size = hpq size - 1
        if(lpq.size()<hpq.size()-1){
            lpq.push(hpq.top());
            hpq.pop();
        }
        
        // else sending top from hpq (min element in hpq) to lpq
        // and then sending top from lpq (max element in lpq) to hpq
        else {
            int h=hpq.top();
            hpq.pop();
            lpq.push(h);
            int l=lpq.top();
            lpq.pop();
            hpq.push(l);
        }
        
    }
    
    double findMedian() {
        // equal size
        if(lpq.size()==hpq.size())
            return (double)(hpq.top()+lpq.top())/2.0;
        // otherwise, hqp's lowest is the median
        return hpq.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

 /*
 Time: O(logn) for addNum, O(1) for findMedian
 Space: O(n)
 */