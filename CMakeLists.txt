cmake_minimum_required(VERSION 3.16)

set(CMAKE_SYSTEM_NAME "huangmei")
set(CMAKE_SYSTEM_PROCESSOR "i686")
set(CMAKE_C_COMPILER "i686-elf-gcc")
set(CMAKE_CXX_COMPILER "i686-elf-g++")
set(CMAKE_ASM_COMPILER "i686-elf-gcc")
SET(CMAKE_C_COMPILER_WORKS 1)
SET(CMAKE_CXX_COMPILER_WORKS 1)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_C_STANDARD 11)
set(CMAKE_VERBOSE_MAKEFILE ON)

project(huangmei)

add_subdirectory(kernel)

add_custom_target(image)
add_custom_command(
        TARGET image
        COMMAND mkdir -p ${CMAKE_BINARY_DIR}/iso
        COMMAND cp -r ${CMAKE_SOURCE_DIR}/meta/boot ${CMAKE_BINARY_DIR}/iso
        COMMAND cp ${CMAKE_BINARY_DIR}/kernel/kernel.elf ${CMAKE_BINARY_DIR}/iso
        COMMAND grub-mkrescue -o Huangmei.iso ${CMAKE_BINARY_DIR}/iso
)

add_custom_target(install-toolchain)
add_custom_command(
        TARGET install-toolchain
        COMMAND bash ${CMAKE_SOURCE_DIR}/meta/cross/install-toolchain.sh
)

add_custom_target(qemu DEPENDS image)
add_custom_command(
        TARGET qemu
        COMMENT "Running Huangmei in qemu"
        COMMAND qemu-system-i386 -cdrom Huangmei.iso
)

add_custom_target(qemu-curses DEPENDS image)
add_custom_command(
        TARGET qemu-curses
        COMMENT "Running Huangmei in qemu"
        COMMAND qemu-system-i386 -cdrom Huangmei.iso -curses
)
