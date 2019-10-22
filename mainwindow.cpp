#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <preprocessing.h>
#include <QGraphicsScene>
#include <QFileDialog>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include "logic/imagePreprocessor.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->preprocessor = new ImagePreprocessor();
    connect(this->preprocessor, SIGNAL(preprocessingImageCreatedSignal(QGraphicsScene*)), this, SLOT(preprocessingImageCreatedSlot(QGraphicsScene*)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setBeforeImage(QGraphicsScene *scene) {
    ui->beforeImage->setScene(scene);
}

void MainWindow::setAfterImage(QGraphicsScene *scene) {
    ui->afterImage->setScene(scene);
}


void MainWindow::on_loadFileButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open file"));
    QGraphicsScene* scene = new QGraphicsScene();
    QGraphicsPixmapItem* item = new QGraphicsPixmapItem(QPixmap(fileName));
    scene->addItem(item);

    this->setBeforeImage(scene);
    this->imagePath = fileName;
    this->setAfterImage(nullptr);
    this->ui->preprocessFileButton->setDisabled(false);
}

void MainWindow::on_preprocessFileButton_clicked()
{
    this->preprocessor->loadImage(this->imagePath);
    this->ui->preprocessFileButton->setDisabled(true);
}

void MainWindow::preprocessingImageCreatedSlot(QGraphicsScene *image) {
    this->setAfterImage(image);
}
