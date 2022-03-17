class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = pushed.size(); // extracting the size of the array 
        
        stack<int> s; // declare an stack 
        int j = 0; // pointer to move in popped array
        
        // start travelling in pushed array
        for(int i = 0; i < n; i++)
        {
            // push current element into stack
            s.push(pushed[i]);
            
            // now see whether they required this element to pop, if yes,
            // then pop and move pointer in our popped array 
            // while the element matches with the top of the stack
            while(!s.empty() && s.top() == popped[j])
            {
                s.pop(); // pop fom stack
                j++; // move pointer in popped array
            }
        }
        
        // now, at last we just have to check whether our stack is empty or not
        // if stack is empty, then return true otherwise false
        return s.empty();
        
    }
};