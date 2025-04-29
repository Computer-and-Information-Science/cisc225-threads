// A simple example creating threads
// Credit: Google AI

#include <iostream>
#include <pthread.h>

void *print_message(void *thread_id) {
    long tid = (long)thread_id;
    std::cout << "Thread " << tid << ": Hello from thread!" << std::endl;
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[5];
    int return_code;
    long i;

    for (i = 0; i < 5; i++) {
        std::cout << "Creating thread " << i << std::endl;
        return_code = pthread_create(&threads[i], NULL, print_message, (void *)i);
        if (return_code) {
            std::cerr << "Error: pthread_create() returned code " << return_code << std::endl;
            return -1;
        }
    }

    for (i = 0; i < 5; i++) {
        pthread_join(threads[i], NULL);
    }

    std::cout << "Main: All threads completed." << std::endl;
    pthread_exit(NULL);
}
