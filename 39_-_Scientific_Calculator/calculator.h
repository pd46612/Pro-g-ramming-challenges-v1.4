#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Calculator; }
QT_END_NAMESPACE

class Calculator : public QMainWindow
{
    Q_OBJECT

public:
    Calculator(QWidget *parent = nullptr);
    ~Calculator();

private slots:
    void on_button_1_clicked();
    void on_button_2_clicked();
    void on_button_3_clicked();
    void on_button_4_clicked();
    void on_button_5_clicked();
    void on_button_6_clicked();
    void on_button_7_clicked();
    void on_button_8_clicked();
    void on_button_9_clicked();
    void on_button_0_clicked();
    void on_button_dot_clicked();
    void on_button_equals_clicked();
    void on_button_sinus_clicked();
    void on_button_cosinus_clicked();
    void on_button_tanges_clicked();
    void on_button_rightBracket_clicked();
    void on_button_log2_clicked();
    void on_button_log10_clicked();
    void on_button_C_clicked();

    void on_button_plus_clicked();

private:
    Ui::Calculator *ui;

    QString displayText = "0";
    QString operation = "";
    double argLeft = -99999;
    double argRight = -99999;
    double result;

    void updateDisplay();
    bool isDisplayFull();
    bool isDisplayZero();
};
#endif // CALCULATOR_H
