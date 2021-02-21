/**
 * \file Piece.h
 * \brief Ce fichier contient l'interface d'une pièce.
 * \author Maï-Anh Porlier
 * \version 0.1
 * \date février 2021
 * 
 */

#ifndef PIECE_H_
#define PIECE_H_

#include <string>
#include <list>    // pour utiliser la liste de la STL

#include "Porte.h"

namespace TP1
{
/**
 *  \class Piece
 *  \brief classe représentant une pièce dans un labyrinthe
 */
    class Piece
    {
    public:
        /**
 * \brief Constructeur par defaut de la piece, il initialise l'attribut parcourue a false par defaut, nom vide et distanceDuDebut a 0
 */
        //constructeur par défaut
        Piece();
/**
 * \brief Constructeur surcharge de la piece, il initialise l'attribut parcourue a false par defaut et distanceDuDebut a 0
 * \param[in]s Le nom de la piece
 */
        //Surcharge du constructeur, le nom de la pièce en argument
        Piece(const std::string &s);
/**
 * \brief Constructeur copie de la piece
 * \param[in]source La piece que l'on veut copier
 */
        //constructeur de copie
        Piece(const Piece &source);
/**
 * \brief Destructeur de la piece
 */
        //destructeur
        ~Piece();
/**
 * \brief Surcharge de l'operateur d'assignation
 * \param[in]source La piece que l'on veut copier
 * \return Une nouvelle piece
 */
        //Surcharge de l'opérateur =
        const Piece &operator=(const Piece &source);
/**
 * \fn Piece::getNom() const
 * \brief Accesseur pour l'attribut nom d'une piece
 * \return string Le nom de la piece
 */
        //Accesseur du nom d'une pièce
        std::string getNom() const;
/**
 * \fn void Piece::setParcourue(bool p)
 * \brief Mutateur de l'attribut parcourue
 * \param[in]p un booleen, true si la piece a ete parcourue, false autrement
 */
        //Pour initialiser l'attribut parcourue à true ou false
        void setParcourue(bool p);
/**
 * \fn void Piece::setDistanceDuDebut(int d)
 * \brief Mutateur de l'attribut distanceDuDebut
 * \param[in]d un int qui indique la distance du debut
 */
        //Pour initialiser l'attribut distanceDuDebut
        void setDistanceDuDebut(int d);
/**
 * \fn bool Piece::getParcourue() const
 * \brief Accesseur pour l'attribut parcourue d'une piece
 * \return bool si la piece a ete parcourue true si oui, false autrement
 */
        //Acceder au membre parcourue
        bool getParcourue() const;
        /**
       * \fn list<Porte> &Piece::getPortes() const
       * \brief Accesseur pour l'attribut portes d'une piece
       * \return list<Porte> la liste de porte de la piece
       */

        //Accéder à la liste des portes qui partent de la pièce
        const std::list<Porte> &getPortes() const;
/**
   * \fn Piece::getDistanceDuDebut() const
   * \brief Accesseur pour l'attribut distanceDuDebut d'une piece
   * \return int la distance du debut de la piece
   */
        //Accéder au membre distanceDuDebut
        int getDistanceDuDebut() const;
/**
 * \fn void Piece::ajoutePorte(const Porte &p)
 * \brief Permet d'ajouter une porte a la liste de porte de la piece
 * \param[in]p La porte que l'on veut rajouter a la liste
 */
        //Ajouter une porte à la liste des portes qui partent de la pièce
        void ajoutePorte(const Porte &p);

/**
 * \brief Surcharge de l'operateur d'egalite
 * \param[in]source La piece que l'on veut comparer
 * \return bool true si la piece est identique, false autrement
 */

        bool operator==(const Piece &source);


    private:
        std::list<Porte> portes; /*!< Les portes qui partent de la pièce. */
        /*!<Cette liste peut ne pas contenir toutes les portes qui
        communiquent avec la pièce. Une partie de ces portes peut être placée dans la liste de portes
        de l'autre pièce associée à la porte (utilise la liste STL).*/

        bool parcourue; /*!< Indique si la pièce a été parcourue*/
        /*!< Le champ "parcourue" sert uniquement à la méthode solutionner() de la classe labyrinthe, afin de ne pas passer
        plusieurs fois par une même pièce et risquer de tourner en rond, et donc boucler sans fin. */

        std::string nom; /*!< Le nom de la pièce. Il doit être unique pour un même labyrinthe.*/

        int distanceDuDebut; /*!< Le nombre de déplacements qu'il est nécessaire d'effectuer depuis la pièce de départ pour se rendre à cette pièce. */

    };

}

#endif /* PIECE_H_ */
