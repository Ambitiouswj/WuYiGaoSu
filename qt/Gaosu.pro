QT       += core gui
QT       += charts
QT       += axcontainer
QT+=multimedia \
multimediawidgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    CPVRSet.cpp \
    Coord.cpp \
    Device.cpp \
    Record.cpp \
    SenPoint.cpp \
    chart.cpp \
    customslider.cpp \
    diagram.cpp \
    equip.cpp \
    equipment.cpp \
    equipment2.cpp \
    equipment3.cpp \
    equipshow.cpp \
    mediaplayer.cpp \
    testchart.cpp \
    addpoint.cpp \
    main.cpp \
    mainwindow.cpp \
    user.cpp \
    widget.cpp \
    widget2.cpp

HEADERS += \
    Main.h \
    chart.h \
    customslider.h \
    diagram.h \
    equip.h \
    equipment.h \
    equipment2.h \
    equipment3.h \
    equipshow.h \
    mediaplayer.h \
    testchart.h \
    addpoint.h \
    mainwindow.h \
    user.h \
    widget.h \
    widget2.h

FORMS += \
    chart.ui \
    customslider.ui \
    diagram.ui \
    equip.ui \
    equipment.ui \
    equipment2.ui \
    equipment3.ui \
    equipshow.ui \
    mediaplayer.ui \
    testchart.ui \
    addpoint.ui \
    mainwindow.ui \
    user.ui \
    widget.ui \
    widget2.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    covers.qrc \
    icon1.qrc \
    icons.qrc \
    pic.qrc \
    ttt.qrc
