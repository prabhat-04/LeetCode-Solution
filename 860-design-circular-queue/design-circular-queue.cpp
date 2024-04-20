class MyCircularQueue {
    vector<int> queue;
    int size;
    int ind=-1,rear=-1;
public:
    MyCircularQueue(int k) {
        size=k;
        queue.resize(size);
    }
    
    bool enQueue(int value) {
        // if(ind==size-1) return false;
        // if((ind==0 && rear==size-1))
        if(isFull()) return false; 
        if(rear==-1){
            ind++;
            queue[++rear]=value;
        }
        else{
            rear = (rear+1)%size;
            queue[rear]=value;

        }
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;
        if(ind==rear){
            ind=rear=-1;
        }
        else{
            ind = (ind+1)%size;
        }
        return true;
    }
    
    int Front() {
        if(isEmpty()) return -1;
        return queue[ind];
    }
    
    int Rear() {
        if(isEmpty()) return -1;
        return queue[rear];
    }
    
    bool isEmpty() {
        if(ind==-1 || rear==-1) return true;
        return false;
    }
    
    bool isFull() {
        if((ind==0 && rear==size-1)|| (rear==ind-1)) return true;
        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */