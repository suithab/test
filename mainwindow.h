#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void huank1(double sum, int time, double yearlv, int type);
    void huank2(long dan, int mian, double cheng, int time, double yearlv, int type);
    void huank3(double sum1,double sum2,int time,double yearly1,double yearly2,int type);
    int huankuanfangshi;
    void qingkong();
    int panduan1();
    int panduan2();
    int panduan3();
    int panduanhk1();
    int panduanhk2();
    int panduanhk3();
private slots:
    void on_ji1_currentIndexChanged(int index);

    void on_fang1_currentIndexChanged(int index);

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
