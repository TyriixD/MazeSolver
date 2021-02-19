/**
 * \file Labyrinthe.cpp
 * \brief Le code des méthodes membres et privés de la classe Labyrinthe.
 * \author IFT-2008, Maï-Anh Porlier
 * \version 0.1
 * \date février 2021
 * 
 */

//Fichiers à compléter par les autres méthodes de la classe Labyrinthes demandées

#include "Labyrinthe.h"

namespace TP1
{
    using namespace std;


// -------------------------------------------------------------------------------------------------
//	Méthodes fournies
// -------------------------------------------------------------------------------------------------

/**
 * \fn	void Labyrinthe::chargeLabyrinthe(Couleur couleur, std::ifstream &entree)
 * \param[in]	couleur, la couleur du jouer auquel le labyrinthe chargé s'applique
 * \param[in]	entree, fichier contenant la définition du labyrinthe
 */
    void Labyrinthe::chargeLabyrinthe(Couleur couleur, std::ifstream &entree)
    {
        int nbCols, nbRangs;

        if (!entree.is_open())
            throw logic_error("Labyrinthe::chargeLabyrinthe: Le fichier n'est pas ouvert !");

        entree >> nbCols >> nbRangs;
        entree.ignore(); //pour consommer le \n (le caractère fin de ligne)

        const int MAX_LIGNE = 1000;
        char ligne[MAX_LIGNE];

        entree.getline(ligne, MAX_LIGNE);
        entree.getline(ligne, MAX_LIGNE);

        std::ostringstream s; //Une chaîne pour écrire dedans, cette chaîne servira pour nommer les pièces du labyrinthe

        for (int i = 0; i < nbCols; i++)
        {
            for (int j = 0; j < nbRangs; j++)
            {
                s << i << "," << j;
                Piece p(s.str());
                s.str("");
                ajoutePieceLabyrinthe(p);
            }
        }

        for (int i = 0; i < nbCols; i++)
        {
            if (ligne[i * 4 + 1] == 'D' || ligne[i * 4 + 1] == 'd')
            {
                std::string nom;
                s << i << ",0";
                nom = s.str();
                s.str("");
                placeDepart(nom);
            }
            if (ligne[i * 4 + 1] == 'F' || ligne[i * 4 + 1] == 'f' || ligne[i * 4
                                                                            + 1] == 'A' || ligne[i * 4 + 1] == 'a')
            {
                std::string nom;
                s << i << ",0";
                nom = s.str();
                s.str("");
                placeArrivee(nom);
            }
        }

        for (int j = 0; j < nbRangs; j++)
        {
            entree.getline(ligne, MAX_LIGNE);

            for (int i = (j == nbRangs - 1 && (j & 1)) ? 1 : 0; i < nbCols; i++)
            {
                if (j & 1)
                {
                    if (j < nbRangs - 2 && ligne[i * 4 + 3] == ' ')
                    {
                        ajoutePassage(couleur, i, j, i, j + 2);
                    }
                    if (j < nbRangs - 1 && ligne[i * 4 + 2] == ' ')
                    {
                        ajoutePassage(couleur, i, j, i, j + 1);
                    }
                    if (j < nbRangs - 1 && ligne[i * 4 + 0] == ' ')
                    {
                        ajoutePassage(couleur, i - 1, j, i, j + 1);
                    }
                    if (j < nbRangs - 1 && (ligne[i * 4 + 1] == 'D' || ligne[i * 4
                                                                             + 1] == 'd'))
                    {
                        std::string nom;
                        s << i << "," << j + 1;
                        nom = s.str();
                        s.str("");
                        placeDepart(nom);
                    }
                    if (j < nbRangs - 1 && (ligne[i * 4 + 1] == 'F' || ligne[i * 4
                                                                             + 1] == 'f' || ligne[i * 4 + 1] == 'A' ||
                                            ligne[i * 4
                                                  + 1] == 'a'))
                    {
                        std::string nom;
                        s << i << "," << j + 1;
                        nom = s.str();
                        s.str("");
                        placeArrivee(nom);
                    }
                } else
                {
                    if (j < nbRangs - 1 && ligne[i * 4 + 0] == ' ')
                    {
                        ajoutePassage(couleur, i - 1, j + 1, i, j);
                    }
                    if (j < nbRangs - 2 && ligne[i * 4 + 1] == ' ')
                    {
                        ajoutePassage(couleur, i, j, i, j + 2);
                    }
                    if (j < nbRangs - 1 && ligne[i * 4 + 2] == ' ')
                    {
                        ajoutePassage(couleur, i, j, i, j + 1);
                    }
                    if (j < nbRangs - 1 && (ligne[i * 4 + 3] == 'D' || ligne[i * 4
                                                                             + 3] == 'd'))
                    {
                        std::string nom;
                        s << i << "," << j + 1;
                        nom = s.str();
                        s.str("");
                        placeDepart(nom);
                    }
                    if (j < nbRangs - 1 && (ligne[i * 4 + 3] == 'F' || ligne[i * 4
                                                                             + 3] == 'f' || ligne[i * 4 + 3] == 'A' ||
                                            ligne[i * 4
                                                  + 3] == 'a'))
                    {
                        std::string nom;
                        s << i << "," << j + 1;
                        nom = s.str();
                        s.str("");
                        placeArrivee(nom);
                    }
                }
            }
        }
    }


/**
 * \fn	Labyrinthe::ajoutePassage(Couleur couleur, int i1, int j1, int i2, int j2)
 * \param[in]	Couleur couleur Couleur de la porte à ajouter
 * \param[in]	int i1
 * \param[in]	int j1
 * \param[in]	int i2
 * \param[in]	int j2
 */
    void Labyrinthe::ajoutePassage(Couleur couleur, int i1, int j1, int i2, int j2)
    {

        NoeudListePieces *piece1, *piece2;
        string nomPiece1, nomPiece2;
        ostringstream s;

        s << i1 << "," << j1;
        nomPiece1 = s.str();

        s.str("");

        s << i2 << "," << j2;
        nomPiece2 = s.str();

        s.str("");

        piece1 = trouvePiece(nomPiece1);
        piece2 = trouvePiece(nomPiece2);

        Porte nouvellePorte(couleur, &(piece2->piece));

        piece1->piece.ajoutePorte(nouvellePorte);
    }


/**
 * \fn	Labyrinthe::ajoutePieceLabyrinthe(Piece& p)
 * \brief ajoute une pièce au labyrinthe (si elle ne s'y trouve pas déjà)
 * \param[in]	p La pièce à ajouter
 * \post	la pièce appartient au labyrinthe;
 */
    void Labyrinthe::ajoutePieceLabyrinthe(const Piece &p)
    {

        Labyrinthe::NoeudListePieces *noeud = new Labyrinthe::NoeudListePieces;
        noeud->piece = p;

        if (dernier == 0)
        {
            noeud->suivant = noeud;
            dernier = noeud;
        } else if (!appartient(p))
        {
            noeud->suivant = dernier->suivant;
            dernier->suivant = noeud;
        }

    }
/**
 * \brief Constructeur par defaut du labyrinthe, initialise tout les attributs a 0
 */
    Labyrinthe::Labyrinthe()
    {
        dernier = 0;
        depart = 0;
        arrivee = 0;

    }
/**
 * \brief Constructeur par defaut du labyrinthe, initialise tout les attributs a 0
 * \param[in]source Le labyrinthe que l'on veut copier
 */
    Labyrinthe::Labyrinthe(const Labyrinthe &source)
    {
        copieListeDesPieces((NoeudListePieces *&) source);
        copieLesPorteDansTouteLesPieces((NoeudListePieces *&) source);
        dernier = source.dernier;
        depart = source.depart;
        arrivee = source.arrivee;

    }
/**
 * \brief Destructeur du labyrinthe, il parcourt le labyrinthe et detruit tout les noeuds
 */
    Labyrinthe::~Labyrinthe()
    {
        effacerListeDePiece();

    }
/**
 * \brief Surcharge de l'operateur d'assignation
 * \param[in]source le Labyrinthe que l'ont veut prendre les valeurs et les assigner a notre labyrinthe courant
 * \return Un labyrinthe avec des nouvelles valeurs
 */
    const Labyrinthe &Labyrinthe::operator=(const Labyrinthe &source)
    {
        if (this != &source)
        {
            effacerListeDePiece();
            copieListeDesPieces((NoeudListePieces *&) source);
            copieLesPorteDansTouteLesPieces((NoeudListePieces *&) source);
            dernier = source.dernier;
            depart = source.depart;
            arrivee = source.arrivee;
        }
        return *this;
    }
/**
 * \fn	Labyrinthe::solutionner(Couleur joueur)
 * \brief Trouve le nombre de deplacement requis pour resoudre le labyrinthe pour un certain joueur donnee
 * \param[in] joueur Le joueur que l'on veut resoudre le labyrinthe
 * \return int le nombre de deplacement requis pour arrive a la fin du labyrinthe
 */
    int Labyrinthe::solutionner(Couleur joueur)
    {

        NoeudListePieces *noeudCourrant = dernier;
        do
        {
            noeudCourrant->piece.setParcourue(false);
            noeudCourrant->piece.setDistanceDuDebut(-1);
            noeudCourrant = noeudCourrant->suivant;

        } while (noeudCourrant != (dernier));

        queue<Piece> fileDePieces;
        //Étape 1
        depart->setDistanceDuDebut(0);
        depart->setParcourue(true);
        fileDePieces.push(*depart);

        do
        {
            //Étape 2.2 Vérification 1
            for (Porte const &porte : fileDePieces.front().getPortes())
            {
                if (porte.getCouleur() == joueur && !porte.getDestination()->getParcourue())
                {
                    porte.getDestination()->setParcourue(true);
                    porte.getDestination()->setDistanceDuDebut(fileDePieces.front().getDistanceDuDebut() + 1);
                    fileDePieces.push(*(porte.getDestination()));
                }

            }

            //Vérification 2 cherche les portes dans les listes de portes de
            // toutes les pièces pour voir s'il y en aurait qui mènent à la pièce défilée

            NoeudListePieces *noeud = dernier;

            do
            {
                if (!noeud->piece.getParcourue())
                {
                    for (Porte const &porte: noeud->piece.getPortes())
                    {
                        if (porte.getCouleur() == joueur && porte.getDestination()->getParcourue())
                        {
                            noeud->piece.setParcourue(true);
                            noeud->piece.setDistanceDuDebut(porte.getDestination()->getDistanceDuDebut() + 1);
                            fileDePieces.push(noeud->piece);
                        }
                    }
                }
                noeud = noeud->suivant;

            } while (noeud != (dernier));
            fileDePieces.pop();


        } while (!fileDePieces.empty() && !arrivee->getParcourue());
        return arrivee->getDistanceDuDebut();


    }
/**
 * \fn	Couleur Labyrinthe::trouveGagnant()
 * \brief Trouve le gagnant du labyrinthe (celui avec le plus petit nombre de deplacement requis)
 * \return Couleur la couleur du joueur qui est gagnant, s'il y a egalite, la priorite est comme ci rouge>vert>bleu>jaune
 */
    Couleur Labyrinthe::trouveGagnant()
    {
        int bleu = solutionner(Bleu);
        int rouge = solutionner(Rouge);
        int jaune = solutionner(Jaune);
        int vert = solutionner(Vert);
        Couleur couleurDuGagnant;

        int cheminPlusCourt = -1;

        if (jaune != -1)
        {
            cheminPlusCourt = jaune;
            couleurDuGagnant = Jaune;
        }

        if (bleu != -1 && (bleu <= cheminPlusCourt || cheminPlusCourt == -1))
        {
            cheminPlusCourt = bleu;
            couleurDuGagnant = Bleu;
        }

        if (vert != -1 && (vert <= cheminPlusCourt || cheminPlusCourt == -1))
        {
            cheminPlusCourt = vert;
            couleurDuGagnant = Vert;
        }
        if (rouge != -1 && (rouge <= cheminPlusCourt || cheminPlusCourt == -1))
        {
            couleurDuGagnant = Rouge;
        }
        return couleurDuGagnant;

    }
/**
 * \fn	Labyrinthe::appartient(const Piece &p) const
 * \brief Verifie si la piece appartient au labyrinthe
 * \param[in]p p la piece que l'on veut savoir si elle est dans la labyrinthe
 * \return Bool true si oui, false autrement
 */
    bool Labyrinthe::appartient(const Piece &p) const
    {
        bool valeurDeRetour = false;
        NoeudListePieces *noeudCourant = dernier;

        do
        {
            if (noeudCourant->piece.getNom() == p.getNom())
            {
                valeurDeRetour = true;
            }

            noeudCourant = noeudCourant->suivant;

        } while (noeudCourant != dernier && !valeurDeRetour);
        return valeurDeRetour;


    }
/**
 * \fn	Labyrinthe::placeDepart(const string &nom)
 * \brief Mutateur pour l'attribut depart, on va chercher le noeud avec le nom donnee en parametre et on assigne l'attribut a ce noeud
 * \param[in]nom nom le nom de la piece qui sera le depart de notre labyrinthe
 */
    void Labyrinthe::placeDepart(const string &nom)
    {
        NoeudListePieces *noeudDepieceCherche = trouvePiece(nom);
        depart = &noeudDepieceCherche->piece;


    }
/**
 * \fn	Labyrinthe::placeArrivee(const string &nom)
 * \brief Mutateur pour l'attribut arrive, on va chercher le noeud avec le nom donnee en parametre et on assigne l'attribut a ce noeud
 * \param[in]nom nom le nom de la piece qui sera l'arrive de notre labyrinthe
 */
    void Labyrinthe::placeArrivee(const string &nom)
    {
        NoeudListePieces *noeudDepieceCherche = trouvePiece(nom);
        arrivee = &noeudDepieceCherche->piece;


    }
/**
 * \fn	Labyrinthe::NoeudListePieces *Labyrinthe::trouvePiece(const string &nom) const
 * \brief trouve le noeud de la piece donnee en parametre
 * \param[in]nom nom la piece que l'on veut trouver
 * \return NoeudListePieces le noeud de la piece cherche
 */
    Labyrinthe::NoeudListePieces *Labyrinthe::trouvePiece(const string &nom) const
    {
        if (nom == "")
        {
            throw invalid_argument("Le nom de la pièce est invalide");
        }
        NoeudListePieces *noeudCourant = dernier;

        do
        {
            if (noeudCourant->piece.getNom() == nom)
            {
                return noeudCourant;
            }

            noeudCourant = noeudCourant->suivant;

        } while (noeudCourant != dernier);

        throw logic_error("La pièce ne fait pas partie du labyrinthe");


    }
/**
 * \fn	Labyrinthe::effacerListeDePiece()
 * \brief efface toutes les noeud du labyrinthe
 */
    void Labyrinthe::effacerListeDePiece()
    {
        NoeudListePieces *noeudCourant = dernier;
        NoeudListePieces *noeudASupprimer;
        do
        {
            noeudASupprimer = noeudCourant;
            noeudCourant = noeudCourant->suivant;
            delete noeudASupprimer;

        } while (noeudCourant != dernier);
    }



/**
 * \fn	Labyrinthe::copieListeDesPieces(Labyrinthe::NoeudListePieces *&source)
 * \brief Fait une copie de chaque noeud du labyrinthe que l'on passe en parametre
 * \param[in]source le dernier noeud du labyrinthe que l'on veut copier les pieces
 */
    void Labyrinthe::copieListeDesPieces(Labyrinthe::NoeudListePieces *&source)
    {
        NoeudListePieces *noeudCourant = source;
        do
        {
            ajoutePieceLabyrinthe(source->piece);
            noeudCourant = noeudCourant->suivant;

        } while (noeudCourant != source);

    }
/**
 * \fn	Labyrinthe::copieLesPorteDansTouteLesPieces(Labyrinthe::NoeudListePieces *&source)
 * \brief Fait une copie chaque liste de piece du labyrinthe que l'on veut copier
 * \param[in]source le dernier noeud du labyrinthe que l'on veut copier les pieces
 */
    void Labyrinthe::copieLesPorteDansTouteLesPieces(Labyrinthe::NoeudListePieces *&source)
    {
        NoeudListePieces *noeudCourant = source;
        do
        {
            NoeudListePieces *noeudQuonAjouteListPorte = trouvePiece(noeudCourant->piece.getNom());

            for (Porte porte: noeudCourant->piece.getPortes()){
                noeudQuonAjouteListPorte->piece.ajoutePorte(porte);
            }

            noeudCourant = noeudCourant->suivant;

        } while (noeudCourant != source);

    }











    //Mettez l'implémentation de vos autres méthodes ici.

}//fin du namespace
