#include <bits\stdc++.h>
using namespace std;

int main(){
    string s = "TM, DTZ KTZSI RJ😔. HTSLWFYX. YMNX NX YMJ JSILTFQ. TW NX NY?🤨";
    int length = s.size(), n;

    // for all possible 26 solitions the outer loop, incrementing by 1 position everytime
    for(int i = 0; i < 26; i++){
        for(int j = 0; j < length; j++){
            // isalpha() returns 0 if character is not an alphabet
            if(isalpha(s[j]) == 0) continue;

            n = s[j];
            n = 65 + (n - 64) % 26;
            s[j] = char(n);
        }
        cout << s << "\n\n";
    }
}