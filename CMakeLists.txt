cmake_minimum_required(VERSION 3.13)
project(Hirolsy)

set(CMAKE_CXX_STANDARD 17)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
add_executable(Hirolsy main.cpp Game.cpp Game.h GUI/StateMachine.cpp GUI/StateMachine.h GUI/GameStates/State.h GUI/GameStates/State.cpp GUI/GUIObject/GUIObject.cpp GUI/GUIObject/GUIObject.h GUI/GameStates/MainMenuState.cpp GUI/GameStates/MainMenuState.h GameLogic/Map.cpp GameLogic/Map.h GUI/GUIObject/Button.cpp GUI/GUIObject/Button.h GUI/Input.cpp GUI/Input.h Events/EventQueue.cpp Events/EventQueue.h GUI/ResourcesContainer.cpp GUI/ResourcesContainer.h Events/Event.cpp Events/Event.h Events/GUIEvent.cpp Events/GUIEvent.h Settings.cpp Settings.h GUI/GameStates/NewGameState.cpp GUI/GameStates/NewGameState.h GUI/GameStates/State.cpp GUI/StateFactory.cpp GUI/StateFactory.h GameLogic/GameObject.cpp GameLogic/GameObject.h)
target_link_libraries(Hirolsy sfml-graphics sfml-audio)
target_link_libraries(Hirolsy "stdc++fs")

