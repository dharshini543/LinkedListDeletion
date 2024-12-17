cmake_minimum_required(VERSION 3.16)

project(LinkedListDeletion LANGUAGES C)

add_executable(LinkedListDeletion main.c)

include(GNUInstallDirs)
install(TARGETS LinkedListDeletion
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
