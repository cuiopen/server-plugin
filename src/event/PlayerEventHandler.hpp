/*
 * Copyright (c) 2017 Noxaro aka Fabian Jungwirth
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3.0 of the License, or (at your option) any later version.
 * See the file COPYING included with this distribution for more information.
 */

#pragma once

#include <iostream>
#include <jni.h>
#include "../sdk/rage.hpp"
#include "../jvm/VM.hpp"
#include "../jvm/Converter.hpp"

class PlayerEventHandler : public rage::IEventHandler, public rage::IPlayerHandler, public rage::IEntityHandler
{
public:
    PlayerEventHandler(JNIEnv *env);

    rage::IPlayerHandler *GetPlayerHandler() override {
        return this;
    }

    rage::IEntityHandler *GetEntityHandler() override {
        return this;
    }

    void OnPlayerJoin(rage::IPlayer *player) override;

    void OnPlayerCommand(rage::IPlayer *player, const std::u16string &command) override;

    void OnPlayerQuit(rage::IPlayer *player, rage::exit_t exitType, const char *reason) override;

    void OnPlayerSpawn(rage::IPlayer *player) override;

    void OnPlayerChat(rage::IPlayer *player, const std::u16string &text) override;

    void OnPlayerEnterVehicle(rage::IPlayer *player, rage::IVehicle *vehicle, uint8_t seatId) override;

    void OnPlayerStartEnterVehicle(rage::IPlayer *player, rage::IVehicle *vehicle, uint8_t seatId) override;

    void OnPlayerExitVehicle(rage::IPlayer *player, rage::IVehicle *vehicle) override;

    void OnPlayerStartExitVehicle(rage::IPlayer *player, rage::IVehicle *vehicle) override;

    void OnPlayerDeath(rage::IPlayer *player, rage::hash_t reason, rage::IPlayer *killer) override;

    void OnPlayerRemoteEvent(rage::IPlayer *player, const std::string &eventName, const rage::args_t &args) override;

    void OnEntityCreated(rage::IEntity *entity) override;

    void OnEntityDestroyed(rage::IEntity *entity) override;

    void OnPlayerReady(rage::IPlayer *player) override;

    void OnPlayerDamage(rage::IPlayer *player, float healthLoss, float armorLoss) override;

    void OnPlayerWeaponChange(rage::IPlayer *player, rage::hash_t oldWeapon, rage::hash_t newWeapon) override;

    void OnEntityModelChange(rage::IEntity *entity, rage::hash_t oldModel) override;

private:
    jclass playerEventClass;
    jmethodID playerCreatedMethod;
    jmethodID playerDestroyedMethod;
    jmethodID playerJoinMethod;
    jmethodID playerCommandMethod;
    jmethodID playerQuitMethod;
    jmethodID playerSpawnMethod;
    jmethodID playerChatMethod;
    jmethodID playerEnterVehicleMethod;
    jmethodID playerStartEnterVehicleMethod;
    jmethodID playerExitVehicleMethod;
    jmethodID playerStartExitVehicleMethod;
    jmethodID playerDeathMethod;
    jmethodID playerRemoteEventMethod;
    jmethodID playerReadyMethod;
    jmethodID playerDamageMethod;
    jmethodID playerWeaponChangeMethod;
    jmethodID playerModelChangeMethod;
};