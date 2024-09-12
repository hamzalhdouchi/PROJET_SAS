#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COLOR_RED     "\x1b[31m"
#define COLOR_GREEN   "\x1b[32m"
#define COLOR_YELLOW  "\x1b[33m"
#define COLOR_BLUE    "\x1b[34m"
#define COLOR_VIOLET  "\x1b[35m"
#define COLOR_RESET   "\x1b[0m"

// Structure pour date de naissance
typedef struct {
    int jour;
    int mois;
    int annee;
} date_nes;

// Structure pour les etudiants
typedef struct {
    int id;
    char nom[20];
    char prenom[20];
    date_nes date_de_naissance;
    char departement[40];
    float note_generale;
} etudiants;

// Tableau d etudiants
etudiants etud[100] = {
        {1, "El Amrani", "Ahmed", {12, 2, 2000}, "Informatique", 14.5},
        {2, "Benkirane", "Sara", {23, 7, 1999}, "Math", 16.0},
        {3, "El Khalifi", "Mohamed", {5, 11, 2001}, "Physique", 13.5},
        {4, "Ait El Moumen", "Fatima", {8, 1, 1998}, "Science", 15.0},
        {5, "Kharbouch", "Youssef", {20, 6, 2000}, "Informatique", 11.0},
        {6, "Lahcen", "Meryem", {13, 8, 1999}, "Math", 17.0},
        {7, "Zouhri", "Rachid", {27, 12, 1997}, "Physique", 12.0},
        {8, "Benjelloun", "Nadia", {15, 4, 2000}, "Science", 10.5},
        {9, "El Ghazi", "Omar", {2, 9, 1999}, "Informatique", 18.0},
        {10, "Ouali", "Samira", {30, 3, 2001}, "Math", 19.0}
};
int taille = 10;
int ID = 10;

// fonction pour ajouter un etudiant
void Ajouter_un_etudiant() {
    system("cls");
    int choix;
    int valid_date = 0;
     system("cls");
    printf("========================================\n");
    printf("=          Ajouter un etudiant         =\n");
    printf("========================================\n");

    printf("entrer le nom : ");
    scanf(" %[^\n]", etud[taille].nom);
    printf("entrer le prenom : ");
    scanf(" %[^\n]", etud[taille].prenom);

    do {
        printf("entrer le jour : ");
        scanf("%d", &etud[taille].date_de_naissance.jour);
        printf("entrer le mois : ");
        scanf("%d", &etud[taille].date_de_naissance.mois);
        printf("entrer l'annee : ");
        scanf("%d", &etud[taille].date_de_naissance.annee);

        // Validation simple des dates
        valid_date = 1;
        if (etud[taille].date_de_naissance.annee < 1900 ||
            etud[taille].date_de_naissance.mois < 1 ||
            etud[taille].date_de_naissance.mois > 12 ||
            etud[taille].date_de_naissance.jour < 1 ||
            etud[taille].date_de_naissance.jour > 31) {
            valid_date = 0;
        }

        if (etud[taille].date_de_naissance.mois == 2) {
            if ((etud[taille].date_de_naissance.annee % 4 == 0 &&
                 etud[taille].date_de_naissance.annee % 100 != 0) ||
                etud[taille].date_de_naissance.annee % 400 == 0) {
                if (etud[taille].date_de_naissance.jour > 29) valid_date = 0;
            } else {
                if (etud[taille].date_de_naissance.jour > 28) valid_date = 0;
            }
        }
        if ((etud[taille].date_de_naissance.mois == 4 ||
             etud[taille].date_de_naissance.mois == 6 ||
             etud[taille].date_de_naissance.mois == 9 ||
             etud[taille].date_de_naissance.mois == 11) &&
            etud[taille].date_de_naissance.jour > 30)
            valid_date = 1;

        if (valid_date == 0) {
            printf(COLOR_RED"Date incorrecte, veuillez ressayer\n"COLOR_RESET);
        }
    } while (valid_date == 0);

    do {
        printf(COLOR_YELLOW "--------- Departement ---------\n"COLOR_RESET);
        printf("1 : physique\n");
        printf("2 : math\n");
        printf("3 : science\n");
        printf("4 : informatique\n");
        printf("Entrer le choix : ");
        scanf("%d", &choix);
        switch (choix) {
            case 1:
                strcpy(etud[taille].departement, "physique");
                break;
            case 2:
                strcpy(etud[taille].departement, "math");
                break;
            case 3:
                strcpy(etud[taille].departement, "science");
                break;
            case 4:
                strcpy(etud[taille].departement, "informatique");
                break;
            default:
                printf(COLOR_RED"choix inacceptable, entrez le choix correct\n"COLOR_RESET);
        }
    } while (choix < 1 || choix > 4);

    printf("entrer la note generale : ");
    scanf("%f", &etud[taille].note_generale);

    etud[taille].id = ++ID;
    taille++;
}

// fonction pour ajouter plusieurs etudiants
void Ajouter_plusieurs_etudiants() {
    system("cls");
    printf("===========================================\n");
    printf("=       Ajouter_plusieurs_etudiants       =\n");
    printf("===========================================\n");
    int nbr;
    printf("entrer le nombre d etudiants : ");
    scanf("%d", &nbr);
    for (int i = 0; i < nbr; i++) {
        Ajouter_un_etudiant();
    }
}

// fonction pour afficher les etudiants
void Afficher_les_etudiants() {
    printf(COLOR_VIOLET "----------------------------------------\n");
    printf("--------Afficher les etudiants----------\n");
    printf("----------------------------------------\n" COLOR_RESET);

    for (int i = 0; i < taille; i++) {
        printf("-------------------------------------\n");
        printf("ID : %d\n", etud[i].id);
        printf("nom : %s\n", etud[i].nom);
        printf("prenom : %s\n", etud[i].prenom);
        printf("date de naissance : %d/%d/%d\n", etud[i].date_de_naissance.jour, etud[i].date_de_naissance.mois, etud[i].date_de_naissance.annee);
        printf("departement : %s\n", etud[i].departement);
        printf("note generale : %.2f\n", etud[i].note_generale);
        printf("-------------------------------------\n");
    }
}

// fonction pour afficher le statut
void afficher_statut() {
    system("cls");
    printf("========================================\n");
    printf("=           afficher statut            =\n");
    printf("========================================\n");
    char description[20];
    for (int i = 0; i < taille; i++) {
        if (etud[i].note_generale >= 10) {
            if (etud[i].note_generale >= 18) {
                strcpy(description, "excellent");
            } else if (etud[i].note_generale >= 16) {
                strcpy(description, "tres bien");
            } else if (etud[i].note_generale >= 14) {
                strcpy(description, "bien");
            } else if (etud[i].note_generale >= 12) {
                strcpy(description, "assez bien");
            } else {
                strcpy(description, "passable");
            }
        } else {
            strcpy(description, "insuffisant");
        }

        printf("-------------------------------------\n");
        printf("ID : %d\n", etud[i].id);
        printf("nom : %s\n", etud[i].nom);
        printf("prenom : %s\n", etud[i].prenom);
        printf("date de naissance : %d/%d/%d\n", etud[i].date_de_naissance.jour, etud[i].date_de_naissance.mois, etud[i].date_de_naissance.annee);
        printf("departement : %s\n", etud[i].departement);
        printf("note generale : %.2f\n", etud[i].note_generale);
        printf("statut : %s\n", description);
        printf("-------------------------------------\n");
    }
}

// fonction pour trier et afficher les �tudiants
void Afficher_trier() {
    system("cls");
    printf("========================================\n");
    printf("=             Afficher trier           =\n");
    printf("========================================\n");
    int i, j;
    int choix;
    etudiants temp;
    printf("-------------------------------------\n");
    printf("1 : trier par ordre alphabetique\n");
    printf("2 : trier par note generale\n");
    printf("3 : trier par statut\n");
    printf("entrer le choix : ");
    scanf("%d", &choix);

    if (choix == 1) {
        for (i = 0; i < taille - 1; i++) {
            for (j = i + 1; j < taille; j++) {
                if (strcmp(etud[i].nom, etud[j].nom) > 0) {
                    temp = etud[i];
                    etud[i] = etud[j];
                    etud[j] = temp;
                }
            }
        }
        Afficher_les_etudiants();
    } else if (choix == 2) {
        for (i = 0; i < taille - 1; i++) {
            for (j = i + 1; j < taille; j++) {
                if (etud[i].note_generale < etud[j].note_generale) {
                    temp = etud[i];
                    etud[i] = etud[j];
                    etud[j] = temp;
                }
            }
        }
        Afficher_les_etudiants();
    } else if (choix == 3) {
        afficher_statut();
    } else {
        printf(COLOR_RED"choix incorrect\n"COLOR_RESET);
    }
}

// fonction pour rechercher des etudiants
void recherche() {
    system("cls");
    printf("========================================\n");
    printf("=               recherche              =\n");
    printf("========================================\n");
    int choix;
    int i;
    char nom[20];
    printf("-------------------------------------\n");
    printf("1 : recherche par nom\n");
    printf("2 : recherche par departement\n");
    printf("Entrer le choix : ");
    scanf("%d", &choix);
    if (choix == 1) {
        printf("entrer le nom : ");
        scanf(" %[^\n]", nom);
        for (i = 0; i < taille; i++) {
            if (strcmp(etud[i].nom, nom) == 0) {
                printf("-------------------------------------\n");
                printf("ID : %d\n", etud[i].id);
                printf("nom : %s\n", etud[i].nom);
                printf("prenom : %s\n", etud[i].prenom);
                printf("date de naissance : %d/%d/%d\n", etud[i].date_de_naissance.jour, etud[i].date_de_naissance.mois, etud[i].date_de_naissance.annee);
                printf("departement : %s\n", etud[i].departement);
                printf("note generale : %.2f\n", etud[i].note_generale);
                printf("-------------------------------------\n");
            }
        }
    } else if (choix == 2) {
        printf("entrer le departement : ");
        scanf(" %[^\n]", nom);
        for (i = 0; i < taille; i++) {
            if (strcmp(etud[i].departement, nom) == 0) {
                printf("-------------------------------------\n");
                printf("ID : %d\n", etud[i].id);
                printf("nom : %s\n", etud[i].nom);
                printf("prenom : %s\n", etud[i].prenom);
                printf("date de naissance : %d/%d/%d\n", etud[i].date_de_naissance.jour, etud[i].date_de_naissance.mois, etud[i].date_de_naissance.annee);
                printf("departement : %s\n", etud[i].departement);
                printf("note generale : %.2f\n", etud[i].note_generale);
                printf("-------------------------------------\n");
            }
        }
    } else {
        printf(COLOR_RED"choix incorrect\n"COLOR_RESET);
    }
}

// fonction pour modifier les informations d un etudiant
    void Modifier() {
    system("cls");
    printf("========================================\n");
    printf("=                 Modifier             =\n");
    printf("========================================\n");
    int id, i, choix;
    printf(COLOR_YELLOW"entrer l ID de l etudiant a modifier : "COLOR_RESET);
    scanf("%d", &id);
    for (i = 0; i < taille; i++) {
        if (etud[i].id == id) {
            printf("1 : modifier le nom\n");
            printf("2 : modifier le prenom\n");
            printf("3 : modifier la date de naissance\n");
            printf("4 : modifier le departement\n");
            printf("5 : modifier la note generale\n");
            printf("entrer le choix : ");
            scanf("%d", &choix);

            switch (choix) {
                case 1:
                    printf("entrer le nouveau nom : ");
                    scanf(" %[^\n]", etud[i].nom);
                    break;
                case 2:
                    printf("entrer le nouveau prenom : ");
                    scanf(" %[^\n]", etud[i].prenom);
                    break;
                case 3:
                    printf("entrer le nouveau jour : ");
                    scanf("%d", &etud[i].date_de_naissance.jour);
                    printf("entrer le nouveau mois : ");
                    scanf("%d", &etud[i].date_de_naissance.mois);
                    printf("entrer la nouvelle annee : ");
                    scanf("%d", &etud[i].date_de_naissance.annee);
                    break;
                case 4:

    do {
        printf(COLOR_YELLOW"--------- Departement ---------\n"COLOR_RESET);
        printf("1 : physique\n");
        printf("2 : sath\n");
        printf("3 : science\n");
        printf("4 : informatique\n");
        printf("Entrer le choix : ");
        scanf("%d", &choix);
        switch (choix) {
            case 1:
                strcpy(etud[taille].departement, "physique");
                break;
            case 2:
                strcpy(etud[taille].departement, "math");
                break;
            case 3:
                strcpy(etud[taille].departement, "science");
                break;
            case 4:
                strcpy(etud[taille].departement, "informatique");
                break;
            default:
                printf(COLOR_RED"choix inacceptable, entrez le choix correct\n"COLOR_RESET);
        }
    } while (choix < 1 || choix > 4);

                    break;
                case 5:
                    printf("entrer la nouvelle note generale : ");
                    scanf("%f", &etud[i].note_generale);
                    break;
                default:
                    printf(COLOR_RED "Choix incorrect\n"COLOR_RESET);
            }
            return;
        }
    }
    printf(COLOR_RED "ID non trouve\n"COLOR_RESET);
}

// fonction pour supprimer un �tudiant
void Supprimer() {
    printf("========================================\n");
    printf("=               Supprimer              =\n");
    printf("========================================\n");
    int id, i, j;
    printf("entrer l ID de l etudiant a supprimer : ");
    scanf("%d", &id);

    for (i = 0; i < taille; i++) {
        if (etud[i].id == id) {
            // Decaler les elements pour supprimer l etudiant
            for (j = i; j < taille - 1; j++) {
                etud[j] = etud[j + 1];
            }
            taille--;
            printf(COLOR_YELLOW"etudiant est supprime.\n"COLOR_RESET);
            return;
        }
    }
    printf(COLOR_RED "ID non trouve\n"COLOR_RESET);
}

// fonction pour calculer la moyenne des notes
void Calculer_moyenne() {
    if (taille == 0) {
        printf(COLOR_RED"Aucun �tudiant dans le systeme.\n"COLOR_RESET);
        return;
    }

    float somme = 0.0;
    for (int i = 0; i < taille; i++) {
        somme += etud[i].note_generale;
    }

    float moyenne = somme / taille;
    printf("La moyenne des notes generales est : %.2f\n", moyenne);
}
  void statistique()
  {
      int choix;
      int nbr_math = 0;
      int nbr_Physique = 0;
      int nbr_Science = 0;
      int nbr_Informatique = 0;
      int nbr_note;
      float seule;
      etudiants temp;
      printf("1 : Nombre total d etudiants\n");
      printf("2 : Afficher le nombre d etudiants dans chaque departemet\n");
      printf("3 : Afficher les etudiants ayant une moyenne generale superieure a un certain seule\n");
      printf("4 : Afficher les 3 etudiants ayant les meilleures note\n");
      printf("5 : Afficher le nombre d etudiants ayant reussi dans chaque departement\n");
      printf("entrer le choix : ");
      scanf("%d",&choix);
      switch(choix)
      {
      case 1:
        printf(" Nombre total d etudiants : %d",taille);
        break;
      case 2:
          for(int i=0;i<taille;i++)
          {
        if(strcmp(etud[i].departement , "math")== 0)
        {
            nbr_math++;
        }
        if(strcmp(etud[i].departement , "physique")== 0)
        {
            nbr_Physique++;
        }
        if(strcmp(etud[i].departement , "science")== 0)
        {
            nbr_Science++;
        }
        if(strcmp(etud[i].departement , "informatique")== 0)
        {
            nbr_Informatique++;
        }
          }
          printf(" afficher le nombre d etudiants dans departemet math : %d\n",nbr_math);
          printf(" afficher le nombre d etudiants dans departemet Physique : %d\n",nbr_math);
          printf(" afficher le nombre d etudiants dans departemet science : %d\n",nbr_math);
          printf(" afficher le nombre d etudiants dans departemet informatique : %d\n",nbr_math);
        break;
      case 3:
         printf("entrer le seule");
         scanf("%f",&seule);
         for(int i=0;i<taille;i++)
         {
             if(etud[i].note_generale > seule)
             {
                printf("-------------------------------------\n");
                printf("ID : %d\n", etud[i].id);
                printf("nom : %s\n", etud[i].nom);
                printf("penom : %s\n", etud[i].prenom);
                printf("date de naissance : %d/%d/%d\n", etud[i].date_de_naissance.jour, etud[i].date_de_naissance.mois, etud[i].date_de_naissance.annee);
                printf("departement : %s\n", etud[i].departement);
                printf("note generale : %.2f\n", etud[i].note_generale);
                printf("-------------------------------------\n");
             }
         }
        break;
      case 4:
            for (int i = 0; i < taille - 1; i++) {
            for (int j = i + 1; j < taille; j++) {
                if (etud[i].note_generale < etud[j].note_generale) {
                    temp = etud[i];
                    etud[i] = etud[j];
                    etud[j] = temp;
                }
            }
        }
       for(int i=0;i<3;i++)
       {
        printf("-------------------------------------\n");
        printf("ID : %d\n", etud[i].id);
        printf("Nom : %s\n", etud[i].nom);
        printf("Prenom : %s\n", etud[i].prenom);
        printf("Date de naissance : %d/%d/%d\n", etud[i].date_de_naissance.jour, etud[i].date_de_naissance.mois, etud[i].date_de_naissance.annee);
        printf("Departement : %s\n", etud[i].departement);
        printf("Note generale : %.2f\n", etud[i].note_generale);
        printf("-------------------------------------\n");
       }
        break;
      case 5:
        for(int i=0;i<taille;i++)
        {
            if(etud[i].note_generale >= 10)
            {
                nbr_note++;
            }
        }
        printf("afficher le nombre d etudiants ayant reussi dans chaque departement : %d",nbr_note);
        break;
      default:
        printf("Choix incorrect");
        break;
      }
  }

// fonction principale
int main() {
    int choix;

    do {
    printf("========================================\n");
    printf("=                  menu                =\n");
    printf("========================================\n");
        printf("1 : ajouter un etudiant\n");
        printf("2 : ajouter plusieurs etudiants\n");
        printf("3 : afficher les etudiants\n");
        printf("4 : afficher etudiants avec statut\n");
        printf("5 : trier et afficher les etudiants\n");
        printf("6 : rechercher des etudiants\n");
        printf("7 : modifier un etudiant\n");
        printf("8 : supprimer un etudiant\n");
        printf("9 : calculer la moyenne des notes\n");
        printf("10 : statistique\n");
        printf("10 : Quitter\n");
        printf("---------------------------------\n");
        printf("Entrer le choix : ");
        scanf("%d", &choix);
        printf("----------------------------------\n");

        switch (choix) {
            case 1:
                Ajouter_un_etudiant();
                break;
            case 2:
                Ajouter_plusieurs_etudiants();
                break;
            case 3:
                Afficher_les_etudiants();
                break;
            case 4:
                afficher_statut();
                break;
            case 5:
                Afficher_trier();
                break;
            case 6:
                recherche();
                break;
            case 7:
                Modifier();
                break;
            case 8:
                Supprimer();
                break;
            case 9:
                Calculer_moyenne();
                break;
            case 10:
                statistique();
                break;
            case 11:
                printf(COLOR_RED"Au revoir\n"COLOR_RESET);
                break;
            default:
                printf(COLOR_RED"Choix incorrect\n"COLOR_RESET);
        }
    } while (choix != 10);

    return 0;
}
