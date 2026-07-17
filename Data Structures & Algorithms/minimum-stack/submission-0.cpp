class MinStack {
public:
    stack<int> s;
    stack<int> mst;

    MinStack() {

    }

    void push(int val) {
        s.push(val);
        mst.push(val);
    }

    void pop() {
        s.pop();
        mst.pop();
    }

    int top() {
        return s.top();
    }

    int getMin() {
        vector<int> res;
        stack<int> temp = mst;   // make a copy

        while (!temp.empty()) {
            res.push_back(temp.top());
            temp.pop();
        }

        return *min_element(res.begin(), res.end());
    }
};