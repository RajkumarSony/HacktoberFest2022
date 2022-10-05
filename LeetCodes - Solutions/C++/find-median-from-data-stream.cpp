class MedianFinder {
public:
    priority_queue<int> maxh;
    priority_queue<int,vector<int>, greater<int>> minh;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        maxh.push(num);              
        minh.push(maxh.top());    
        maxh.pop();                  
        if(maxh.size() < minh.size()){     
            maxh.push(minh.top());       
            minh.pop();                     
        }
    }
    
    double findMedian() {
        if(maxh.size()==minh.size()){
            double t = maxh.top()+minh.top();
            return t/2.0;
        }
        
        return maxh.top();
    }
};
