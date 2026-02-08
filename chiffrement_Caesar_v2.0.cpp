/* Y. WANG - 2025.12.15 */

#include <iostream>
#include <string>

using namespace std;

string chiffrement_Caesar(const string& cypher, const int& indice) {
    // variables
    int i;
    char element;
    string msg_cypher = "";
    // debut
    for (i = 0; i < int(cypher.size()); i++) {
        if (cypher[i] >= 'A' && cypher[i] <= 'Z') {
            element = 'A' + (cypher[i] - 'A' + indice) % 26;
        }
        else if (cypher[i] >= 'a' && cypher[i] <= 'z') {
            element = 'a' + (cypher[i] - 'a' + indice) % 26;
        }
        else if (cypher[i] == ' ' || cypher[i] == ',' || cypher[i] == '!') {
            element = cypher[i];
        }
        msg_cypher = msg_cypher + element;
    }
    return msg_cypher;
}

string dechiffrement_Caesar(const string& cypher, const int& chiffre_decypher) {
    // variables
    int i;
    char element;
    string msg_decypher = "";
    // debut
    for (i = 0; i < int(cypher.size()); i++) {
        if (cypher[i] >= 'A' && cypher[i] <= 'Z') {
            element = 'A' + (cypher[i] - 'A' - chiffre_decypher) % 26;
        }
        else if (cypher[i] >= 'a' && cypher[i] <= 'z') {
            element = 'a' + (cypher[i] - 'a' - chiffre_decypher) % 26;
        }
        else if (cypher[i] == ' ' || cypher[i] == ',' || cypher[i] == '!') {
            element = cypher[i];
        }
        msg_decypher = msg_decypher + element;
    }
    return msg_decypher;
}

int main() {
    // Variables
    int indice;
    int ind_chiffre_dechiffre;
    string message_input;
    // Debut
    cout << "Votre message : ";
    getline(cin, message_input);
    cout << "Pour chiffrer, entrez 1. Pour dechiffrer entrez 2 : ";
    cin >> ind_chiffre_dechiffre;
    if (ind_chiffre_dechiffre == 1) {
        cout << "Indice pour decaler : ";
        cin >> indice;
        cout << "Message apres le dechiffrement : " << chiffrement_Caesar(message_input, indice);
    }
    else if (ind_chiffre_dechiffre == 2) {
        cout << "Indice pour decaler : ";
        cin >> indice;
        cout << "Message apres le dechiffrement : " << dechiffrement_Caesar(message_input, indice);
    }
}