/* Loris SOGLIUZZO */
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// Question 1
struct guerrier
{
    char* nom;
    int pv;
    int attaque;
    double guerison;
};

void afficher_guerrier(struct guerrier g)
{
    printf("Nom: %s | PV: %d | Attaque: %d | Guerison: %.2f\n", g.nom, g.pv, g.attaque, g.guerison);
}

void attaque(struct guerrier* pjoueur, struct guerrier* padversaire)
{
    padversaire -> pv -= pjoueur -> attaque;
}

void bouclier(struct guerrier* pjoueur)
{
    pjoueur -> pv += pjoueur -> guerison * (100 - pjoueur -> pv);
}

int rand_int(int p)
{
    int n = rand()%(2*p+1);
    return n - p;
}

int main()
{
    srand(time(0));
    // Question 2
    struct guerrier Aragorn = {"Aragorn", 100, 20, 0.6};
    struct guerrier Boromir = {"Boromir", 100, 30, 0.4};

    // Question 3
    afficher_guerrier(Aragorn);
    afficher_guerrier(Boromir);

    // Question 4
    /* On utilise des pointeurs dans cette fonction pour modifier les valeurs 
    des structs des guerriers. S'il n'y avait pas de pointeurs, une copie de 
    notre struct serait faite et les pv du guerrier attaqué n'auraient pas changé. */
    attaque(&Aragorn, &Boromir);
    afficher_guerrier(Boromir);
    
    // Question 5
    bouclier(&Boromir);
    afficher_guerrier(Boromir);

    // Question 6 - 7 - 8 - 10
    Boromir.pv = 100;
    struct guerrier * pjoueur = &Aragorn;
    struct guerrier * padversaire = &Boromir;
    struct guerrier* gagnant = 0;
    int tour = 1;
    while (gagnant == 0)
    {
        printf("Vous jouez %s. Entrez 'a' pour attaquer ou pour 'b' pour utiliser votre bouclier\n", pjoueur -> nom);
        char touche;
        scanf(" %c",&touche);
        if (touche == 'a')
        {
            attaque(pjoueur, padversaire);
        }
        else
        {
            bouclier(pjoueur);
        }

        padversaire -> pv += rand_int(5);
        
        afficher_guerrier(*pjoueur);
        afficher_guerrier(*padversaire);


        if(padversaire -> pv <= 0)
        {
            gagnant = pjoueur;
        }

        struct guerrier * ptemp = pjoueur;
        pjoueur = padversaire;
        padversaire = ptemp;
        tour ++;
    }
    printf("%s a gagné après %d tours !\n", gagnant -> nom, tour);

    // Question 9: Aragon peut jouer indéfiniment s'il joue toute le temps le bouclier


    return 0;
}
