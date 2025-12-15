/* Y. WANG - 2025.12.15 */

#include <iostream>
#include <string>

using namespace std;

string dechiffrement_Caesar(const string& cypher, const int& chiffre_decypher) {
    // variables
    int i;
    char element;
    string decypher = "";
    // debut
    for (i = 0; i < int(cypher.size()); i++) {
        if (cypher[i] >= 'A' && cypher[i] <= 'Z') {
            element = 'A' + (cypher[i] - 'A' + chiffre_decypher) % 26;
        }
        else if (cypher[i] >= 'a' && cypher[i] <= 'z') {
            element = 'a' + (cypher[i] - 'a' + chiffre_decypher) % 26;
        }
        else if (cypher[i] == ' ' || cypher[i] == ',' || cypher[i] == '!') {
            element = cypher[i];
        }
        decypher = decypher + element;
    }
    return decypher;

}

int main() {
    // Variables
    int decypher_indice;
    string input_cypher;
    // Debut
    cout << "Phrase a dechyper : ";
    getline(cin, input_cypher);
    cout << "Indice pour decypher : ";
    cin >> decypher_indice;
    
    cout << "Message apres le dechiffrement : " << dechiffrement_Caesar(input_cypher, decypher_indice);

}