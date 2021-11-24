#include <bits\stdc++.h>
using namespace std;

// initialising the Base64 character set
string Base64 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

int main(){
    string encrypted_message = "R3JlYXQgam9iLiBKdWxpdXMgQ2Flc2VyIHdhcyBib3JuIGluIHRoZSAxMDAgQkM6ClBEQSBKQVRQIFlFTERBTiBHQVVPTVFXTkEgRU8gUERBIFdITERXWEFQTyBTRVBES1FQIEYKT1BYV09EUFNLUUxPTkNYUU5VSkVPTFhQV0FFSE1PVVpPRVFYWFZLVUpPV0JMTVdYUFFVSU9FTFBNWUtZRUhNT0dPS1lRWEFYS1lLRExZUVpZTFlIQVdXQkxNV1hRWUxXVldPWQ==";
    int length = encrypted_message.size(), element;
    string intermediate, decrypted_message = "", temp;

    // loop to convert the Base64 encrypted code into one large binary string
    for(int i = 0; i < length; i++){
        if(encrypted_message[i] != '='){
            // .find() finds the first occurence of that character in the Base64 string
            element = Base64.find(encrypted_message[i]);

            temp = "";
            int rem, m = 6;
            // calculating 6 bit binary form of Base64 char
            while(m--){
                rem = element % 2;
                element /= 2;
                if(rem == 0) temp += '0';
                else temp += '1';
            }
            // appending temp in reverse to the intermediate
            for(int i = 5; i >= 0; i--){
                intermediate += temp[i];
            }
        }

        // if we have '=' we must pop 2 zeroes from the end
        else{
            intermediate.pop_back();
            intermediate.pop_back();
        }
    }

    int num, n = intermediate.size();
    // loop to convert intermediate binary string into ASCII character string
    for(int i = 0; i < n; i += 8){
        num = 0;

        // taking consecutive binary substrings of length 8 and calculating their value in decimal number system
        for(int j = i; j < i + 8; j++){
            if(intermediate[j] == '1') num += pow(2, (7 - (j - i)));
        }
        decrypted_message += (char)num;
    }

    cout << decrypted_message << "\n";
    return 0;
}