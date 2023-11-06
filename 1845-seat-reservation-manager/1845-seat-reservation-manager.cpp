class SeatManager {
private:
    set<int> seats;
public:
    SeatManager(int n) {
        for(int i=1;i<=n;i++)
            seats.insert(i);
    }
    
    int reserve() {
        if(seats.empty())
            return -1;
        int temp = *seats.begin();
        seats.erase(seats.begin());
        return temp;
    }
    
    void unreserve(int seatNumber) {
        if(seatNumber>0)
            seats.insert(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */