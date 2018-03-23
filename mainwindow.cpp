#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QShortcut>

const int lenX = 100;
const int lenY = 100;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->tableWidget_2, SIGNAL(cellDoubleClicked(int,int)), this, SLOT(dClick(int,int)));
    connect(ui->tableWidget, SIGNAL(cellDoubleClicked(int,int)), this, SLOT(dClickT1(int,int)));
    QShortcut *keyExit = new QShortcut(this);
    keyExit->setKey(Qt::Key_Escape);
    connect(keyExit, SIGNAL(activated()), this, SLOT(slotExit()));
}

MainWindow::~MainWindow()
{
    delete [] verojatnosExpMas;
    delete ui;
}

int MainWindow::calcX(int X)
{
    return X + lenX/2;
}

int MainWindow::calcY(int Y)
{
    return Y + lenY/2;
}

void MainWindow::on_pushButton_clicked()
{
    intervalList.DeleteAll();
    verojatnosThList.DeleteAll();
    rndValList.DeleteAll();

    str_M = ui->lineEdit_3->text();
    str_N = ui->lineEdit_2->text();
    str_P = ui->lineEdit->text();

    int_M = str_M.toInt();//?
    int_N = str_N.toInt();//?
    double_P = str_P.toDouble();//?

    sizeMasVerojatnosExp = int_N + 1;
    verojatnosExpMas = new double[sizeMasVerojatnosExp];
    for (int i = 0; i < sizeMasVerojatnosExp; i++)
        verojatnosExpMas[i] = 0;

    ui->tableWidget->setRowCount(int_N + 1);
    ui->tableWidget->setColumnCount(6);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << tr("yi (Значение сл.в.)") << tr("Вероятность Th") << tr("ni/M (Вероятность эксп)") << tr("ni (nj=число{xi:xi=yj}")<< tr("лев гр") << tr("прав гр"));
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    ui->tableWidget_2->setRowCount(1);
    ui->tableWidget_2->setColumnCount(8);
    ui->tableWidget_2->setHorizontalHeaderLabels(QStringList() << tr("Eη") << tr("_x") << tr("|Eη - _x|") << tr("Dη")<< tr("S^2") << tr("|Dη - _S^2|") << tr("_Me") << tr("_R") << tr("_R"));
    ui->tableWidget_2->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget_2->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    ui->tableWidget_3->setRowCount(int_M);
    ui->tableWidget_3->setColumnCount(1);
    ui->tableWidget_3->setHorizontalHeaderLabels(QStringList() << tr("Разыгранное значение"));
    ui->tableWidget_3->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget_3->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    ui->tableWidget_4->setRowCount(4);
    ui->tableWidget_4->setColumnCount(int_N + 1);
    ui->tableWidget_4->setVerticalHeaderLabels(QStringList() <<tr("yj") <<tr("P({η = yj}) (Aj)") <<tr("nj / M (Bj)") <<tr("|Aj - Bj| (Cj)"));
    ui->tableWidget_4->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget_4->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    //расчет вероятностей Th
    double  result = 0;
    for (int row = 0; row < ui->tableWidget->rowCount(); ++row)
    {
        result = CX(int_N,row) * pow(double_P,row) * pow(1-double_P,int_N-row);
        verojatnosThList.InSertLast(result);
    }


    //Рассчет вероятностей эксп
    ///         1. заполнение списка диапазонов
    ///
    ZVENO1 first;
    first.left = 0;
    first.right = verojatnosThList.GetElem(0);
    intervalList.InSertFirst(first);

    for (int row = 1; row < ui->tableWidget->rowCount(); ++row)
    {
        ZVENO1 newZ;
        newZ.left = intervalList.GetElem(row-1).left;
        newZ.right = intervalList.GetElem(row-1).right;

        newZ.left = newZ.left + verojatnosThList.GetElem(row-1);
        newZ.right =  newZ.right + verojatnosThList.GetElem(row);

        intervalList.InSertLast(newZ);
    }

    ///                 2. Розыгрыш значений
    double rnd = 0;
    ///                 3. Экспиримент
    int index = 0;
    for (int i = 0; i < int_M; i++)
    {
        rnd = MyRand(0,1);
        rndValList.InSertLast(rnd);
        index = -777;
        for (int row = 0; row < ui->tableWidget->rowCount(); row++)
            if ( (intervalList.GetElem(row).left <= rnd)  && (rnd < intervalList.GetElem(row).right) )
                index = row;
        if (rnd == 1) index = ui->tableWidget->rowCount() - 1;

        if (index == -777)
        {
            QMessageBox::warning(this, tr("Error"),tr("rnd=%1").arg(QString::number(rnd)));
            exit(0);
        }

        if (int_M != 0)
        {
            verojatnosExpMas[index]++;
        }
    }

    //-----------------------------

    double SumNi = 0;//
    double SumNiExpiriment = 0;//
    //Заполнение таблицы 1
    for (int row = 0; row < ui->tableWidget->rowCount(); ++row)
    {
        for (int column = 0; column < ui->tableWidget->columnCount(); ++column)
        {
            if (column == 0)
            {
                QTableWidgetItem *newItem;
                newItem = new QTableWidgetItem(tr(qPrintable(QString::number(row))));
                ui->tableWidget->setItem(row, column, newItem);

            }
            if (column == 1)
            {
                QTableWidgetItem *newItem;
                newItem = new QTableWidgetItem(tr(qPrintable(QString::number(verojatnosThList.GetElem(row)))));
                ui->tableWidget->setItem(row, column, newItem);
                SumNi = SumNi + verojatnosThList.GetElem(row);

            }
            if (column == 2)//вер эксп отношение
            {
                //
                QTableWidgetItem *newItem;
                newItem = new QTableWidgetItem(tr(qPrintable(QString::number(verojatnosExpMas[row]/int_M))));
                ui->tableWidget->setItem(row, column, newItem);
                SumNiExpiriment = SumNiExpiriment + verojatnosExpMas[row]/int_M;
            }
            if (column == 3)//кол во эксп
            {
                QTableWidgetItem *newItem;
                newItem = new QTableWidgetItem(tr(qPrintable(QString::number(verojatnosExpMas[row]))));
                ui->tableWidget->setItem(row, column, newItem);
            }
            if (column == 4)//лев
            {
                //
                QTableWidgetItem *newItem;
                newItem = new QTableWidgetItem(tr(qPrintable(QString::number(intervalList.GetElem(row).left))));
                ui->tableWidget->setItem(row, column, newItem);
            }

            if (column == 5)//прав
            {
                //
                QTableWidgetItem *newItem;
                newItem = new QTableWidgetItem(tr(qPrintable(QString::number(intervalList.GetElem(row).right))));
                ui->tableWidget->setItem(row, column, newItem);
            }

        }
    }

    //Заполнение таблицы 2
    for (int row = 0; row < ui->tableWidget_3->rowCount(); ++row)
    {
        for (int column = 0; column < ui->tableWidget_3->columnCount(); ++column)
        {
            QTableWidgetItem *newItem;
            newItem = new QTableWidgetItem(tr(qPrintable(QString::number(rndValList.GetElem(row)))));
            ui->tableWidget_3->setItem(row, column, newItem);
        }
    }

    ui->label_8->setText(QString::number(SumNi));
    ui->label_11->setText(QString::number(SumNiExpiriment));

    ///---------------------------------------------------------------------------------------------------------
    ///---------------------------------------------------------------------------------------------------------
    //------------------------------------------------ЧАСТЬ2----------------------------------------------------
    ///---------------------------------------------------------------------------------------------------------
    ///---------------------------------------------------------------------------------------------------------

    /*1. Eη */
    result = 0;
    QString arg1, arg2;
    for (int i = 0; i < ui->tableWidget->rowCount(); i++)
    {
        arg1 = ui->tableWidget->item(i, 0)->text();
        arg2 = ui->tableWidget->item(i, 2)->text();
        result = result + arg1.toDouble()*arg2.toDouble();
    }
    QTableWidgetItem *newItem;
    newItem = new QTableWidgetItem(tr(qPrintable(QString::number(result))));
    ui->tableWidget_2->setItem(0, 0, newItem);

    /*2. _x*/
    result = 0;
    for (int i = 0; i < ui->tableWidget_3->rowCount(); i++)
    {
        arg1 = ui->tableWidget_3->item(i, 0)->text();
        result = result + arg1.toDouble();
    }
    result = result / int_M;
    newItem = new QTableWidgetItem(tr(qPrintable(QString::number(result))));
    ui->tableWidget_2->setItem(0, 1, newItem);

    /*3. |Eη - _x|*/
    result = 0;
    arg1 = ui->tableWidget_2->item(0, 0)->text();
    arg2 = ui->tableWidget_2->item(0, 1)->text();
    result = arg1.toDouble() - arg2.toDouble();
    result = fabs(result);
    newItem = new QTableWidgetItem(tr(qPrintable(QString::number(result))));
    ui->tableWidget_2->setItem(0, 2, newItem);

    /*4. Dη*/
    result = 0;
    for (int i = 0; i < ui->tableWidget->rowCount(); i++)
    {
        arg1 = ui->tableWidget->item(i, 0)->text();
        arg2 = ui->tableWidget->item(i, 2)->text();
        result = result + pow(arg1.toDouble(),2) * arg2.toDouble();
    }
    result = result - pow(ui->tableWidget_2->item(0, 0)->text().toDouble(),2);
    newItem = new QTableWidgetItem(tr(qPrintable(QString::number(result))));
    ui->tableWidget_2->setItem(0, 3, newItem);

    /*5. S^2*/
    result = 0;
    for (int i = 0; i < ui->tableWidget_3->rowCount(); i++)
    {
        arg1 = ui->tableWidget_3->item(i, 0)->text();
        result = result + pow(arg1.toDouble() - ui->tableWidget_2->item(0, 1)->text().toDouble(), 2);
    }
    result = result / int_M;
    newItem = new QTableWidgetItem(tr(qPrintable(QString::number(result))));
    ui->tableWidget_2->setItem(0, 4, newItem);

    /*6. |Dη - S^2|*/
    result = 0;
    arg1 = ui->tableWidget_2->item(0, 3)->text();
    arg2 = ui->tableWidget_2->item(0, 4)->text();
    result = arg1.toDouble() - arg2.toDouble();
    result = fabs(result);
    newItem = new QTableWidgetItem(tr(qPrintable(QString::number(result))));
    ui->tableWidget_2->setItem(0, 5, newItem);

    /*7. _Me*/
    if (int_M == 0)
    {
        newItem = new QTableWidgetItem(tr(qPrintable("nan")));
        ui->tableWidget_2->setItem(0, 6, newItem);
    }
    else
    {
        if (int_M % 2 == 0) //чет
        {
            result =  ui->tableWidget_3->item(ui->tableWidget_3->rowCount()-1, 0)->text().toDouble() + ui->tableWidget_3->item(ui->tableWidget_3->rowCount()-2, 0)->text().toDouble();
            result = result/2;
        }
        else//нч
        {
            result =  ui->tableWidget_3->item(ui->tableWidget_3->rowCount()-1, 0)->text().toDouble();
        }
        newItem = new QTableWidgetItem(tr(qPrintable(QString::number(result))));
        ui->tableWidget_2->setItem(0, 6, newItem);
    }

    /*8. _R*/
    if (int_M == 0)
    {
        newItem = new QTableWidgetItem(tr(qPrintable("nan")));
        ui->tableWidget_2->setItem(0, 7, newItem);
    }
    else
    {
        double max = ui->tableWidget_3->item(0, 0)->text().toDouble();
        double min = ui->tableWidget_3->item(0, 0)->text().toDouble();
        for (int i = 1; i < ui->tableWidget_3->rowCount(); i++)
        {
            if (ui->tableWidget_3->item(i, 0)->text().toDouble() > max)
            {
                max = ui->tableWidget_3->item(i, 0)->text().toDouble();
            }
            if (ui->tableWidget_3->item(i, 0)->text().toDouble() < min)
            {
                min = ui->tableWidget_3->item(i, 0)->text().toDouble();
            }
        }
        newItem = new QTableWidgetItem(tr(qPrintable(QString::number(max - min))));
        ui->tableWidget_2->setItem(0, 7, newItem);
    }
    //Заполнение таблицы 2 задание 2
    {
        double max = 0;
        for (int row = 0; row < ui->tableWidget->rowCount(); ++row)
        {
            //стр1
            newItem = new QTableWidgetItem(tr(qPrintable(ui->tableWidget->item(row, 0)->text())));
            ui->tableWidget_4->setItem(0, row, newItem);
            //стр2
            arg1 = ui->tableWidget->item(row, 1)->text();
            newItem = new QTableWidgetItem(tr(qPrintable(arg1)));
            ui->tableWidget_4->setItem(1, row, newItem);
            //стр3
            arg2 = ui->tableWidget->item(row, 2)->text();
            newItem = new QTableWidgetItem(tr(qPrintable(arg2)));
            ui->tableWidget_4->setItem(2, row, newItem);
            //стр4
            result = fabs(arg1.toDouble() - arg2.toDouble());
            newItem = new QTableWidgetItem(tr(qPrintable(QString::number(result))));
            if (row == 0) max = result;
            if (result > max) max = result;
            ui->tableWidget_4->setItem(3, row, newItem);
        }

        ui->label_16->setText(QString::number(max));
    }

    //---------------------------------------------------------------------------------------
    //графики

    //---------------------------------------------------------------------------------------
    //Выборочная ф

    //---------------------------------------------------------------------------------------

    //Теоритическая ф распр
    //Рисуем график точками y=x*x

    //Сгенерируем данные
    //Для этого создадим два массива точек:
    //один для созранения x координат точек,
    //а второй для y соответственно

    double a = - 1; //Начало интервала, где рисуем график по оси Ox
    double b =  int_N + 1; //Конец интервала, где рисуем график по оси Ox
    double h = 0.1; //Шаг, с которым будем пробегать по оси Ox

    int N=(b-a)/h + 2; //Вычисляем количество точек, которые будем отрисовывать

    QVector<double> x(N), x2(N), y(N), y2(N); //Массивы координат точек

    //Вычисляем наши данные

    int i=0, i2 = 0;
    for (double X = a; X <= b; X =  X + h)//Пробегаем по всем точкам
    {
        //Th ф-я
        x[i] = X;
        //QMessageBox::warning(this, tr("Error"),tr("X=%1").arg(QString::number(X)));


        if (X <= 0)
        {
            y[i] = 0.0;
            x[i] = X;
            i++;
        }
        else
            if (X > int_N)
            {
                y[i] = 1.0;
                x[i] = X;
                i++;
            }
        else
            {
                for (int j = 0; j <= int_N - 1; j++)
                {
                    if ((X > j) && (X <= j+1))
                    {
                          x[i] = X;
                          y[i] = ui->tableWidget->item(j, 1)->text().toDouble();
                          i++;
                          break;
                    }
                }
            }
    //Выборочная ф-я

            result = 0;
            for (int k = 0; k < ui->tableWidget_3->rowCount(); k++)
            {
                arg1 = ui->tableWidget_3->item(k, 0)->text();
                if (arg1.toDouble() < X) result++;
            }
            x2[i2] = X;
            y2[i2] = result/int_M;
            i2++;
    }

    ui->widget->clearGraphs();//Если нужно, то очищаем все графики
    //Добавляем один график в widget
    ui->widget->addGraph();
        ui->widget->addGraph();

    //Говорим, что отрисовать нужно график по нашим двум массивам x и y
    ui->widget->graph(0)->setData(x, y);
    ui->widget->graph(1)->setData(x2, y2);

    ui->widget->graph(0)->setPen(QColor(255, 0, 0, 127));//задаем цвет точки
    ui->widget->graph(1)->setPen(QColor(0, 255, 0, 127));//задаем цвет точки

    ui->widget->graph(0)->setLineStyle(QCPGraph::lsNone);//убираем линии
    ui->widget->graph(1)->setLineStyle(QCPGraph::lsNone);//убираем линии
    //формируем вид точек
    ui->widget->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, 8));
    ui->widget->graph(1)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, 8));

    //Подписываем оси Ox и Oy
    ui->widget->xAxis->setLabel("x");
    ui->widget->yAxis->setLabel("F(x)");

    //Установим область, которая будет показываться на графике
    ui->widget->xAxis->setRange(a, b);//Для оси Ox

    //Для показа границ по оси Oy сложнее, так как надо по правильному
    //вычислить минимальное и максимальное значение в векторах
    double minY = y[0], maxY = y[0];
    for (int i=1; i<N; i++)
    {
        if (y[i]<minY) minY = y[i];
        if (y[i]>maxY) maxY = y[i];
    }
    ui->widget->yAxis->setRange(minY, maxY);//Для оси Oy

    //перерисуем график на нашем widget
    ui->widget->replot();
}
