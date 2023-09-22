/**
 * File: confused-friends.c
 * ---------------------------
 * Presents a pthreads examples illustrating how data is (clumsily) shared
 * with threads.  The example is intentionally broken, however, to illustrate
 * the simplest of race conditions.
 */

#include <pthread.h>  // provides pthread_t type, thread functions
#include <stdio.h>    // provides printf, which is thread-safe

static const char *kFriends[] = {
    "Jack", "Michaela", "Luis", "Richard", "Jordan", "Lisa",
    "Imaginary"
};
static const size_t kNumFriends = sizeof(kFriends)/sizeof(kFriends[0]) - 1;

static void *meetup(void *args) {
    const char *name = kFriends[*(size_t *)args];
    printf("Hey, I'm %s.  Empowered to meet you.\n", name);
    return NULL;
}

int main() {
    printf("%zu friends meet.\n", kNumFriends);
    pthread_t friends[kNumFriends];
    for (size_t i = 0; i < kNumFriends; i++)
        pthread_create(&friends[i], NULL, meetup, &i);
    for (size_t j = 0; j < kNumFriends; j++)
        pthread_join(friends[j], NULL);
    printf("Is everyone accounted for?\n");
    return 0;
}
