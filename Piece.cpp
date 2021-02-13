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


    Piece::Piece() {

    }

    Piece::Piece(const std::string &s): nom(s) {

    }

    Piece::Piece(const Piece &source) { //TODO

    }

    Piece::~Piece() {

    }

    const Piece &Piece::operator=(const Piece &source) {
        return *this;; //TODO
    }

    std::string Piece::getNom() const {
        return nom;
    }

    void Piece::setParcourue(bool p) { //TODO

    }

    void Piece::setDistanceDuDebut(int d) { //TODO

    }

    bool Piece::getParcourue() const {
        return parcourue;
    }

    const std::list<Porte> &Piece::getPortes() const {
        return portes;
    }

    int Piece::getDistanceDuDebut() const { //TODO
        return 0;
    }

    void Piece::ajoutePorte(const Porte &p) {
        portes.push_back(p);

    }
    Piece* Piece::clone() const{
        return new Piece(*this);

    }

}
