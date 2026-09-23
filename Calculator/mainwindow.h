#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private:
    Ui::MainWindow *ui;

    void buttonNumberClicked();
    void buttonDecimalClicked();
    void buttonOperatorClicked();
    void buttonEqualsClicked();
    void buttonClearClicked();

    double firstNumber = 0;
    QString currentOperator;
    bool waitingForOperand = false;
    bool resultDisplayed = false;
};
#endif // MAINWINDOW_H
