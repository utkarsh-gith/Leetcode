// Using hash table 
// map the oldNode to newNode 
// cloneNode -> random = mapping[originalNode -> random]

class Solution {
public:
    void insert(Node* &head, Node* &tail, int val){
        
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
        }else{
            tail -> next = newNode;
            tail = newNode;
        }

    }
    Node* copyRandomList(Node* head) {
        
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;

        Node* temp = head;

        while(temp){

            insert(cloneHead, cloneTail, temp -> val);
            temp = temp -> next;

        }

        unordered_map<Node*, Node*> mapping;

        Node* originalNode = head;
        Node* cloneNode = cloneHead;

        while(originalNode){
            mapping[originalNode] = cloneNode;
            originalNode = originalNode -> next;
            cloneNode = cloneNode -> next;
        }

        originalNode = head;
        cloneNode = cloneHead;

        while(originalNode){
            cloneNode -> random = mapping[originalNode -> random];
            originalNode = originalNode -> next;
            cloneNode = cloneNode -> next;
        }

        return cloneHead;
    }
};

// OR
// changes the next pointer of every original node to new node 
// changes the next pointer of new node to next original node
// temp -> next -> random = temp -> random -> next;
// reverts back to the orignal LL

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        if(!head){
            return head;
        }
        Node* temp = head;

        while(temp){

            Node* newNode = new Node(temp -> val);
            newNode -> next = temp -> next;
            temp -> next = newNode;
            temp = newNode -> next;

        }

        temp = head;

        while(temp){
            if(temp -> random){
                temp -> next -> random = temp -> random -> next;
            }else{
                temp -> next -> random = NULL;
            }
            
            temp = temp -> next -> next;
            
        }

        Node* newHead = head -> next;
        Node* clone = newHead;
        temp = head;
        

        while(clone -> next){
            temp -> next = clone -> next;
            temp = temp -> next;
            clone -> next = temp -> next;
            clone = clone -> next;
        }
        temp -> next = NULL;

        return newHead;

    }
};