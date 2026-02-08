/* Y. WANG - 2025.12.15 */
/* Amelioration : Gestion des cas speciaux et boucle interactive */

#include <iostream>
#include <string>

using namespace std;

int ajusterIndice(int indice) {
    return (indice % 26 + 26) % 26; // Assurer l'indice entre 0 et 25.
}

string chiffrement_Caesar(const string& msg_cypher, int indice) {
    // variables
    int i;
    char element;
    string msg_resultat = "";
    // debut
    indice = ajusterIndice(indice);

    for (auto element : msg_cypher) {
        if (element >= 'A' && element <= 'Z' ) {
            msg_resultat += 'A' + (element - 'A' + indice) % 26;
        }
        else if (element >= 'a' && element <= 'z') {
            msg_resultat += 'a' + (element - 'a' + indice) % 26;
        }
        else {
            msg_resultat += element;
        }
    }
    return msg_resultat;
}

string dechiffrement_Caesar(const string& msg_cypher, int indice) {
    return chiffrement_Caesar(msg_cypher, -indice); // Le dechiffrement est un chiffrement avec l'indice oppose
}

int main() {
    // Variables
    int choix = 0;
    int indice = 0;

    string message_input;
    // Debut
    cout << '\n' << "=== Programme de Chiffrement de Caesar ===" << '\n';
    cout << "1. Chiffrer un message" << '\n';
    cout << "2. Dechiffrer un message" << '\n';
    cout << "3. Quitter" << '\n';
    cout << "Votre choix : ";
    cin >> choix;
    
    if (choix < 1 || choix > 3) {
        cin.clear(); // Efface l'état d'erreur
        cout << "Veuillez entrer un nombre (1, 2 ou 3)" << '\n';
    }
    cin.ignore();
    if (choix == 3) {
        cout << "Au revoir!" << endl;
    }
    else {
        cout << "Entrez votre message : ";
        getline(cin, message_input);
        cout << "Entrez la cle de decalage (un entier positif ou negatif) : ";
        cin >> indice;

        if (choix == 1) {
            cout << "Message chiffre : " << chiffrement_Caesar(message_input, indice) << endl;
        } else {
            cout << "Message dechiffre : " << dechiffrement_Caesar(message_input, indice) << endl;
        }
        
    }
}