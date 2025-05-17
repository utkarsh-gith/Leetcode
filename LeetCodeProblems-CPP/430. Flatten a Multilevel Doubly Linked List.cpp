class Solution {
public:

    void convert(Node* head){

        Node* temp = head -> child;
        while(temp -> next){
            if(temp -> child){
                convert(temp);
            }
            temp = temp -> next;
        }
        temp -> next = head -> next;
        if(head -> next){
            head -> next -> prev = temp;
        }
        head -> next = head -> child;
        head -> next -> prev = head;
        head -> child = NULL;
    }
    Node* flatten(Node* head) {
        
        Node* temp = head;

        while(temp){
            if(temp -> child){
                convert(temp);
            }
            temp = temp -> next;
        }
        return head;
    }
};