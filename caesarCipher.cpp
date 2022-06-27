string caesarCipher(string s, int k) {
    int val_char = 0;
    string newS = "";
    for (int i = 0; i < s.length(); i++) {
        val_char = int(s[i]);
        if (val_char >= 97 && val_char <= 122) {
            val_char = val_char - 97;
            val_char = (val_char + k) % 26;
            val_char = val_char + 97;
            newS += val_char;
        }
        else if (val_char >= 65 && val_char <= 90) {
            val_char = val_char - 65;
            val_char = (val_char + k) % 26;
            val_char = val_char + 65;
            newS += val_char;
        }
        else
            newS += val_char;

    }
    return newS;
}
