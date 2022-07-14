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
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_boton_recarga_10_clicked();

    void on_boton_recarga_5_clicked();

    void on_boton_recarga_2_clicked();

    void on_boton_recarga_1_clicked();

    void on_cambio_a_monedas_clicked();

    void on_boton_jugar_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
