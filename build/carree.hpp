#ifndef CARRE_HPP
#define CARRE_HPP

#include <iostream>
#include "rectangle.hpp"

template <typename T>
class Carre : public Rectangle<T>
{
private:
    T cote;   // un seul attribut

public:
    // Constructeur
    Carre(const Point<T>& c, const T& coteVal)
        : Rectangle<T>(c, coteVal, coteVal), cote(coteVal) {}

    // Accesseur 
    T getCote() const { return cote; }

    //  Mutateur 
    void setCote(const T& cVal)
    {
        cote = cVal;
        // On met aussi à jour les attributs du rectangle parent
        this->setLargeur(cVal);
        this->setHauteur(cVal);
    }

    // Opérateur << ami 
    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, const Carre<U>& s);
};


// Définition de l'opérateur <<
template <typename U>
std::ostream& operator<<(std::ostream& os, const Carre<U>& s)
{
    os << "Carré : centre=" << s.centre
       << ", cote=" << s.cote
       << ", perimetre=" << s.perimetre()
       << ", surface=" << s.surface();
    return os;
}

#endif
