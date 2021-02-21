/**
 * \file Porte.h
 * \brief Ce fichier contient l'interface d'une porte.
 * \author Maï-Anh Porlier
 * \version 0.1
 * \date février 2021
 *
 */

#ifndef PORTE_H_
#define PORTE_H_


namespace TP1
{
/**
 * \enum Couleur
 * \brief La couleur d'un joueur
 *
 * elle peut prendre 5 valeurs : Rouge, Bleu, Jaune ou Vert ainsi que la
 * valeur "Aucun" qui est une valeur spéciale utilisée dans la fonction "trouveGagnant".
 */
    typedef enum
    {
        Rouge, Vert, Bleu, Jaune, Aucun
    } Couleur;

// La ligne qui suit sert à signifier au compilateur que la classe "Piece" existe.
// On le fait, car la structure "Porte" comporte des pointeurs vers la classe "Piece", et vice versa.
    class Piece;

/**
 * \class Porte
 * \brief classe qui représente une porte d'une couleur donnée entre deux pièces
 */

    class Porte
    {
    public:
/**
 * \brief Constructeur par defaut de la porte, il initialise l'attribut couleur a Aucun et destination a 0 par defaut
 */
        //constructeur par défaut
        Porte();
/**
 * \brief Constructeur surcharge  de la porte
 * \param[in]c la couleur de la porte
 * \param[in]d la destination de la porte
 */
        //Constructeur, en argument la couleur de la porte ainsi que la pièce de destination
        Porte(const Couleur &c, Piece *d);
/**
 * \brief Constructeur copie de la porte
 * \param[in]p_porte la porte que l'on veut copier
 */
        //Constructeur de copie
        Porte(const Porte &);
/**
 * \brief Destructeur de la porte
 */
        //un destructeur qui ne fera rien
        ~Porte();
/**
 * \brief Surcharge de l'operateur d'assignation
 * \param[in]source la porte que l'on veut donner les valeurs de notre labyrinthe courant
 * \return La porte courante avec ses nouvelles valeurs
 */
        //Surcharge de l'opérateur =
        const Porte &operator=(const Porte &source);
/**
 * \fn Porte::operator==(const Porte &source) const
 * \brief Surcharge de l'operateur d'egalite
 * \param[in]source la porte que l'on veut comparer
 * \return bool true si la porte est identique, false autrement
 */
        //Surcharge de l'opérateur ==
        bool operator==(const Porte &source) const;
/**
 * \fn Porte::getCouleur() const
 * \brief Accesseur pour l'attribut color d'une porte
 * \return Couleur la couleur de la porte
 */
        //accesseur de la couleur d'une porte
        Couleur getCouleur() const;
/**
 * \fn *Porte::getDestination() const
 * \brief Accesseur pour l'attribut destination d'une porte
 * \return Piece *Porte Un pointeur qui pointe ou la porte mene
 */
        //Accesseur de la piece de destination
        Piece *getDestination() const;

    private:
        Piece *destination; /*!< Vers où la porte mène.*/
        Couleur color; /*< Couleur de la porte.*/
        /*!< Cette couleur spécifie en même temps quel est le joueur qui a le droit de franchir cette porte.*/

    };

}

#endif /* PORTE_H_ */
