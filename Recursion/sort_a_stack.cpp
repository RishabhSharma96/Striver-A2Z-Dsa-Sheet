/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

/* The below method sorts the stack s 
you are required to complete the below method */

void sorted_insert(stack<int> & s , int element){
    if((!s.empty() && s.top() < element) || (s.empty())){
        s.push(element);
        return ;
    }
    
    int num = s.top() ;
    s.pop() ;
    sorted_insert(s,element);
    s.push(num);
}

void SortedStack :: sort()
{
    if(s.empty()){
        return ;
    }

    int num = s.top() ;
    s.pop() ;

    sort();

    sorted_insert(s,num);
}