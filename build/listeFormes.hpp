#ifndef LISTEFORMES_HPP
#define LISTEFORMES_HPP

#include <vector>
#include <limits>
#include "forme.hpp"
#include "rectangle.hpp"
#include "carree.hpp"

template <typename T>
class ListeFormes
{
private:
    std::vector<Forme<T>*> formes;

public:
    // Ajouter une forme 
    void ajouter(Forme<T>* f)
    {
        formes.push_back(f);
    }

    // Accéder à une forme 
    Forme<T>* get(size_t i) const
    {
        return formes.at(i);
    }

    // Taille de la liste 
    size_t taille() const
    {
        return formes.size();
    }

    // Surface totale 
    double surfaceTotale() const
    {
        double total = 0.0;
        for (auto f : formes)
            total += f->surface();
        return total;
    }

    //boite englobante 
    // Renvoie un rectangle T
    Rectangle<T> boiteEnglobante() const
    {
        if (formes.empty())
        {
            // boîte vide = rectangle de taille 0 au centre (0,0)
            return Rectangle<T>(Point<T>(0,0), 0, 0);
        }

        // valeurs extremes
        double xmin = std::numeric_limits<double>::max();
        double xmax = std::numeric_limits<double>::lowest();
        double ymin = std::numeric_limits<double>::max();
        double ymax = std::numeric_limits<double>::lowest();

        for (auto f : formes)
        {
            // On récupère le centre
            Point<T> c = f->getCentre();
            double cx = static_cast<double>(c.getX());
            double cy = static_cast<double>(c.getY());

            // Selon le type, on identifie le rectangle couvrant
            const Rectangle<T>* r = dynamic_cast<const Rectangle<T>*>(f);

            if (r)
            {
                double L = static_cast<double>(r->getLargeur());
                double H = static_cast<double>(r->getHauteur());

                double x1 = cx - L/2.0;
                double x2 = cx + L/2.0;
                double y1 = cy - H/2.0;
                double y2 = cy + H/2.0;

                if (x1 < xmin) xmin = x1;
                if (x2 > xmax) xmax = x2;
                if (y1 < ymin) ymin = y1;
                if (y2 > ymax) ymax = y2;
            }
        }

        // centre = milieu de xmin/xmax
        double centreX = (xmin + xmax) / 2.0;
        double centreY = (ymin + ymax) / 2.0;
        double largeur = xmax - xmin;
        double hauteur = ymax - ymin;

        return Rectangle<T>(
            Point<T>(static_cast<T>(centreX), static_cast<T>(centreY)),
            static_cast<T>(largeur),
            static_cast<T>(hauteur)
        );
    }

    // affichage
    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, const ListeFormes<U>& lf);
};


// opérateur <<
template <typename U>
std::ostream& operator<<(std::ostream& os, const ListeFormes<U>& lf)
{
    os << "Liste de " << lf.formes.size() << " formes :" << std::endl;

    for (size_t i = 0; i < lf.formes.size(); ++i)
    {
        os << "  - " << *(lf.formes[i]) << std::endl;
    }
    return os;
}

#endif
