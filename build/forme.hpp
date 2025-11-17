#ifndef FORME_HPP
#define FORME_HPP

#include <iostream>
#include "point.hpp"

template <typename T>
class Forme
{
protected:
    Point<T> centre;   // centre de la forme

public:
    // constructeur
    Forme(const Point<T>& c)
        : centre(c) {}

    //destructeur virtuel
    virtual ~Forme() {}

    // méthodes abstraites
    virtual double perimetre() const = 0;
    virtual double surface() const = 0;

    //accesseur du centre
    Point<T> getCentre() const { return centre; }

    // opérateur << ami
    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, const Forme<U>& f);
};


// Définition de l’opérateur <<
template <typename U>
std::ostream& operator<<(std::ostream& os, const Forme<U>& f)
{
    os << "[Forme centrée en " << f.centre << "]";
    return os;
}

#endif
