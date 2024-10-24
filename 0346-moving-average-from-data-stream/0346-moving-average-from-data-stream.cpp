class MovingAverage {
public:
    queue<int> q;
    int currentValue;
    int currentSize;
    int globalSize;
    MovingAverage(int size) {
        for(int i = 0; i < size ; i++) q.push(0);
        currentValue = 0;
        currentSize = 0;
        globalSize = size;
    }
    
    double next(int val) {
        int frontValue = q.front();
        q.pop();
        q.push(val);
        currentSize = (currentSize >= globalSize) ? globalSize : currentSize + 1;
        currentValue = currentValue - frontValue + val;
        return (double)currentValue / currentSize;
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */