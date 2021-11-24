<h1><b>WEC-Systems-Cryptography-Assignment:</b></h1>
<h2><b>Solution:</b></h2>

</br><b>1. Scanning QR Code:</b> 
On reading the QR code provided using a QR scanner app, we receive the following text:</br></br>

>R3JlYXQgam9iLiBKdWxpdXMgQ2Flc2VyIHdhcyBib3JuIGluIHRoZSAxMDAgQkM6ClBEQSBKQVRQIFlFTERBTiBHQVVPTVFXTkEgRU8gUERBIFdITERXWEFQTyBTRVBES1FQIEYKT1BYV09EUFNLUUxPTkNYUU5VSkVPTFhQV0FFSE1PVVpPRVFYWFZLVUpPV0JMTVdYUFFVSU9FTFBNWUtZRUhNT0dPS1lRWEFYS1lLRExZUVpZTFlIQVdXQkxNV1hRWUxXVldPWQ==

</br><b>2. Using Base64 decoder:</b>
The encrypted message is a string consisting of characters from the sets `[A-Z]`, `[a-z]`, `[0-9]` and has `'='` symbols at the end. So, converting it from Base64 to ASCII:</br></br>

>Great job. Julius Caeser was born in the 100 BC:</br>
PDA JATP YELDAN GAUOMQWNA EO PDA WHLDWXAPO SEPDKQP F</br>
OPXWODPSKQLONCXQNUJEOLXPWAEHMOUZOEQXXVKUJOWBLMWXPQUIOELPMYKYEHMOGOKYQXAXKYKDLYQZYLYHAWWBLMWXQYLWVWOY

</br><b>3. Applying Caesar Cipher:</b>
The first statement gives us the hint of using caesar cipher on the encrypted message, being that all the characters in uppercase alphabets. Iterating brute force through all the 26 possible solutions and manually checking them, we get:</br></br>

>THE NEXT CIPHER KEYSQUARE IS THE ALPHABETS WITHOUT J</br>
STBASHTWOUPSRGBURYNISPBTAEILQSYDSIUBBZOYNSAFPQABTUYMSIPTQCOCILQSKSOCUBEBOCOHPCUDCPCLEAAFPQABUCPAZASC

</br><b>4. Applying Playfair Cipher:</b> The first statement gives us the hint of using playfair cipher on the second statement, which is still encrypted.