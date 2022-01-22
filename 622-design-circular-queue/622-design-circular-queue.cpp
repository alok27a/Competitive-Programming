class MyCircularQueue {
private:
    vector<int> v;
    int front, rear, maxLimit;
    void makeEmpty(){
        front = rear = -1;
    }
    void initQueue(){
        front = rear = 0;
    }
    void incrementRear(){
        ++rear;
        if(rear > maxLimit) rear = 0;
    }
    void incrementFront(){
        ++front;
        if(front > maxLimit) front = 0;
    }
    bool noItemRemain(){
        return front == rear && front != -1;
    }
public:
    MyCircularQueue(int k) {
        v.resize(k, -1);
        front = rear = -1;
        maxLimit = k - 1;
    }

    bool enQueue(int value) {
        if(isFull()) return false;
        else{
           if(isEmpty()){
               initQueue();
               v[rear] = value;
           }
           else{
               incrementRear();
               v[rear] = value;
           }
           return true;
        }
    }

    bool deQueue() {
        if(isEmpty()) return false;
        else{
            v[front] = -1;
            if(noItemRemain()) makeEmpty();
            else incrementFront();
            return true;
        }

    }

    int Front() {
        if(isEmpty()) return -1;
        else return v[front];
    }

    int Rear() {
        if(isEmpty()) return -1;
        else return v[rear];
    }

    bool isEmpty() {
        return front == rear && front == -1;
    }

    bool isFull() {
        return (front == 0 && rear == maxLimit) || (rear == front - 1);
    }
};