#include <bits\stdc++.h>
using namespace std;

int main(){
    // the two encrypted messages we received from applying Base64 decoding
    string s1 = "PDA JATP YELDAN GAUOMQWNA EO PDA WHLDWXAPO SEPDKQP F";
    string s2 = "OPXWODPSKQLONCXQNUJEOLXPWAEHMOUZOEQXXVKUJOWBLMWXPQUIOELPMYKYEHMOGOKYQXAXKYKDLYQZYLYHAWWBLMWXQYLWVWOY";
    int length1 = s1.size(), length2 = s2.size(), n1, n2;

    // Given Julius Caesar was born in **'100'** BC
    // 100 % 26 = 22, behind by 22 positons, so move ahead by 4 positions
    int n = 4;

    for(int j = 0; j < length1; j++){
        if(s1[j] == ' ') continue;

        // n1 stores ASCII value for character s[j], subtracting by 65 to make range between 0 - 25 for the alphabets
        n1 = s1[j];
        // mod function to make the shifting circular, that is for example 'z' -> 'a'
        n1 = 65 + (n1 - 65 + n) % 26;
        s1[j] = char(n1);
    }

    // for the second encrypted message
    for(int j = 0; j < length2; j++){
        if(s2[j] == ' ') continue;

        n2 = s2[j];
        n2 = 65 + (n2 - 65 + n) % 26;
        s2[j] = char(n2);
    }

    cout << s1 << "\n" << s2 << "\n\n";
    return 0;
}