#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
#include <stdio.h>

#pragma comment(lib, "user32")
//#include <filesystem> //Afin d'indexer les fichiers d'un dossier     https://stackoverflow.com/questions/612097/how-can-i-get-the-list-of-files-in-a-directory-using-c-or-c

#include "gameloop.h"
#include "ai.h"

using namespace std;

int main()
{
    srand(time(0));
    system("mode 200");
    clearScreen();
    cout << "\n                                   .::.\n"
            "                                  .;:**'\n"
            "                                   `\n"
            "     .:XHHHHk.              db.   .;;.     dH  MX   \n"
            "   oMMMMMMMMMMM       ~MM  dMMP :MMMMMR   MMM  MR      ~MRMN\n"
            "   QMMMMMb  \"MMX       MMMMMMP !MX' :M~   MMM MMM  .oo. XMMM 'MMM\n"
            "     `MMMM.  )M> :X!Hk. MMMM   XMM.o\"  .  MMMMMMM X?XMMM MMM>!MMP\n"
            "      'MMMb.dM! XM M'?M MMMMMX.`MMMMMMMM~ MM MMM XM `\" MX MMXXMM\n"
            "       ~MMMMM~ XMM. .XM XM`\"MMMb.~*?**~ .MMX M t MMbooMM XMMMMMP\n"
            "        ?MMM>  YMMMMMM! MM   `?MMRb.    `\"\"\"   !L\"MMMMM XM IMMM\n"
            "         MMMX   \"MMMM\"  MM       ~%:           !Mh.\"\"\" dMI IMMP\n"
            "         'MMM.                                             IMX\n"
            "          ~M!M                                             IMP\n";


    string aTrainerName = "tempName";

    Trainer *aTrainer = new Trainer(aTrainerName),
            *aTrainer2 = new Trainer(aTrainerName);

    AI *firstAI = new AI("AI1"),
            *secndAI = new AI("AI2");
    //for(int i=1; i<=151; i++)
        //print_pokemon(i);

    switch (versusMenu()) {
    case 0:     cout << "Player 1:\n";
            aTrainer = bootMenu();
            cout << "Player 2:\n";
            aTrainer2 = bootMenu();

            battleSequence(aTrainer, aTrainer2);
        break;

    case 1: cout << "Player 1:\n";
            aTrainer = bootMenu();
            firstAI->setItsOpponent(aTrainer);

            battleSequence1AI(aTrainer, firstAI);
        break;

    case 2: firstAI->setItsOpponent(secndAI);
            secndAI->setItsOpponent(firstAI);

        battleSequence2AI(firstAI, secndAI);
        break;

    };

    aTrainer->save();
    aTrainer2->save();

    cout <<"\n\n_____/\\\\\\\\\\\\\\\\\\\\\\\\_____/\\\\\\\\\\\\\\\\\\\\\\\\_\n"
            " ___/\\\\\\//////////____/\\\\\\//////////__ \n"
            "  __/\\\\\\______________/\\\\\\_____________ \n"
            "   _\\/\\\\\\____/\\\\\\\\\\\\\\_\\/\\\\\\____/\\\\\\\\\\\\\\_ \n"
            "    _\\/\\\\\\___\\/////\\\\\\_\\/\\\\\\___\\/////\\\\\\_ \n"
            "     _\\/\\\\\\_______\\/\\\\\\_\\/\\\\\\_______\\/\\\\\\_ \n"
            "      _\\/\\\\\\_______\\/\\\\\\_\\/\\\\\\_______\\/\\\\\\_ \n"
            "       _\\//\\\\\\\\\\\\\\\\\\\\\\\\/__\\//\\\\\\\\\\\\\\\\\\\\\\\\/__ \n"
            "        __\\////////////_____\\////////////____ \n\n";

    delete aTrainer;
    delete aTrainer2;
    delete firstAI;
    delete secndAI;

    cout << "\n\n";
    return 0;
}

 //cout << "\ntest " << totalPokeList[28]->getItsName() << endl;

/* faire sortir de la boucle au ko du pokemon et pas de la team!!!
 * faire choisir un pokemon au debut du combat et doit rester jusqu'a un changement quelconque
 * Permettre le changement de pokemon durant le combat
si pokemon est KO  oblige le changement
penser a ne pas pouvoir choisir un pokemon KO
mettre un pokemon avec de la vie en tant qu'actif*********
si equipe ko mais FIN du combat et soigne l'equipe
preciser le nom du joueur effectuant les actions
*/

//A faire: overload << pour les pokemons : dire noms type et ses stats (propre style tableau) DONE
//TRainer:  save de sa team avec son nom DONE   +  selection random DONE
//GERE LES FINDS POUR QUE CELA FONCTIONNE POUR UN TRAINER ET LA LISTE TOTAL DES POKEMONS !! DONE
//Pour les combats: soit se dire qu'un pokemon est unique sinon meme HP tous (si deux fois le meme pokemon selectione)
//sinon il faut creer une fctn copy afin d'avoir un nouveau pokemon a partir de la list general en recuperant toutes ses stats.DONE

// + boucle de jeu pour savoir qui affronte qui
//pokedex avec image pokemon (qgraphic view / scene)
