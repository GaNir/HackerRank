#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <set>

using namespace std;

// add:  using multiset to get the names sorted
// find: searching the partial name in the minimal names range 

int main() {
    int N;
    string line, data;
    multiset<string> vStr;
    
    std::getline (std::cin,line);
    N = stoi(line);
    
    for (int n=0;n<N;n++){
        std::getline (std::cin,line);
        data = line.substr(line.find(" ")+1);
        
        if (line.find("find") == 0) {
            int cnt=0;
            string strUpperSearch = string(data);
            //add 1 to last string character to get the minimal upper search limit
            strUpperSearch[strUpperSearch.length()-1]+=1;   
            auto posStart = vStr.lower_bound(data);
            auto posEnd   = vStr.lower_bound(strUpperSearch);
            for (auto pos = posStart;pos!=posEnd;pos++){
                // compare patial name
                if (((*pos).substr(0,data.length())) == data) cnt++;
            }
            cout<<cnt<<"\n";
        }
        
        if (line.find("add") == 0) {
            vStr.insert(data);
        }
        
    }
    
    return 0;
}
