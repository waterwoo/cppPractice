cmake_minimum_required(VERSION 3.16)
project(cppPractice)

set(CMAKE_CXX_STANDARD 17)

add_executable(cppPractice main.cpp sumOfTwoInt.cpp sumOfTwoInt.h
        climbStairs.cpp climbStairs.h minCostClimbingStairs.cpp
        minCostClimbingStairs.h numDecodings.cpp numDecodings.h
        binaryTreeNode.cpp binaryTreeNode.h licenseKeyFormatting.cpp
        licenseKeyFormatting.h solutions.cpp solutions.h myFirstStack.cpp myFirstStack.h
        myFirstQueue.cpp myFirstQueue.h MyCircularQueue.cpp MyCircularQueue.h MapSum.cpp MapSum.h bulbSwitch.cpp bulbSwitch.h TopVotedCandidate.cpp TopVotedCandidate.h)
