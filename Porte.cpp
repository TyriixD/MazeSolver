/**
 * \file Porte.cpp
 * \brief Ce fichier contient une implantation des méthodes de la classe Porte
 * \author Mai-Anh Porlier
 * \version 0.1
 * \date février 2021
 *
 */

#include "Porte.h"
#include "Piece.h"

namespace TP1
{

    //Mettez l'implémentation de vos méthodes ici.
/**
 * \brief Constructeur par defaut de la porte, il initialise l'attribut couleur a Aucun et destination a 0 par defaut
 */
    Porte::Porte() : color(Aucun), destination(0)
    {

    }
/**
 * \brief Constructeur surcharge  de la porte
 * \param[in]c la couleur de la porte
 * \param[in]d la destination de la porte
 */
    Porte::Porte(const Couleur &c, Piece *d)
    {
        color = c;
        destination = d;

    }
/**
 * \brief Constructeur copie de la porte
 * \param[in]p_porte la porte que l'on veut copier
 */
    Porte::Porte(const Porte &p_porte)
    {
        color = p_porte.color;
        destination = p_porte.destination;

    }
/**
 * \brief Destructeur de la porte
 */
    Porte::~Porte()
    {

    }
/**
 * \brief Surcharge de l'operateur d'assignation
 * \param[in]source la porte que l'on veut donner les valeurs de notre labyrinthe courant
 * \return La porte courante avec ses nouvelles valeurs
 */
    const Porte &Porte::operator=(const Porte &source)
    {
        if (this != &source)
        {
            destination = source.destination;
            color = source.color;
        }
        return *this;
    }
/**
 * \fn Porte::operator==(const Porte &source) const
 * \brief Surcharge de l'operateur d'egalite
 * \param[in]source la porte que l'on veut comparer
 * \return bool true si la porte est identique, false autrement
 */
    bool Porte::operator==(const Porte &source) const
    {
        bool valeurDeRetour;
        if (destination == source.destination && color == source.color)
        {
            valeurDeRetour = true;
        } else
        {
            valeurDeRetour = false;
        }
        return valeurDeRetour;

    }
/**
 * \fn Porte::getCouleur() const
 * \brief Accesseur pour l'attribut color d'une porte
 * \return Couleur la couleur de la porte
 */
    Couleur Porte::getCouleur() const
    {
        return color;
    }
/**
 * \fn *Porte::getDestination() const
 * \brief Accesseur pour l'attribut destination d'une porte
 * \return Piece *Porte Un pointeur qui pointe ou la porte mene
 */
    Piece *Porte::getDestination() const
    {
        return destination;
    }
}
