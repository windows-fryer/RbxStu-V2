cmake_minimum_required(VERSION 3.26)
project(Module)

add_definitions(-DLUAI_GCMETRICS)   # Force GC metrics on Luau.

set(BUILD_SHARED_LIBS OFF)
set(PROJECT_NAME Module)
set(CMAKE_CXX_STANDARD 23)

add_library(Module SHARED
        main.cpp
        Logger.cpp
        Logger.hpp
        Scanner.cpp
        Scanner.hpp
        Utilities.cpp
        Utilities.hpp
        RobloxManager.cpp
        RobloxManager.hpp
        Roblox/TypeDefinitions.hpp
        Roblox/TypeDefinitions.hpp
        LuauManager.cpp
        LuauManager.hpp
        Scheduler.hpp
        Scheduler.cpp
        Security.hpp
        Security.cpp
        Communication.cpp
        Communication.hpp
        Environment/EnvironmentManager.cpp
        Environment/EnvironmentManager.hpp
        Environment/Libraries/Globals.cpp
        Environment/Libraries/Globals.hpp
        Environment/Libraries/Debug.cpp
        Environment/Libraries/Debug.hpp
        Environment/Libraries/Filesystem.cpp
        Environment/Libraries/Filesystem.hpp
        ClosureManager.cpp
        ClosureManager.hpp
        Environment/Libraries/Closures.cpp
        Environment/Libraries/Closures.hpp
        Environment/Libraries/Metatable.cpp
        Environment/Libraries/Metatable.hpp
        Environment/Libraries/Cache.cpp
        Environment/Libraries/Cache.hpp
        Environment/Libraries/Console.cpp
        Environment/Libraries/Console.hpp
        Environment/Libraries/Script.cpp
        Environment/Libraries/Script.hpp
        Environment/Libraries/Misc.cpp
        Environment/Libraries/Misc.hpp
        Environment/Libraries/Instance.cpp
        Environment/Libraries/Instance.hpp
        Environment/Libraries/Input.cpp
        Environment/Libraries/Input.hpp
        Disassembler/Disassembler.cpp
        Disassembler/Disassembler.hpp
        Disassembler/DisassemblyRequest.hpp
        Disassembler/DisassembledChunk.cpp
        Disassembler/DisassembledChunk.hpp
)
target_include_directories(Module PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(Module PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/Dependencies")
# Dependencies


# Curl For People
# FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git
#         GIT_TAG 3b15fa82ea74739b574d705fea44959b58142eb8)
# FetchContent_MakeAvailable(cpr)

#rcmp
# FetchContent_Declare(rcmp GIT_REPOSITORY https://github.com/Smertig/rcmp.git
#         GIT_TAG f5f75ae00a57c67fe41f79fd59c4b7f6997b999e)
# FetchContent_MakeAvailable(rcmp)

# cpr
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/Dependencies/cpr")

# Luau
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/Dependencies/Luau")

# minhook
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/Dependencies/Minhook")

# IXWebSocket
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/Dependencies/IXWebSocket")

# cryptopp
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/Dependencies/cryptopp-cmake")

# capstone
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/Dependencies/Capstone")

find_package(lz4 CONFIG REQUIRED)
find_package(OpenSSL CONFIG REQUIRED)

target_link_libraries(${PROJECT_NAME}
        PRIVATE
        # minhook
        minhook
        # Curl For People
        cpr::cpr

        # Luau
        Luau.Compiler
        Luau.Ast
        # Luau.Analysis
        Luau.VM
        Luau.VM.Internals
        Luau.EqSat
        Luau.CodeGen

        Dbghelp.lib

        ixwebsocket

        lz4::lz4

        cryptopp::cryptopp

        capstone
)

