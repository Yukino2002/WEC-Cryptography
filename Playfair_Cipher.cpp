#include <bits\stdc++.h>
using namespace std;

// intialsing the key square as specified in the message we received after applying caesar cipher
char keysquare[5][5] = {{'A','B','C','D','E'}, {'F','G','H','I','K'}, {'L','M','N','O','P'}, {'Q','R','S','T','U'}, {'V','W','X','Y','Z'}};
// declaring a map so that we can store the indices where that particular character occurs
map <char, pair<int, int>> m;

int main(){
    // the encrypted message we received from solving the previous task
    string s = "STBASHTWOUPSRGBURYNISPBTAEILQSYDSIUBBZOYNSAFPQABTUYMSIPTQCOCILQSKSOCUBEBOCOHPCUDCPCLEAAFPQABUCPAZASC";
    string decrypted_message = "";
    int length = s.size();

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            // using make pair function to store the indicies of every character in the map at once
            m[keysquare[i][j]] = make_pair(i, j);
        }
    }

    // for storing indices
    int x1, y1, x2, y2; 
    for(int i = 0; i < length; i += 2){
        x1 = m[s[i]].first, y1 = m[s[i]].second, x2 = m[s[i + 1]].first, y2 = m[s[i + 1]].second;

        // if rows are same, moving the character behind by 1 position in the same row
        if(x1 == x2){
            decrypted_message += keysquare[x1][(y1 - 1 + 5) % 5];
            decrypted_message += keysquare[x2][(y2 - 1 + 5) % 5];
        }
        // if columns are same, moving the character above by 1 position in the same column
        else if(y1 == y2){
            decrypted_message += keysquare[(x1 - 1 + 5) % 5][y2];
            decrypted_message += keysquare[(x2 - 1 + 5) % 5][y2];
        }
        // if both are different, taking row opposite corner points of the rectangle formed by interchanging columns
        else{
            decrypted_message += keysquare[x1][y2];
            decrypted_message += keysquare[x2][y1];
        }
    }
    cout << decrypted_message;
    return 0;
}
