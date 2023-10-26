/**
			@author Created by Virgile Broillet P2103804 on 09/10/2023
			@file BROILLET\_P2103804.cpp
            @brief TP Noté du 9 octobre 2023, Sujet A
		
			@copyright Copyright © 2023 Virgile Broillet P2103804. All rights reserved for studying or personal use.
*/

#include <iostream>
#include <stdlib.h>
using namespace std;

/**
 @brief structure debut jeu composer de deux chaines de carcateres solution et mots et d'un entier essai
*/
struct JeuPendu 
{
    string solution, mot;
    unsigned int essai;
};

/**
 @brief fonction qui initialise le jeu
 @fn debutJeu()
 @param[in] J la structure jeu
 */
void debutJeu(JeuPendu &J);

/**
 @brief fonction qui affiche le jeu
 @fn afficherJeu()
 @param[in] J la structure jeu
 */
void afficherJeu(const JeuPendu &J);

/**
 @brief fonction qui essaie le caractere car a l'indice indice sur la partie J
 @fn essaieCaractere()
 @param[in] J la structure jeu
 @param[in] indice l'indice de la lettre a tester
 @param[in] car le caractere a tester
 */
void essaieCaractere(JeuPendu &J, unsigned int indice, const char car);

/**
 @brief facilite la saisie ATTENTION je n'ai pas eu le temps de faire les cas > a la taille du mot et si le mot est fini ou non
 @fn devinecar()
 @param[in] J la structure
 */
void devinecar(JeuPendu &J);

/**
 @brief fonction main du programme, on peut essayer avec le mot "bebe" paar exemple en changeant l'indice 1 en 0
 */
int main(void) {
    /// creation de la partie de pendu
    JeuPendu J;
    /// initialisation de la partie
    debutJeu(J);
    /// affichage de la partie
    afficherJeu(J);
    /// test du carcatere b a l'indice 1
    devinecar(J);
    /// affichage du resultat
    afficherJeu(J);
    return 0;
}

/// partie codage des fonctions

void devinecar(JeuPendu &J){
    
    unsigned int indice;
    char car;
    cout << "quel indice lettre voulez vous devinez ? entrez un entier > 0" << endl;
    cin >> indice;
    cout << "quelle lettre voulez vous devinez saisisez la lettre" << endl;
    cin >> car;
    essaieCaractere(J, indice, car);
}

void essaieCaractere(JeuPendu &J, unsigned int indice, const char car){
    if (J.solution[indice] == car) {
        J.mot[indice] = J.solution[indice];
    }else{
        J.essai --;
    }
}

void afficherJeu(const JeuPendu &J){
    cout << J.mot << ", essai restant : " << J.essai << endl;
}

void debutJeu(JeuPendu &J){
    cout << "saisir solution" << endl;
    cin >> J.solution ;
    for (int i = 0; (i < J.solution.length()); i++) {
        J.mot = J.mot + '?';
    }
    J.essai = 10;
}
