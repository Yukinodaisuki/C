//创建 calculator类 ，主要负责计算
//预期功能如下：
//（1）获取用户所填数据
//（2）点击【开始计算】按钮，判断是否有不符合格式的数据，弹出提示信息
//（3）根据用户要求，调用相应算法
//（4）将计算结果以相应格式输出
//（5）点击【清空重填】按钮，清空数据

#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>
#include <QLineEdit>


class calculator : public QLineEdit
{
    Q_OBJECT
public:
    explicit calculator(QWidget *parent = nullptr);
    ~calculator();

    QLineEdit *line;
    double unit=0, area=0, rate_1=0, total=0, rate_2=0;
    double c_loan=0, c_rate=0, p_loan=0, p_rate=0;

    double percent=0, month_1=0, month_2=0, month_3=0;


signals:


public slots:

};

#endif // CALCULATOR_H
