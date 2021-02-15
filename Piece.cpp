/**
 * \file Piece.cpp
 * \brief Ce fichier contient une implantation des méthodes de la classe Piece
 * \author Étudiant(e)
 * \version 0.1
 * \date février 2021
 *
 */

#include "Piece.h"

namespace TP1
{

	//Mettez l'implémentation de vos méthodes ici.


    Piece::Piece(): parcourue(false), nom(""){

    }

    Piece::Piece(const std::string &s): parcourue(false), nom(s) {



    }

    Piece::Piece(const Piece &source): parcourue(source.parcourue),
                                        nom(source.nom),
                                        portes(source.portes),
                                        distanceDuDebut(source.distanceDuDebut) {

    }

    Piece::~Piece() {}

    const Piece &Piece::operator=(const Piece &source) {
        if (this != &source){
            parcourue = source.parcourue;
            nom = source.nom;
            portes = source.portes;
            distanceDuDebut = source.distanceDuDebut;

        }
        return *this;;

    }

    std::string Piece::getNom() const {
        return nom;
    }

    void Piece::setParcourue(bool p) {
        parcourue = p;

    }

    void Piece::setDistanceDuDebut(int d) {
        distanceDuDebut = d;

    }

    bool Piece::getParcourue() const {
        return parcourue;
    }

    const std::list<Porte> &Piece::getPortes() const {
        return portes;
    }

    int Piece::getDistanceDuDebut() const {
        return distanceDuDebut;
    }

    void Piece::ajoutePorte(const Porte &p) {
        portes.push_back(p);

    }
    Piece* Piece::clone() const{
        return new Piece(*this);

    }

}
