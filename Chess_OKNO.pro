QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += main.cpp\
    bishop.cpp \
    game.cpp \
    horse.cpp \
    king.cpp \
        mainwindow.cpp \
    pawn.cpp \
    piece.cpp \
    player.cpp \
    queen.cpp \
    ranking.cpp \
    rook.cpp \
    tile.cpp

HEADERS  += mainwindow.h \
    bishop.h \
    game.h \
    horse.h \
    king.h \
    pawn.h \
    piece.h \
    player.h \
    queen.h \
    ranking.h \
    rook.h \
    tile.h

RESOURCES += \
    Images.qrc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
