QT += core
QT += network
QT += sql
QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle
CONFIG += sdk_no_version_check

CONFIG(release, debug|release):DEFINES += QT_NO_DEBUG_OUTPUT

DEFINES += THREAD_POOL_MAX=150

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG(release, debug|release):QMAKE_POST_LINK=$(STRIP) $(TARGET)

SOURCES += \
        ServiceTcp.cpp \
        ServiceTcpProcessor.cpp \
        ServiceTcpProcessorTask.cpp \
        main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    ServiceTcp.h \
    ServiceTcpProcessor.h \
    ServiceTcpProcessorTask.h
