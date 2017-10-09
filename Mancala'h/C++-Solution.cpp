#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

//Reference to meelo's solution
//Page: http://www.cnblogs.com/meelo/p/6129697.html

int find(const vector<deque<int> > &states, const deque<int> &state){
    for (int i=0; i<states.size(); i++) {
        if(states[i] == state)
            return i;
    }
    return -1;
}

int find_depth(deque<int> s){
    int index = -1;
    vector<deque<int> > states;
    while (index == -1) {
        states.push_back(s);
        int front = s.front();
        s.pop_front();
        int i,q_size = s.size();
        for (i=0; i<min(front, q_size); i++)
            s[i]++;
        for (; i<front; i++)
            s.push_back(1);
        index = find(states, s);
    }
    return index;
}

// DFS
int find_height(deque<int> &state, vector<deque<int> > &state_cache){
    int max_depth = 0;
    for (int l=state.size()-1; l>=0; l--) {
        deque<int> s(state);
        for (int i=l; i>=0; i--) {
            s[i]--;
        }
        bool invalid_state = false;
        for (int i=0; i<s.size()-1; i++) {
            if (s[i]==0 && s[i+1]!=0) {
                invalid_state = true;
                break;
            }
        }
        if (!invalid_state) {
            s.push_front(l+1);
            while (s.back()==0) {
                s.pop_back();
            }
            if(find(state_cache, s)!=-1) break;
            state_cache.push_back(s);
            max_depth = max(max_depth, find_height(s, state_cache)+1);
            state_cache.pop_back();
        }
    }
    return max_depth;
}

int main() {
    deque<int> state;
    
    int m;
    while (cin >> m) {
        state.push_back(m);
    }

    vector<deque<int> > state_cache;
    state_cache.push_back(state);
    
    cout << find_depth(state) << ' ' << find_height(state, state_cache);
    return 0;
}
