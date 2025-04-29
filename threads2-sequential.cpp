// Same work as threads2.cpp, but done sequentially without threads

#include <iostream>
// #include <pthread.h>
#include <chrono>

// Function to be executed by each thread
void* thread_function(void* arg) {
    int thread_id = *(int*)arg;
    std::cout << "Thread " << thread_id << " started." << std::endl;
    
    // Simulate some work
    for (int i = 0; i < 1000000000; ++i);

    std::cout << "Thread " << thread_id << " finished." << std::endl;
    // pthread_exit(NULL);
    return NULL;
}

int main() {
    int num_threads = 5;
    // pthread_t threads[num_threads];
    // int thread_ids[num_threads];

    // Record start time
    auto start_time = std::chrono::high_resolution_clock::now();

    // Create threads
    for (int i = 0; i < num_threads; ++i) {
        // thread_ids[i] = i;
        // int result = pthread_create(&threads[i], NULL, thread_function, &thread_ids[i]);
        // if (result) {
        //     std::cerr << "Error creating thread: " << result << std::endl;
        //     return 1;
        // }
        thread_function(&i);
    }

    // Wait for threads to finish
    // for (int i = 0; i < num_threads; ++i) {
    //     pthread_join(threads[i], NULL);
    // }

    // Record end time
    auto end_time = std::chrono::high_resolution_clock::now();
    
    // Calculate duration
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);

    std::cout << "All threads finished." << std::endl;
    std::cout << "Execution time: " << duration.count() << " milliseconds" << std::endl;

    return 0;
}
