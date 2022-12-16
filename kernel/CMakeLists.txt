set(CMAKE_C_FLAGS "-O0 -g -ffreestanding -Wall -Wextra")
set(CMAKE_EXE_LINKER_FLAGS "-T ${CMAKE_CURRENT_SOURCE_DIR}/linker.ld -ffreestanding -nostdlib")

ENABLE_LANGUAGE(ASM)

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/include)

set(SOURCE_FILES
        src/arch/i686/start.S
        src/kernel.c
        src/log.c)

add_executable(kernel.elf ${SOURCE_FILES})
