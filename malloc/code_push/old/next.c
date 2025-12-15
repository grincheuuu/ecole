/* ************************************************************************** */
/*                                                                            */
/*                        ______                                              */
/*                     .-"      "-.                                           */
/*                    /            \                                          */
/*        _          |              |          _                              */
/*       ( \         |,  .-.  .-.  ,|         / )                             */
/*        > "=._     | )(__/  \__)( |     _.=" <                              */
/*       (_/"=._"=._ |/     /\     \| _.="_.="\_)                             */
/*              "=._ (_     ^^     _)"_.="                                    */
/*                  "=\__|IIIIII|__/="                                        */
/*                 _.="| \IIIIII/ |"=._                                       */
/*       _     _.="_.="\          /"=._"=._     _                             */
/*      ( \_.="_.="     `--------`     "=._"=._/ )                            */
/*       > _.="                            "=._ <                             */
/*      (_/                                    \_)                            */
/*                                                                            */
/*      Filename: test.c                                                      */
/*      By: espadara <espadara@pirate.capn.gg>                                */
/*      Created: 2025/11/11 22:41:16 by espadara                              */
/*      Updated: 2025/11/26 14:33:50 by almoraru                              */
/*                                                                            */
/* ************************************************************************** */

#include "libft_malloc.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>


# define TEST_COUNT 50
# define STRESS_TEST_COUNT 1000
# define NUM_THREADS 8
# define ALLOCS_PER_THREAD 100

void test_basic_allocations(void)
{
    printf("\n🔹 TEST 1: Basic Allocations\n");

    void *ptr1 = malloc(10);
    void *ptr2 = malloc(100);
    void *ptr3 = malloc(1000);
    void *ptr4 = malloc(10000);

    assert(ptr1 != NULL);
    assert(ptr2 != NULL);
    assert(ptr3 != NULL);
    assert(ptr4 != NULL);

    // Write to them
    memset(ptr1, 'A', 10);
    memset(ptr2, 'B', 100);
    memset(ptr3, 'C', 1000);
    memset(ptr4, 'D', 10000);

    // Verify
    assert(((char*)ptr1)[0] == 'A');
    assert(((char*)ptr2)[0] == 'B');
    assert(((char*)ptr3)[0] == 'C');
    assert(((char*)ptr4)[0] == 'D');

    free(ptr1);
    free(ptr2);
    free(ptr3);
    free(ptr4);

    printf("  ✅ Basic allocations work!\n");
}

void test_zone_boundaries(void)
{
    printf("\n🔹 TEST 2: Zone Boundaries\n");

    // Test TINY zone boundary (64 bytes)
    void *tiny_max = malloc(128);
    void *tiny_over = malloc(129);

    // Test SMALL zone boundary (1024 bytes)
    void *small_max = malloc(1024);
    void *small_over = malloc(1025);

    assert(tiny_max != NULL);
    assert(tiny_over != NULL);
    assert(small_max != NULL);
    assert(small_over != NULL);

    printf("  TINY max (128):    %p\n", tiny_max);
    printf("  TINY over (129):   %p\n", tiny_over);
    printf("  SMALL max (1024): %p\n", small_max);
    printf("  SMALL over (1025): %p\n", small_over);

    free(tiny_max);
    free(tiny_over);
    free(small_max);
    free(small_over);

    printf("  ✅ Zone boundaries work!\n");
}

void test_zero_and_null(void)
{
    printf("\n🔹 TEST 3: Zero Size and NULL\n");

    void *zero = malloc(0);
    printf("  malloc(0) returned: %p\n", zero);

    free(NULL);  // Should not crash
    printf("  free(NULL) didn't crash\n");

    free(zero);

    printf("  ✅ Edge cases handled!\n");
}

void test_realloc(void)
{
    printf("\n🔹 TEST 4: Realloc Tests\n");

    char *ptr = malloc(50);
    printf("  malloc(50) = %p\n", ptr);
    assert(ptr != NULL);

    strcpy(ptr, "Hello, Kraken!");
    printf("  Original (50 bytes): '%s' at %p\n", ptr, ptr);

    // Grow
    printf("  Calling realloc(%p, 100)...\n", ptr);
    ptr = realloc(ptr, 1024);
    printf("  realloc(1024*1024) returned: %p\n", ptr);
    assert(ptr != NULL);
    assert(strcmp(ptr, "Hello, Kraken!") == 0);
    printf("  After realloc(100): '%s'\n", ptr);

    // Shrink
    printf("  Calling realloc(%p, 20)...\n", ptr);
    ptr = realloc(ptr, 1);
    printf("  realloc(20) returned: %p\n", ptr);
    assert(ptr != NULL);
    printf("  After realloc(20): '%s'\n", ptr);

    // NULL realloc (should act like malloc)
    printf("  Calling realloc(NULL, 50)...\n");
    void *new_ptr = realloc(NULL, 50);
    printf("  realloc(NULL, 50) returned: %p\n", new_ptr);
    assert(new_ptr != NULL);
    free(new_ptr);

    free(ptr);

    printf("  ✅ Realloc works!\n");
}

void test_calloc(void)
{
    printf("\n🔹 TEST 5: Calloc (zero-initialized)\n");

    int *arr = calloc(10, sizeof(int));
    assert(arr != NULL);

    int all_zero = 1;
    for (int i = 0; i < 10; i++) {
        if (arr[i] != 0) {
            all_zero = 0;
            break;
        }
    }

    assert(all_zero);
    printf("  ✅ Calloc zeros memory!\n");

    free(arr);
}

void test_fragmentation(void)
{
    printf("\n🔹 TEST 6: Fragmentation Test\n");

    void *ptrs[100];

    // Allocate 100 small blocks
    for (int i = 0; i < 100; i++) {
        ptrs[i] = malloc(32);
        assert(ptrs[i] != NULL);
    }

    // Free every other block (create holes)
    for (int i = 0; i < 100; i += 2) {
        free(ptrs[i]);
    }

    // Allocate more (should reuse freed blocks)
    for (int i = 0; i < 100; i += 2) {
        ptrs[i] = malloc(32);
        assert(ptrs[i] != NULL);
    }

    // Free all
    for (int i = 0; i < 100; i++) {
        free(ptrs[i]);
    }

    printf("  ✅ Fragmentation handled!\n");
}

void test_large_allocations(void)
{
    printf("\n🔹 TEST 7: Large Allocations\n");

    void *huge1 = malloc(1024 * 1024);      // 1 MB
    void *huge2 = malloc(1024 * 1024 * 42);  // 42 MB

    assert(huge1 != NULL);
    assert(huge2 != NULL);

    printf("  1 MB allocation:  %p\n", huge1);
    printf("  42 MB allocation:  %p\n", huge2);

    memset(huge1, 0xFF, 1024 * 1024);
    memset(huge2, 0xAA, 1024 * 1024 * 42);

    assert(((unsigned char*)huge1)[0] == 0xFF);
    assert(((unsigned char*)huge2)[0] == 0xAA);

    free(huge1);
    free(huge2);

    printf("  ✅ Large allocations work!\n");
}

void test_stress(void)
{
    printf("\n🔹 TEST 8: Stress Test (%d allocations)\n", STRESS_TEST_COUNT);

    void *ptrs[STRESS_TEST_COUNT];

    for (int i = 0; i < STRESS_TEST_COUNT; i++) {
        // Random sizes
        size_t size = (i % 10) * 100 + 10;
        ptrs[i] = malloc(size);
        assert(ptrs[i] != NULL);
        memset(ptrs[i], i % 256, size);
    }

    // Free in reverse order
    for (int i = STRESS_TEST_COUNT - 1; i >= 0; i--) {
        free(ptrs[i]);
    }

    printf("  ✅ Stress test passed!\n");
}

// ==================== MULTITHREADING TESTS ====================

typedef struct {
    int thread_id;
    int alloc_count;
    int failed;
} thread_data_t;

void *thread_simple_alloc_free(void *arg)
{
    thread_data_t *data = (thread_data_t *)arg;
    void *ptrs[ALLOCS_PER_THREAD];

    for (int i = 0; i < data->alloc_count; i++) {
        size_t size = (i % 10) * 100 + 16;
        ptrs[i] = malloc(size);
        
        if (ptrs[i] == NULL) {
            data->failed = 1;
            return NULL;
        }

        // Write a pattern to verify memory integrity
        memset(ptrs[i], (data->thread_id + i) % 256, size);
    }

    // Verify data integrity
    for (int i = 0; i < data->alloc_count; i++) {
        size_t size = (i % 10) * 100 + 16;
        unsigned char expected = (data->thread_id + i) % 256;
        unsigned char *ptr = (unsigned char *)ptrs[i];
        
        if (ptr[0] != expected || ptr[size - 1] != expected) {
            data->failed = 1;
            return NULL;
        }
    }

    // Free all
    for (int i = 0; i < data->alloc_count; i++) {
        free(ptrs[i]);
    }

    return NULL;
}

void test_multithread_basic(void)
{
    printf("\n🔹 TEST 9: Basic Multithreading (%d threads, %d allocs each)\n", 
           NUM_THREADS, ALLOCS_PER_THREAD);

    pthread_t threads[NUM_THREADS];
    thread_data_t thread_data[NUM_THREADS];

    // Create threads
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_data[i]. thread_id = i;
        thread_data[i].alloc_count = ALLOCS_PER_THREAD;
        thread_data[i].failed = 0;

        if (pthread_create(&threads[i], NULL, thread_simple_alloc_free, &thread_data[i]) != 0) {
            printf("  ❌ Failed to create thread %d\n", i);
            return;
        }
    }

    // Join threads
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
        
        if (thread_data[i].failed) {
            printf("  ❌ Thread %d reported failure!\n", i);
            return;
        }
    }

    printf("  ✅ All %d threads completed successfully!\n", NUM_THREADS);
}

void *thread_mixed_sizes(void *arg)
{
    thread_data_t *data = (thread_data_t *)arg;
    
    // Allocate different zone types
    void *tiny = malloc(64);      // TINY
    void *small = malloc(512);    // SMALL
    void *large = malloc(5000);   // LARGE

    if (! tiny || !small || !large) {
        data->failed = 1;
        return NULL;
    }

    // Write patterns
    memset(tiny, 'T', 64);
    memset(small, 'S', 512);
    memset(large, 'L', 5000);

    // Sleep to increase race condition chances
    usleep(100);

    // Verify
    if (((char*)tiny)[0] != 'T' || ((char*)small)[0] != 'S' || ((char*)large)[0] != 'L') {
        data->failed = 1;
    }

    free(tiny);
    free(small);
    free(large);

    return NULL;
}

void test_multithread_mixed_sizes(void)
{
    printf("\n🔹 TEST 10: Multithreading with Mixed Zone Sizes\n");

    pthread_t threads[NUM_THREADS];
    thread_data_t thread_data[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        thread_data[i].thread_id = i;
        thread_data[i].failed = 0;
        pthread_create(&threads[i], NULL, thread_mixed_sizes, &thread_data[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
        
        if (thread_data[i].failed) {
            printf("  ❌ Thread %d failed!\n", i);
            return;
        }
    }

    printf("  ✅ Mixed size allocations across threads work!\n");
}

void *thread_realloc_test(void *arg)
{
    thread_data_t *data = (thread_data_t *)arg;
    
    char *ptr = malloc(50);
    if (!ptr) {
        data->failed = 1;
        return NULL;
    }

    snprintf(ptr, 50, "Thread %d", data->thread_id);
    
    // Grow
    ptr = realloc(ptr, 200);
    if (!ptr) {
        data->failed = 1;
        return NULL;
    }

    // Verify data still intact
    char expected[50];
    snprintf(expected, 50, "Thread %d", data->thread_id);
    if (strncmp(ptr, expected, strlen(expected)) != 0) {
        data->failed = 1;
    }

    // Shrink
    ptr = realloc(ptr, 30);
    if (!ptr) {
        data->failed = 1;
        return NULL;
    }

    free(ptr);
    return NULL;
}

void test_multithread_realloc(void)
{
    printf("\n🔹 TEST 11: Concurrent Realloc\n");

    pthread_t threads[NUM_THREADS];
    thread_data_t thread_data[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        thread_data[i].thread_id = i;
        thread_data[i]. failed = 0;
        pthread_create(&threads[i], NULL, thread_realloc_test, &thread_data[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
        
        if (thread_data[i].failed) {
            printf("  ❌ Thread %d failed!\n", i);
            return;
        }
    }

    printf("  ✅ Concurrent realloc works!\n");
}

void *thread_fragmentation_test(void *arg)
{
    thread_data_t *data = (thread_data_t *)arg;
    void *ptrs[50];

    // Allocate
    for (int i = 0; i < 50; i++) {
        ptrs[i] = malloc(32);
        if (!ptrs[i]) {
            data->failed = 1;
            return NULL;
        }
    }

    // Free every other
    for (int i = 0; i < 50; i += 2) {
        free(ptrs[i]);
    }

    // Re-allocate (should reuse freed blocks)
    for (int i = 0; i < 50; i += 2) {
        ptrs[i] = malloc(32);
        if (!ptrs[i]) {
            data->failed = 1;
            return NULL;
        }
    }

    // Free all
    for (int i = 0; i < 50; i++) {
        free(ptrs[i]);
    }

    return NULL;
}

void test_multithread_fragmentation(void)
{
    printf("\n🔹 TEST 12: Concurrent Fragmentation\n");

    pthread_t threads[NUM_THREADS];
    thread_data_t thread_data[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        thread_data[i].thread_id = i;
        thread_data[i].failed = 0;
        pthread_create(&threads[i], NULL, thread_fragmentation_test, &thread_data[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
        
        if (thread_data[i].failed) {
            printf("  ❌ Thread %d failed!\n", i);
            return;
        }
    }

    printf("  ✅ Concurrent fragmentation handled!\n");
}

void *thread_calloc_test(void *arg)
{
    thread_data_t *data = (thread_data_t *)arg;
    
    int *arr = calloc(100, sizeof(int));
    if (!arr) {
        data->failed = 1;
        return NULL;
    }

    // Verify all zeros
    for (int i = 0; i < 100; i++) {
        if (arr[i] != 0) {
            data->failed = 1;
            free(arr);
            return NULL;
        }
    }

    free(arr);
    return NULL;
}

void test_multithread_calloc(void)
{
    printf("\n🔹 TEST 13: Concurrent Calloc\n");

    pthread_t threads[NUM_THREADS];
    thread_data_t thread_data[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        thread_data[i].thread_id = i;
        thread_data[i].failed = 0;
        pthread_create(&threads[i], NULL, thread_calloc_test, &thread_data[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
        
        if (thread_data[i].failed) {
            printf("  ❌ Thread %d failed!\n", i);
            return;
        }
    }

    printf("  ✅ Concurrent calloc works!\n");
}

void test_original_demo(void)
{
    printf("\n🔹 TEST 10: Original Demo\n");

    void *ptr[1024];

    for (int i = 0; i < 20; i++)
    {
        if ((i % 2) == 0)
            ptr[i] = malloc(600);
        else if ((i % 5) == 0)
            ptr[i] = malloc(5000);
        else if ((i % 3) == 0)
            ptr[i] = malloc(200);
        else if ((i % 8) == 0)
            ptr[i] = malloc(1000);
        else if ((i % 7) == 0)
            ptr[i] = malloc(10000000);
        else
            ptr[i] = malloc(50);
    }

    show_alloc_mem();

    printf("\n------------BONUS------------\n");
    char *poof = "cocococococcococo1231232132132131ZAAAAAAAAAWAAAAAAAAAAAAAAAAAAAAAARUUUUUUUUUUUUUUUDOOOOOOOOOOOOOOO";
    int len =strlen(poof);
    memcpy(ptr[3], (void *)poof, len);
    show_alloc_mem(ptr[3]);

    for (int i = 0; i < 20; i++)
        free(ptr[i]);

    printf("\n  ✅ Original demo passed!\n");
}

int main(void)
{
    printf("🐙 ============================================== 🐙\n");
    printf("       KRAKENLIB MALLOC COMPREHENSIVE TESTS\n");
    printf("🐙 ============================================== 🐙\n");

    /* BASIC TESTS */
    test_basic_allocations();
    test_zone_boundaries();
    test_zero_and_null();
    test_realloc();
    test_calloc();
    test_fragmentation();
    test_large_allocations();
    test_stress();

    /* BONUS THREAD TESTS */
/*    test_multithread_basic();
    test_multithread_mixed_sizes();
    test_multithread_realloc();
    test_multithread_fragmentation();
    test_multithread_calloc();*/

    /* SIMPLE BONUS TEST */
    test_original_demo();
    
    printf("\n");
    printf("🐙 ============================================== 🐙\n");
    printf("       🎉 ALL MALLOC TESTS PASSED! 🎉\n");
    printf("       The Kraken's memory is UNLEASHED!\n");
    printf("🐙 ============================================== 🐙\n");
    printf("\n");

    return (0);
}
