<h1><b>WEC-Systems-Cryptography-Assignment:</b></h1>
<h2><b>Solution:</b></h2>

</br><b>1. Scanning QR Code:</b> 
On reading the QR code provided using a QR scanner app, we receive the following text:</br></br>

>R3JlYXQgam9iLiBKdWxpdXMgQ2Flc2VyIHdhcyBib3JuIGluIHRoZSAxMDAgQkM6ClBEQSBKQVRQIFlFTERBTiBHQVVPTVFXTkEgRU8gUERBIFdITERXWEFQTyBTRVBES1FQIEYKT1BYV09EUFNLUUxPTkNYUU5VSkVPTFhQV0FFSE1PVVpPRVFYWFZLVUpPV0JMTVdYUFFVSU9FTFBNWUtZRUhNT0dPS1lRWEFYS1lLRExZUVpZTFlIQVdXQkxNV1hRWUxXVldPWQ==

</br></br><b>2. Using Base64 decoder:</b>
The encrypted message is a string consisting of characters from the sets `[A-Z]`, `[a-z]`, `[0-9]` and has `'='` symbols at the end. So, converting it from Base64 to ASCII:</br></br>

>Great job. Julius Caeser was born in the 100 BC:</br>
PDA JATP YELDAN GAUOMQWNA EO PDA WHLDWXAPO SEPDKQP F</br>
OPXWODPSKQLONCXQNUJEOLXPWAEHMOUZOEQXXVKUJOWBLMWXPQUIOELPMYKYEHMOGOKYQXAXKYKDLYQZYLYHAWWBLMWXQYLWVWOY

</br>In the encoding process of Base64, we convert the ASCII characters into their 8 bit binary representations. Then, we make groups of 6 and convert them into their corresponding character in the Base64 character set. Ex: "ABC" in ASCII -> (01000001)(01000010)(01000011) -> (010000)(010100)(001001)(000011) -> QUJD in Base64

However, the total number of bits might not be a multiple of 6 (will fall short either by  2 or 4), so in that case, we append two zeroes to the right to make groups of 6 bits.

For decoding, we just convert all the Base64 chars into 6 bits based on their index, if we get any '=' pop 2 zeroes from the end and make groups of 8. We then convert them to their ASCII values, and obtain the decrypted string.

</br></br><b>3. Applying Caesar Cipher:</b>
The first statement gives us the hint of using caesar cipher on the encrypted message, being that all the characters in uppercase alphabets. Iterating brute force through all the 26 possible solutions and manually checking them, we get:</br></br>

>THE NEXT CIPHER KEYSQUARE IS THE ALPHABETS WITHOUT J</br>
STBASHTWOUPSRGBURYNISPBTAEILQSYDSIUBBZOYNSAFPQABTUYMSIPTQCOCILQSKSOCUBEBOCOHPCUDCPCLEAAFPQABUCPAZASC

</br>In caesar cipher, we shift all the alphabets in the string by a fixed position and substitute them. This on the entire alphabet set so it  works in a circular manner. Ex: shifting 'A' by 2, gives 'C' and shifting 'Z' by 5, gives 'E'.

There are 26 possible encryptions for any string, so if we don't know the value of the number of shifts required, we can always brute force it.
In the question, '100' gave the hint that it must be shifted 100 times, or 100 % 26 = 22 times behind.

</br><b>4. Applying Playfair Cipher:</b> The first statement gives us the hint of using playfair cipher on the second statement, which is still encrypted.