#include <bits\stdc++.h>
using namespace std;

int main(){
    // the two encrypted messages we received from solving the previous task
    string s1 = "PDA JATP YELDAN GAUOMQWNA EO PDA WHLDWXAPO SEPDKQP F";
    string s2 = "OPXWODPSKQLONCXQNUJEOLXPWAEHMOUZOEQXXVKUJOWBLMWXPQUIOELPMYKYEHMOGOKYQXAXKYKDLYQZYLYHAWWBLMWXQYLWVWOY";
    int length1 = s1.size(), length2 = s2.size(), n1, n2;

    // outer loop for all 26 possible solutions, nested loops for shifting the characters by 1 position everytime
    // we increment every character by 1 position for one iteration
    // every character from the original string becomes it's next character
    // so for the second iteration incrementing by 1 position again is equivalent to incrementing the original string by 2 positions
    // this way we get all the possible solutions
    for(int i = 0; i < 26; i++){

        // for the first encrypted message
        for(int j = 0; j < length1; j++){
            // if we get a ' ' character doing nothing
            if(s1[j] == ' ') continue;

            // n1 stores ASCII value for character s[j], subtracting by 65 to make range between 0 - 25 for the alphabets
            n1 = s1[j];
            // mod function to make the shifting circular, that is for example 'z' -> 'a'
            n1 = 65 + (n1 - 65 + 1) % 26;
            // type casting it to char, and storing the result
            s1[j] = char(n1);
        }

        // for the second encrypted message
        for(int j = 0; j < length2; j++){
            if(s2[j] == ' ') continue;

            n2 = s2[j];
            n2 = 65 + (n2 - 65 + 1) % 26;
            s2[j] = char(n2);
        }

        // printing all the results one by one and checking them manually
        cout << s1 << "\n" << s2 << "\n\n";
    }
    return 0;
}