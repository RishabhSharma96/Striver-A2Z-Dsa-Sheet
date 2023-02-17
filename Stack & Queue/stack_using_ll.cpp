//Function to push an integer into the stack.
void MyStack ::push(int x) 
{
    StackNode* temp = new StackNode(x);
    if(top == NULL){
        top = temp ;
    }
    else{
        temp->next = top ;
        top = temp ;
    }
        
}

//Function to remove an item from top of the stack.
int MyStack ::pop() 
{
    if(top == NULL){
        return -1 ;
    }
    else{
        int x = top->data ;
        StackNode* temp = top ;
        top = top->next ;
        temp->next = NULL ;
        delete(temp) ;
        return x ;
    }
    
}
