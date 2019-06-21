cmake_minimum_required(VERSION 3.13)
project(Hirolsy)

set(CMAKE_CXX_STANDARD 17)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
add_executable(Hirolsy main.cpp Game.cpp Game.h GUI/StateMachine.cpp GUI/StateMachine.h GUI/GameStates/State.h GUI/GameStates/State.cpp GUI/GUIObject/GUIObject.cpp GUI/GUIObject/GUIObject.h GUI/GameStates/MainMenuState.cpp GUI/GameStates/MainMenuState.h GameLogic/Map.cpp GameLogic/Map.h GUI/GUIObject/Button.cpp GUI/GUIObject/Button.h GUI/Input.cpp GUI/Input.h Events/EventQueue.cpp Events/EventQueue.h GUI/ResourcesContainer.cpp GUI/ResourcesContainer.h Events/Event.cpp Events/Event.h Events/GUIEvent.cpp Events/GUIEvent.h Settings.cpp Settings.h GUI/GameStates/NewGameState.cpp GUI/GameStates/NewGameState.h GUI/GameStates/State.cpp GUI/StateFactory.cpp GUI/StateFactory.h GameLogic/GameObject.cpp GameLogic/GameObject.h GameLogic/Player.cpp GameLogic/Player.h GUI/GUIObject/MapView.cpp GUI/GUIObject/MapView.h GUI/GameStates/MainGameState.cpp GUI/GameStates/MainGameState.h GameLogic/MapLoader.cpp GameLogic/MapLoader.h GameLogic/MockMapLoader.cpp GameLogic/MockMapLoader.h GameLogic/Hero.cpp GameLogic/Hero.h GameLogic/Unit.cpp GameLogic/Unit.h GameLogic/Fields/Field.cpp GameLogic/Fields/Field.h GameLogic/Fields/Road.cpp GameLogic/Fields/Road.h GameLogic/Fields/Grass.cpp GameLogic/Fields/Grass.h GameLogic/Fields/Mountains.cpp GameLogic/Fields/Mountains.h GameLogic/Town.cpp GameLogic/Town.h GameLogic/Mine.cpp GameLogic/Mine.h)
target_link_libraries(Hirolsy sfml-graphics sfml-audio)
target_link_libraries(Hirolsy "stdc++fs")

