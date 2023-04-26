#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <time.h>
#include <stdlib.h>
#include <setjmp.h>
#include <cmocka.h>

#include "uuid.h"

static void generate_random_stream(uint8_t *destination_buffer, size_t size)
{
    for (size_t i = 0; i < size; i++) {
        destination_buffer[i] = (uint8_t) rand();
    }
}

static void simple_compare_test(void **state)
{
    uint8_t raw_uuid[UUID_SIZE];
    generate_random_stream(raw_uuid, sizeof(raw_uuid) / sizeof(raw_uuid[0]));

    uuid_t target_uuid;
    load_uuid(&target_uuid, raw_uuid);

    assert_memory_equal(target_uuid.value, raw_uuid, UUID_SIZE);
}

static void load_and_store_uuid_test(void **state)
{
    uint8_t source_raw_uuid[UUID_SIZE];
    uint8_t destination_raw_uuid[UUID_SIZE] = {0};
    generate_random_stream(source_raw_uuid, sizeof(source_raw_uuid) / sizeof(source_raw_uuid[0]));

    uuid_t target_uuid;
    load_uuid(&target_uuid, source_raw_uuid);
    store_uuid(destination_raw_uuid, &target_uuid);

    assert_memory_equal(
        destination_raw_uuid, source_raw_uuid, sizeof(destination_raw_uuid) / sizeof(destination_raw_uuid[0]));
}

static void copy_uuid_test(void **state)
{
    uint8_t raw_uuid[UUID_SIZE];
    generate_random_stream(raw_uuid, sizeof(raw_uuid) / sizeof(raw_uuid[0]));

    uuid_t target_source_uuid;
    load_uuid(&target_source_uuid, raw_uuid);

    uuid_t target_destination_uuid;
    copy_uuid(&target_destination_uuid, &target_source_uuid);

    assert_memory_equal(&target_destination_uuid, &target_source_uuid, sizeof(target_destination_uuid));
}

int main(int argc, char **argv)
{
    srand(time(NULL));
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(simple_compare_test),
        cmocka_unit_test(load_and_store_uuid_test),
        cmocka_unit_test(copy_uuid_test),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}