/*
 * MIT License
 *
 * Copyright (c) 2023 G2Labs Grzegorz Grzęda
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#include "uuid.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void copy_uuid(uuid_t* destination, const uuid_t* source) {
    if (!destination || !source) {
        return;
    }
    memcpy(destination->value, source->value, UUID_SIZE);
}

void load_uuid(uuid_t* uuid, const uint8_t* buffer) {
    if (!uuid || !buffer) {
        return;
    }
    memcpy(uuid->value, buffer, UUID_SIZE);
}

void load_uuid_from_string(uuid_t* uuid, const char* text) {
    if (!uuid || !text) {
        return;
    }
    for (int i = 0; i < UUID_SIZE; i++) {
        char number[3] = {0};
        strncpy(number, text + (i << 1), 2);
        uuid->value[i] = (uint8_t)strtol(number, NULL, 16);
    }
}

void store_uuid(uint8_t* buffer, const uuid_t* uuid) {
    if (!uuid || !buffer) {
        return;
    }
    memcpy(buffer, uuid->value, UUID_SIZE);
}

void store_uuid_to_string(char* text, const uuid_t* uuid) {
    if (!uuid || !text) {
        return;
    }
    for (size_t i = 0; i < UUID_SIZE; i++) {
        sprintf(text + (i << 1), "%.2x", uuid->value[i]);
    }
}

bool are_uuids_equal(const uuid_t* uuid_0, const uuid_t* uuid_1) {
    if (!uuid_0 || !uuid_1) {
        return false;
    }
    return (memcmp(uuid_0->value, uuid_1->value, UUID_SIZE) == 0);
}