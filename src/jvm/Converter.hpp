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

#include <string>
#include <iostream>
#include <codecvt>
#include <iomanip>
#include <clocale>
#include <cuchar>
#include <cstring>

#include <jni.h>
#include "VM.hpp"

namespace JVM {

    class Converter {
    public:
//        static std::u16string toU16string(JNIEnv *env, jstring input);

        static std::string toString(JNIEnv *env, jstring input);

        static jstring toJString(JNIEnv *env, std::u16string input);

        static jstring toJString(JNIEnv *env, const char *input);

        static jstring toJString(JNIEnv *env, std::string string);

        static std::vector<int> toIntVector(JNIEnv *env, jintArray array);
    };

}
