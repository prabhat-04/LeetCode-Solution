class MyCircularDeque {
    vector<int> vec;
    int size,K=0;
    int front=0,back=0;
public:
    MyCircularDeque(int k) {
        vec.resize(k);
        size=k;
        // back=k-1;
    }
    
    bool insertFront(int value) {
        if(isFull()) return false;
        front = (front-1 +size)%size;
        vec[front]=value;
        K++;
        if(K==1) back=front;
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull()) return false;
        back =(back+1 +size)%size;
        vec[back] = value;
        K++;
        if(K==1) back=front;
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty()) return false;
        front = (front+1)%size;
        K--;
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty()) return false;
        back = (back-1+size)%size;
        K--;
        return true;
    }
    
    int getFront() {
        if(isEmpty()) return -1;
        return vec[front];
    }
    
    int getRear() {
        if(isEmpty()) return -1;
        return vec[back];
    }
    
    bool isEmpty() {
        return K==0;
    }
    
    bool isFull() {
        return K==size;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */