QT += core gui widgets network
TARGET = StoryCreator
TEMPLATE = app

SOURCES += src/main.cpp \
			src/helper.cpp \
			src/logger.cpp \
			src/main_window.cpp

HEADERS += src/helper.hpp \
			src/logger.hpp \
			src/main_window.hpp

RESOURCES += \
			resources.qrc