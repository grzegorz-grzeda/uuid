/**
 * MIT License
 * Copyright (c) 2023 Grzegorz Grzęda
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#ifndef UUID_H
#define UUID_H

#include <stdint.h>
#include <stdbool.h>

#define UUID_SIZE (16)

typedef struct uuid {
    uint8_t value[UUID_SIZE];
} uuid_t;

void copy_uuid(uuid_t *destination, const uuid_t *source);

void load_uuid(uuid_t *uuid, const uint8_t *buffer);

void load_uuid_from_string(uuid_t *uuid, const char *text);

void store_uuid(uint8_t *buffer, const uuid_t *uuid);

void store_uuid_to_string(char *text, const uuid_t *uuid);

bool are_uuids_equal(const uuid_t *uuid_0, const uuid_t *uuid_1);

#endif // UUID_H