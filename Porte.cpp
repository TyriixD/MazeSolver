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

    Porte::Porte(): color(Aucun){

    }

    Porte::Porte(const Couleur& c, Piece *d): color(c), destination(d){

    }

    Porte::Porte(const Porte & p_porte) {
        color = p_porte.color;
        Piece pieceCopie = *(p_porte.destination); // On vient chercher la valeur de du pointeur piece
        Piece * pointeurCopie; //
        pointeurCopie = pieceCopie.clone(); //Créer un espace mémoire pour la nouvelle destination
        destination = pointeurCopie; // Assigne le pointeur Piece à la destination

    }

    Porte::~Porte() {

    }

    const Porte &Porte::operator=(const Porte &source) {
        if (this != &source){
            delete destination;
            Porte copieDePorte(source);
            destination = copieDePorte.getDestination();
            color = copieDePorte.getCouleur();
            delete source.destination;
        }
        return *this;
    }

    bool Porte::operator==(const Porte &source) const {
        bool valeurDeRetour;
        if (destination == source.destination && color == source.color)
        {
            valeurDeRetour = true;
        }
        else {
            valeurDeRetour = false;
        }
        return valeurDeRetour;

    }

    Couleur Porte::getCouleur() const {
        return color;
    }

    Piece *Porte::getDestination() const {
       return destination;
    }
}
