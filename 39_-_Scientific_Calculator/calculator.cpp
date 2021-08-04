#include "calculator.h"
#include "ui_calculator.h"

#include <math.h>

Calculator::Calculator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Calculator)
{
    ui->setupUi(this);
}

Calculator::~Calculator()
{
    delete ui;
}

void Calculator::updateDisplay()
{
    ui->display->setText(displayText);
}

bool Calculator::isDisplayFull()
{
    if(displayText.size() >= 15) return true;
    else return false;
}

bool Calculator::isDisplayZero()
{
    if (displayText == '0' || displayText == "nan") return true;
    else return false;
}

void Calculator::on_button_1_clicked()
{
    if(isDisplayZero())
        displayText = "";
    if(!isDisplayFull())
    {
        displayText = displayText + '1';
        updateDisplay();
    }
}

void Calculator::on_button_2_clicked()
{
    if(isDisplayZero())
        displayText = "";
    if(!isDisplayFull())
    {
        displayText = displayText + '2';
        updateDisplay();
    }
}

void Calculator::on_button_3_clicked()
{
    if(isDisplayZero())
        displayText = "";
    if(!isDisplayFull())
    {
        displayText = displayText + '3';
        updateDisplay();
    }
}

void Calculator::on_button_4_clicked()
{
    if(isDisplayZero())
        displayText = "";
    if(!isDisplayFull())
    {
        displayText = displayText + '4';
        updateDisplay();
    }
}

void Calculator::on_button_5_clicked()
{
    if(isDisplayZero())
        displayText = "";
    if(!isDisplayFull())
    {
        displayText = displayText + '5';
        updateDisplay();
    }
}

void Calculator::on_button_6_clicked()
{
    if(isDisplayZero())
        displayText = "";
    if(!isDisplayFull())
    {
        displayText = displayText + '6';
        updateDisplay();
    }
}

void Calculator::on_button_7_clicked()
{
    if(isDisplayZero())
        displayText = "";
    if(!isDisplayFull())
    {
        displayText = displayText + '7';
        updateDisplay();
    }
}

void Calculator::on_button_8_clicked()
{
    if(isDisplayZero())
        displayText = "";
    if(!isDisplayFull())
    {
        displayText = displayText + '8';
        updateDisplay();
    }
}

void Calculator::on_button_9_clicked()
{
    if(isDisplayZero())
        displayText = "";
    if(!isDisplayFull())
    {
        displayText = displayText + '9';
        updateDisplay();
    }
}

void Calculator::on_button_0_clicked()
{
    if(!isDisplayFull() && displayText != "0.0" && displayText != '0')
    {
        displayText = displayText + '0';
        updateDisplay();
    }
}

void Calculator::on_button_dot_clicked()
{
    if(displayText.size() <= 13 && !displayText.contains('.'))
    {
        displayText = displayText + '.';
        updateDisplay();
    }
}

void Calculator::on_button_equals_clicked()
{
    if(displayText.contains("sin") || displayText.contains("cos") || displayText.contains("tan") || displayText.contains("log"))
    {
        displayText = displayText + ")";
        bool pastLeftBracket = false;
        bool pastRightBracket = false;
        QString argument;
        for (int i = 0; i < displayText.size(); i++)
        {
            if (displayText.at(i) == '(')
            {
                pastLeftBracket = true;
                continue;
            }
            if (displayText.at(i) == ')')
            {
                pastRightBracket = true;
                continue;
            }
            if (pastLeftBracket && !pastRightBracket)
            {
                argument = argument + displayText.at(i);
                continue;
            }
        }
        double argumentDouble = argument.toDouble();
        if (displayText.contains("sin"))
            result = sin(argumentDouble);
        else if(displayText.contains("cos"))
            result = cos(argumentDouble);
        else if(displayText.contains("tan"))
            result = tan(argumentDouble);
        displayText = QString::number(result);
        result = 0;
        updateDisplay();
    }
    else if(operation == "add")
    {
        argRight = displayText.toDouble();
        result = argLeft + argRight;
        displayText = QString::number(result);
        result = 0;
        updateDisplay();
    }
}

void Calculator::on_button_sinus_clicked()
{
    displayText = "sin(";
    updateDisplay();
}

void Calculator::on_button_cosinus_clicked()
{
    displayText = "cos(";
    updateDisplay();
}

void Calculator::on_button_tanges_clicked()
{
    displayText = "tan(";
    updateDisplay();
}

void Calculator::on_button_rightBracket_clicked()
{
    if (displayText.contains("sin") || displayText.contains("cos") || displayText.contains("tan") || displayText.contains("log") || displayText.contains("^"))
    {
        displayText = displayText + ")";
        updateDisplay();
    }
}

void Calculator::on_button_log2_clicked()
{
    result = log2(displayText.toDouble());
    displayText = QString::number(result);
    result = 0;
    updateDisplay();
}


void Calculator::on_button_log10_clicked()
{
    result = log10(displayText.toDouble());
    displayText = QString::number(result);
    result = 0;
    updateDisplay();
}

void Calculator::on_button_C_clicked()
{
    displayText = "0";
    updateDisplay();
    result = 0;
    operation = "";
    argLeft = -99999;
    argRight = -99999;
}

void Calculator::on_button_plus_clicked()
{
    if(ui->display->text() == "nan" || argLeft == -99999)
        argLeft = 0.0;
    else
    {
        argLeft = displayText.toDouble();
        displayText = "0";
        updateDisplay();
        operation = "add";
    }
}

