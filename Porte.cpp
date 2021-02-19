/**
 * \file Porte.cpp
 * \brief Ce fichier contient une implantation des méthodes de la classe Porte
 * \author Étudiant(e)
 * \version 0.1
 * \date février 2021
 *
 */

#include "Porte.h"
#include "Piece.h"

namespace TP1
{

    //Mettez l'implémentation de vos méthodes ici.

    Porte::Porte() : color(Aucun), destination(0)
    {

    }

    Porte::Porte(const Couleur &c, Piece *d)
    {
        color = c;
        destination = d;

    }

    Porte::Porte(const Porte &p_porte)
    {
        color = p_porte.color;
        destination = p_porte.destination;

    }

    Porte::~Porte()
    {

    }

    const Porte &Porte::operator=(const Porte &source)
    {
        if (this != &source)
        {
            destination = source.destination;
            color = source.color;
        }
        return *this;
    }

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

    Couleur Porte::getCouleur() const
    {
        return color;
    }

    Piece *Porte::getDestination() const
    {
        return destination;
    }
}
