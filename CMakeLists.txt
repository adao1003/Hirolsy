cmake_minimum_required(VERSION 3.13)
project(Hirolsy)

set(CMAKE_CXX_STANDARD 17)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
add_executable(Hirolsy main.cpp Game.cpp Game.h GUI/StateMachine.cpp GUI/StateMachine.h GUI/GameStates/State.h GUI/GameStates/State.cpp GUI/GUIObject/GUIObject.cpp GUI/GUIObject/GUIObject.h GUI/GameStates/MainMenuState.cpp GUI/GameStates/MainMenuState.h GameLogic/Map.cpp GameLogic/Map.h GUI/GUIObject/Button.cpp GUI/GUIObject/Button.h GUI/ResourcesContainer.cpp GUI/ResourcesContainer.h GUI/GameStates/NewGameState.cpp GUI/GameStates/NewGameState.h GUI/GameStates/State.cpp GUI/StateFactory.cpp GUI/StateFactory.h GameLogic/GameObject.cpp GameLogic/GameObject.h GameLogic/Player.cpp GameLogic/Player.h GUI/GUIObject/MapView.cpp GUI/GUIObject/MapView.h GUI/GameStates/MainGameState.cpp GUI/GameStates/MainGameState.h GameLogic/Hero.cpp GameLogic/Hero.h GameLogic/Units/Unit.cpp GameLogic/Units/Unit.h GameLogic/Fields/Field.cpp GameLogic/Fields/Field.h GameLogic/Fields/Road.cpp GameLogic/Fields/Road.h GameLogic/Fields/Grass.cpp GameLogic/Fields/Grass.h GameLogic/Fields/Mountains.cpp GameLogic/Fields/Mountains.h GameLogic/Town.cpp GameLogic/Town.h GameLogic/Mines/Mine.cpp GameLogic/Mines/Mine.h GameLogic/PlayerQueue.cpp GameLogic/PlayerQueue.h GameLogic/Mines/Sawmill.cpp GameLogic/Mines/Sawmill.h GameLogic/Mines/Quarry.cpp GameLogic/Mines/Quarry.h TileMap.cpp TileMap.h GUI/GUIObject/Text.cpp GUI/GUIObject/Text.h GUI/GameStates/BattleState.cpp GUI/GameStates/BattleState.h GameLogic/Battle/Battle.cpp GameLogic/Battle/Battle.h GameLogic/Battle/BattleFieldPart.cpp GameLogic/Battle/BattleFieldPart.h GUI/GUIObject/BattleView.cpp GUI/GUIObject/BattleView.h GameLogic/Units/Unit0.cpp GameLogic/Units/Unit0.h GameLogic/Units/Unit1.cpp GameLogic/Units/Unit1.h)
target_link_libraries(Hirolsy sfml-graphics sfml-audio)
target_link_libraries(Hirolsy "stdc++fs")

