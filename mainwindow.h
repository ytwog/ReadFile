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

    void GetText(QString filename = "text.txt");

private slots:
    void on_ifstream1_clicked();
    void on_ofstream_clicked();


    void on_ifstream1_2_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
