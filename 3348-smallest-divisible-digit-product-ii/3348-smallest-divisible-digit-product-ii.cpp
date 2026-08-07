#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct State {
        int a, b, c, d;

        bool operator<(const State &o) const {
            if (a != o.a) return a < o.a;
            if (b != o.b) return b < o.b;
            if (c != o.c) return c < o.c;
            return d < o.d;
        }

        bool operator==(const State &o) const {
            return a == o.a && b == o.b &&
                   c == o.c && d == o.d;
        }
    };

    string smallestNumber(string num, long long t) {

        long long tt = t;

        int A = 0, B = 0, C = 0, D = 0;

        while (tt % 2 == 0) {
            tt /= 2;
            A++;
        }

        while (tt % 3 == 0) {
            tt /= 3;
            B++;
        }

        while (tt % 5 == 0) {
            tt /= 5;
            C++;
        }

        while (tt % 7 == 0) {
            tt /= 7;
            D++;
        }

        if (tt != 1)
            return "-1";

        State needed = {A, B, C, D};

        vector<State> vec(10);

        vec[1] = {0,0,0,0};
        vec[2] = {1,0,0,0};
        vec[3] = {0,1,0,0};
        vec[4] = {2,0,0,0};
        vec[5] = {0,0,1,0};
        vec[6] = {1,1,0,0};
        vec[7] = {0,0,0,1};
        vec[8] = {3,0,0,0};
        vec[9] = {0,2,0,0};

        auto reduceState = [&](State s, int dig) {
            State v = vec[dig];
            return State{
                max(s.a - v.a, 0),
                max(s.b - v.b, 0),
                max(s.c - v.c, 0),
                max(s.d - v.d, 0)
            };
        };

        State zero = {0,0,0,0};

        map<State,int> dist;
        map<State, vector<State>> rev;

        dist[zero] = 0;

        for(int i=0;i<=A;i++)
            for(int j=0;j<=B;j++)
                for(int k=0;k<=C;k++)
                    for(int l=0;l<=D;l++)
                    {
                        State s={i,j,k,l};

                        for(int dig=1;dig<=9;dig++)
                        {
                            rev[reduceState(s,dig)].push_back(s);
                        }
                    }

        queue<State> q;
        q.push(zero);

        while(!q.empty())
        {
            State cur=q.front();
            q.pop();

            if(!rev.count(cur))
                continue;

            for(auto prev:rev[cur])
            {
                if(!dist.count(prev))
                {
                    dist[prev]=dist[cur]+1;
                    q.push(prev);
                }
            }
        }

        auto buildSuffix = [&](State state,int L)
        {
            string res="";

            for(int pos=0;pos<L;pos++)
            {
                int remain=L-pos-1;

                for(int dig=1;dig<=9;dig++)
                {
                    State nxt=reduceState(state,dig);

                    if(dist.count(nxt) && dist[nxt]<=remain)
                    {
                        res.push_back(char('0'+dig));
                        state=nxt;
                        break;
                    }
                }
            }

            return res;
        };

        int n=num.size();

        if(num.find('0')==string::npos)
        {
            State s=needed;

            for(char ch:num)
                s=reduceState(s,ch-'0');

            if(s==zero)
                return num;
        }

        int idx0=num.find('0');

        int maxBreak;

        if(idx0==string::npos)
            maxBreak=n-1;
        else
            maxBreak=idx0;

        vector<State> prefState(maxBreak+1,needed);

        for(int k=1;k<=maxBreak;k++)
        {
            prefState[k]=reduceState(prefState[k-1],num[k-1]-'0');
        }

        string answer="";

        bool found=false;

        for(int i=maxBreak;i>=0 && !found;i--)
        {
            State stateEnter=prefState[i];

            int remain=n-1-i;

            for(int dig=(num[i]-'0')+1;dig<=9;dig++)
            {
                State nxt=reduceState(stateEnter,dig);

                if(dist.count(nxt) && dist[nxt]<=remain)
                {
                    answer=num.substr(0,i);
                    answer.push_back(char('0'+dig));
                    answer+=buildSuffix(nxt,remain);

                    found=true;
                    break;
                }
            }
        }

        if(found)
            return answer;

        int L=max(n+1,dist[needed]);

        return buildSuffix(needed,L);
    }
};