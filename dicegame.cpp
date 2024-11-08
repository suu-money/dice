#include "dicegame.h"
#include "ui_dicegame.h"
#include <QPixmap>
#include <QRandomGenerator>
#include <QTimer>

DiceGame::DiceGame(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::DiceGame), rollCount(0)
{
    ui->setupUi(this);

    // Initialize timer for rolling effect
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &DiceGame::showRandomSide);

    // Connect button click to roll dice
    connect(ui->rollButton, &QPushButton::clicked, this, &DiceGame::rollDice);
}

DiceGame::~DiceGame()
{
    delete ui;
}

void DiceGame::rollDice()
{
    rollCount = 10;  // Number of "rolls" to show before stopping
    timer->start(100); // Start timer with 100ms intervals
}

void DiceGame::showRandomSide()
{
    if (rollCount > 0) {
        // Random side from 1 to 6
        int side = QRandomGenerator::global()->bounded(1, 7);
        QString imagePath = QString(":/dice%1.png").arg(side);
        ui->diceLabel->setPixmap(QPixmap(imagePath));
        rollCount--;
    } else {
        timer->stop(); // Stop rolling after set rolls
    }
}
