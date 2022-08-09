/*
128. You have been given a singly linked list of integers along with two integers, 'M,' and 'N.' Traverse the linked list such that you retain the 'M' nodes, then delete the next 'N' nodes. Continue the same until the end of the linked list.
To put it in other words, in the given linked list, you need to delete N nodes after every M nodes.
*/

/****************************************************************
 
    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/

Node *skipMdeleteN(Node *head, int M, int N)
{
	
   Node* temp = head;
    
    if(M != 0 && N == 0 || M == 0 && N == 0){
        
        return head;
    }
    if(M == 0 ||  head == NULL){
        
    	return NULL;
    }
    
    while(temp){
        
        for(int i = 1; i < M; i++){
            
            temp = temp -> next;
        }
        
        if(temp){
            
            // "j" is for readability purposes only. It is not inside a nested 'for loop'
            for(int j = 1; j <= N; j++){
                
                Node* a = temp -> next;
                if(a){
                Node* b = a -> next;
                temp -> next = b;
                delete a;
                }
            }
            
            temp = temp -> next;
        }
    }
    
    return head;
}