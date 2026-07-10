class MedianFinder {
public:
        priority_queue<int>maxHeap;
        priority_queue<int , vector<int> , greater<int>>minHeap;
    MedianFinder() {


    }
    
    void addNum(int num) {
        if( maxHeap.empty() || maxHeap.top()  > num)
        maxHeap.push(num);
        else minHeap.push(num);

        if( abs((int) maxHeap.size() - (int)minHeap.size()  )> 1){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        if(maxHeap.size() < minHeap.size()){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    
    double findMedian() {
        if(minHeap.size() == maxHeap.size()){
          return   (double) (minHeap.top() + maxHeap.top() )/ 2;
        }
        else {
            return (double)maxHeap.top();
        }
    }
};

