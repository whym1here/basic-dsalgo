#include<bits/stdc++.h>
using namespace std;

template<typename T>
class MinMaxQueue {    
public:
    deque<T> q, minq, maxq;
    
    void push_back(T val) {
        q.push_back(val);
        while(!minq.empty() and minq.back() > val)
            minq.pop_back();
        while(!maxq.empty() and maxq.back() < val) 
            maxq.pop_back();
        minq.push_back(val);
        maxq.push_back(val);
    }
    
    void pop_front() {
        T val = q.front(); q.pop_front();
        if(val == minq.front())
            minq.pop_front();
        if(val == maxq.front())
            maxq.pop_front();
    }
    
    T min() {
        return minq.front();
    }
    
    T max() {
        return maxq.front();
    }
    
    T front() {
        return q.front();
    }  
 
    int size() {
        return q.size();
    }
 
    bool empty() {
        return q.empty();
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}