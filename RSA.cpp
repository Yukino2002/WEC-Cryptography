#include <bits\stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    // encrypting the message, using the public key data given
    ll m = 243, n = 2419, e = 11;
    ll ans = 1;

    // calculating the value, but since it will overflow taking mod at every step
    for(int i = 1; i <= 11 ;i++){
        ans = (ans * m) % n;
    }
    cout << ans;
    return 0;
}