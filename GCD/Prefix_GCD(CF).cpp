#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
template <typename T>
using oset = tree<T, null_type, less<T>,rb_tree_tag, tree_order_statistics_node_update>;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
uniform_int_distribution<int> random(1, 1000000);
#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
#define ok cout<<"ok"<<endl<<flush;
#define endl '\n'
#define INF 1e16
const ll M =1e9+7;
const ll N =1e5+1;
void debug(vector<ll>&v){for(auto it:v){cout<<it<<" ";}cout<<endl;}
ll n,m;
int32_t main()
{
    fast
    ll i,j,k,p,q,tc=1,cs=0;cin >> tc;
    while(tc--)
    {
        cin>>n;
        vector<ll>v(n);
        ll x=0,y=0,z=INT_MAX,ans=0;
        multiset<ll>st;
        for(auto &it:v)
        {
            cin>>it;
            st.insert(it);
            x=__gcd(x,it);
            z=min(z,it);
        }
        ans+=z;
        st.erase(st.find(z));
        while(z!=x)
        {
            k=z;
            j=INT_MAX;
            for(auto it:st)
            {
                ll temp=__gcd(z,it);
                if(temp<=k){k=temp;j=it;}
            }z=k;
            ans+=z;
            st.erase(st.find(j));
        }
        ans+=x*(st.size());
        cout<<ans<<endl;
    }
}
 /* 
এই প্রবলেমটা GCD এর ক্যারেক্টারিষ্টিক বোঝার জন্য খুবই উপযোগী। GCD এর ট্রিক্সটা বুঝলে এই প্রবলেমটা ব্রুট ফোর্স চালায়েই করা যায়।
সো, এই প্রবলেমটা একটা মাষ্ট সলভ প্রবলেম হিসেবে দেখছি। পাশাপাশি প্রাইম ফ্যাক্টরের ও ধারণা থাকা উচিত। 

যেহেতু, ১০০,০০০ এর নিচে কেবল ৭ টা ডিফারেন্ট প্রাইম নাম্বারই থাকতে পারে, তাই প্রতিটা টেষ্ট কেস 7n complexity তে সলভ করা পসিবল
   */
