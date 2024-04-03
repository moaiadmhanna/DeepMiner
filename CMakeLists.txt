cmake_minimum_required(VERSION 3.27)
project(DeepMiner)

set(CMAKE_CXX_STANDARD 17)

add_executable(DeepMiner main.cpp
        GameField.h
        GameField.cpp
        Defaults/defaults.h
        Defaults/defaults.h
        Defaults/defaults.cpp
        Bots/Miner.h
        Bots/Miner.cpp
        Bots/MinerBotsFabrik.h
        Bots/MinerBotsFabrik.cpp)
