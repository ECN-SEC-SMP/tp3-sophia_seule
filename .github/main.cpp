#include <iostream>
#include "point.hpp"

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
}
