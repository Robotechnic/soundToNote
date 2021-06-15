QT       += core gui charts multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
CONFIG += console

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    utils/fft.cpp \
    utils/frequencyparser.cpp \
    main.cpp \
    widgets/soundWidget.cpp \
    widgets/window.cpp

HEADERS += \
    utils/fft.h \
    utils/notesFrequency.h \
    utils/frequencyparser.h \
    widgets/soundWidget.h \
    widgets/window.h

FORMS += \
    ui/window.ui

TRANSLATIONS += \
    voiceToNote_fr_FR.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
	icons/icons.qrc
