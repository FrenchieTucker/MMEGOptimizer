#-------------------------------------------------
#
# Project created by QtCreator 2019-04-11T00:46:02
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MMEGOptimizer
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
    AuraBase.cpp \
    AuraSkillUp.cpp \
    CreatureBaseStat.cpp \
    Creature_wdg.cpp \
    Guild.cpp \
    HeroicStat.cpp \
    ProcRuneParSubStat.cpp \
    Profile.cpp \
    PuissanceGlypheParNiveau.cpp \
    Rune.cpp \
    global.cpp \
        main.cpp \
    MMEGOptimizer_ctrl.cpp \
    MMEGOptimizer_wdg.cpp \
    Creature.cpp

HEADERS += \
    AuraBase.h \
    AuraSkillUp.h \
    CreatureBaseStat.h \
    Creature_wdg.h \
    Guild.h \
    HeroicStat.h \
    MMEGOptimizer_ctrl.h \
    MMEGOptimizer_wdg.h \
    ProcRuneParSubStat.h \
    Profile.h \
    PuissanceGlypheParNiveau.h \
    Rune.h \
    extractionProcess.h \
    Creature.h \
    global.h

FORMS += \
        Creature.ui \
        MMEGOptimizer.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

