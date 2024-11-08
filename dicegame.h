#ifndef DICEGAME_H
#define DICEGAME_H

#include <QMainWindow>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class DiceGame; }
QT_END_NAMESPACE

class DiceGame : public QMainWindow
{
    Q_OBJECT

public:
    explicit DiceGame(QWidget *parent = nullptr);
    ~DiceGame();

private slots:
    void rollDice();
    void showRandomSide(); // For the rolling effect

private:
    Ui::DiceGame *ui;
    QTimer *timer;
    int rollCount;
};
#endif // DICEGAME_H
