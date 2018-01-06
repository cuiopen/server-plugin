/*
 * Copyright (c) 2017 Noxaro aka Fabian Jungwirth
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3.0 of the License, or (at your option) any later version.
 * See the file COPYING included with this distribution for more information.
 */

#include "Player.hpp"

/**
 * Get's a player from the player pool.
 * If the pool returns null for the player a JVM exception will be thrown
 */
rage::IPlayer* Game::Player::getPlayerById(JNIEnv *env, int playerId) {
    rage::IMultiplayer *mp = RageJavaCore::getInstance().getMultiPlayer();
    if(mp == nullptr) {
        return nullptr;
    }
    rage::IPlayer *player = mp->GetPlayerPool().GetAt((rage::entityId_t) playerId);
    if(player) {
        return player;
    }
    JVM::Exception::throwPlayerNotFoundException(env, playerId);
    return nullptr;
}
