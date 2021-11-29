<h1><b>WEC-Systems-Cryptography-Assignment:</b></h1>
<h1><b>Solution:</b></h1>


</br><h2><b>First Task:</b></h2>
</br><b>Scanning QR Code:</b> 

On reading the QR code provided using a QR scanner app, we receive the following text:</br></br>

>R3JlYXQgam9iLiBKdWxpdXMgQ2Flc2VyIHdhcyBib3JuIGluIHRoZSAxMDAgQkM6ClBEQSBKQVRQIFlFTERBTiBHQVVPTVFXTkEgRU8gUERBIFdITERXWEFQTyBTRVBES1FQIEYKT1BYV09EUFNLUUxPTkNYUU5VSkVPTFhQV0FFSE1PVVpPRVFYWFZLVUpPV0JMTVdYUFFVSU9FTFBNWUtZRUhNT0dPS1lRWEFYS1lLRExZUVpZTFlIQVdXQkxNV1hRWUxXVldPWQ==


</br><h2><b>Second Task:</b></h2>
</br><b>Using Base64 decoder:</b>
The encrypted message is a string consisting of characters from the sets `[A-Z]`, `[a-z]`, `[0-9]` and has `'='` symbols at the end. So, converting it from Base64 to ASCII:</br></br>

>Great job. Julius Caeser was born in the 100 BC:</br>
PDA JATP YELDAN GAUOMQWNA EO PDA WHLDWXAPO SEPDKQP F</br>
OPXWODPSKQLONCXQNUJEOLXPWAEHMOUZOEQXXVKUJOWBLMWXPQUIOELPMYKYEHMOGOKYQXAXKYKDLYQZYLYHAWWBLMWXQYLWVWOY

</br>In the encoding process of Base64, we convert the ASCII characters into their 8 bit binary representations. Then, we make groups of 6 and convert them into their corresponding character in the Base64 character set. Ex: "ABC" in ASCII -> (01000001)(01000010)(01000011) -> (010000)(010100)(001001)(000011) -> QUJD in Base64

However, the total number of bits might not be a multiple of 6 (will fall short either by  2 or 4), so in that case, we append two or four zeroes accordingly to the right to make groups of 6 bits.

For decoding, we just convert all the Base64 chars into 6 bits based on their index, for every '=', we pop 2 zeroes from the end and make groups of 8. We then convert them to their ASCII values, and obtain the decrypted string.


</br><h2><b>Third Task:</b></h2>
</br><b>Applying Caesar Cipher:</b>
The first statement gives us the hint of using caesar cipher on the encrypted message, using that we get:</br></br>

>THE NEXT CIPHER KEYSQUARE IS THE ALPHABETS WITHOUT J</br>
STBASHTWOUPSRGBURYNISPBTAEILQSYDSIUBBZOYNSAFPQABTUYMSIPTQCOCILQSKSOCUBEBOCOHPCUDCPCLEAAFPQABUCPAZASC

</br>In caesar cipher, we shift all the alphabets in the string by a fixed position and substitute them. This on the entire alphabet set so it  works in a circular manner. Ex: shifting 'A' by 2, gives 'C' and shifting 'Z' by 5, gives 'E'.

There are 26 possible encryptions for any string, so if we don't know the value of the number of shifts required, we can always brute force it.
In the question, '100' gave the hint that it must be shifted 100 times, or 100 % 26 = 22 times behind.


</br><h2><b>Fourth Task:</b></h2>
</br><b>Applying Playfair Cipher:</b> The first statement gives us the hint of using playfair cipher on the second statement, which is still encrypted. That gives us:</br></br>

>RSAENCRYPTNUMBERTWOHUNDREDFOURTYTHREEWITHNVALUEASTWOTHOUSANDFOURHUNDREDANDNINETEENANDEVALUEASELEVENX

</br>Playfair cipher involves declaring a matrix of 5X5 and filling the letters corresponding to the key we get. In the question, our key square was all characters from A - Z except J.
Ex: We got key as "WEC", we will fill the matrix in that order first row-wise and then fill the remaining alphabets sequentially.

During decryption, we make pairs of two, and check both the characters' position in the matrix.

If both of them belong to the same row, we change that character to the one that is just before it, i.e., if i and j are row and column indices respectively, the decrypted string will have the character matrix[i][j - 1]. We can do the same for the second element, in case (j - 1) equals -1, we take the last element of the row, i.e., matrix[i][4].

Something similar is done in the case when the columns are same, we take the element above that character in the column.

In case both of the row and columns are different, we take the row opposite corner element of the so formed rectangle. If i1, i2 and j1, j2 are rows and columns indices of the two characters respectively, first character becomes = matrix[i1][j2] and second becomes = matrix[i2][j1], interchanging the columns.

For encryption, just choose the elements after the character instead of taking the ones previous to them. In the case, we have oddd number of characters, we add a bogus'Z' to complete all pairs of two. Also, when two consecutive characters are same, we add a bogus character.

Here, the 'X' at the end of the decrypted message is a bogus character without any meaning.


</br><h2><b>Fifth Task:</b></h2>
</br><b>Applying RSA Encryption:</b> We get the following numbers from our previously decrypted message. They are:</br></br>

>m (Message) = 243</br>
n, e (Public Key) = 2419, 11

</br>RSA encryption involves generating a public key, which is the product of somw two primes, say p and q, so, n = p*q;

We also need an exponent part, e which is an integer and not a factor of n, and must be in the range 1 < e < Φ(n).

The encryption and decryption process for RSA is fairly complex but for the given task, since the data was already provided, encrypting it was application of a basic formula, which is, encrypted message = (m ^ e) % n.

We get 1982 as the result.


</br><h2><b>Sixth Task:</b></h2>
</br><b>Unlocking the zip:</b> We get the following number as our result from RSA encryption:</br></br>

>1982

</br>On trying this number on the locked zip file we were provided with, it successfully unlocked it. The encrypted message we get is:</br></br>

>TM, DTZ KTZSI RJ😔. HTSLWFYX. YMNX NX YMJ JSILTFQ. TW NX NY?🤨

</br>This is a clear application of caesar cipher again.


</br><h2><b>Seventh Task:</b></h2>
</br><b>Applying Caesar Cipher Again:</b> Since there was no hint given this time, we had to brute force all the possible solutions. On checking manually, We finally get the decrypted message:</br></br>

>OH, YOU FOUND ME😔. CONGRATS. THIS IS THE ENDGOAL. OR IS IT?🤨

