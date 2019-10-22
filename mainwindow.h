#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "logic/imagePreprocessor.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setBeforeImage(QGraphicsScene *scene);
    void setAfterImage(QGraphicsScene *scene);

private slots:
    void on_loadFileButton_clicked();
    void on_preprocessFileButton_clicked();
    void preprocessingImageCreatedSlot(QGraphicsScene* image);

private:
    Ui::MainWindow *ui;
    ImagePreprocessor *preprocessor;
    QString imagePath;
};

#endif // MAINWINDOW_H
