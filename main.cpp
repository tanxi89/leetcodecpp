#include <iostream>
#include "include/Solution.h"
using namespace std;

int main() {
    Solution s;

    //20
    string str = "(())[]{}";
    cout << s.isValid(str) << endl;
    //42
    int a[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    vector<int> rain(a,a + sizeof(a)/sizeof(int));
    cout << s.trap(rain) << endl;
    //71
    string path = "/a/./b/../../c/";
    cout << s.simplifyPath(path) << endl;
    //89
    //90
    return 0;
}
