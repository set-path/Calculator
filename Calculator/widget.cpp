#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowTitle("计算器");
    this->calculator.init();
    this->ui->lineEdit->setText(QString::number(this->calculator.showresult()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_0_clicked()
{
    this->calculator.GetExpression('0');
    this->ui->lineEdit->setText(QString::fromStdString(this->calculator.showexpression()));
}

void Widget::on_pushButton_1_clicked()
{
    this->calculator.GetExpression('1');
    this->ui->lineEdit->setText(QString::fromStdString(this->calculator.showexpression()));
}

void Widget::on_pushButton_2_clicked()
{
    this->calculator.GetExpression('2');
    this->ui->lineEdit->setText(QString::fromStdString(this->calculator.showexpression()));
}

void Widget::on_pushButton_3_clicked()
{
    this->calculator.GetExpression('3');
    this->ui->lineEdit->setText(QString::fromStdString(this->calculator.showexpression()));
}

void Widget::on_pushButton_4_clicked()
{
    this->calculator.GetExpression('4');
    this->ui->lineEdit->setText(QString::fromStdString(this->calculator.showexpression()));
}

void Widget::on_pushButton_5_clicked()
{
    this->calculator.GetExpression('5');
    this->ui->lineEdit->setText(QString::fromStdString(this->calculator.showexpression()));
}

void Widget::on_pushButton_6_clicked()
{
    this->calculator.GetExpression('6');
    this->ui->lineEdit->setText(QString::fromStdString(this->calculator.showexpression()));
}

void Widget::on_pushButton_8_clicked()
{
    this->calculator.GetExpression('7');
    this->ui->lineEdit->setText(QString::fromStdString(this->calculator.showexpression()));
}

void Widget::on_pushButton_9_clicked()
{
    this->calculator.GetExpression('8');
    this->ui->lineEdit->setText(QString::fromStdString(this->calculator.showexpression()));
}

void Widget::on_pushButton_10_clicked()
{
    this->calculator.GetExpression('9');
    this->ui->lineEdit->setText(QString::fromStdString(this->calculator.showexpression()));
}

void Widget::on_pushButton_point_clicked()
{
    this->calculator.GetExpression('.');
    this->ui->lineEdit->setText(QString::fromStdString(this->calculator.showexpression()));
}

void Widget::on_pushButton_add_clicked()
{
    this->calculator.GetExpression('+');
    this->ui->lineEdit->setText(QString::fromStdString(this->calculator.showexpression()));
}

void Widget::on_pushButton_sub_clicked()
{
    this->calculator.GetExpression('-');
    this->ui->lineEdit->setText(QString::fromStdString(this->calculator.showexpression()));
}

void Widget::on_pushButton_mul_clicked()
{
    this->calculator.GetExpression('*');
    this->ui->lineEdit->setText(QString::fromStdString(this->calculator.showexpression()));
}

void Widget::on_pushButton_div_clicked()
{
    this->calculator.GetExpression('/');
    this->ui->lineEdit->setText(QString::fromStdString(this->calculator.showexpression()));
}

void Widget::on_pushButton_left_bracket_clicked()
{
    this->calculator.GetExpression('(');
    this->ui->lineEdit->setText(QString::fromStdString(this->calculator.showexpression()));
}

void Widget::on_pushButton_right_bracket_clicked()
{
    this->calculator.GetExpression(')');
    this->ui->lineEdit->setText(QString::fromStdString(this->calculator.showexpression()));
}

void Widget::on_pushButton_clear_clicked()
{
    this->calculator.init();
    this->calculator.setresult(0);
    this->ui->lineEdit->setText(QString::number(this->calculator.showresult()));
}

void Widget::on_pushButton_equal_clicked()
{
    this->calculator.GetExpression('=');
    int flag = this->calculator.Calculation();
    if(flag == 0&&this->calculator.showflag()==false){
        this->ui->lineEdit->setText(QString::number(this->calculator.showresult()));
    }else if(this->calculator.showflag()==true){
        this->ui->lineEdit->setText("除数不能为0");
        this->calculator.init();
        return;
    }
    this->calculator.init();
    this->calculator.setexpression(QString::number(this->calculator.showresult()).toStdString());
}

void Widget::on_pushButton_reciprocal_clicked()
{
    if(this->calculator.showresult() == 0.0){
        this->ui->lineEdit->setText("除数不能为0");
        this->calculator.init();
        return;
    }
    double res = 1 / this->calculator.showresult();
    this->ui->lineEdit->setText(QString::number(res));
    this->calculator.setexpression(QString::number(res).toStdString());
}

void Widget::on_pushButton_backspace_clicked()
{
    if(this->calculator.showexpression() == ""){
        return;
    }
    this->calculator.subrxpression(0, this->calculator.showexpression().length() - 1);
    this->ui->lineEdit->setText(QString::fromStdString(this->calculator.showexpression()));
}
