/*
 * Copyright (c) 2017 Noxaro aka Fabian Jungwirth
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3.0 of the License, or (at your option) any later version.
 * See the file COPYING included with this distribution for more information.
 */

#include "Exception.hpp"

void JVM::Exception::throwNotImplementedException(std::string reason) {
    jclass clazz = VM::getJNIEnv()->FindClass("mp/game/plugin/java/api/exception/NotImplementedException");
    VM::getJNIEnv()->ThrowNew(clazz, reason.c_str());
}

void JVM::Exception::throwPlayerNotFoundException(int playerId) {
    jclass clazz = VM::getJNIEnv()->FindClass("mp/game/plugin/java/api/exception/PlayerNotFoundException");
    VM::getJNIEnv()->ThrowNew(clazz, std::to_string(playerId).c_str());
}

void JVM::Exception::throwVehicleNotFoundException(int vehicleId) {
    jclass clazz = VM::getJNIEnv()->FindClass("mp/game/plugin/java/api/exception/VehicleNotFoundException");
    VM::getJNIEnv()->ThrowNew(clazz, std::to_string(vehicleId).c_str());
}

void JVM::Exception::throwJNIExecutionException(std::string reason) {
    jclass clazz = VM::getJNIEnv()->FindClass("mp/game/plugin/java/api/exception/JNIExecutionException");
    VM::getJNIEnv()->ThrowNew(clazz, reason.c_str());
}

void JVM::Exception::throwCheckpointNotFoundException(int checkpointId) {
    jclass clazz = VM::getJNIEnv()->FindClass("mp/game/plugin/java/api/exception/CheckpointNotFoundException");
    VM::getJNIEnv()->ThrowNew(clazz, std::to_string(checkpointId).c_str());
}

