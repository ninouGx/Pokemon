#include "widget.h"
#include "ui_widget.h"

using namespace std;

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    Trainer *aTrainer = new Trainer(""),
            *aTrainer2 = new Trainer("");

    AI *firstAI = new AI("AI1"),
            *secndAI = new AI("AI2");

    connect(ui->noAiButton, SIGNAL(clicked()), this, SLOT(setPagePlayer()));
    connect(ui->newPlayerButton, SIGNAL(clicked()), this, SLOT(newPlayer()));

}


Widget::~Widget()
{
    delete ui;
}


void Widget::gameLoop()
{

}

void Widget::setPagePlayer()
{
    ui->pokemonWidget->setCurrentIndex(1);
}

void Widget::newPlayer()
{
    Trainer *aTrainer = new Trainer("");
    aTrainer->createTeam();
}

void Widget::loadPlayer()
{

}


void Widget::start()
{
}

    /*srand(time(0));

    string aTrainerName = "tempName";

    Trainer *aTrainer = new Trainer(aTrainerName),
            *aTrainer2 = new Trainer(aTrainerName);

    AI *firstAI = new AI("AI1"),
            *secndAI = new AI("AI2");

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

    delete aTrainer;
    delete aTrainer2;

    cout << "\n\n";*/
