find_program(CONAN conan)
if (NOT CONAN)
    message(FATAL_ERROR "CONAN IS NOT INSTALLED. INSTALL WITH: pip install conan")
endif ()

if (NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
    message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
    file(DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/master/conan.cmake"
            "${CMAKE_BINARY_DIR}/conan.cmake"
            EXPECTED_HASH SHA256=5cdb3042632da3efff558924eecefd580a0e786863a857ca097c3d1d43df5dcd
            TLS_VERIFY ON)
endif ()

include(${CMAKE_BINARY_DIR}/conan.cmake)

conan_add_remote(
        NAME
        bincrafters
        URL
        # https://api.bintray.com/conan/bincrafters/public-conan)
        https://conan.io/center/)

conan_cmake_run(CONANFILE ${CMAKE_SOURCE_DIR}/conanfile.txt
        BASIC_SETUP
        CMAKE_TARGETS
        BUILD missing)

include(${CMAKE_BINARY_DIR}/${library}/conanbuildinfo.cmake)
conan_basic_setup()
