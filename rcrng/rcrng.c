#include "rcrng.h"

static uint32_t counter;
static uint32_t magic_number = 100000;
static const uint8_t thread_count = 6;

void* inc(void* arg) {
    for (uint32_t i = 0; i < magic_number; i++) 
        counter++;
    return NULL;
}

uint16_t rcrng(uint16_t from, uint16_t to) {
    if (from >= to)
        return 0;
    counter = 0;
    pthread_t threads[thread_count];
    for (uint8_t i = 0; i < thread_count; i++) {
        pthread_create(&threads[i], NULL, inc, NULL);
        if (i == (thread_count / 2))
            magic_number++;
    }
    for (uint8_t i = 0; i < thread_count; i++)
        pthread_join(threads[i], NULL);
    magic_number--;
    uint16_t range = to - from + 1;
    return (counter % range) + from;
}