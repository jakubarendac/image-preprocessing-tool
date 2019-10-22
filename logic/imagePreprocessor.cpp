#include "imagePreprocessor.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include "QGraphicsScene"
#include "QGraphicsView"
#include "QGraphicsPixmapItem"
#include "mainwindow.h"
#include <preprocessing.h>

ImagePreprocessor::ImagePreprocessor(QObject *parent) : QObject(parent)
{
    qRegisterMetaType<PREPROCESSING_RESULTS >("PREPROCESSING_RESULTS");
    connect(&this->p, SIGNAL(preprocessingDoneSignal(PREPROCESSING_RESULTS)), this, SLOT(preprocessingResultsSlot(PREPROCESSING_RESULTS)));
    connect(&this->p, SIGNAL(preprocessingErrorSignal(int)), this, SLOT(preprocessingErrorSlot(int)));
}

void ImagePreprocessor::loadImage(QString imgPath) {
    this->p.loadInput(imgPath);
    this->p.start();
}


void ImagePreprocessor::displayImage(cv::Mat image, string type) {
    cv::cvtColor(image,image, cv::COLOR_RGB2BGR);
    QGraphicsScene* scene = new QGraphicsScene();
    QGraphicsPixmapItem* item = new QGraphicsPixmapItem(QPixmap::fromImage(QImage((unsigned char*) image.data, image.cols, image.rows, QImage::Format_RGB888)));
    scene->addItem(item);

    emit preprocessingImageCreatedSignal(scene);
}

void ImagePreprocessor::preprocessingResultsSlot(PREPROCESSING_RESULTS result) {
    this->displayImage(result.imgSkeleton, "after");
}

void ImagePreprocessor::preprocessingErrorSlot(int errorcode) {
    std::cout << "error code " << errorcode;
}

