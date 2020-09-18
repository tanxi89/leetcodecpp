//
// Created by 陈鑫 on 2020/9/11.
//

#include "../include/Solution.h"

//20
bool Solution::isValid(string s) {
    stack<char> mystack;
    if(s.size()%2!=0){
        return false;
    }
    for(int i=0;i<s.size();i++) {
        if (mystack.empty()) {
            if (s[i] == ')' || s[i] == ']' || s[i]=='}') {
                return false;
            }
        }
        if (s[i] == '(' || s[i] == '[' || s[i]=='{') {
            mystack.push(s[i]);
        } else if ((s[i] == ')' && mystack.top() == '(')
            || (s[i] == ']' && mystack.top() == '[')
            || (s[i] == '}' && mystack.top() == '{')) {
                mystack.pop();
        } else {
            return false;
        }
    }
    return mystack.empty();
}

//42
int Solution::trap(vector<int> &height) {
    /* overtime
    int capacity = 0;
    if (height.size() <= 2) {
        return 0;
    }
    for (int i = 1; i < height.size()-1; ++i) {
        int max_left=0;
        int max_right=0;

        for (int i = i; i >= 0; i--) {
            max_left = max(max_left,height[i]);
        }
        for (int k = i; k <= height.size()-1; ++k) {
            max_right = max(max_right,height[k]);
        }
        if (min(max_left,max_right) > height[i]) {
            capacity += (min(max_left, max_right) - height[i]);
        }
    }
    return capacity;
     */

    //dynamic programing
    int capacity = 0;
    int size = height.size();
    if (size <= 2) {
        return 0;
    }

    vector<int> max_left(size,0);
    vector<int> max_right(size,0);

    max_left[0] = height[0];
    for (int i = 1; i <= size-1; ++i) {
        max_left[i] = max(max_left[i-1],height[i]);
    }

    max_right[size - 1] = height[size - 1];
    for (int i = size - 2; i >= 0; i--) {
        max_right[i] = max(max_right[i+1],height[i]);
    }

    for (int i=1; i < size-1; i++) {
        capacity += min(max_left[i], max_right[i]) - height[i];
    }
    return capacity;
}

//71
string Solution::simplifyPath(string path) {
    stack<char> mystack;
    stack<char> resultStack;
    string simplePath;
    char last = '/';

    mystack.push('/');
    for(int i=0;i<path.size();i++) {
        if ((path[i] >= 'a' && path[i] <= 'z') || (path[i] >= 'A' && path[i] <= 'Z')) {
            mystack.push(path[i]);
            if(last == '.'){
                mystack.pop();
            }
            last = path[i];
        }
        if (path[i] == '/') {
            if (mystack.top() != '/') {
                mystack.push(path[i]);
                if(last == '.'){
                    mystack.pop();
                }
                last = path[i];
            }
        }

        if (path[i] == '.') {
            if (mystack.top() == '.') {
                while ((!((mystack.top() >= 'a' && mystack.top() <= 'z') || (mystack.top() >= 'A' && mystack.top() <= 'Z'))) && !mystack.empty()){
                    mystack.pop();
                }
                last = mystack.top();
            } else {
                mystack.push(path[i]);
                last = path[i];
            }
        }
    }

    while (!mystack.empty()) {
        char temp = mystack.top();
        mystack.pop();
    }

    while (!resultStack.empty()) {
        simplePath += resultStack.top();
        resultStack.pop();
    }
    return simplePath;
}