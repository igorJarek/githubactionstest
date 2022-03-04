cmake_minimum_required(VERSION 3.10)

# Remove when sharing with others.
list(APPEND CMAKE_PREFIX_PATH "/opt/QT/Tools/QtCreator")

project(Githubactionstest)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_CXX_STANDARD 17)

find_package(QtCreator COMPONENTS Core REQUIRED)
find_package(Qt5 COMPONENTS Test REQUIRED)
find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
set(QtX Qt${QT_VERSION_MAJOR})

option(WITH_TESTS "Build Tests" OFF)
add_feature_info("Build tests" ${WITH_TESTS} "")

if (WITH_TESTS)
    set(IMPLICIT_DEPENDS Qt5::Test)
endif()

if (WITH_TESTS)
  enable_testing()
endif()

add_qtc_plugin(Githubactionstest
  PLUGIN_DEPENDS
    QtCreator::Core
  DEPENDS
    ${QtX}::Widgets
    QtCreator::ExtensionSystem
    QtCreator::Utils
  SOURCES
    .github/workflows/build_cmake.yml
    .github/workflows/README.md
    README.md
    githubactionstest.cpp
    githubactionstest.h
    githubactionstest_global.h
    githubactionstestconstants.h
)

add_qtc_test(tst_filesearch
  DEPENDS Utils
  SOURCES
    tst_filesearch.cpp
    tst_filesearch.qrc
)

if (WITH_TESTS)
    add_qtc_test(TestCase
      DEPENDS Qt6::Core
      SOURCES test.cpp
    )
endif()
