/* Y. WANG - 2025.10.12
   Compter la fréquence de chaque lettre dans une chaine de caracteres non vide, et afficher celle qui apparait la plus frequemment et aussi sa fréquence. 
*/

#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <cctype>
using namespace std;


// Prgramme principale
int main() {
    // Variables
    char lettre;
    string mot;
    int indice, compt;
    int maxFreq = 0;

    vector<int> freq(26, 0);
    vector<string> resulat;

    // Debut
    cout << "donnez un mot : ";
    cin >> mot;

    for (auto lettre : mot) {
        lettre = tolower(lettre);
        if (lettre >= 'a' && lettre <= 'z') {
            indice = lettre - 'a';
            freq[indice] ++;
        }
    }
    
    for (auto compt : freq) {
        if (compt > maxFreq) {
            maxFreq = compt;
        }
    }

    if (maxFreq == 0) {
        cout << "Aucune lettre" << endl;
    } 
    else if (maxFreq == 1) {
        cout << "Chaque lettre apparait une fois." << endl;
    }
    else {
        cout << "Lettre(s) la/les plus frequente(s) :" << endl;
        for (int i = 0; i < 26; i++) {
            if (freq[i] == maxFreq) {
                char lettre = 'a' + i;
                cout << "'" << lettre << "' : " << maxFreq << " fois" << endl;
            }
        }
    }
}
