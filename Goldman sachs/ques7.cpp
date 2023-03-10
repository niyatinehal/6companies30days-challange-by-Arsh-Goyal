//2179. Count Good Triplets in an Array
//https://leetcode.com/problems/count-good-triplets-in-an-array/description/
typedef long long ll;
vector<ll>seg;
vector<ll>v;
int n;


void build(ll l, ll r, ll c = 1){
    if(l == r){
        seg[c] = v[l];
        return;
    }
    ll mid = (l+r)/2;
    build(l,mid,2*c);
    build(mid+1,r,2*c+1);
    seg[c] = seg[2*c]+seg[2*c+1];
    return;
}

ll query(ll l,ll r,ll a,ll b,ll c = 1){
    if(l>b || r<a){
        return 0;
    }
    if(l>=a and r<=b){
        return seg[c];
    }
    ll mid = (l+r)/2;
    return query(l,mid,a,b,2*c)+query(mid+1,r,a,b,2*c+1);
}

void update(ll l,ll r, ll ind, ll c=1){
    if(ind<l || r<ind){
        return;
    }
    if(l == r and l == ind){
        seg[c] = 1;
        return;
    }
    ll mid = (l+r)/2;
    update(l,mid,ind,2*c);
    update(mid+1,r,ind,2*c+1);
    seg[c] = seg[2*c]+seg[2*c+1];    
}
class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        ll n = nums1.size();
        v.resize(n+1,0);
        ll ans = 0;
        map<ll,ll>mp;
        for(ll i=0;i<n;i++){
            mp[nums2[i]+1] = i+1;
        }
        seg.clear();
        seg.resize(4*n+1,0);
        build(1,n);
        for(int i=1;i<=n;i++){
            ll r = mp[nums1[i-1]+1];
            ll q = query(1,n,1,r);
            ll d = i-q-1;
            ll e = n-r-d;
            ans += e*q;
            update(1,n,r);
        }
        return ans;
    }
};