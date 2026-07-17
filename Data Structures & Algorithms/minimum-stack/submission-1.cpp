class MinStack {
public:
    stack<int> s;

    MinStack() {

    }

    void push(int val) {
        s.push(val);
        
    }

    void pop() {
        s.pop();
        
    }

    int top() {
        return s.top();
    }

    int getMin() {
        vector<int> res;
        stack<int> temp = s;   // make a copy

        while (!temp.empty()) {
            res.push_back(temp.top());
            temp.pop();
        }

        return *min_element(res.begin(), res.end());
    }
};