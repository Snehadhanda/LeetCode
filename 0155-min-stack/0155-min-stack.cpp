//approch is: hum baki sare elements like push, pop, top O(1) me kr sktey hai.....lkin getmin ko krne ke liye dekhna pade ga
//toh getmin ko O(1) me krne ke liye hum ek vector of pair bnaye ge jisme hmare pair ka 1st element will represent the actual element and pair ka second element of pair will represent min element till that index
//so jb bhi hume min element return krna hoga.....hum rightmost wale pair ka 2nd wala element return kr denge

class MinStack {
public:
    vector<pair<int,int>> st;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()) {
            // means we have to insert the 1st element
            //also we have created a dynamic array so we don't have to worry about stack overflow...kuki vector apna size increment krta rhe ga
            pair<int,int> p;
            p.first = val; //value insert kr denge
            p.second = val; //kuki phla element insert kr rhe hai toh vhi element min hoga
            st.push_back(p); // vector me push kr denge
        }
        else{
            pair<int,int>p;
            p.first = val;
            int puranaMin = st.back().second;
            p.second = min(puranaMin, val);
            st.push_back(p);
        }
    }
    
    void pop() {
        st.pop_back();
    }
    
    int top() {
        pair<int,int> rightMostPair = st.back();
        return rightMostPair.first;
    }
    
    int getMin() {
        pair<int,int> rightMostPair = st.back();
        return rightMostPair.second;

    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */