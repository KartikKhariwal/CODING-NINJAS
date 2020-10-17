#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    bool flag;
        
    vector<long long> dp((1<<n),0);
    dp[0]=1;

    for(long mask = 0; mask < (1<<n)-1; mask++){
        for(long i = 0; i < n; i++){
            //bitmask represenets whigh no pushed to permutation and which nott
                long x = 1+i;
                flag = true;
    
                //here we check no which is not pushed yet meets the condition with any set bit if its then wrong permutation 
                for(long j = 0; j < n; j++){
                    if(mask&(1<<j)){
                        long y = j+1;
                        if((x&y) == x){
                            flag = false;
                            break;
                        }
                    }
                }

                if(flag){
                    dp[mask|(1<<i)] += dp[mask];
                }
            }
        }
    }

    cout<<dp[(1<<n)-1] << endl;
    return 0;
}


