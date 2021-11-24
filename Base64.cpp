#include <bits\stdc++.h>
using namespace std;

// initialising the Base64 character set
// range is 0-63, as every character is represented using 6 bits
string Base64 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

int main(){
    string encrypted_message = "R3JlYXQgam9iLiBKdWxpdXMgQ2Flc2VyIHdhcyBib3JuIGluIHRoZSAxMDAgQkM6ClBEQSBKQVRQIFlFTERBTiBHQVVPTVFXTkEgRU8gUERBIFdITERXWEFQTyBTRVBES1FQIEYKT1BYV09EUFNLUUxPTkNYUU5VSkVPTFhQV0FFSE1PVVpPRVFYWFZLVUpPV0JMTVdYUFFVSU9FTFBNWUtZRUhNT0dPS1lRWEFYS1lLRExZUVpZTFlIQVdXQkxNV1hRWUxXVldPWQ==";
    int length = encrypted_message.size(), element;
    
    // declaring an intermediate string which will store the bit representation of individual characters from Base64
    string intermediate, decrypted_message = "";

    // loop to convert the Base64 encrypted code into one large binary string
    for(int i = 0; i < length; i++){
        // we check at which index the particular character occurs, because we need the 6 bit representation of that index
        if(encrypted_message[i] != '='){
            // .find() finds the first occurence of that character in the Base64 string
            element = Base64.find(encrypted_message[i]);

            // bitset function directly calculates the binary value corresponding to the number
            bitset<6> b = (element);
            // apending it to the intermediate string
            intermediate += b.to_string();
        }

        // if we have '=' we must pop 2 zeroes from the end
        // while decoding we make groups of 8 consecutive bits but the number of bits in intermediate string might not be a multiple of 8
        // while encoding we fall short by either 2 or 4 bits, so we add '=' per two '0' bits appended at the end
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

        // typecasting it to char and appending to the decrypted string
        decrypted_message += (char)num;
    }

    // displaying the final message for the first step
    cout << decrypted_message << "\n";
    return 0;
}