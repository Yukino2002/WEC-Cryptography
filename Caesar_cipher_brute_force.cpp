#include <bits\stdc++.h>
using namespace std;

int main(){
    string s = "TM, DTZ KTZSI RJ😔. HTSLWFYX. YMNX NX YMJ JSILTFQ. TW NX NY?🤨";
    int length = s.size(), n;

    for(int i = 0; i < 26; i++){
        for(int j = 0; j < length; j++){
            if(isalpha(s[j]) == 0) continue;

            n = s[j];
            n = 65 + (n - 64) % 26;
            
            s[j] = char(n);
        }
        cout << s << "\n\n";
    }
}