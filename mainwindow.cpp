#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <qthread.h>
 #include <QThread>

class Sleeper : public QThread { public: static void usleep(unsigned long usecs){QThread::usleep(usecs);} static void msleep(unsigned long msecs){QThread::msleep(msecs);} static void sleep(unsigned long secs){QThread::sleep(secs);} };

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),

    ui(new Ui::MainWindow)
{    
    ui->setupUi(this);
    QPixmap pix(":/arcade.png");
    ui->fondo->setScaledContents(1);
    ui->fondo->setPixmap(pix);

}

MainWindow::~MainWindow()
{
    delete ui;
}

int creditos=0;

void MainWindow::on_boton_recarga_10_clicked()
{
    creditos+=10;
    ui->mostrar_creditos->setText(QString::number(creditos));
}

void MainWindow::on_boton_recarga_5_clicked()
{
    creditos+=5;
    ui->mostrar_creditos->setText(QString::number(creditos));
}

void MainWindow::on_boton_recarga_2_clicked()
{
    creditos+=2;
    ui->mostrar_creditos->setText(QString::number(creditos));
}

void MainWindow::on_boton_recarga_1_clicked()
{
    creditos+=1;
    ui->mostrar_creditos->setText(QString::number(creditos));

}



void MainWindow::on_cambio_a_monedas_clicked()
{
    if(creditos==0){
        QMessageBox msg2;
       msg2.setText("Tienes cero creditos");
         msg2.exec();
    }else {


#define MONEDAS 5
    int monedas[]={20,10,5,2,1};
QString g_cambio;
QString temp;
QMessageBox mbox;

if(ui->dar_de_20->isChecked()){
//nada
}else {
    if(ui->dar_de_10->isChecked()){
    monedas[0] = monedas[1];
    }else {
        if(ui->dar_de_5->isChecked()){
    monedas[0] = monedas[2];
        }else {
            if(ui->dar_de_2->isChecked()){
                monedas[0] = monedas[3];
            }else{
                monedas[0] = monedas[4];
            }
}
}
}
if(ui->dar_de_10->isChecked()){
//nada
}else {
    if(ui->dar_de_5->isChecked()){
        monedas[1]=monedas[2];
    }else{
            if(ui->dar_de_2->isChecked()){
                monedas[1]=monedas[3];
            }else {
        monedas[1]=monedas[4];
}

    }
}
if(ui->dar_de_5->isChecked()){
//nada
}else {
    if(ui->dar_de_2->isChecked()){
        monedas[2]=monedas[3];
    }else {
monedas[2] = monedas[4];
}
}
if(ui->dar_de_2->isChecked()){
//nada
}else {
   monedas[3]=monedas[4];
}

int solucion[MONEDAS];

   int i, devolucion;
   devolucion=creditos;   
   for (i = 0; i < MONEDAS; i++){
      solucion[i] =0;
   }
//borra datos basura




   //incia buble voraz
   for (i = 0; i < MONEDAS; i++){
      while (devolucion >= monedas[i])
      {
         solucion[i]++;
         devolucion-= monedas[i];
      }
   }
   //fin
   if (devolucion){

   }else{      
      for (i = 0; i < MONEDAS; i++){
         if (solucion[i]&&solucion[i]!=solucion[i+1]){
             temp = "Recibes "+QString::number(solucion[i])+" de "+QString::number(monedas[i])+"  "+"\n";
             g_cambio+=temp;
         }
      }
mbox.setText(g_cambio);
mbox.exec();
creditos=0;
ui->mostrar_creditos->setText(QString::number(creditos));
}
    }
}

void MainWindow::on_boton_jugar_clicked()
{
    int ran,ran2,ran3;
    QPixmap pm1(":/1.png");
    QPixmap pm2(":/2.png");
    QPixmap pm3(":/3.png");
    QPixmap pm4(":/4.png");
    QPixmap pm5(":/5.png");

   QMessageBox mbox;
   if(creditos<7){
       mbox.setText("NECESITAS 7 CREDITOS\n PARA JUGAR");
        mbox.exec();
   }else {
       creditos-=7;
       ui->mostrar_creditos->setText(QString::number(creditos));
      ran = 1 + rand() % (6 - 1);
      ui->imagen_1->setScaledContents(1);
      switch(ran){
      case 1:{
          ui->imagen_1->setPixmap(pm1);          
      }break;
      case 2:{
ui->imagen_1->setPixmap(pm2);
      }break;
      case 3:{
ui->imagen_1->setPixmap(pm3);
      }break;
      case 4:{
ui->imagen_1->setPixmap(pm4);
      }break;
      case 5:{
ui->imagen_1->setPixmap(pm5);
      }break;
      }
      ui->imagen_2->setScaledContents(1);
      //Sleep(2000);
      ui->imagen_2->setPixmap(pm1);
ran2 = 1 + rand() % (6 - 1);
//Sleeper::sleep(2);
      switch(ran2){
      case 1:{
          ui->imagen_2->setPixmap(pm1);
      }break;
      case 2:{
ui->imagen_2->setPixmap(pm2);

      }break;
      case 3:{
ui->imagen_2->setPixmap(pm3);
      }break;
      case 4:{
ui->imagen_2->setPixmap(pm4);
      }break;
      case 5:{
ui->imagen_2->setPixmap(pm5);
      }break;
      }

      ui->imagen_3->setScaledContents(1);     
      ui->imagen_3->setPixmap(pm1);
      ran3 = 1 + rand() % (6 - 1);
//Sleeper::sleep(2);
        switch(ran3){
      case 1:{
          ui->imagen_3->setPixmap(pm1);         
      }break;
      case 2:{
ui->imagen_3->setPixmap(pm2);
      }break;
      case 3:{
ui->imagen_3->setPixmap(pm3);
      }break;
      case 4:{
ui->imagen_3->setPixmap(pm4);
      }break;
      case 5:{
ui->imagen_3->setPixmap(pm5);
      }break;
      }
}
   if(ran==ran2&&ran==ran3){
       QMessageBox qmb2;
       qmb2.setText("Felicidades\nGanaste 175 creditos");
       creditos+=175;
       ui->mostrar_creditos->setText(QString::number(creditos));
       qmb2.exec();

   }else if (ran==ran2||ran==ran3) {
       QMessageBox qmb2;
       qmb2.setText("Felicidades\nGanaste 101 creditos");
       creditos+=101;
       ui->mostrar_creditos->setText(QString::number(creditos));
       qmb2.exec();
}else if (ran2==ran||ran2==ran3) {
       QMessageBox qmb2;
       qmb2.setText("Felicidades\nGanaste 101 creditos");
       creditos+=101;
       ui->mostrar_creditos->setText(QString::number(creditos));
       qmb2.exec();
}else if (ran3==ran2||ran3==ran) {
       QMessageBox qmb2;
       qmb2.setText("Felicidades\nGanaste 101 creditos");
       creditos+=101;
       ui->mostrar_creditos->setText(QString::number(creditos));
       qmb2.exec();
}

}
