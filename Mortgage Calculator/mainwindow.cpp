#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <calculator.h>

#include <QPainter>
#include <QRegExp>
#include <QString>
#include <QLineEdit>
#include <QComboBox>
#include <QMessageBox>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


//设置图标
    setWindowIcon(QIcon(":/img/ico.png"));

//设置标题
    setWindowTitle("房贷计算器");


//设置默认定位
    //栈控件
    ui->stackedWidget_1->setCurrentIndex(0);
    ui->stackedWidget_2->setCurrentIndex(0);
    ui->showResult->setCurrentIndex(0);
    //下拉框
    ui->comboBox_1->setCurrentIndex(0);
    ui->comboBox_2->setCurrentIndex(0);
    ui->comboBox_a1->setCurrentIndex(0);
    ui->comboBox_a2->setCurrentIndex(0);
    ui->comboBox_b->setCurrentIndex(0);
    ui->comboBox_c->setCurrentIndex(0);
    //设置“还款方式”默认选中“等额本息”
    ui->radioButton_1->setChecked(true);



//尝试 正则表达式 限制输入
    //限制整数部分最高6位，小数部位最多2位
    QRegExp rx1("^([1-9]\\d{0,5})(\\.\\d{1,2})?$");
    QValidator *validator_MAX6 = new QRegExpValidator(rx1);

    //限制整数部分最高4位，小数部位最多2位
    QRegExp rx2("^([1-9]\\d{0,3})(\\.\\d{1,2})?$");
    QValidator *validator_MAX4 = new QRegExpValidator(rx2);

    //限制整数部分最高2位，小数部位最多2位
    QRegExp rx3("^([1-9]\\d{0,1})(\\.\\d{1,2})?$");
    QValidator *validator_MAX2 = new QRegExpValidator(rx3);

    //限制整数部分最高10位，小数部位最多2位
    QRegExp rx4("^([1-9]\\d{0,9})(\\.\\d{1,2})?$");
    QValidator *validator_MAX10 = new QRegExpValidator(rx4);


//商业贷款 & 公积金贷款
    //面积、单价部分
    ui->lineEdit_a1->setValidator(validator_MAX6);

    ui->lineEdit_a2->setValidator(validator_MAX4);

    ui->lineEdit_a3->setValidator(validator_MAX2);
    //贷款总额部分
    ui->lineEdit_b1->setValidator(validator_MAX10);

    ui->lineEdit_b2->setValidator(validator_MAX2);


//组合型贷款
    //商业贷款额
    ui->lineEdit_c1->setValidator(validator_MAX6);

    ui->lineEdit_c2->setValidator(validator_MAX2);
    //公积金贷款额
    ui->lineEdit_c3->setValidator(validator_MAX6);

    ui->lineEdit_c4->setValidator(validator_MAX2);



//根据comboBox当前选项切换stakedWidget
    //选择贷款类型
    void(QComboBox::*fp)(int)=&QComboBox::currentIndexChanged;
    //使用 信号与槽 实现即时切换
    connect(ui->comboBox_1, fp, ui->stackedWidget_1, [=](){
        if(ui->comboBox_1->currentIndex() == 0 || ui->comboBox_1->currentIndex() == 1)
        {
            ui->stackedWidget_1->setCurrentIndex(0);
        }

        if(ui->comboBox_1->currentIndex() == 2)
        {
            ui->stackedWidget_1->setCurrentIndex(1);
        }
    });

    //商业贷款 & 公积金贷款时，选择计算方式
    connect(ui->comboBox_2, fp, ui->stackedWidget_2, [=](){
        if(ui->comboBox_2->currentIndex() == 0)
        {
            ui->stackedWidget_2->setCurrentIndex(0);
        }

        if(ui->comboBox_2->currentIndex() == 1)
        {
            ui->stackedWidget_2->setCurrentIndex(1);
        }
    });


//开始计算
    connect(ui->btn_1, &QPushButton::clicked, [=]{
    //首先判断贷款类型和计算方法
        if(ui->comboBox_1->currentIndex() == 0)
        {
            if(ui->comboBox_2->currentIndex() == 0) flag = 1;//商业贷款 + 按面积单价计算
            if(ui->comboBox_2->currentIndex() == 1) flag = 2;//商业贷款 + 按贷款总额计算
        }
        if(ui->comboBox_1->currentIndex() == 1)
        {
            if(ui->comboBox_2->currentIndex() == 0) flag = 3;//公积金贷款 + 按面积单价计算
            if(ui->comboBox_2->currentIndex() == 1) flag = 4;//公积金贷款 + 按贷款总额计算
        }
        if(ui->comboBox_1->currentIndex() == 2) flag = 5;//组合型贷款

        //判断输入合法后，进行计算
        calculator *data = new calculator;
        if(isValid())
        {
            //获取数据
            data->unit = ui->lineEdit_a1->text().toDouble();
            data->area = ui->lineEdit_a2->text().toDouble();
            data->rate_1 = ui->lineEdit_a3->text().toDouble() *0.01;
            data->percent = (8 - 0.5*ui->comboBox_a1->currentIndex()) *0.1;
            data->month_1 = 300 - 12*ui->comboBox_a2->currentIndex();

            data->total = ui->lineEdit_b1->text().toDouble();
            data->rate_2 = ui->lineEdit_b2->text().toDouble() *0.01;
            data->month_2 = 300 - 12*ui->comboBox_b->currentIndex();

            data->c_loan = ui->lineEdit_c1->text().toDouble();
            data->c_rate = ui->lineEdit_c2->text().toDouble() *0.01;
            data->p_loan = ui->lineEdit_c3->text().toDouble();
            data->p_rate = ui->lineEdit_c4->text().toDouble() *0.01;
            data->month_3 = 300 - 12*ui->comboBox_c->currentIndex();


            switch (flag) {
            //商业贷款或公积金贷款， 按面积、单价计算
            case 1:
            case 3:
                {
                    double principal = data->unit * data->area * data->percent;
                    if(ui->radioButton_1->isChecked() == true)//等额本息
                    {
                        double monthly = 0, t = 1;
                        for(int i=0; i<data->month_1; i++)
                        {
                            t = t*(1 + data->rate_1/12);
                        }
                        monthly = principal*data->rate_1 / 12 * t / (t-1);
                        long totalRepayment = monthly * data->month_1;
                        long totalInterest = totalRepayment - principal;

                        ui->showResult->setCurrentIndex(1);
                        ui->a1->setText(QString::number(data->unit * data->area - principal));
                        ui->a2->setText(QString::number(monthly));
                        ui->a3->setText(QString::number((long)principal));
                        ui->a4->setText(QString::number(totalInterest));
                        ui->a5->setText(QString::number(totalRepayment));
                        ui->a6->setText(QString::number(data->month_1));
                    }

                    if(ui->radioButton_2->isChecked() == true)//等额本金
                    {
                        double first_month = principal/data->month_1 + principal*data->rate_1/12;
                        double decrement = principal/data->month_1 * data->rate_1/12;
                        long totalRepayment = (principal/data->month_1 + first_month + decrement)*data->month_1/2;
                        long totalInterest = totalRepayment - principal;

                        ui->showResult->setCurrentIndex(3);
                        ui->b1->setText(QString::number(data->unit * data->area - principal));
                        ui->b2->setText(QString::number(first_month));
                        ui->b3->setText(QString::number(decrement));
                        ui->b4->setText(QString::number((long)principal));
                        ui->b5->setText(QString::number(totalInterest));
                        ui->b6->setText(QString::number(totalRepayment));
                        ui->b7->setText(QString::number(data->month_1));
                    }
                }
                break;

            //商业贷款或公积金贷款， 按贷款总额计算
            case 2:
            case 4:
                {
                    double principal = 10000 * data->total;
                    if(ui->radioButton_1->isChecked() == true)//等额本息
                    {
                        double monthly = 0, t = 1;
                        for(int i=0; i<data->month_2; i++)
                        {
                            t = t*(1 + data->rate_2/12);
                        }
                        monthly = principal * data->rate_2 / 12 * t / (t-1);
                        long totalRepayment = monthly*data->month_2;
                        long totalInterest = totalRepayment - principal;

                        ui->showResult->setCurrentIndex(2);
                        ui->c1->setText(QString::number(monthly));
                        ui->c2->setText(QString::number((long)principal));
                        ui->c3->setText(QString::number(totalInterest));
                        ui->c4->setText(QString::number(totalRepayment));
                        ui->c5->setText(QString::number(data->month_2));
                    }

                    if(ui->radioButton_2->isChecked() == true)//等额本金
                    {
                        double first_month = principal/data->month_2 + principal*data->rate_2/12;
                        double decrement = principal/data->month_2 * data->rate_2/12;
                        long totalRepayment = (principal/data->month_2 + first_month + decrement)*data->month_2/2;
                        long totalInterest = totalRepayment - principal;

                        ui->showResult->setCurrentIndex(4);
                        ui->d1->setText(QString::number(first_month));
                        ui->d2->setText(QString::number(decrement));
                        ui->d3->setText(QString::number((long)principal));
                        ui->d4->setText(QString::number(totalInterest));
                        ui->d5->setText(QString::number(totalRepayment));
                        ui->d6->setText(QString::number(data->month_2));
                    }
                }
                break;

            //组合型贷款
            case 5:
                {
                    double c_principal = 10000 * data->c_loan;
                    double p_principal = 10000 * data->p_loan;
                    if(ui->radioButton_1->isChecked() == true)//等额本息
                    {
                        double monthly = 0, m = 1, n = 1;
                        for(int i=0; i<data->month_3; i++)
                        {
                            m = m*(1 + data->c_rate/12);
                            n = n*(1 + data->p_rate/12);
                        }
                        monthly = c_principal*data->c_rate/12*m/(m-1) + p_principal*data->p_rate/12*n/(n-1);
                        long totalRepayment = monthly*data->month_3;
                        long totalInterest = totalRepayment - c_principal - p_principal;

                        ui->showResult->setCurrentIndex(2);
                        ui->c1->setText(QString::number(monthly));
                        ui->c2->setText(QString::number((long)(c_principal+p_principal)));
                        ui->c3->setText(QString::number(totalInterest));
                        ui->c4->setText(QString::number(totalRepayment));
                        ui->c5->setText(QString::number(data->month_3));
                    }

                    if(ui->radioButton_2->isChecked() == true)//等额本金
                    {
                        double first_month = (c_principal/data->month_3 + c_principal*data->c_rate/12) + (p_principal/data->month_3 + p_principal*data->p_rate/12);
                        double decrement = c_principal/data->month_3 * data->c_rate/12  +  p_principal/data->month_3 * data->p_rate/12;
                        long totalRepayment = ( (c_principal+p_principal)/data->month_3 + first_month + decrement)*data->month_3/2 ;
                        long totalInterest = totalRepayment - p_principal - c_principal;

                        ui->showResult->setCurrentIndex(4);
                        ui->d1->setText(QString::number(first_month));
                        ui->d2->setText(QString::number(decrement));
                        ui->d3->setText(QString::number((long)(c_principal+p_principal)));
                        ui->d4->setText(QString::number(totalInterest));
                        ui->d5->setText(QString::number(totalRepayment));
                        ui->d6->setText(QString::number(data->month_3));
                    }
                }
                break;
            default:
                break;
            }
        }
    });

//清除数据
    connect(ui->btn_2, &QPushButton::clicked, [=]{
        ui->lineEdit_a1->clear();
        ui->lineEdit_a2->clear();
        ui->lineEdit_a3->clear();
        ui->lineEdit_b1->clear();
        ui->lineEdit_b2->clear();
        ui->lineEdit_c1->clear();
        ui->lineEdit_c2->clear();
        ui->lineEdit_c3->clear();
        ui->lineEdit_c4->clear();
        ui->showResult->setCurrentIndex(0);
    });

}


//设置背景图片
void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/img/2.png");
    painter.setOpacity(0.5);
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
}

//判断输入是否合法
bool MainWindow::isValid()
{
    //输入不合法时弹出提示
    //按面积单价计算时
    bool re = 1;
    if(flag == 1 || flag == 3)
    {
        if(ui->lineEdit_a1->text() == NULL)
        {
            re = 0;
            QMessageBox::information(this, "提示","请输入房屋单价");
            return false;
        }
        if(ui->lineEdit_a2->text() == NULL)
        {
            re = 0;
            QMessageBox::information(this, "提示","请输入房屋面积");
            return false;
        }
        if(ui->lineEdit_a3->text() == NULL)
        {
            re = 0;
            QMessageBox::information(this, "提示","请输入贷款利率");
            return false;
        }
    }
    //按贷款总额计算时
    if(flag == 2 || flag == 4)
    {
        if(ui->lineEdit_b1->text() == NULL)
        {
            re = 0;
            QMessageBox::information(this, "提示","请输入贷款总额");
            return false;
        }
        if(ui->lineEdit_b2->text() == NULL)
        {
            re = 0;
            QMessageBox::information(this, "提示","请输入贷款利率");
            return false;
        }
    }
    //按组合型贷款计算时
    if(flag == 5)
    {
        if(ui->lineEdit_c1->text() == NULL)
        {
            re = 0;
            QMessageBox::information(this, "提示","请输入商业贷款额");
            return false;
        }
        if(ui->lineEdit_c2->text() == NULL)
        {
            re = 0;
            QMessageBox::information(this, "提示","请输入商贷利率");
            return false;
        }
        if(ui->lineEdit_c3->text() == NULL)
        {
            re = 0;
            QMessageBox::information(this, "提示","请输入公积金贷款额");
            return false;
        }
        if(ui->lineEdit_c4->text() == NULL)
        {
            re = 0;
            QMessageBox::information(this, "提示","请输入公积金利率");
            return false;
        }
    }
    return re;
}

MainWindow::~MainWindow()
{
    delete ui;
}
