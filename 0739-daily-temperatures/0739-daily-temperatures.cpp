class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int>nge(n, 0); // initially all 0, stores distance between their next greater element and current temperature
        stack<int>st{};
        
		// move from right to left
        for(int i = n-1; i>=0; --i){
            // pop until we find next greater element to the right
			// since we came from right stack will have element from right only
			// s.top() is the index of elements so we put that index inside temperatures vector to check
            while(!st.empty() && temperatures[st.top()] <= temperatures[i])
                st.pop();
				
            // if stack not empty, then we have some next greater element, 
			// so we take distance between next greater and current temperature
			// as we are storing indexes in the stack
            if(!st.empty())
                nge[i] = st.top()-i; // distance between next greater and current
            
			// push the index of current temperature in the stack,
			// same as pushing current temperature in stack
            st.push(i);
        }
        
        return nge;
        
        
    }
};


// understand:
// [1,2,3] return[1,1,0]
// [1] return [0]
// time:n
// space:1

// match:
// brute force =>n^2
// stack => time:n space:n

// plan:
// use mono stack
// create the result array have the same length with tempetature array
// create 1 node contain the value of array and index
// add the first node to stack
// iterate through the array
// compare, if stack is not empty and the next value of array>the stack.top
//     while(stack is not empty and the next value >stacktop )
//         update (the index of the next value-the index of stack.top) index of the result array
//         stack.pop
//     add the index of the next value to stack
    
    
// else
//     update the next value
//     add the next value to stack

// return the result array
    


