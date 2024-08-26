#define ll long long int
class Solution {
public:
    int countGoodNumbers(long long n) {
        long long temp = pow(20, n/2);
        return (n&1) ? (temp*5)%mod : temp;
    }

private:
    int mod=1e9+7;
    ll pow(ll  a, ll b){
        ll res=1;
        while(b){
            if(b&1){
                res= (res*a)%mod;
            }
            a=(a*a)%mod;
            b/=2;
        }
        return res;
    }
};