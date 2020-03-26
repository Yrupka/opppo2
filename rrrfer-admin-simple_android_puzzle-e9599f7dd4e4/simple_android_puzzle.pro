QT += core gui sql
QT += widgets multimedia sql

QMAKE_CXXFLAGS += -std=c++17

TARGET = puzzle
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
    main.cpp \
    game/pathpoints.cpp \
    game/puzzlepath.cpp \
    game/puzzlegame.cpp \
    game/itemground.cpp \
    game/random_points.cpp \
    game/puzzleview.cpp \
    game/puzzleitem/puzzleitem.cpp \
    game/puzzleitem/selectableitem.cpp \
    game/puzzleitem/rotatableitem.cpp \
    game/puzzleitem/movableitem.cpp \
    game/puzzleitem/settableitem.cpp \
    game/puzzleitem/puzzlematrix.cpp \
    menu/levelmodewidget.cpp \
    menu/style_button/mainmenubutton.cpp \
    menu/style_button/pickedbutton.cpp \
    menu/style_button/modebutton.cpp \
    menu/mainmenuwidget.cpp \
    screencontroller.cpp \
    screensstack.cpp \
    sound_controller/media.cpp \
    sound_controller/soundcontroller.cpp \
    sound_controller/universalmodebutton.cpp \
    statobject.cpp \
    statwidget.cpp \
    tutorialviewer/helpviewer.cpp \
    tutorialviewer/scrolledtextbrowser.cpp \
    menu/style_button/statisticlabel.cpp

HEADERS += \
    game/pathpoints.h \
    game/puzzlepath.h \
    game/puzzlegame.h \
    game/itemground.h \
    game/random_points.h \
    game/puzzleview.h \
    game/itemground.h \
    game/puzzleitem/puzzleitem.h \
    game/puzzleitem/selectableitem.h \
    game/puzzleitem/rotatableitem.h \
    game/puzzleitem/movableitem.h \
    game/puzzleitem/settableitem.h \
    game/puzzleitem/puzzlematrix.h \
    image_picker/iimagepicker.h \
    image_picker/imagepickerdesktop.h \
    menu/levelmodewidget.h \
    menu/style_button/mainmenubutton.h \
    menu/style_button/pickedbutton.h \
    menu/style_button/modebutton.h \
    mode.h \
    menu/levelmodewidget.h \
    screencontroller.h \
    screensstack.h \
    singleton.h \
    sound_controller/media.h \
    sound_controller/soundcontroller.h \
    sound_controller/universalmodebutton.h \
    statobject.h \
    statwidget.h \
    tutorialviewer/helpviewer.h \
    menu/mainmenuwidget.h \
    tutorialviewer/scrolledtextbrowser.h \
    menu/style_button/statisticslabel.h

RESOURCES += \
    resources/resources.qrc

android {
  QT += androidextras

  HEADERS += \
    image_picker/imagepickerandroid.h

  ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android

  DISTFILES += \
    android/AndroidManifest.xml \
    android/gradle/wrapper/gradle-wrapper.jar \
    android/gradlew \
    android/src/lqsa/util/ImageFromActivityResult.java \
    android/res/values/libs.xml \
    android/build.gradle \
    android/gradle/wrapper/gradle-wrapper.properties \
    android/gradlew.bat \
    android/gradle.properties \
    _build/android-build/gradle/wrapper/gradle-4.6-bin.zip.
}

!android {

}




