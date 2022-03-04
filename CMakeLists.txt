cmake_minimum_required(VERSION 3.10)

# Remove when sharing with others.
list(APPEND CMAKE_PREFIX_PATH "/opt/QT/Tools/QtCreator")

project(Githubactionstest)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_CXX_STANDARD 17)

find_package(QtCreator COMPONENTS Core REQUIRED)
find_package(Qt6 COMPONENTS Test REQUIRED)
find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
set(QtX Qt${QT_VERSION_MAJOR})

option(WITH_TESTS "Build Tests" OFF)
add_feature_info("Build tests" ${WITH_TESTS} "")

add_qtc_plugin(Githubactionstest
  PLUGIN_DEPENDS
    QtCreator::Core
  DEPENDS
    ${QtX}::Widgets
    Qt6::Test
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

if (WITH_TESTS)
  set(IMPLICIT_DEPENDS Qt6::Test)
endif()

if (WITH_TESTS)
  enable_testing()
endif()

if (WITH_TESTS)
    add_qtc_test(Test
      DEPENDS Qt6::Core
      SOURCES tests/test.cpp
    )
endif()
