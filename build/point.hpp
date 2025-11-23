#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>

template <typename T>
class Point{
private:
    T x; //abscisse
    T y; //ordonnée
public: 
    //constructeur point 
    Point(const T& xVal, const T& yVal) {
        x = xVal;
        y = yVal;
    }
    // constructeur de recopie
    Point(const Point<T>& other)
        : x(other.x), y(other.y) {}

    //Accesseurs
    T getX() const { return x; }
    T getY() const { return y; }

    //Mutateurs
    void setX(const T& newX) { x = newX; }
    void setY(const T& newY) { y = newY; }
    
    //méthode translater
    void translater(const T& dx, const T& dy)
    {
        x += dx;
        y += dy;
    }

    // opérateur << ami 
    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, const Point<U>& p);
};

// Définition de l’opérateur << (doit être en dehors de la classe)
template <typename U>
std::ostream& operator<<(std::ostream& os, const Point<U>& p)
{
    os << "(x=" << p.x << ", y=" << p.y << ")";
    return os;
}

// ----------------------------------------------------------
// SPÉCIALISATION DE translater POUR LES STRINGS
// ----------------------------------------------------------

template<>
void Point<std::string>::translater(const std::string& dx, const std::string& dy)
{
    // On ignore dx et dy volontairement.
    // Pour un point de type string, la notion de translation n'a pas de sens :
    // on montre donc une spécialisation en utilisant swap comme demandé.
    std::swap(this->x, this->y);
}


#endif 


