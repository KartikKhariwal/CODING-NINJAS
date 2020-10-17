
//https://www.hackerrank.com/challenges/winning-lottery-ticket/problem

#include <bits/stdc++.h>

using namespace std;

// Complete the winningLotteryTicket function below.
long winningLotteryTicket(vector<string> tickets) {
    int*count =new int[1025]();
    for(int i=0;i<tickets.size();i++){
        string s=tickets[i];
        int mask=0;
        for(int j=0;j<s.length();j++){
            mask|=(1<<(s[j]-'0'));
        }
        count[mask]++;
    }
    long ans=0;
    for(int m1=0;m1<1024;m1++){
        for(int m2=m1;m2<1024;m2++){
            if((m1|m2)==1023){
                if(m1==m2){
                    ans+=((long)count[m1]*(count[m1]-1))/2;
                }else {
                    ans+=((long)count[m1]*(count[m2]));
                }
            }
        }
    }
    return ans;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> tickets(n);

    for (int i = 0; i < n; i++) {
        string tickets_item;
        getline(cin, tickets_item);

        tickets[i] = tickets_item;
    }

    long result = winningLotteryTicket(tickets);

    fout << result << "\n";

    fout.close();

    return 0;
}
