#include <iostream>
#include <set>

// Inspired by the solution at https://stackoverflow.com/questions/31113993/maximum-subarray-sum-modulo-m
int main() {
    int N;
    std::cin>>N;
    for (int nn=0;nn<N;nn++){
        long long n,m;
        std::set<long long> mSet;
        long long maxVal = 0;
        long long sumVal = 0;

        std::cin>>n>>m;
        mSet.insert(m);
        for (long long q=0;q<n;q++){
            long long tmp, complement;

            std::cin>>tmp;
            sumVal = (sumVal + tmp)%m;
            auto itSub = mSet.upper_bound(sumVal);
            maxVal = std::max(maxVal,(m + sumVal - *itSub)%m);
            mSet.insert(sumVal);                
        }
        std::cout<<maxVal<<"\n";
    }
}
