#include <bits/stdc++.h>
using namespace std;

typedef struct def{
    string gname;
    int price;
}goodies;

int compare (goodies a, goodies b) {
    return a.price<b.price;
}

int main() {
    int n, m, i, j, pricecal;
    cin>>n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    vector<goodies>v(n);
    string s;
    for(i=0; i<n; i++) {
        getline(cin, s);
        //cout<<s<<endl;
        pricecal=0;
        int t=1;
        for(j=s.size()-1; j>=0; j--) {
            if(s[j]==' ') break;
            pricecal=(s[j]-'0')*t+pricecal;
             t*=10;
            //cout<<pricecal<<endl;
        }
        //cout<<pricecal;
        v[i].price=pricecal;
        v[i].gname = s.substr(0, j);
        //cout<<v[i].gname<<" "<<v[i].price<<endl;
        //cin>>v[i].gname>>v[i].price;
        
    }
    sort(v.begin(), v.end(), compare);
    int p;
    cin>>m;
	int minm=INT_MAX;
    for(i=m; i<n; i++) {
        //cout<<v[i].gname<<" "<<v[i].price<<endl;
        if(minm>v[i].price-v[i-m+1].price) {
            minm=v[i].price-v[i-m+1].price;
            p=i;
        }
    }
    int k=1;
    i=p-m+1;
    cout<<"The goodies selected for distribution are: ";
    for(; m--; i++) {
     cout<<v[i].gname<<": "<<v[i].price<<endl;
    }
    cout<<"And the difference between the choosen goodie with the highest price and the lowest price is ";
    cout<<minm;
	return 0;
}