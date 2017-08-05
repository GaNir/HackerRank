#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <stack>

using namespace std;

bool isCouple(char a, char b){
    if (a=='(' && b==')') return true;
    if (a=='[' && b==']') return true;
    if (a=='{' && b=='}') return true;
    return false;
}

bool is_balanced(string expression) {
    stack<char> st;
    const std::string startBr("([{");
    for (const char &c:expression){
       if (startBr.find(c) != std::string::npos) {st.push(c);} //starting bracket
       else { //verify ending bracket
           if (st.empty()) return false;
           if (!isCouple(st.top(),c)) return false;
           st.pop();
       } 
    }
    if (!st.empty()) return false;
    return true;
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        string expression;
        cin >> expression;
        bool answer = is_balanced(expression);
        if(answer)
            cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
