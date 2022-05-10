#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QStackedWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include "ai.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

public slots:
    void start();
    void gameLoop();
    void setPagePlayer();
    void newPlayer();
    void loadPlayer();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
