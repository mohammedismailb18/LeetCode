#define MOD 1000000007
#define ll long long

class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<ll ,ll>> eng;
        for(ll i=0; i<n; i++)
            eng.push_back({efficiency[i], speed[i]});
        sort(eng.rbegin(), eng.rend());
        
        priority_queue<ll, vector<ll>, greater<ll>> q;
        ll ans = 0, sum = 0;
        for(ll i=0; i<n; i++){
            sum += eng[i].second;
            ans = max(ans, sum*eng[i].first);
            q.push(eng[i].second);
            if(q.size() > k-1){
                sum -= q.top();
                q.pop();
            }
        }
        return (int)(ans % MOD);
    }
};
