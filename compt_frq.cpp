/* Y. WANG - 2025.10.12
   Compter la fréquence de chaque lettre dans une chaine de caracteres non vide, et afficher celle qui apparait la plus frequemment et aussi sa fréquence. 
*/

#include <iostream>
#include <string>
#include <vector>
#include <cassert>
using namespace std;

/*
PREMIER SOUS-ALOGORITHME
----------------------------------------------------------
Role : fonction qui compte la frequence de chaque lettre dans une chaine de caracters et les donner dans une liste.
Entree : mot_courant - chaine de caracteres.
Sortie : ls_freq - liste d'entiers.
Precondition : mot_courant n'est pas vide.

std :: vector<int> compt_frequence(std :: string mot_courant) {
    // variables
    char lettre_std, lettre_courant;
    int i, frequence = 0;
    std :: vector<int> ls_freq;

    // precondition
    assert(mot_courant.size() != 0);

    // debutmo
    for (int i = 0; i < mot_courant.size(); i++) {
        lettre_std = mot_courant[i];

        for (char lettre_courant : mot_courant) {
            if (lettre_courant == lettre_std) {
                frequence += 1;
            }
        }
    ls_freq.push_back(frequence);
    frequence = 0;
    } 
    return ls_freq;
}

DEUXIEME SOUS-ALGORITHME
Role : fonction qui prend chaque lettre dans une chaine de caracters et les mettre dans une liste.
Entree : mot_courant - chaine de caracteres.
Sortie : ls_lettre - liste de caractere.
Precondition : mot_courant n'est pas vide.
std :: vector<char> lettre_tiroir(std :: string mot_courant) {
    // variables
    std :: vector<char> ls_lettre;
    char lettre_courant, element;
    int i;
    bool trouve;

    // debut
    for (char lettre_courant : mot_courant) {
        trouve = false;

        for (char element : ls_lettre) {
            if (lettre_courant == element) {
                trouve = true;
                break;
            }
        }
        if (!trouve) {
            ls_lettre.push_back(lettre_courant);
        } 
    }
    return ls_lettre;
}

Programme principal
int main() {
    // Variables
    std :: string mot;
    std :: vector<int> resultat1;
    std :: vector<char> resultat2;
    std :: vector<std :: string> resultat_final;
    int i, j;

    // Debut
    std :: cout << "donnez un mot : ";
    std :: cin >> mot;
    
    resultat1 = compt_frequence(mot);
    resultat2 = lettre_tiroir(mot);
}
*/

/*
PREMIER SOUS-ALGORITHME
Role : procedure qui prend une chaine de caracteres, compte la frequence de chaque lettre et les met dans une liste.
Entree : mot_courant - chaine de caracteres.
Sortie : ls_final - liste de chaine de caracteres.
Precondition ：la chaine de caracteres n'est pas vide.

std :: vector<std :: string> compt_freq(std :: string mot_courant) {
    // variables
    char lettre_std, lettre_courant, lettre_parcourant, element;
    int i, j, ind, frequence = 0;
    bool trouve;
    std :: vector<int> ls_freq;
    std :: vector<char> ls_lettre;
    std :: vector<std :: string> ls_final;

    // precondition
    assert(mot_courant.size() != 0);

    // debut
    // determiner la frequence de chaque lettre
    for (int i = 0; i < mot_courant.size(); i++) {
        lettre_std = mot_courant[i];

        for (char lettre_courant : mot_courant) {
            if (lettre_courant == lettre_std) {
                frequence += 1;
            }
        }
    ls_freq.push_back(frequence);
    frequence = 0;
    }
    // mettre chaque lettre non repetitive dans une liste
    for (char lettre_courant : mot_courant) {
        trouve = false;

        for (char element : ls_lettre) {
            if (lettre_courant == element) {
                trouve = true;
                break;
            }
        }
        if (!trouve) {
            ls_lettre.push_back(lettre_courant);
        } 
    }
    for (ind = 0; ind < ls_lettre.size(); ind++) {

        ls_final.push_back(std :: string(1, ls_lettre[ind]) + ":" + std :: to_string(ls_freq[ind]));
    }
    return ls_final;
}

Programme principal
int main() {
    // Variables
    std :: string mot;
    std :: vector<std :: string> resultat;
    int indice;

    // Debut
    std :: cout << "donnez un mot : ";
    std :: cin >> mot;

    resultat = compt_freq(mot);

    for (indice = 0; indice < resultat.size(); indice++) {
        std :: cout << resultat[indice] << "\n"; 
    }
}
*/

/*
PREMIER SOUS-ALGORITHME
Role : procedure qui prend une chaine de caracteres, met chaque lettre non repetitive dans une liste, ensuite compte les frequences selon la liste.
Entree : mot_courant - chaine de caracteres.
Sortie : 

Precondition ：la chaine de caracteres n'est pas vide.
*/
vector<string> compt_freq(string mot_courant) {
    // variables
    int frequence = 0, i, j, ind, indice = 0, valeur_max = 1;
    bool trouve;
    char lettre, lettre_std, lettre_para;
    vector<char> ls_lettre;
    vector<int> ls_frequence, ls_indice_max = {};
    vector<string> ls_finale = {};

    // preconditions
    assert (mot_courant.size() != 0);
    
    // debut
    // mettre les lettres non repetitives dans une liste.
    for (int i = 0; i < mot_courant.size(); i++) {
        trouve = false;
        lettre_std = mot_courant[i];
        for (int j = 0; j < ls_lettre.size(); j++) {
            if (lettre_std == ls_lettre[j]) {
                trouve = true;
                break;
            }
        }
        if (!trouve) {
            ls_lettre.push_back(lettre_std);
        }
    }
    // compter la frequence selon la liste.
    for (int ind = 0; ind < ls_lettre.size(); ind++) {
        for (char lettre : mot_courant) {
            if (lettre == ls_lettre[ind]) {
                frequence += 1;
            }
        }
        ls_frequence.push_back(frequence);
        frequence = 0;
    }
    // il devrait retourner {t,e,s,i,n,g} et {2,1,1,1,1,1}.

    /* composer les deux listes
    for (int indice = 0; indice < ls_lettre.size(); indice++) {
        ls_finale.push_back(std :: string(1, ls_lettre[indice]) + ":" + std :: to_string(ls_frequence[indice]));
    }

    return ls_finale;
    */

    // chercher la valeur maximale dans ls_frequence.
    for (int valeur : ls_frequence) {
        if (valeur > valeur_max) {
            valeur_max = valeur;
        }
    }

    // trouver indice de cette valeur.
    // cas particulier 1 - il n'y a que 1 dans la liste
    if (valeur_max == 1) {
        cout << "chaque lettre n'apparait qu'une fois" << endl;
    }

    // inclure cas particulier 2.
    // {2, 1, 1, 3, 1, 1} ---> retourner une liste de 1 indice {3}
    // {2, 2, 1, 1, 1, 1} ---> retourner une liste de 2 indices {0,1}.
    else {
        for (int indice = 0; indice < ls_frequence.size(); indice++) {
            if (ls_frequence[indice] == valeur_max) {
                ls_indice_max.push_back(indice);
            }
        }
    }
    for (int ind_max : ls_indice_max) {
        ls_finale.push_back(string(1,ls_lettre[ind_max]) + " : " + to_string(ls_frequence[ind_max]));
    }
    return ls_finale;
}

// Prgramme principale
int main() {
    // Variables
    string mot;
    int indice;
    vector<string> resulat;

    // Debut
    cout << "donnez un mot : ";
    cin >> mot;

    resulat = compt_freq(mot);
    for (int indice = 0; indice < int(resulat.size()); indice++) {
        cout << resulat[indice] << endl;
    }
}
