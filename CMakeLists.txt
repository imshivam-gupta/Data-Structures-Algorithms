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
        DynamicProgramming/CSES/ArrayDescription.cpp
        Graphs/CSES/Monsters.cpp
        Graphs/Learning/AdjacencyMatrixRep.cpp
        Graphs/Learning/formatted.cpp
        Graphs/Learning/AdjacencyListRep.cpp
        Graphs/Learning/BFS.cpp
        GenericTrees/CSES/Subordinates.cpp
        GenericTrees/CSES/csesformat.cpp
        GenericTrees/CSES/TreeMatching.cpp
        GenericTrees/CSES/TreeDiameter.cpp
        GenericTrees/CSES/TreeDistanceI.cpp
        GenericTrees/CSES/TreeDistanceII.cpp
        GenericTrees/Learning/Traversal.cpp
        GenericTrees/Learning/LCA.cpp
)
