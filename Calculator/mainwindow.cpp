#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->button0, &QPushButton::clicked, this, &MainWindow::buttonNumberClicked);
    connect(ui->button1, &QPushButton::clicked, this, &MainWindow::buttonNumberClicked);
    connect(ui->button2, &QPushButton::clicked, this, &MainWindow::buttonNumberClicked);
    connect(ui->button3, &QPushButton::clicked, this, &MainWindow::buttonNumberClicked);
    connect(ui->button4, &QPushButton::clicked, this, &MainWindow::buttonNumberClicked);
    connect(ui->button5, &QPushButton::clicked, this, &MainWindow::buttonNumberClicked);
    connect(ui->button6, &QPushButton::clicked, this, &MainWindow::buttonNumberClicked);
    connect(ui->button7, &QPushButton::clicked, this, &MainWindow::buttonNumberClicked);
    connect(ui->button8, &QPushButton::clicked, this, &MainWindow::buttonNumberClicked);
    connect(ui->button9, &QPushButton::clicked, this, &MainWindow::buttonNumberClicked);
    connect(ui->buttonDecimal, &QPushButton::clicked, this, &MainWindow::buttonDecimalClicked);
    connect(ui->buttonAdd, &QPushButton::clicked, this, &MainWindow::buttonOperatorClicked);
    connect(ui->buttonSubtract, &QPushButton::clicked, this, &MainWindow::buttonOperatorClicked);
    connect(ui->buttonMultiply, &QPushButton::clicked, this, &MainWindow::buttonOperatorClicked);
    connect(ui->buttonDivide, &QPushButton::clicked, this, &MainWindow::buttonOperatorClicked);
    connect(ui->buttonEquals, &QPushButton::clicked, this, &MainWindow::buttonEqualsClicked);
    connect(ui->buttonClear, &QPushButton::clicked, this, &MainWindow::buttonClearClicked);



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::buttonNumberClicked()
{
    QPushButton *button = qobject_cast<QPushButton *>(sender());

    QString currentText = ui->display->text();
    QString buttonText = button->text();

    if (resultDisplayed)
    {
        ui->display->setText(buttonText);
        resultDisplayed = false;
        return;
    }

    if (waitingForOperand)
    {
        ui->display->setText(buttonText);
        waitingForOperand = false;
    }
    else if (currentText == "0")
    {
        ui->display->setText(buttonText);
    }
    else
    {
        ui->display->setText(currentText + buttonText);
    }
}

void MainWindow::buttonDecimalClicked()
{
    if (waitingForOperand)
    {
        ui->display->setText("0.");
        waitingForOperand = false;
        return;
    }
    QString currentText = ui->display->text();
    if (!currentText.contains("."))
    {
        ui->display->setText(currentText + ".");
    }
}

void MainWindow::buttonOperatorClicked()
{
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    firstNumber = ui->display->text().toDouble();
    currentOperator = button->text();
    waitingForOperand = true;
}

void MainWindow::buttonEqualsClicked()
{
    if (currentOperator.isEmpty()) {
        resultDisplayed = true;
        return;
    }

    double secondNumber = ui->display->text().toDouble();

    double result = 0;

    if (currentOperator == "+")
    {
        result = firstNumber + secondNumber;
    }
    else if (currentOperator == "-")
    {
        result = firstNumber - secondNumber;
    }
    else if (currentOperator == "×")
    {
        result = firstNumber * secondNumber;
    }
    else if (currentOperator == "÷")
    {
        if (secondNumber == 0)
        {
            ui->display->setText("Error");
            resultDisplayed = true;
            return;
        }
        result = firstNumber / secondNumber;
    }

    ui->display->setText(QString::number(result));

    resultDisplayed = true;
}

void MainWindow::buttonClearClicked()
{
    ui->display->setText("0");

    firstNumber = 0;
    currentOperator.clear();
    waitingForOperand = false;
    resultDisplayed = false;
}
