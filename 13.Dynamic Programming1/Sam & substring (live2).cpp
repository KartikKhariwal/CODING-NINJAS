//https://www.hackerrank.com/challenges/sam-and-substrings/problem


//note  123 ans = 0*10+1(0[or i]+1) + 1*10+2(1+1) +14*10 +3*(2+1) =1 +14 + 149 =164   i.e newsum=oldsum+oldsum*10+newdigit*(position)

#include <bits/stdc++.h>
#define mod (1000000007)
using namespace std;

// Complete the substrings function below.
int substrings(string n) {

    long long sum=0,total=0;
    for(long long i=0;i<n.length();i++){
        sum=((sum*10)%mod +((i+1)*(n[i]-'0'))%mod)%mod;//sum=sum*10 +(i+1)*(n[i]-'0');
        total=((sum)%mod+(total)%mod)%mod;
    }
    return total;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n;
    getline(cin, n);

    int result = substrings(n);

    fout << result << "\n";

    fout.close();

    return 0;
}
