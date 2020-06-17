#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMessageBox>
#include <QPainter>
#include <QPixmap>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(800,400);
    setWindowTitle("房贷计算器");
    ui->fang1->addItem("商业贷款");
    ui->fang1->addItem("公积金贷款");
    ui->fang1->addItem("组合型贷款");
    ui->ji1->addItem("根据面积、单价计算");
    ui->ji1->addItem("根据贷款总额计算");
    ui->stackedWidget->setCurrentIndex(0);
   //限制输入
    ui->danjia1->setValidator(new QIntValidator(0,1000000000,ui->danjia1));
    ui->mianji1->setValidator(new QIntValidator(0,100000000,ui->mianji1));
    ui->nian1->setValidator(new QIntValidator(0,100,ui->nian1));
    ui->cheng1->setValidator(new QDoubleValidator(2,8,1,ui->cheng1));
    ui->lilv1->setValidator(new QDoubleValidator(0,100,2,ui->lilv1));
    ui->zonge->setValidator(new QIntValidator(0,1000000000,ui->zonge));
    ui->nian2->setValidator(new QIntValidator(0,100,ui->nian2));
    ui->lilv2->setValidator(new QDoubleValidator(0,100,2,ui->lilv2));
    ui->fangz->setValidator(new QIntValidator(0,10000000,ui->fangz));
    ui->fangg->setValidator(new QIntValidator(0,100000000,ui->fangg));
    ui->lilvs->setValidator(new QDoubleValidator(0,100,2,ui->lilvs));
    ui->lilvg->setValidator(new QDoubleValidator(0,100,2,ui->lilvg));
    ui->nian3->setValidator(new QIntValidator(0,100,ui->nian3));
    //还款方式
    connect(ui->benjin,&QRadioButton::clicked,[=](){
        huankuanfangshi=1;
    });
    connect(ui->benxi,&QRadioButton::clicked,[=](){
        huankuanfangshi=2;
    });
    connect(ui->benjin2,&QRadioButton::clicked,[=](){
        huankuanfangshi=1;
    });
    connect(ui->benxi2,&QRadioButton::clicked,[=](){
        huankuanfangshi=2;
    });
    connect(ui->benjin3,&QRadioButton::clicked,[=](){
        huankuanfangshi=1;
    });
    connect(ui->benxi3,&QRadioButton::clicked,[=](){
        huankuanfangshi=2;
    });
    //计算
    connect(ui->start1,&QPushButton::clicked,[=](){
        ui->textEdit->setText("");
        //判断
        if(panduan1()||panduanhk1())
        {
            if(panduan1())
                QMessageBox::critical(this,"警告","有信息未输入");
            if(panduanhk1())
                QMessageBox::critical(this,"警告","未选择还款方式");
        }
        else
        {
            bool ok;
            QString dj,mj,ch,nian,l,k;
            dj=ui->danjia1->text();
            mj=ui->mianji1->text();
            ch=ui->cheng1->text();
            nian=ui->nian1->text();
            l=ui->lilv1->text();
            long int dj1=dj.toInt(&ok);
            int mj1=mj.toInt(&ok);
            double ch1=ch.toDouble(&ok);
            int nian1=nian.toInt(&ok);
            double l1=l.toDouble(&ok);
            if(ch1>8||ch1<2)
            {
                QMessageBox::critical(this,"警告！","按揭成数不合理，请重新输入");
                ui->cheng1->setText("");
            }
            else if(nian1>30)
            {
                QMessageBox::critical(this,"警告！","按揭年数不合理，请重新输入");
                ui->nian1->setText("");
            }
            else if(l1>6)
            {
               QMessageBox::critical(this,"警告！","利率输入不合理，请重新输入");
               ui->lilv1->setText("");
            }
            else
            huank2(dj1,mj1,ch1,nian1,l1,huankuanfangshi);
        }
    });
    connect(ui->start2,&QPushButton::clicked,[=](){
        ui->textEdit->setText("");
        //判断
        if(panduan2()||panduanhk2())
        {
            if(panduan2())
                QMessageBox::critical(this,"警告！","有信息未输入");
            if(panduanhk2())
                QMessageBox::critical(this,"警告！","未选择还款方式");
        }
        {
            bool ok;
            QString ze,nian,l;
            ze=ui->zonge->text();
            nian=ui->nian2->text();
            l=ui->lilv2->text();
            double ze1=ze.toDouble(&ok);
            int nian1=nian.toInt(&ok);
            double l1=l.toDouble(&ok);
            if(nian1>30)
            {
                QMessageBox::critical(this,"警告！","按揭年数输入不合理，请重新输入");
                ui->nian2->setText("");
            }
            else if(l1>100)
            {
               QMessageBox::critical(this,"警告！","利率输入不合理，请重新输入");
               ui->lilv2->setText("");
            }
            else
            huank1(ze1,nian1,l1,huankuanfangshi);
        }
    });
    connect(ui->start3,&QPushButton::clicked,[=](){
        ui->textEdit->setText("");
        //判断
        if(panduan3()||panduanhk3())
        {
            if(panduan3())
            QMessageBox::critical(this,"警告","有信息未输入");
            if(panduanhk3())
            QMessageBox::critical(this,"警告","未选择还款方式");
        }
        else
        {
            bool ok;
            QString ze1,ze2,nian,l1,l2;
            ze1=ui->fangz->text();
            ze2=ui->fangg->text();
            nian=ui->nian3->text();
            l1=ui->lilvs->text();
            l2=ui->lilvg->text();
            double z1=ze1.toDouble(&ok);
            double z2=ze2.toDouble(&ok);
            int nian1=nian.toInt(&ok);
            double li1=l1.toDouble(&ok);
            double li2=l2.toDouble(&ok);
            if(nian1>30)
            {
                QMessageBox::critical(this,"警告！","按揭年数输入不合理，请重新输入");
                ui->nian3->setText("");
            }
            else if(li1>100)
            {
               QMessageBox::critical(this,"警告！","利率输入不合理，请重新输入");
               ui->lilvs->setText("");
            }
            else if(li2>100)
            {
               QMessageBox::critical(this,"警告！","利率输入不合理，请重新输入");
               ui->lilvg->setText("");
            }
            else
            huank3(z1,z2,nian1,li1,li2,huankuanfangshi);
        }
    });
    //清除
    connect(ui->clear,&QPushButton::clicked,[=](){
       if(QMessageBox::Yes == QMessageBox::question(this,"提示信息","请问您确认清空数据吗",QMessageBox::Yes|QMessageBox::No,QMessageBox::Yes))
           qingkong();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::huank1(double sum, int time, double yearlv, int type)
{
    //等额本金
    double ben,monthk1,monthk2,sum1,k;
    sum*=10000;
    k=sum;
    time*=12;
    double monthlv=yearlv/1200.0;
    QString zong;
    ui->textEdit->append("贷款总额："+zong.setNum(sum,'f',0)+" 元");
    ui->textEdit->append("还款月数："+zong.setNum(time)+" 个");
    if(type==1)
    {
        ben=sum/time;

        //首月还款
        monthk1=sum*monthlv+ben;
        QString area;
        area.setNum(monthk1);
        ui->textEdit->append("首月还款："+area.setNum(monthk1,'f',0)+" 元");
        //每月递减
        double jian;
        jian=ben*monthlv;
        ui->textEdit->append("每月递减："+area.setNum(jian,'f',0)+" 元");
        //支付利息
        double lixi;
        for(int i=0;i<time;i++)
        {
            lixi+=sum*monthlv;
            sum-=ben;
        }
        ui->textEdit->append("支付利息："+area.setNum(lixi,'f',0)+" 元");
        sum1=k+lixi;
        ui->textEdit->append("还款总额："+area.setNum(sum1,'f',0)+" 元");
    }
    //等额本息
    if(type==2)
    {
        monthk2=(sum*monthlv*pow(1+monthlv,time))/(pow(1+monthlv,time)-1);
        ui->textEdit->append("每月月供："+zong.setNum(monthk2,'f',0)+" 元");
        double li;
        li=monthk2*time-sum;
        ui->textEdit->append("支付利息："+zong.setNum(li,'f',0)+" 元");
        sum1=k+li;
        ui->textEdit->append("还款总额："+zong.setNum(sum1,'f',0)+" 元");
    }
}
void MainWindow::huank2(long dan, int mian, double cheng, int time, double yearlv, int type)
{
    double sum,ben,monthk1,monthk2,shou,k,sum1;
    sum=dan*mian*cheng/10.0;
    k=sum;
    shou=dan*mian*(10-cheng)/10.0;
    double monthlv=yearlv/1200.0;
    time*=12;
    QString zong;
    ui->textEdit->append("购房首付："+zong.setNum(shou,'f',1)+" 元");
    ui->textEdit->append("贷款总额："+zong.setNum(sum,'f',1)+" 元");
    ui->textEdit->append("还款月数："+zong.setNum(time)+" 个");
    if(type==1)
    {
        ben=sum/time;

        //首月还款
        monthk1=sum*monthlv+ben;
        QString area;
        area.setNum(monthk1);
        ui->textEdit->append("首月还款："+area.setNum(monthk1,'f',0)+" 元");
        //每月递减
        double jian;
        jian=ben*monthlv;
        ui->textEdit->append("每月递减："+area.setNum(jian,'f',0)+" 元");
        //支付利息
        double lixi;
        for(int i=0;i<time;i++)
        {
            lixi+=sum*monthlv;
            sum-=ben;
        }
        ui->textEdit->append("支付利息："+area.setNum(lixi,'f',0)+" 元");
        sum1=k+lixi;
        ui->textEdit->append("还款总额："+area.setNum(sum1,'f',0)+" 元");
    }
    if(type==2)
    {
        monthk2=(sum*monthlv*pow(1+monthlv,time))/(pow(1+monthlv,time)-1);
        ui->textEdit->append("每月月供："+zong.setNum(monthk2,'f',0)+" 元");
        double li;
        li=monthk2*time-sum;
        ui->textEdit->append("支付利息："+zong.setNum(li,'f',0)+" 元");
        sum1=k+li;
        ui->textEdit->append("还款总额："+zong.setNum(sum1,'f',0)+" 元");
    }
}
void MainWindow::huank3(double sum1, double sum2, int time, double yearly1, double yearly2, int type)
{
    double ben1,monthk1,monthk2,monthk3,monthk4,ben2,sum,k;
    sum1*=10000;
    sum2*=10000;
    k=sum1+sum2;
    time*=12;
    double monthlv1=yearly1/1200.0;
    double monthlv2=yearly2/1200.0;
    QString zong;
    ui->textEdit->append("贷款总额："+zong.setNum(k,'f',0)+" 元");
    ui->textEdit->append("商贷总额："+zong.setNum(sum1,'f',0)+" 元");
    ui->textEdit->append("公积金总额："+zong.setNum(sum2,'f',0)+" 元");
    ui->textEdit->append("还款月数："+zong.setNum(time)+" 个");
    if(type==1)
    {
        ben1=sum1/time;
        ben2=sum2/time;
        //首月还款
        monthk1=sum1*monthlv1+ben1;
        monthk3=sum2*monthlv2+ben2;
        QString area;
        area.setNum(monthk1+monthk3);
        ui->textEdit->append("首月还款："+area.setNum(monthk1+monthk3,'f',0)+" 元");
        //每月递减
        double jian1,jian2;
        jian1=ben1*monthlv1;
        jian2=ben2*monthlv2;
        ui->textEdit->append("每月递减："+area.setNum(jian1+jian2,'f',0)+" 元");
        //支付利息
        double lixi1,lixi2;
        for(int i=0;i<time;i++)
        {
            lixi1+=sum1*monthlv1;
            lixi2+=sum2*monthlv2;
            sum1-=ben1;
            sum2-=ben2;
        }
        ui->textEdit->append("支付利息："+area.setNum(lixi1+lixi2,'f',0)+" 元");
        sum=k+lixi1+lixi2;
        ui->textEdit->append("还款总额："+area.setNum(sum,'f',0)+" 元");
    }
    if(type==2)
    {
        monthk2=(sum1*monthlv1*pow(1+monthlv1,time))/(pow(1+monthlv1,time)-1);
        monthk4=(sum2*monthlv2*pow(1+monthlv2,time))/(pow(1+monthlv2,time)-1);
        ui->textEdit->append("每月月供："+zong.setNum(monthk2+monthk4,'f',0)+" 元");
        double li1,li2;
        li1=monthk2*time-sum1;
        li2=monthk4*time-sum2;
        ui->textEdit->append("支付利息："+zong.setNum(li1+li2,'f',0)+" 元");
        sum=k+li1+li2;
        ui->textEdit->append("还款总额："+zong.setNum(sum,'f',0)+" 元");
    }
}
void MainWindow::on_ji1_currentIndexChanged(int index)
{
    if(index==1)
    {
        ui->stackedWidget->setCurrentIndex(1);
        ui->nian2->setText("25");
        ui->lilv2->setText("4.65");
    }
    if(index==0)
        ui->stackedWidget->setCurrentIndex(0);
}
void MainWindow::qingkong()
{
    ui->danjia1->setText("");
    ui->mianji1->setText("");
    ui->cheng1->setText("");
    ui->nian1->setText("");
    ui->lilv1->setText("");
    ui->zonge->setText("");
    ui->nian2->setText("");
    ui->lilv2->setText("");
    ui->fangz->setText("");
    ui->lilvs->setText("");
    ui->fangg->setText("");
    ui->lilvg->setText("");
    ui->nian3->setText("");
    ui->textEdit->setText("");
}
int MainWindow::panduan1()
{
    if(ui->danjia1->text().isEmpty()||ui->mianji1->text().isEmpty()||ui->cheng1->text().isEmpty()||ui->nian1->text().isEmpty()||ui->lilv1->text().isEmpty())
        return true;
    else
        return false;
}
int MainWindow::panduan2()
{
    if(ui->zonge->text().isEmpty()||ui->nian2->text().isEmpty()||ui->lilv2->text().isEmpty())
        return true;
    else
        return false;
}
int  MainWindow::panduan3()
{
    if(ui->fangz->text().isEmpty()||ui->fangg->text().isEmpty()||ui->lilvs->text().isEmpty()||ui->lilvg->text().isEmpty()||ui->nian3->text().isEmpty())
        return true;
    else
        return false;
}
void MainWindow::on_fang1_currentIndexChanged(int index)
{
    if(index==2)
    {
        ui->ji1->setCurrentIndex(1);
        ui->stackedWidget->setCurrentIndex(2);
        ui->lilvs->setText("3.25");
        ui->lilvg->setText("3.25");
        ui->nian3->setText("25");
    }
    if(index==0)
    {
        ui->ji1->setCurrentIndex(0);
        ui->stackedWidget->setCurrentIndex(0);
        ui->cheng1->setText("6.5");
        ui->nian1->setText("25");
        ui->lilv1->setText("4.65");
    }
    if(index==1)
    {
        ui->ji1->setCurrentIndex(0);
        ui->stackedWidget->setCurrentIndex(0);
        ui->cheng1->setText("6.5");
        ui->nian1->setText("25");
        ui->lilv1->setText("3.25");
    }
}
int MainWindow::panduanhk1()
{
    if(!ui->benjin->isChecked()&&!ui->benxi->isChecked())
        return true;
    else
        return false;
}
int MainWindow::panduanhk2()
{
    if(!ui->benjin2->isChecked()&&!ui->benxi2->isChecked())
        return true;
    else
        return false;
}
int MainWindow::panduanhk3()
{
    if(!ui->benjin3->isChecked()&&!ui->benxi3->isChecked())
        return true;
    else
        return false;
}

