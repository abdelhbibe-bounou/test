#ifndef __Solveur__
#define __Solveur__

#include <bits/stdc++.h>

using namespace std;
// définition de la classe point
class Point
{
protected:
	double x; // attribut x
	double y; // attribut y

public:
	Point(){};						// premier constructeur
	Point(double x, double y);		// 2eme constructeur pour unpoint 2D dont on connait  ( x,y)
	Point(double x);				// 3eme costructeur pour point 1D dont on connait (x)
	double getX();					//  méthode qui retourne la coordonnée X d'un objet Point
	double getY();					//  méthode qui retourne la coordonnée Y d'un objet Point
	void setX(double x);			// méthode qui permet d'affecter la coordonnée x à un obejet Point
	void setY(double y);			//méthode qui permet d'affecter la coordonnée yà un obejet Point
	void setXY(double x, double y); //méthode qui permet d'affecter la coordonnée x et la coordonnée y à un obejet Point
};

class Probleme // déclaration d'un polymorphisme Problemes et ses classe dérivées (P1, P2, P3 et P4)
{
	// déclaration des attributs communs pour un obejt Pobleme
protected:
	int dim;			 // dimension du problème ( dons notre cas 1D et bien 2D)
	int type;			 // cette varibale va nous aider à identifier le problème à résoudre ( il prent 1 pour le problème 1 par exemple)
	double **constantes; // Tableau 2D pour stocker les constantes ( ici pour le problème 2 et 3)
	double **variables;	 // tableua 2D pour stocker les domaines de recherche de la solution

public:
	virtual double F(Point p) = 0; // déclaration et initialisation  d'une méthode qu'est dans ce cas la fonction à minimiser qui prend variable de type point en entrées elle va nous servir à calcler la solution Fmin
	int getDim();				   // méthode qui contient la dimension du problème
	double **getVariables();	   //  méthode qui renvoie un tableau 2 D contenant l'espace de recherche
};

class P1 : public Probleme // le probleme est le probleme 1 (P1)
{
public:
	P1();					   // constructeur de P1
	~P1(){};				   // destructeur de P1
	virtual double F(Point p); // methode de défition de la fonction à minimiser qui prend un point (1D/2D) en entrée
};

class P2 : public Probleme //le probleme est le probleme 2 (P2)
{
public:
	P2();
	~P2(){};
	virtual double F(Point p);
};

class P3 : public Probleme //le probleme est le probleme 3 (P3)
{
public:
	P3();
	~P3(){};
	virtual double F(Point p);
};

class P4 : public Probleme //le probleme est le probleme 4 (P4)
{
public:
	P4();
	~P4(){};
	virtual double F(Point p);
};
class Solveur
{

protected:
	int type;

public:
	virtual void resoudre(Probleme *problm, Point &Pmin, double &Fmin) = 0; // méthode qui permet de résoudre le problème
};

class S1 : public Solveur //le solveur est le solveur 1
{
public:
	virtual void resoudre(Probleme *problm, Point &Pmin, double &Fmin);
};

class S2 : public Solveur // le solveur est le solvueur 2
{
public:
	virtual void resoudre(Probleme *problm, Point &Pmin, double &Fmin);
};

class S3 : public Solveur // le solveur est le solvueur 3
{
public:
	virtual void resoudre(Probleme *problm, Point &Pmin, double &Fmin);
};

class S4 : public Solveur //Ule solveur est le solvueur 4
{
public:
	virtual void resoudre(Probleme *problm, Point &Pmin, double &Fmin);
};

class S5 : public Solveur //le solveur est le solvueur 5
{
public:
	virtual void resoudre(Probleme *problm, Point &Pmin, double &Fmin);
};

class S6 : public Solveur //le solveur est le solvueur 6
{
public:
	virtual void resoudre(Probleme *problm, Point &Pmin, double &Fmin);
};

class S7 : public Solveur //le solveur est le solvueur 7
{
public:
	virtual void resoudre(Probleme *problm, Point &Pmin, double &Fmin);
};

#endif
