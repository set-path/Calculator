#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "calculator.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButton_0_clicked();

    void on_pushButton_1_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_point_clicked();

    void on_pushButton_add_clicked();

    void on_pushButton_sub_clicked();

    void on_pushButton_mul_clicked();

    void on_pushButton_div_clicked();

    void on_pushButton_left_bracket_clicked();

    void on_pushButton_right_bracket_clicked();

    void on_pushButton_clear_clicked();

    void on_pushButton_equal_clicked();

    void on_pushButton_reciprocal_clicked();

    void on_pushButton_backspace_clicked();

private:
    Ui::Widget *ui;
    Calculator calculator;
};
#endif // WIDGET_H
