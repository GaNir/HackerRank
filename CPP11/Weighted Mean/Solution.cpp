#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>

template <typename T>
std::vector<T> getVectorInput(int N){
       std::vector<T> x;
       x.reserve(N);
       for (int n=0;n<N;n++){
            int tmp;
            std::cin>>tmp;
            x.push_back(tmp);
    } 
    return x;
}


int main() {
    int N;
    std::cin>>N;
    
    std::vector<int> x = getVectorInput<int>(N);
    std::vector<int> w = getVectorInput<int>(N);
     
    int totalW =std::accumulate(w.begin(),w.end(),0);
    int xwSum = std::inner_product(x.begin(),x.end(), w.begin(), 0);
   
    printf("%.1f",(float)xwSum/totalW);

}
