#-------------------------------------------------
#
# Project created by QtCreator 2019-10-19T20:24:54
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = image-preprocessing-tool
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        logic/imagePreprocessor.cpp \
        main.cpp \
        mainwindow.cpp

HEADERS += \
        logic/imagePreprocessor.h \
        mainwindow.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

# preprocessing lib related stuff

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../libs/build-Preprocessing-Desktop-Debug/release/ -lPreprocessing
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../libs/build-Preprocessing-Desktop-Debug/debug/ -lPreprocessing
else:unix: LIBS += -L$$PWD/../../libs/build-Preprocessing-Desktop-Debug/ -lPreprocessing

INCLUDEPATH += $$PWD/../../libs/openfinger-preprocessor
DEPENDPATH += $$PWD/../../libs/openfinger-preprocessor

QMAKE_CFLAGS_ISYSTEM=

#CUDA
unix:!macx: LIBS += -L/opt/cuda/lib64/ -lcudart
INCLUDEPATH += /opt/cuda/include
DEPENDPATH += /opt/cuda/include

#ArrayFire
unix:!macx: LIBS += -L/usr/lib64/ -lafcuda
INCLUDEPATH += /usr/include
DEPENDPATH += /usr/include

#OpenCV
unix:!macx: LIBS += -L/usr/lib64/ -lopencv_core
unix:!macx: LIBS += -L/usr/lib64/ -lopencv_imgproc
unix:!macx: LIBS += -L/usr/lib64/ -lopencv_imgcodecs
unix:!macx: LIBS += -L/usr/lib64/ -lopencv_highgui
INCLUDEPATH += /usr/include/opencv4

#Caffe
unix:!macx: LIBS += -L/usr/lib64/ -lcaffe
INCLUDEPATH += /usr/include
DEPENDPATH += /usr/include
