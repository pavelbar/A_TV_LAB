#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMainWindow>
#include <QMessageBox>
#include <QTableWidget>
#include <QPixmap>
#include <QTime>
#include <QGraphicsScene>

#include <tlist.h>
#include "ui_mainwindow.h"

/*
1. Как получить одинаковую выборку для отладки программы
2. Плостность равномерного распределия.
*/

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    struct ZVENO1
    {
     double left = 0;
     double right = 0;
    };
    TList<ZVENO1> intervalList;
    TList<double> verojatnosThList;
    double *verojatnosExpMas;
    int sizeMasVerojatnosExp = 0;
    TList<double> rndValList;

    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void slotExit()
    {
        close();
    }
    void  dClickT1(int row,int col)
    {
        QMessageBox helpT1;
        QPixmap myPixmap(":/helpT1.PNG");
        helpT1.setIconPixmap(myPixmap);
        helpT1.setText(tr(" "));
        helpT1.show();
        helpT1.exec();
    }

    void  dClick(int row,int col)
    {
        switch(col)
        {
          case 0:
            QMessageBox::warning(this, tr("Пояснение"),tr("Математическое ожидание E дискретной случайной величины η вычисляется как сумма произведений значений yi , которые принимает СВ η, на соответствующие вероятности ni:"));
            break;

          case 1:
            QMessageBox::warning(this, tr("Пояснение"),tr("Выборочное среднее значение это сумма всех разыгранных значений деленная на количество этих значений. "));
            break;

         // case 2:
        //    QMessageBox::warning(this, tr("Пояснение"),tr("2"));
         //   break;

        case 3:
        {
          QMessageBox help3;
          QPixmap myPixmap("://help3.PNG");
          help3.setIconPixmap(myPixmap);
          help3.setText(tr("Дисперсия - это мера разброса значений случайной величины η относительно ее математического ожидания  Eη. Не мб отрицательна. D(X)=M(X−M(X))^2"));
          help3.show();
          help3.exec();
          break;
        }

        case 4:
        {
          QMessageBox help4;
          QPixmap myPixmap(":/help4.PNG");
          help4.setIconPixmap(myPixmap);
          help4.setText(tr(" "));
          help4.show();
          help4.exec();
          break;
        }

       // case 5:
         // QMessageBox::warning(this, tr("Пояснение"),tr("5"));
         // break;

        case 6:
        {
          QMessageBox help6;
          QPixmap myPixmap(":/help6.PNG");
          help6.setIconPixmap(myPixmap);
          help6.setText(tr(" "));
          help6.show();
          help6.exec();
          break;
        }
        case 7:
          QMessageBox::warning(this, tr("Пояснение"),tr("Размах выборки - разница между макс и мин значением в выборке"));
          break;



        }
    }

private:
    Ui::MainWindow *ui;
    QString str_M;
    QString str_N;
    QString str_P;
    int int_M;
    int int_N;
    double double_P;

    int calcX(int X);
    int calcY(int Y);

    double MyRand(double fMin, double fMax)
    {
        double f = (double)rand() / RAND_MAX;
        return fMin + f * (fMax - fMin);
    }

    int CX(int n, int m)
    {
        int k = n - m;
        if (m > k)
            m = k;
        if (!m)
            return 1;
        int akk = k = n - m + 1, r1, r2;
        k++;
        for (int i = 2; i <= m; i++, k++)
        {
            if (!(r1 = akk % i))
            {
                akk = akk / i * k;
                continue;
            }
            if (!(r2 = k % i))
            {
                akk = k / i * akk;
                continue;
            }
            int t1 = akk / i, t2 = k / i;
            akk = t1 * t2 * i + t1 * r2 + t2 *r1 + r1 * r2 / i;
        }
        return akk;
    }

};

#endif // MAINWINDOW_H
