#include <bits\stdc++.h>
using namespace std;
// Initialising the Base64 character set
// Range is 0-63, as every character is represented using 6 bits
string Base64 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

int main(){
    string encoded_message = "R3JlYXQgam9iLiBKdWxpdXMgQ2Flc2VyIHdhcyBib3JuIGluIHRoZSAxMDAgQkM6ClBEQSBKQVRQIFlFTERBTiBHQVVPTVFXTkEgRU8gUERBIFdITERXWEFQTyBTRVBES1FQIEYKT1BYV09EUFNLUUxPTkNYUU5VSkVPTFhQV0FFSE1PVVpPRVFYWFZLVUpPV0JMTVdYUFFVSU9FTFBNWUtZRUhNT0dPS1lRWEFYS1lLRExZUVpZTFlIQVdXQkxNV1hRWUxXVldPWQ==";
    int length = encoded_message.size(), element;
    
    //declaring an intermediate string which will store the bit representation of individual characters from Base64
    string intermediate, decoded_message = "";

    for(int i = 0; i < length; i++){
        if(encoded_message[i] != '='){
            element = encoded_message[i];
            
            element = Base64.find(element);

            bitset<6> b = (element);
            intermediate += b.to_string();
        }
    }

    int num, n = intermediate.size();
    for(int i = 0; i < n; i += 8){
        num = 0;
        for(int j = i; j < i + 8; j++){
            if(intermediate[j] == '1') num += pow(2, (7 - (j - i)));
        }
        decoded_message += (char)num;
    }
    cout << decoded_message;
    return 0;
}