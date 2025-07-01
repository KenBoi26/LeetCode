class MyCircularQueue {
public:

    class Node{
        public:
            int data;
            Node* next;
        
            Node(): data(0), next(nullptr){}
            Node(int val):data(val), next(nullptr){}
            Node(int val, Node* pos):data(val), next(pos){}


    };

    Node* head;
    Node* tail;
    int maxSize;
    int currSize;

    
    MyCircularQueue(int k) {
        maxSize = k;
        currSize = 0;
        head = nullptr;
        tail = nullptr;
    }


    
    bool enQueue(int value) {
        if(isFull()){
            return false;
        }
        Node* newNode = new Node(value);
        if(isEmpty()){
            head = newNode;
            tail = newNode;
            newNode->next = head;
        }else{
            tail->next = newNode;
            newNode->next = head;
            tail = newNode;
        }

        currSize++;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()){
            return false;
        }

        if(currSize == 1){
            delete head;
            head = nullptr;
            tail = nullptr;
        }else{
            Node* old = head;
            head = old->next;
            tail->next = head;
            delete old;
        }
        currSize--;
        return true;
    }
    
    int Front() {
        if (isEmpty()) {
            return -1;
        }

        return head->data;
    }
    
    int Rear() {
        if (isEmpty()) {
            return -1;
        }
        return tail->data;
    }
    
    bool isEmpty() {
        return currSize == 0;
    }
    
    bool isFull() {
        return currSize == maxSize;
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