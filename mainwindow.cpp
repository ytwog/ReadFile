#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <fstream>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <clocale>
#include <cstring>
#include <QChar>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_ofstream_clicked()
{
    /*QFile file("refined.txt");
    file.open(QIODevice::WriteOnly);
    QTextStream out(&file);
    QVector <QString> wordsVector;
    QString line = file.readLine();
     while(!line.isNull())
     {
     QStringList words = line.split(' ', QString::SkipEmptyParts);
     for (int i = 0; i < words.size(); ++i)
     {
         wordsVector.push_back(words[i]);
     }
     line = file.readLine();
     }
     for(int i=0;i<wordsVector.size();i++){

         ui->refinedtxt->setText(wordsVector[i]);
     }
    file.close();*/
}


void MainWindow::on_ifstream1_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Выберите файл"), "C:\\QTprojects\\ReadFile","Text File(*.txt)");
    QFile file(filename);
    file.open(QIODevice::ReadWrite);
    QTextStream in(&file);
    QString text = in.readAll();
    ui->sourcetxt->setText(text);
    file.flush();
    file.close();
    QStringList list = text.split(QRegExp("\\b"));
    setlocale(LC_ALL, "Russian");
   QChar vowels[20] = {L'о','е','а','и','ё','у','ы','ю','э','я','О','Е','А','И','Ё','У','Ы','Ю','Э','Я'};
  /*QString vowels=  QString::fromUtf8("оеаиёуыюэяОЕАИЁУЫЮЭЯ");
 QString::fromLocal8Bit("[оеаиёуыюэяОЕАИЁУЫЮЭЯ]");*/

    int key=3, count = 0,ind=0;

    QStringList::iterator it;
    for (it = list.begin(); it != list.end(); ++it)
    {
        count=0;
        QString word = *it;
        std::string str = word.toStdString();
        for(int i = 0; i < word.size();i++)
        {
            for(int j = 0; j <20;j++ )
            {
               if((str[i])==(vowels[j]))
            {
                count++;
            }
            }
        }
        if(count==key){list.removeAt(ind);}
        ind++;
    }


    QString retext = list.join("");
    ui->refinedtxt->setText(retext);

}
