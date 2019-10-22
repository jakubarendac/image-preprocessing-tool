#include <preprocessing.h>
#include <QGraphicsScene>
#ifndef IMAGEPREPROCESSOR_H
#define IMAGEPREPROCESSOR_H

class ImagePreprocessor: public QObject
{
    Q_OBJECT

private:
    Preprocessing p;

    void displayImage(cv::Mat image, string type);
private slots:
    void preprocessingResultsSlot(PREPROCESSING_RESULTS result);
    void preprocessingErrorSlot(int errorcode);
public:
    ImagePreprocessor(QObject *parent = nullptr);
    void loadImage(QString imgPath);
signals:
    void preprocessingImageCreatedSignal(QGraphicsScene* image);
};

#endif // IMAGEPREPROCESSOR_H
