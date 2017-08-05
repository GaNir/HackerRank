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

using namespace std;

int number_needed(string a, string b) {
   sort(a.begin(),a.end());
   sort(b.begin(),b.end());
   auto ita = a.begin();
   auto itb = b.begin();
   
   int counter = 0; 
   for(;ita!= a.end() || itb != b.end();){
       if (ita == a.end()){ while(itb != b.end()){itb++; counter++;};break;}
       if (itb == b.end()){ while(ita != a.end()){ita++; counter++;};break;}
       
       if (*ita == *itb) {ita++;itb++;}
       else if(*ita < *itb) {ita++; counter++;}
       else {itb++; counter++;}
   }
   return counter; 
}

int main(){
    string a;
    cin >> a;
    string b;
    cin >> b;
    cout << number_needed(a, b) << endl;
    return 0;
}
