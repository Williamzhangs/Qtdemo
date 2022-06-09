#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLineSeries>
#include <QSplineSeries>
#include <QValueAxis>
#include <QCategoryAxis>
#include <QColorDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->tableWidget->setColumnCount(3);  //设置列数
    QStringList headText = QStringList() << QStringLiteral("星期") << QStringLiteral("最低气温")<< QStringLiteral("最高气温");
    ui->tableWidget->setHorizontalHeaderLabels(headText);  //设置水平标签
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);  //不懂

    ui->tableWidget->setRowCount(7);  //设置行数

    two << "周一"<<"周二"<< "周三" << "周四" << "周五" << "周六" << "周日";
    one << "4" << "2" << "5" <<"1" << "5" << "2" << "5";
    five << "11" << "12" << "18" << "14" << "15" << "18" << "17";

    for(int i =0;i <7;i++)
    {
        int col = 0;
        ui->tableWidget->setItem(i,col++,new QTableWidgetItem(two.at(i)));
        ui->tableWidget->setItem(i,col++,new QTableWidgetItem(one.at(i)));
        ui->tableWidget->setItem(i,col++,new QTableWidgetItem(five.at(i)));
    }
    ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    createQsplineSeries();  //调用函数
}

void MainWindow::createQsplineSeries()
{
    ui->picture->setRenderHint(QPainter::Antialiasing,true);
    ui->picture->chart()->setTitle(QStringLiteral("QSplineSeries演示"));
    ui->picture->chart()->setTheme(QChart::ChartThemeDark);

    //创建坐标轴
    QValueAxis *axisX = new QValueAxis;
    axisX->setRange(0,6);
    QValueAxis *axisY = new QValueAxis;
    axisY->setRange(0,40);

    //创建光滑曲线序列，并添加数据
    QSplineSeries *splineSer = new QSplineSeries;//ddddd
    splineSer->setName(QStringLiteral("最高温"));

    for(int i =0;i<ui->tableWidget->rowCount();i++)
    {
        splineSer->append(i,ui->tableWidget->item(i,2)->text().toInt());
    }
    ui->picture->chart()->addSeries(splineSer);
    ui->picture->chart()->setAxisX(axisX,splineSer);
    ui->picture->chart()->setAxisY(axisY,splineSer);

    //创建折现序列
    QSplineSeries *splineSer1 = new QSplineSeries;
    splineSer1->setName(QStringLiteral("最低温"));
    for(int i =0;i<ui->tableWidget->rowCount();i++)
    {
        splineSer1->append(i,ui->tableWidget->item(i,1)->text().toInt());
    }
    ui->picture->chart()->addSeries(splineSer1);
    ui->picture->chart()->setAxisX(axisX,splineSer1);
    ui->picture->chart()->setAxisY(axisY,splineSer1);
}

MainWindow::~MainWindow()
{
    delete ui;
}

