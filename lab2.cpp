#include <iostream>
#include <string>
#include <map>

using namespace std;

string encryptString(const string& plaintext, map<char, string>& keypadMap) {
    string encryptedText;
    for (char ch : plaintext) {
        char lowercaseCh = tolower(ch); 
        if (keypadMap.count(lowercaseCh) > 0) {
            encryptedText += keypadMap[lowercaseCh];
        }
    }
    return encryptedText;
}

string decryptString(const string& plaintext, map<char, string>& keypadMap) {
    string decryptedText;
    for (int i = 0; i < plaintext.size(); i += 2) {
        string digits = plaintext.substr(i, 2);
        for (auto entry : keypadMap) {
            if (entry.second == digits) {
                decryptedText.push_back(entry.first);
                break;
            }
        }
    }
    return decryptedText;
}

int main() {
    map<char, string> keypadMap{
        {'a', "21"}, {'b', "22"}, {'c', "23"},
        {'d', "31"}, {'e', "32"}, {'f', "33"},
        {'g', "41"}, {'h', "42"}, {'i', "43"},
        {'j', "51"}, {'k', "52"}, {'l', "53"},
        {'m', "61"}, {'n', "62"}, {'o', "63"},
        {'p', "71"}, {'q', "72"}, {'r', "73"}, {'s', "74"},
        {'t', "81"}, {'u', "82"}, {'v', "83"},
        {'w', "91"}, {'x', "92"}, {'y', "93"}, {'z', "94"}
    };

    string message;
    cout << "Enter the message to encrypt: ";
    cin >> message;

    // Encryption
    string encryptedMessage = encryptString(message, keypadMap);
    cout << "Encrypted message: " << encryptedMessage << endl;

    // Decryption 
    string decryptedMessage = decryptString(encryptedMessage, keypadMap);
    cout << "Decrypted message: " << decryptedMessage << endl;

    return 0;
}

