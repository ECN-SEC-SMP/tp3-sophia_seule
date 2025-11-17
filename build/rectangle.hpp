#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include <iostream>
#include "forme.hpp"

template <typename T>
class Rectangle : public Forme<T>
{
private:
    T largeur;
    T hauteur;

public:
    // --- Constructeur ---
    Rectangle(const Point<T>& c, const T& l, const T& h)
        : Forme<T>(c), largeur(l), hauteur(h) {}

    // --- Accesseurs ---
    T getLargeur() const { return largeur; }
    T getHauteur() const { return hauteur; }

    // --- Mutateurs ---
    void setLargeur(const T& l) { largeur = l; }
    void setHauteur(const T& h) { hauteur = h; }

    // --- Redéfinitions des méthodes abstraites ---
    double perimetre() const override
    {
        return 2.0 * (static_cast<double>(largeur) + static_cast<double>(hauteur));
    }

    double surface() const override
    {
        return static_cast<double>(largeur) * static_cast<double>(hauteur);
    }

    // --- Opérateur << ami ---
    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, const Rectangle<U>& r);
};


// Définition de l'opérateur <<
template <typename U>
std::ostream& operator<<(std::ostream& os, const Rectangle<U>& r)
{
    os << "Rectangle : centre=" << r.centre
       << ", largeur=" << r.largeur
       << ", hauteur=" << r.hauteur
       << ", perimetre=" << r.perimetre()
       << ", surface=" << r.surface();
    return os;
}

#endif
