#include <bits\stdc++.h>
using namespace std;

int main(){
    string s1 = "PDA JATP YELDAN GAUOMQWNA EO PDA WHLDWXAPO SEPDKQP F";
    string s2 = "OPXWODPSKQLONCXQNUJEOLXPWAEHMOUZOEQXXVKUJOWBLMWXPQUIOELPMYKYEHMOGOKYQXAXKYKDLYQZYLYHAWWBLMWXQYLWVWOY";
    int length1 = s1.size(), length2 = s2.size(), n1, n2;
    for(int i = 0; i < 26; i++){
        for(int j = 0; j < length1; j++){
            if(s1[j] == ' ') continue;
            n1 = s1[j];
            n1 = 65 + (n1 + 1 - 65) % 26;
            s1[j] = char(n1);
        }
        for(int j = 0; j < length2; j++){
            if(s2[j] == ' ') continue;
            n2 = s2[j];
            n2 = 65 + (n2 + 1 - 65) % 26;
            s2[j] = char(n2);
        }
        cout << s1 << "\n" << s2 << "\n\n";
    }
    return 0;
}