#include <iostream>
#include "point.hpp"
#include "carre.hpp"

int main()
{
    // Création d'un point
    Point<double> p1(1.5, 2.0);
    std::cout << "p1 = " << p1 << std::endl;

    // Test translater
    p1.translater(0.5, -1.0);
    std::cout << "Après translation : p1 = " << p1 << std::endl;

    // Test constructeur de recopie
    Point<double> p2(p1);
    std::cout << "p2 (copie de p1) = " << p2 << std::endl;

    // Test setters
    p2.setX(10.0);
    p2.setY(20.0);
    std::cout << "Après modification : p2 = " << p2 << std::endl;

    // Test getters
    std::cout << "Coordonnées de p2 : x=" << p2.getX()
              << ", y=" << p2.getY() << std::endl;

    return 0;

    /*
    question 3 - carree - test
    Point<double> c(1.0, 1.0);
    Carre<double> s(c, 4.0);

    std::cout << s << std::endl;

    s.setCote(10.0);
    std::cout << "Après modification : " << s << std::endl;

    return 0;*/

    /* 
    question 4 - specialisation - test
    Point<std::string> p("Bonjour", "Nantes");
    std::cout << p << std::endl;

    p.translater("ignored", "ignored");
    std::cout << p << std::endl; */

    /* 
    question 5 - liste de formes - test
    #include <iostream>
    #include "listeFormes.hpp"

    int main()
    {
        ListeFormes<double> lf;

        // création de formes
        Point<double> c1(0, 0);
        Point<double> c2(5, 5);

        lf.ajouter(new Rectangle<double>(c1, 4.0, 2.0));
        lf.ajouter(new Carre<double>(c2, 3.0));

        // affichage
        std::cout << lf << std::endl;

        // surface totale
        std::cout << "Surface totale = " << lf.surfaceTotale() << std::endl;

        // boîte englobante
        Rectangle<double> box = lf.boiteEnglobante();
        std::cout << "Boite englobante : " << box << std::endl;

        // nettoyage (le plus simple)
        for (size_t i = 0; i < lf.taille(); i++)
            delete lf.get(i);

        return 0;
    }  */


}
