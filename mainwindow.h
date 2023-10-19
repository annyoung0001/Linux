#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QStringList>
#include <QString>
#include <QComboBox>
#include <QMessageBox>
#include <QPlainTextEdit>
//********* *Charts*****************//
#include <QtCharts/QChartView>
#include <QtCharts/QSplineSeries>
#include <QTimer>
#include <QtCharts/QChart>
#include <QValueAxis>
#include <QGraphicsView>
#include <QChart>//图表
#include <QtDataVisualization>
#define MAX_X 100
#define MAX_Y 10
QT_BEGIN_NAMESPACE


QT_CHARTS_USE_NAMESPACE
namespace Ui { class MainWindow; }
using namespace QtDataVisualization;
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QChart *chart;
    QSplineSeries *splineserives;
    QTimer *s_timer;
    QTimer *rec_timer;
     int buf1 = 0;
     int dataread = 0;
     QByteArray buf;
     QByteArray databuf;

     QSerialPort *Serialport;
     QLabel *label_7; // 声明一个指向Label控件的指针
     QLabel *dataget; // 声明一个指向Label控件的指针
     int data_get1,data_get2=0,data_get3=0,data_get4=0,data_get5=0;
     int data_get6=0,data_get7=0,data_get8=0,data_get9=0,data_get10=0;
     int data_get11=0,data_get12=0,data_get13=0,data_get14=0,data_get15=0,data_get16=0;
private slots:
    void on_cont_B_clicked();
    void serialportread();
    void on_Close_B_clicked();
    void Chart_Init();
    void DrawLine();
    void TimeOut();
    void TimeRead();

    void data_get();
    void String_proess();
private:
    Ui::MainWindow *ui;


    QWidget *graphContainer;//图表的容器
    Q3DBars *graph3D;       //图表
    QBar3DSeries *series;   //序列

    void iniGraph3D();


};
#endif // MAINWINDOW_H
