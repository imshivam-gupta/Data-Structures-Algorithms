cmake_minimum_required(VERSION 3.28)
project(DSA)

set(CMAKE_CXX_STANDARD 17)

add_executable(DSA main.cpp
        DynamicProgramming/CSES/CoinCombinationsI.cpp
        DynamicProgramming/CSES/DiceCombinations.cpp
        DynamicProgramming/CSES/MinimizingCoins.cpp
        DynamicProgramming/CSES/CoinCombinationsII.cpp
        Adhoc/SpecialSubset.cpp
        DynamicProgramming/CSES/RemovingDigits.cpp
        DynamicProgramming/CSES/GridPaths.cpp
        DynamicProgramming/CSES/BookShop.cpp
)
