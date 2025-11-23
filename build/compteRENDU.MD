# TP – Classes, Templates, Héritage & Polymorphisme

## Compte-rendu - SOPHIA LOUKILI

---

## 1. Introduction

Ce TP avait pour objectif de manipuler différentes notions avancées du langage C++ :

* Création de classes génériques (templates)
* Constructeurs, constructeur de recopie
* Accesseurs, mutateurs
* Méthode spécialisée
* Surcharge de l’opérateur `<<`
* Classe abstraite et polymorphisme
* Héritage (Rectangle, Carré)
* Structure de données `vector` et manipulation de pointeurs
* Calcul de surface totale et boîte englobante

---

## 2. Classe `Point<T>`

La classe `Point<T>` représente un point du plan avec deux coordonnées génériques :

* `T x` (abscisse)
* `T y` (ordonnée)

### Fonctionnalités implémentées :

* Constructeur paramétré
* Constructeur de recopie
* Getters / setters
* Méthode `translater(dx, dy)` (générique)
* Surcharge de l’opérateur `<<`
* **Spécialisation de `translater()` pour `std::string`** utilisant `std::swap`

### Exemple d’essai :

```cpp
Point<double> p1(1.5, 2.0);
p1.translater(0.5, -1.0);
Point<double> p2(p1);
```

### Spécialisation :

```cpp
Point<std::string> p("Bonjour", "Nantes");
p.translater("ignored", "ignored"); // swap automatique
```

---

## 3. Classe abstraite `Forme<T>`

`Forme<T>` est une classe abstraite représentant une forme géométrique centrée en un `Point<T>`.

Elle déclare deux méthodes abstraites :

```cpp
virtual double perimetre() const = 0;
virtual double surface() const = 0;
```

Elle surcharge également l’opérateur `<<` pour afficher le centre.

---

## 4. Classes `Rectangle<T>` et `Carre<T>`

### Rectangle<T>

Implémente :

* largeur et hauteur
* calcul du périmètre : `2*(L+H)`
* calcul de la surface : `L*H`
* opérateur `<<`

### Carre<T>

Hérite de `Rectangle<T>` :

* attribut `cote`
* constructeur spécifique
* mise à jour automatique de largeur = hauteur = cote
* opérateur `<<`

### Exemple d’essai :

```cpp
Carre<double> s(Point<double>(1,1), 4);
s.setCote(10); // met automatiquement largeur = hauteur = 10
```

---

## 5. Classe `ListeFormes<T>`

Implémentée à l’aide de `std::vector<Forme<T>*>`.

### Fonctionnalités :

* `ajouter(Forme<T>*)`
* `get(i)`
* `taille()`
* `surfaceTotale()`
* **boiteEnglobante()** : retourne un `Rectangle<T>` minimal couvrant toutes les formes

La boîte englobante est calculée à partir d’un `dynamic_cast<Rectangle<T>*>`.

### Exemple d’essai :

```cpp
ListeFormes<double> lf;
lf.ajouter(new Rectangle<double>(Point<double>(0,0), 4, 2));
lf.ajouter(new Carre<double>(Point<double>(5,5), 3));

double total = lf.surfaceTotale();
Rectangle<double> box = lf.boiteEnglobante();
```

---

## 6. Jeux d’essais 

### Points :

```
p1 = (x=1.5, y=2.0)
Après translation : p1 = (x=2.0, y=1.0)
p2 (copie de p1) = (x=2.0, y=1.0)
```

### Spécialisation string :

```
(x=Bonjour, y=Nantes)
(x=Nantes, y=Bonjour)
```

### Carré :

```
Carré : centre=(x=1, y=1), cote=4, perimetre=16, surface=16
Après modification : cote=10, perimetre=40, surface=100
```

### Liste de formes :

```
Liste de 2 formes :
  - Rectangle : centre=(x=0, y=0), largeur=4, hauteur=2,
                perimetre=12, surface=8
  - Carré : centre=(x=5, y=5), cote=3,
            perimetre=12, surface=9

Surface totale = 17

Boîte englobante :
Rectangle : centre=(x=2.25, y=2.75),
            largeur=8.5,
            hauteur=7.5,
            perimetre=32,
            surface=63.75
```

---

## 7. Conclusion

Ce TP m’a permis de :

* maîtriser les templates en C++
* spécialiser une méthode pour un type précis (`std::string`)
* mettre en œuvre une classe abstraite
* utiliser l’héritage pour construire un modèle de formes géométriques
* surcharger des opérateurs
* manipuler `vector` avec des pointeurs polymorphiques
* calculer une boîte englobante géométrique
