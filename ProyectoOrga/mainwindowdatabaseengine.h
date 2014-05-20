#ifndef MAINWINDOWDATABASEENGINE_H
#define MAINWINDOWDATABASEENGINE_H

#include <QMainWindow>

namespace Ui {
class MainWindowDataBaseEngine;
}

class MainWindowDataBaseEngine : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindowDataBaseEngine(QWidget *parent = 0);
    ~MainWindowDataBaseEngine();

private:
    Ui::MainWindowDataBaseEngine *ui;
};

#endif // MAINWINDOWDATABASEENGINE_H
