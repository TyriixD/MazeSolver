/**
 * \file Piece.cpp
 * \brief Ce fichier contient une implantation des méthodes de la classe Piece
 * \author Mai-anh Porlier
 * \version 0.1
 * \date février 2021
 *
 */

#include "Piece.h"

namespace TP1
{

    //Mettez l'implémentation de vos méthodes ici.

/**
 * \brief Constructeur par defaut de la piece, il initialise l'attribut parcourue a false par defaut, nom vide et distanceDuDebut a 0
 */
    Piece::Piece() : parcourue(false), nom(""), distanceDuDebut(0)
    {

    }
/**
 * \brief Constructeur surcharge de la piece, il initialise l'attribut parcourue a false par defaut et distanceDuDebut a 0
 * \param[in]s Le nom de la piece
 */
    Piece::Piece(const std::string &s) : parcourue(false), nom(s), distanceDuDebut(0)
    {

    }
/**
 * \brief Constructeur copie de la piece
 * \param[in]source La piece que l'on veut copier
 */
    Piece::Piece(const Piece &source)
    {
        parcourue = source.parcourue;
        nom = source.nom;
        portes = source.portes;
        distanceDuDebut = source.distanceDuDebut;

    }
/**
 * \brief Destructeur de la piece
 */
    Piece::~Piece()
    {}
/**
 * \brief Surcharge de l'operateur d'assignation
 * \param[in]source La piece que l'on veut copier
 * \return Une nouvelle piece
 */
    const Piece &Piece::operator=(const Piece &source)
    {
        if (this != &source)
        {
            parcourue = source.parcourue;
            nom = source.nom;
            portes = source.portes;
            distanceDuDebut = source.distanceDuDebut;

        }
        return *this;;

    }
/**
 * \fn Piece::getNom() const
 * \brief Accesseur pour l'attribut nom d'une piece
 * \return string Le nom de la piece
 */
    std::string Piece::getNom() const
    {
        return nom;
    }
/**
 * \fn void Piece::setParcourue(bool p)
 * \brief Mutateur de l'attribut parcourue
 * \param[in]p un booleen, true si la piece a ete parcourue, false autrement
 */
    void Piece::setParcourue(bool p)
    {
        parcourue = p;

    }
/**
 * \fn void Piece::setDistanceDuDebut(int d)
 * \brief Mutateur de l'attribut distanceDuDebut
 * \param[in]d un int qui indique la distance du debut
 */
    void Piece::setDistanceDuDebut(int d)
    {
        distanceDuDebut = d;

    }
/**
 * \fn bool Piece::getParcourue() const
 * \brief Accesseur pour l'attribut parcourue d'une piece
 * \return bool si la piece a ete parcourue true si oui, false autrement
 */
    bool Piece::getParcourue() const
    {
        return parcourue;
    }

    /**
   * \fn list<Porte> &Piece::getPortes() const
   * \brief Accesseur pour l'attribut portes d'une piece
   * \return list<Porte> la liste de porte de la piece
   */
    const std::list<Porte> &Piece::getPortes() const
    {
        return portes;
    }
/**
   * \fn Piece::getDistanceDuDebut() const
   * \brief Accesseur pour l'attribut distanceDuDebut d'une piece
   * \return int la distance du debut de la piece
   */
    int Piece::getDistanceDuDebut() const
    {
        return distanceDuDebut;
    }
/**
 * \fn void Piece::ajoutePorte(const Porte &p)
 * \brief Permet d'ajouter une porte a la liste de porte de la piece
 * \param[in]p La porte que l'on veut rajouter a la liste
 */
    void Piece::ajoutePorte(const Porte &p)
    {
        portes.push_back(p);
    }

/**
 * \brief Surcharge de l'operateur d'egalite
 * \param[in]source La piece que l'on veut comparer
 * \return bool true si la piece est identique, false autrement
 */
    bool Piece::operator==(const Piece &source)
    {
        bool valeurDeRetour;
        if (portes == source.portes && parcourue == source.parcourue && nom == source.nom)
        {
            valeurDeRetour = true;
        } else
        {
            valeurDeRetour = false;
        }
        return valeurDeRetour;
    }

}
