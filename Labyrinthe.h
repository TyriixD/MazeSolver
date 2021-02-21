/**
 * \file Labyrinthe.h
 * \brief Ce fichier contient l'interface d'un labyrinthe.
 * \author Maï-Anh Porlier
 * \version 0.1
 * \date février 2021
 * 
 */

#ifndef LABYRINTHE_H_
#define LABYRINTHE_H_

#include <iostream>
#include <fstream> // pour les fichiers
#include <sstream> // lecture/écriture dans un string, voir la méthode chargeLabyrinthe() fournie
#include <string>
#include <queue>    // Pour utiliser la file de la STL afin de solutionner le labyrinthe

#include "Porte.h"
#include "Piece.h"


namespace TP1
{

/**
 * \class Labyrinthe
 * \brief classe représentant un labyrinthe formé de plusieurs pièces dotées de portes de couleur.
 */
    class Labyrinthe
    {
    public:
        //Constructeur par défaut
/**
 * \brief Constructeur par defaut du labyrinthe, initialise tout les attributs a 0
 */

        Labyrinthe();
/**
 * \brief Constructeur copie du labyrinthe
 * \param[in]source Le labyrinthe que l'on veut copier
 */
        //constructeur de copie
        Labyrinthe(const Labyrinthe &source);
/**
 * \brief Destructeur du labyrinthe, il parcourt le labyrinthe et detruit tout les noeuds
 */
        //Destructeur
        ~Labyrinthe();
/**
 * \brief Surcharge de l'operateur d'assignation
 * \param[in]source le Labyrinthe que l'ont veut prendre les valeurs et les assigner a notre labyrinthe courant
 * \return Un labyrinthe avec des nouvelles valeurs
 */
        //Surcharge de l'opérateur =
        const Labyrinthe &operator=(const Labyrinthe &source);

        //Méthode fournie dans le fichier Labyrinthe.cpp, elle charge
        //un fichier contenant un labyrinthe d'une certaine couleur
        //
        //Voici comment un labyrinthe est mis en mémoire:
        //1- ChargerLabyrinthe() appelle ajoutePieceLabyrinthe()
        //2- ajoutePieceLabyrinthe() ajoute la pièce si elle n'existe pas déjà.
        //3- Si la pièce existe déjà, ajoutePieceLabyrinthe() n'ajoute pas de pièce et laisse le programme rouler
        //4- On sort de ajoutePieceLabyrinthe() et ChargerLabyrinthe() fait quelques opérations pour ensuite appeler ajoutePassage()
        //5- ajoutePassage() ajoute les portes à la pièce qui à été préalablement créée ou qui existait déjà
        //6- La pièce et les portes sont créées et on passe à une autre pièce
        /**
 * \fn	void Labyrinthe::chargeLabyrinthe(Couleur couleur, std::ifstream &entree)
 * \param[in]	couleur, la couleur du jouer auquel le labyrinthe chargé s'applique
 * \param[in]	entree, fichier contenant la définition du labyrinthe
 */
        void chargeLabyrinthe(Couleur couleur, std::ifstream &entree);

        //Cette fonction doit ajouter la pièce p à un labyrinthe. Dans le cas où
        //une pièce du labyrinthe porte déjà un même nom, la méthode ne doit
        //rien faire (faire un simple return, sans générer d'exception).
        /**
        * \fn	Labyrinthe::ajoutePieceLabyrinthe(Piece& p)
        * \brief ajoute une pièce au labyrinthe (si elle ne s'y trouve pas déjà)
        * \param[in]	p La pièce à ajouter
        * \post	la pièce appartient au labyrinthe;
        */
        void ajoutePieceLabyrinthe(const Piece &p);

        //Cette méthode doit solutionner un labyrinthe pour le joueur spécifié par joueur.
        //Elle doit donc trouver en combien d'étapes au minimum le joueur spécifié peut solutionner
        //le labyrinthe, en ne passant bien sûr que par les portes qui correspondent à sa couleur.
        //
        //Si un labyrinthe ne peut pas être solutionné par le joueur, il faut retourner -1. Dans ce cas,
        //nous ne considèrerons pas cela comme un appel anormal de la fonction.
        //Vous devez utiliser l'algorithme suivant pour solutionner le labyrinthe, en utilisant une file "queue" de la STL:
        // 1. Enfiler la pièce de départ en lui associant une distance du départ de zéro.
        // 2. Faire
        //       1. Défiler une pièce
        //       2. Enfiler toutes les pièces qui sont accessibles à partir de cette pièce à l'aide d'une porte
        //          de la couleur du joueur, et qui n'ont pas été déjà parcourues, en leur associant la distance
        //			du départ de la pièce défilée plus un.
        //
        //			Remarquez qu'il faut faire une vérification double ici. Il faut d'abord chercher les portes dans la liste
        //			de portes de la pièce défilée, puis il faut ensuite aussi chercher les portes dans les listes de portes de
        //			toutes les pièces pour voir s'il y en aurait qui mènent à la pièce défilée. Ceci est nécessaire car les portes
        //			ne sont pas à sens unique, mais la méthode qui charge un labyrinthe fournie ne les ajoute qu'une seule fois
        //			dans le modèle d'implantation. Afin de savoir si une pièce a déjà été parcourue ou non, employez le champ
        //			booléen parcourue. N'enfilez que des pièces pour lesquelles ce champ a false comme valeur, puis au moment
        //			où vous l'enfilez, appliquez-lui la valeur true. Aussi, n'oubliez pas, avant de commencer l'algorithme, de
        //			mettre ce champ à false pour toutes les pièces du labyrinthe.
        //
        //	Tant qu'il reste des pièces dans la file et que la pièce d'arrivée n'a pas encore été atteinte (défilée).
        /**
 * \fn	Labyrinthe::solutionner(Couleur joueur)
 * \brief Trouve le nombre de deplacement requis pour resoudre le labyrinthe pour un certain joueur donnee
 * \param[in] joueur Le joueur que l'on veut resoudre le labyrinthe
 * \return int le nombre de deplacement requis pour arrive a la fin du labyrinthe
 */
        int solutionner(Couleur joueur);

        /**
 * \fn	Couleur Labyrinthe::trouveGagnant()
 * \brief Trouve le gagnant du labyrinthe (celui avec le plus petit nombre de deplacement requis)
 * \return Couleur la couleur du joueur qui est gagnant, s'il y a egalite, la priorite est comme ci rouge>vert>bleu>jaune
 */

        //Cette méthode devra appeler quatre fois la méthode solutionner(), une fois par couleur, pour déterminer
        //quel est le joueur qui peut solutionner le labyrinthe en le moins de déplacements. Si aucun joueur ne peut
        //solutionner un labyrinthe, retournez Aucun. Dans le cas où deux joueurs ou plus peuvent arriver ex-equo,
        //accordez la priorité au joueur rouge, puis au joueur vert, puis au bleu, puis au jaune. Par exemple,
        // si le joueur rouge peut solutionner le labyrinthe en 12 coups, le joueur vert en 8 coups, le joueur bleu en 9
        // coups, puis le jaune en 8 coups aussi, c'est le vert qui gagne.
        Couleur trouveGagnant();

        //Accesseur pour le membre depart
        Piece *getDepart() const
        { return depart; }

        //Accesseur pour le membre arrivee
        Piece *getArrivee() const
        { return arrivee; }
/**
 * \fn	Labyrinthe::appartient(const Piece &p) const
 * \brief Verifie si la piece appartient au labyrinthe
 * \param[in]p p la piece que l'on veut savoir si elle est dans la labyrinthe
 * \return Bool true si oui, false autrement
 */
        //Vérifie si une pièce portant le nom de la pièce fournie se trouve dans le labyrinthe
        bool appartient(const Piece &p) const;
/**
 * \fn	Labyrinthe::effacerListeDePiece()
 * \brief efface toutes les noeud du labyrinthe
 */
        void effacerListeDePiece();


    private:
/**
 * \fn	Labyrinthe::ajoutePassage(Couleur couleur, int i1, int j1, int i2, int j2)
 * \param[in]	Couleur couleur Couleur de la porte à ajouter
 * \param[in]	int i1
 * \param[in]	int j1
 * \param[in]	int i2
 * \param[in]	int j2
 */

        //Méthode privée fournie dans le fichier Labyrinthe.cpp, elle ajoute un passage
        //dans un labyrinthe. Elle est appelée par la méthode chargeLabyrinthe()
        void ajoutePassage(Couleur couleur, int i1, int j1, int i2, int j2);
/**
 * \fn	Labyrinthe::placeDepart(const string &nom)
 * \brief Mutateur pour l'attribut depart, on va chercher le noeud avec le nom donnee en parametre et on assigne l'attribut a ce noeud
 * \param[in]nom nom le nom de la piece qui sera le depart de notre labyrinthe
 */
        //Méthode privée, elle sert pour charger un labyrinthe. Ajuste le pointeur depart d'un labyrinthe
        //pour qu'il contienne l'adresse de la pièce correspondant au nom spécifié par nom. Lancer une
        //exception logic_error si aucune pièce du labyrinthe ne porte le nom nom.
        void placeDepart(const std::string &nom);
/**
 * \fn	Labyrinthe::placeArrivee(const string &nom)
 * \brief Mutateur pour l'attribut arrive, on va chercher le noeud avec le nom donnee en parametre et on assigne l'attribut a ce noeud
 * \param[in]nom nom le nom de la piece qui sera l'arrive de notre labyrinthe
 */
        //Même chose que pour la fonction placeDepart décrite plus haut, mais pour le pointeur arrivee d'un labyrinthe.
        void placeArrivee(const std::string &nom);

        class NoeudListePieces //noeud typique d'une liste chaînée circulaire
        {
        public:
            // La piece contenue dans un noeud d'une liste chaînée circulaire.
            Piece piece;

            // Le noeud suivant
            NoeudListePieces *suivant;
        };
/**
 * \fn	Labyrinthe::copieListeDesPieces(Labyrinthe::NoeudListePieces *&source)
 * \brief Fait une copie de chaque noeud du labyrinthe que l'on passe en parametre
 * \param[in]source le dernier noeud du labyrinthe que l'on veut copier les pieces
 */
        void copieListeDesPieces(NoeudListePieces *&source);
/**
 * \fn	Labyrinthe::copieLesPorteDansTouteLesPieces(Labyrinthe::NoeudListePieces *&source)
 * \brief Fait une copie chaque liste de porte que l'on veut copier avec la destination du labyrinthe courant
 * \param[in]source le dernier noeud du labyrinthe que l'on veut copier les portes
 */
        void copieLesPorteDansTouteLesPieces(NoeudListePieces *&source);
/**
 * \fn	Labyrinthe::ajouteCopieDePorte(Couleur couleur, std::string nomPiece)
 * \brief Fait une copie en profondeur d'une porte. On donne la couleur et le nom de la destination de la porte copie puis on va chercher le nom dans notre lab courant
 * \param[in] nomPiece Le nom de la piece qui va etre la destination de la porte copie
 */
        Porte ajouteCopieDePorte(Couleur couleur, std::string nomPiece);


        //Méthode privée. Retourne l'adresse du noeud de la liste de pièces contenue dans le labyrinthe
        //qui correspond à la pièce portant le nom nom, la méthode doit lancer une exception invalid_argument si le nom de
        //la pièce est vide. La méthode doit lancer également une exception logic_error si la pièce est introuvable.
        //Remarquez qu'il faut retourner l'adresse du noeud et non l'adresse de la pièce.
        /**
 * \fn	Labyrinthe::NoeudListePieces *Labyrinthe::trouvePiece(const string &nom) const
 * \brief trouve le noeud de la piece donnee en parametre
 * \param[in]nom nom la piece que l'on veut trouver
 * \return NoeudListePieces le noeud de la piece cherche
 */
        NoeudListePieces *trouvePiece(const std::string &nom) const;

        //
        NoeudListePieces *dernier; /*!< Le dernier noeud de la liste chaînée circulaire.*/
        /*!<  Ce noeuds ne contient pas nécessairement les pièces de départ ou d'arrivée. */

        Piece *depart; /*!< Adresse de la pièce de départ (et non du noeud qui la contient) */
        Piece *arrivee; /*!< Adresse de la pièce d'arrivée (et non du noeud qui la contient) */


    };

}

#endif /* LABYRINTHE_H_ */
