class MyLinkedList {
    class Node{
    public:
        int data;
        Node* next;

        Node(int val){
            data = val;
            next = NULL;
        }
    };
public:
    Node* head;
    MyLinkedList() {
        head = nullptr;
    }
    
    int get(int index) {
        Node* temp = head;
        int count = 0;

        while (temp != nullptr) {
            if (count == index) return temp->data;
            count++;
            temp = temp->next;
        }

        return -1;
    }
    
    void addAtHead(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }
    
    void addAtTail(int val) {
        Node* newNode = new Node(val);
        if(head == nullptr){
            head = newNode;
            return;
        }
        Node* temp = head;

        while(temp->next){
            temp = temp->next;
        }

        temp->next = newNode;
    }
    
    void addAtIndex(int index, int val) {
        Node* newNode = new Node(val);
        Node* temp = head;

        if(index == 0){
            addAtHead(val);
            return;
        }
        
        for(int i=0; i<index-1; i++){
            if(!temp) return;
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }
    
    void deleteAtIndex(int index) {
        
        Node* temp = head;

        if(index == 0){
            Node* toDel = head;
            head = head->next;
            delete toDel;
            return;
        }

        for(int i=0; i<index-1; i++){
            if(!temp || !temp->next) return;
            temp = temp->next;
        }

        if(!temp->next) return;

        Node* toDel = temp->next;

        temp->next = temp->next->next;

        delete toDel;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */