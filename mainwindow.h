#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCharts/QtCharts>  //头文件

using namespace QtCharts;  //命名空间

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

    //slots槽函数
    void on_btnSlinecolor_clicked();
    void on_btnsplinepointcolor_clicked();
    void on_chkdatapoint_statechanged();
    void on_chkdatapointlabelvisible_statechanged();

    void createQsplineSeries();

private:
    Ui::MainWindow *ui;

    QStringList two;
    QStringList one;
    QStringList five;

};
#endif // MAINWINDOW_H
