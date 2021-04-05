#include "Solveur.hpp"
#include <bits/stdc++.h>

double randMToN(double M, double N) // définition d'une fonction qui prend en entrée deux réalsM et N et renvoie un réal aléatoire dans l'intervalle [M,N]
{
   return M + (rand() / (RAND_MAX / (N - M)));
}

/* -------------------------------- définition des méthodes de classes S(i) {1,2....7} -----------------------------------------------------*/

// définition de la méthode resoudre pour le solveur S1 qui prend en entrée un pointeur Probleme
//et une reférence type Point qui va nous servir pour stocker le point qui donne Fminet
//une deuxième réference  de type double pour stocker Fmin
void S1::resoudre(Probleme *problm, Point &Pmin, double &Fmin)
{

   if (problm->getDim() == 1)
   {
      double x_centre = ((problm->getVariables())[0][1] + (problm->getVariables())[0][0]) / 2;
      Pmin.setX(x_centre);

      Fmin = problm->F(Pmin);
   }

   if (problm->getDim() == 2)
   {
      double x_centre = ((problm->getVariables())[0][1] + (problm->getVariables())[0][0]) / 2;
      double y_centre = ((problm->getVariables())[1][1] + (problm->getVariables())[1][0]) / 2;
      Pmin.setXY(x_centre, y_centre);

      Fmin = problm->F(Pmin);
   }
}

void S2::resoudre(Probleme *problm, Point &Pmin, double &Fmin)
{

   Point tmp;
   if (problm->getDim() == 1)
   {

      double pas = ((problm->getVariables()[0][1] - (problm->getVariables())[0][0])) / 9;
      tmp.setX(problm->getVariables()[0][0]);
      Pmin.setX(tmp.getX());
      Fmin = problm->F(tmp);
      for (int i = 1; i < 10; i++)
      {
         tmp.setX(problm->getVariables()[0][0] + pas * i);
         if (Fmin > problm->F(tmp))
         {
            Pmin.setX(tmp.getX());
            Fmin = problm->F(tmp);
         }
      }
   }

   if (problm->getDim() == 2)
   {
      double pasX = ((problm->getVariables()[0][1]) - (problm->getVariables()[0][0])) / 9;
      double pasY = ((problm->getVariables()[1][1]) - (problm->getVariables()[1][0])) / 9;
      cout << pasX << "  " << pasY << endl;
      tmp.setX(problm->getVariables()[0][0]);
      tmp.setY(problm->getVariables()[1][0]);
      Pmin.setXY(tmp.getX(), tmp.getY());
      Fmin = problm->F(tmp);

      for (int i = 0; i < 10; i++)
      {
         for (int j = 0; j < 10; j++)
         {
            tmp.setXY(problm->getVariables()[0][0] + pasX * i, problm->getVariables()[1][0] + pasY * j);

            if (Fmin > problm->F(tmp))
            {

               Pmin.setXY(tmp.getX(), tmp.getY());
               Fmin = problm->F(tmp);
            }
         }
      }
   }
}

// L'idée de ce solveur est la suivante : en 1D ce solveur est similaire au Solveur S1 et en 2D on s'inspire du solveur 2 qu'est basé sur la discrétisation Par 10
// le variable temp de type Point stocke à chaque évaluation les coodonées x y si on se retrouve avec un Fmin inféneiure à la valeur déja trouvée dans l'itération précédente
//
void S3::resoudre(Probleme *problm, Point &Pmin, double &Fmin)
{

   Point tmp;

   if (problm->getDim() == 1)
   {
      Solveur *Solv = new S1;
      Solv->resoudre(problm, Pmin, Fmin);
   }
   if (problm->getDim() == 2)
   {

      double pasX = ((problm->getVariables()[0][1]) - (problm->getVariables()[0][0])) / 9;
      double pasY = ((problm->getVariables()[1][1]) - (problm->getVariables()[1][0])) / 9;
      double x_centre = ((problm->getVariables())[0][1] + (problm->getVariables())[0][0]) / 2;

      tmp.setX(x_centre);
      tmp.setY(problm->getVariables()[1][0]);
      Pmin.setXY(tmp.getX(), tmp.getY());
      Fmin = problm->F(tmp);

      for (int i = 0; i < 10; i++)
      {
         tmp.setY(problm->getVariables()[1][0] + pasY * i);

         if (Fmin > problm->F(tmp))
         {

            Pmin.setY(tmp.getY());
            Fmin = problm->F(tmp);
         }
      }

      for (int i = 0; i < 10; i++)
      {
         tmp.setX(problm->getVariables()[0][0] + pasX * i);

         if (Fmin > problm->F(tmp))
         {

            Pmin.setX(tmp.getX());
            Fmin = problm->F(tmp);
         }
      }
   }
}

void S4::resoudre(Probleme *problm, Point &Pmin, double &Fmin)
{
   Point tmp;

   if (problm->getDim() == 1)
   {

      double RandX = randMToN(problm->getVariables()[0][0], problm->getVariables()[0][1]);
      tmp.setX(RandX);
      Fmin = problm->F(tmp);
      Pmin.setX(tmp.getX());

      for (int i = 0; i < 999; i++)
      {
         RandX = randMToN(problm->getVariables()[0][0], problm->getVariables()[0][1]);
         tmp.setX(RandX);

         if (Fmin > problm->F(tmp))
         {
            Pmin.setX(tmp.getX());
            Fmin = problm->F(tmp);
         }
      }
   }

   if (problm->getDim() == 2)
   {
      double RandX = randMToN(problm->getVariables()[0][0], problm->getVariables()[0][1]);
      double RandY = randMToN(problm->getVariables()[1][0], problm->getVariables()[1][1]);

      tmp.setXY(RandX, RandY);
      Fmin = problm->F(Pmin);
      Pmin.setXY(tmp.getX(), tmp.getY());

      for (int i = 0; i < 999; i++)
      {
         RandX = randMToN(problm->getVariables()[0][0], problm->getVariables()[0][1]);
         RandY = randMToN(problm->getVariables()[1][0], problm->getVariables()[1][1]);
         tmp.setXY(RandX, RandY);

         if (Fmin > problm->F(tmp))
         {
            Pmin.setXY(tmp.getX(), tmp.getY());
            Fmin = problm->F(tmp);
         }
      }
   }
}

void S5::resoudre(Probleme *problm, Point &Pmin, double &Fmin)
{

   if (problm->getDim() == 1)
   {

      Solveur *Solv = new S4;
      Solv->resoudre(problm, Pmin, Fmin);
      double minX = problm->getVariables()[0][0];
      double maxX = problm->getVariables()[0][1];

      for (int i = 0; i < 100; i++)
      {

         double larg_2 = ((problm->getVariables())[0][1] - (problm->getVariables())[0][0]) / 4;
         problm->getVariables()[0][0] = max(minX, Pmin.getX() - larg_2);
         problm->getVariables()[0][1] = min(maxX, Pmin.getX() + larg_2);
         Solv->resoudre(problm, Pmin, Fmin);
      }
   }
   else if (problm->getDim() == 2)
   {
      Solveur *Solv = new S4;
      Solv->resoudre(problm, Pmin, Fmin);
      double minX = problm->getVariables()[0][0];
      double minY = problm->getVariables()[1][0];
      double maxX = problm->getVariables()[0][1];
      double maxY = problm->getVariables()[1][1];

      for (int i = 0; i < 100; i++)
      {
         double larg_x_2 = ((problm->getVariables())[0][1] - (problm->getVariables())[0][0]) / 4;
         double larg_y_2 = ((problm->getVariables())[1][1] - (problm->getVariables())[1][0]) / 4;

         problm->getVariables()[0][0] = max(minX, Pmin.getX() - larg_x_2);
         problm->getVariables()[0][1] = min(maxX, Pmin.getX() + larg_x_2);

         problm->getVariables()[1][0] = max(minY, Pmin.getY() - larg_y_2);
         problm->getVariables()[1][1] = min(maxY, Pmin.getY() + larg_y_2);

         Solv->resoudre(problm, Pmin, Fmin);
      }
   }
}

void S6::resoudre(Probleme *problm, Point &Pmin, double &Fmin)
{

   Point tmp;

   if (problm->getDim() == 1)
   {
      Point G, D;

      double x_centre = ((problm->getVariables())[0][1] + (problm->getVariables())[0][0]) / 2;
      double pasX = ((problm->getVariables()[0][1]) - (problm->getVariables()[0][0])) / 9;

      Pmin.setX(x_centre);
      Fmin = problm->F(Pmin);

      G.setX(min(Pmin.getX() + pasX, problm->getVariables()[0][1]));
      D.setX(max(Pmin.getX() - pasX, problm->getVariables()[0][0]));
      while (problm->F(G) < Fmin || problm->F(D) < Fmin)
      {
         if (problm->F(G) < problm->F(D))
         {
            Pmin.setX(G.getX());
            Fmin = problm->F(Pmin);
         }
         else
         {
            Pmin.setX(D.getX());
            Fmin = problm->F(Pmin);
         }

         G.setX(min(Pmin.getX() + pasX, problm->getVariables()[0][1]));
         D.setX(max(Pmin.getX() - pasX, problm->getVariables()[0][0]));
      }
   }

   if (problm->getDim() == 2)
   {
      Point G, D, U, DOW;

      double x_centre = ((problm->getVariables())[0][1] + (problm->getVariables())[0][0]) / 2;
      double y_centre = ((problm->getVariables())[1][1] + (problm->getVariables())[1][0]) / 2;

      double pasX = ((problm->getVariables()[0][1]) - (problm->getVariables()[0][0])) / 9;
      double pasY = ((problm->getVariables()[1][1]) - (problm->getVariables()[1][0])) / 9;
      double pasMin = min(pasX, pasY);

      tmp.setXY(x_centre, y_centre);
      Pmin.setXY(tmp.getX(), tmp.getY());
      Fmin = problm->F(tmp);

      G.setX(min(Pmin.getX() + pasMin, problm->getVariables()[0][1]));
      D.setX(max(Pmin.getX() - pasMin, problm->getVariables()[0][0]));

      U.setX(min(Pmin.getX() + pasMin, problm->getVariables()[1][1]));
      DOW.setX(max(Pmin.getX() - pasMin, problm->getVariables()[1][0]));

      while (problm->F(G) < Fmin || problm->F(D) < Fmin || problm->F(U) < Fmin || problm->F(DOW) < Fmin)
      {

         if (problm->F(G) <= problm->F(D) && problm->F(G) <= problm->F(U) && problm->F(G) <= problm->F(DOW))
         {
            Pmin.setXY(G.getX(), G.getY());
            Fmin = problm->F(Pmin);
         }
         else if (problm->F(D) <= problm->F(G) && problm->F(D) <= problm->F(U) && problm->F(D) <= problm->F(DOW))
         {
            Pmin.setXY(D.getX(), D.getY());
            Fmin = problm->F(Pmin);
         }
         else if (problm->F(U) <= problm->F(D) && problm->F(U) <= problm->F(G) && problm->F(U) <= problm->F(DOW))
         {
            Pmin.setXY(U.getX(), U.getY());
            Fmin = problm->F(Pmin);
         }
         else if (problm->F(DOW) <= problm->F(D) && problm->F(DOW) <= problm->F(G) && problm->F(DOW) <= problm->F(U))
         {
            Pmin.setXY(DOW.getX(), DOW.getY());
            Fmin = problm->F(Pmin);
         }

         G.setX(min(Pmin.getX() + pasMin, problm->getVariables()[0][1]));
         D.setX(max(Pmin.getX() - pasMin, problm->getVariables()[0][0]));

         U.setX(min(Pmin.getX() + pasMin, problm->getVariables()[1][1]));
         DOW.setX(max(Pmin.getX() - pasMin, problm->getVariables()[1][0]));
      }
   }
}

void S7::resoudre(Probleme *problm, Point &Pmin, double &Fmin)
{

   Point tmp;

   if (problm->getDim() == 1)
   {
      Point G, D;

      double x_centre = ((problm->getVariables())[0][1] + (problm->getVariables())[0][0]) / 2;
      double pasX = ((problm->getVariables()[0][1]) - (problm->getVariables()[0][0])) / 9;
      Pmin.setX(x_centre);
      Fmin = problm->F(Pmin);
      while (pasX >= 0.001)
      {

         G.setX(min(Pmin.getX() + pasX, problm->getVariables()[0][1]));
         D.setX(max(Pmin.getX() - pasX, problm->getVariables()[0][0]));
         while (problm->F(G) < Fmin || problm->F(D) < Fmin)
         {
            if (problm->F(G) < problm->F(D))
            {
               Pmin.setX(G.getX());
               Fmin = problm->F(Pmin);
            }
            else
            {
               Pmin.setX(D.getX());
               Fmin = problm->F(Pmin);
            }

            G.setX(min(Pmin.getX() + pasX, problm->getVariables()[0][1]));
            D.setX(max(Pmin.getX() - pasX, problm->getVariables()[0][0]));
         }
         pasX /= 10;
      }
   }

   if (problm->getDim() == 2)
   {
      Point G, D, U, DOW;

      double x_centre = ((problm->getVariables())[0][1] + (problm->getVariables())[0][0]) / 2;
      double y_centre = ((problm->getVariables())[1][1] + (problm->getVariables())[1][0]) / 2;

      double pasX = ((problm->getVariables()[0][1]) - (problm->getVariables()[0][0])) / 9;
      double pasY = ((problm->getVariables()[1][1]) - (problm->getVariables()[1][0])) / 9;
      double pasMin = min(pasX, pasY);
      tmp.setXY(x_centre, y_centre);
      Pmin.setXY(tmp.getX(), tmp.getY());
      Fmin = problm->F(tmp);

      while (pasMin > 0.001)
      {

         G.setX(min(Pmin.getX() + pasMin, problm->getVariables()[0][1]));
         D.setX(max(Pmin.getX() - pasMin, problm->getVariables()[0][0]));

         U.setX(min(Pmin.getX() + pasMin, problm->getVariables()[1][1]));
         DOW.setX(max(Pmin.getX() - pasMin, problm->getVariables()[1][0]));

         while (problm->F(G) < Fmin || problm->F(D) < Fmin || problm->F(U) < Fmin || problm->F(DOW) < Fmin)
         {

            if (problm->F(G) <= problm->F(D) && problm->F(G) <= problm->F(U) && problm->F(G) <= problm->F(DOW))
            {
               Pmin.setXY(G.getX(), G.getY());
               Fmin = problm->F(Pmin);
            }
            else if (problm->F(D) <= problm->F(G) && problm->F(D) <= problm->F(U) && problm->F(D) <= problm->F(DOW))
            {
               Pmin.setXY(D.getX(), D.getY());
               Fmin = problm->F(Pmin);
            }
            else if (problm->F(U) <= problm->F(D) && problm->F(U) <= problm->F(G) && problm->F(U) <= problm->F(DOW))
            {
               Pmin.setXY(U.getX(), U.getY());
               Fmin = problm->F(Pmin);
            }
            else if (problm->F(DOW) <= problm->F(D) && problm->F(DOW) <= problm->F(G) && problm->F(DOW) <= problm->F(U))
            {
               Pmin.setXY(DOW.getX(), DOW.getY());
               Fmin = problm->F(Pmin);
            }

            G.setX(min(Pmin.getX() + pasMin, problm->getVariables()[0][1]));
            D.setX(max(Pmin.getX() - pasMin, problm->getVariables()[0][0]));

            U.setX(min(Pmin.getX() + pasMin, problm->getVariables()[1][1]));
            DOW.setX(max(Pmin.getX() - pasMin, problm->getVariables()[1][0]));
         }
         pasMin /= 10;
      }
   }
}



// définition de la méthode qui permet de recoir un tableau 2D qui contient les variables ( les bornes inf et sup d intervalle)
double **Probleme::getVariables()
{
   return this->variables;
}

int Probleme::getDim()
{
   return this->dim;
}
/* -------------------------------- définition des méthodes de classes P(i) {1,2,3,4} -----------------------------------------------------*/
P1::P1() // définition de P1
{
   this->type = 1;                                        // ici il s'agit du probleme 1
   this->dim = 1;                                         // dimension du probleme 1 est = 1
   this->variables = (double **)malloc(sizeof(double *)); // création du tableau 2D des poiteurs pour stocker les limites d'intervalle du domaine de recherche (ici j'ai utilisé l'allocation dynamique)
   this->variables[0] = (double *)malloc(2 * sizeof(double));
   this->variables[0][0] = -2;
   this->variables[0][1] = 2;
}

double P1::F(Point p) // définiton de la fonction f(x)= 2 + 3*x + 4*x^2
{
   return (2 + 3 * p.getX() + 4 * p.getX() * p.getX());
}

P2::P2() // définition de P2
{
   this->type = 2;
   this->dim = 2;

   this->variables = (double **)malloc(2 * sizeof(double *));
   this->variables[0] = (double *)malloc(2 * sizeof(double));
   this->variables[1] = (double *)malloc(2 * sizeof(double));

   this->variables[0][0] = -100;
   this->variables[0][1] = 100;
   this->variables[1][0] = -100;
   this->variables[1][1] = 100;
}
double P2::F(Point p) // définiton de la fonction f(p)= ||p-p1||^2+||p-p2||^2
{
   Point p1(-1, 2), p2(-3, 5);

   return (p.getX() - p1.getX()) * (p.getX() - p1.getX()) + (p.getY() - p1.getY()) * (p.getY() - p1.getY()) + (p.getX() - p2.getX()) * (p.getX() - p2.getX()) + (p.getY() - p2.getY()) * (p.getY() - p2.getY());
}

P3::P3() // définition de P3
{
   this->type = 3;
   this->dim = 2;
   this->variables = (double **)malloc(2 * sizeof(double *));
   this->variables[0] = (double *)malloc(2 * sizeof(double));
   this->variables[1] = (double *)malloc(2 * sizeof(double));

   this->variables[0][0] = -100;
   this->variables[0][1] = 100;
   this->variables[1][0] = -100;
   this->variables[1][1] = 100;
}

double P3::F(Point p) // définiton de la fonction f(p)= ||p-p1||^2 + ||p-p2||^2 + |p-p3||^2+||p-p4||^2
{
   Point p1(-1, 2), p2(-3, 5), p3(-2.5, 3.5), p4(-4.2, 3.7);

   return (p.getX() - p1.getX()) * (p.getX() - p1.getX()) + (p.getY() - p1.getY()) * (p.getY() - p1.getY()) + (p.getX() - p2.getX()) * (p.getX() - p2.getX()) + (p.getY() - p2.getY()) * (p.getY() - p2.getY()) + (p.getX() - p3.getX()) * (p.getX() - p3.getX()) + (p.getY() - p3.getY()) * (p.getY() - p3.getY()) + (p.getX() - p4.getX()) * (p.getX() - p4.getX()) + (p.getY() - p4.getY()) * (p.getY() - p4.getY());
}

P4::P4() // définition de P4
{
   this->type = 4;
   this->dim = 1;
   this->variables = (double **)malloc(sizeof(double *));
   this->variables[0] = (double *)malloc(2 * sizeof(double));
   this->variables[0][0] = -2;
   this->variables[0][1] = 2;
}

double P4::F(Point p) // défintion de la fonction f(x) = exp(2 + 3*x + 4*x^2)
{
   return exp(2 + 3 * p.getX() + 4 * p.getX() * p.getX());
}

////////////////////////////définition des méthodes de la classe Point////////////////////////////////////////////
double Point::getX()
{
   return this->x;
}

double Point::getY()
{
   return this->y;
}

Point::Point(double x, double y)
{
   this->x = x;
   this->y = y;
}

Point::Point(double x)
{
   this->x = x;
}

void Point::setX(double x)
{
   this->x = x;
}

void Point::setY(double y)
{
   this->y = y;
}

void Point::setXY(double x, double y)
{
   this->x = x;
   this->y = y;
}
