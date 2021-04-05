#include <iostream>
#include "Solveur.hpp"

using namespace std;

int main(int argc, char **arg)
{
    srand(0); // initialisation du générateur des nombres aléatoires pour éviter que la fonction randMToN(double M, double N) retourne la meme valeur

    ofstream Output("result.txt", ios::out | ios::trunc);

    Probleme *problm;
    Solveur *Solv;

    if (argc <= 2)
    {
        Output << "Les données sont insuffisantes" << endl;
    }
    else
    {
        string Solveur = arg[1];
        string Probleme = arg[2];

        cout << Solveur << "  " << Probleme << endl;

        if (Probleme == "P1")
        {
            cout << "Probleme 1" << endl;
            problm = new P1; //On crée le probleme P1 et on met son adresse dans un pointeur de Probleme
        }
        else if (Probleme == "P2")
        {
            cout << "Probleme 2" << endl;
            problm = new P2; //On crée le probleme P2 et on met son adresse dans un pointeur de Probleme
        }
        else if (Probleme == "P3")
        {
            cout << "Probleme 3" << endl;
            problm = new P3; //On crée le probleme P3 et on met son adresse dans un pointeur de Probleme
        }
        else if (Probleme == "P4")
        {
            cout << "Probleme 4" << endl;
            problm = new P4; //On crée le probleme P4 et on met son adresse dans un pointeur de Probleme
        }
        else
        {
            Output << "Le probleme choisi est non reconue !!" << endl;
        }

        if (Solveur == "S1")
        {
            cout << "Solveur 1" << endl;
            Solv = new S1; //on crée le solveur S1 et on met son adresse dans un pointeur de Solveur
        }
        else if (Solveur == "S2")
        {
            cout << "Solveur 2" << endl;
            Solv = new S2; //on crée le solveur S2 et on met son adresse dans un pointeur de Solveur
        }
        else if (Solveur == "S3")
        {
            cout << "Solveur 3" << endl;
            Solv = new S3;
        }
        else if (Solveur == "S4")
        {
            cout << "Solveur 4" << endl;
            Solv = new S4; //on crée le solveur S4 et on met son adresse dans un pointeur de Solveur
        }
        else if (Solveur == "S5")
        {
            cout << "Solveur 5" << endl;
            Solv = new S5; //on crée le solveur S5 et on met son adresse dans un pointeur de Solveur
        }
        else if (Solveur == "S6")
        {
            cout << "Solveur 6" << endl;
            Solv = new S6; //on crée le solveur S6 et on met son adresse dans un pointeur de Solveur
        }

        else if (Solveur == "S7")
        {
            cout << "Solveur 7" << endl;
            Solv = new S7; //on crée le solveur S7 et on met son adresse dans un pointeur de Solveur
        }

        else
        {
            Output << "Le solveur choisi est non reconue !!" << endl;
        }
    }

    Point solu;
    double Fmin;
    Solv->resoudre(problm, solu, Fmin);
    
    if (problm->getDim() == 1)
        cout << "Point = (" << solu.getX() << "), Fmin = " << Fmin << endl;
    else if (problm->getDim() == 2)
        cout << "Point = (" << solu.getX() << ", " << solu.getY() << ")  Fmin = " << Fmin << endl;


    if (problm->getDim() == 1)
        Output << "Fmin = " << Fmin << endl
               << "Point = (" << solu.getX() << ")";
    else if (problm->getDim() == 2)
        Output << "Fmin = " << Fmin << endl
               << "Point = (" << solu.getX() << "," << solu.getY() << ")";

    return 0;
}
