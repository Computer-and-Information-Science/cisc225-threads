// Threads example avoiding a race condition using mutex

#include <iostream>
#include <pthread.h>

const int X = 1;
const int Y = 1;
const int MAX = 1000000;
int myValue = 0;

pthread_mutex_t lock;

// Function to be executed by each thread
void* thread_function(void* arg) {
	   
	for (int i = 0; i < MAX / 2; i++) {
		pthread_mutex_lock(&lock);
		myValue = myValue / X + Y;
		pthread_mutex_unlock(&lock);
	}

    pthread_exit(NULL);
    return NULL;
}

int main() {
	pthread_t thread1;
	pthread_t thread2;
	int result;

	// Initialize the mutex
	if (pthread_mutex_init(&lock, NULL)) {
		std::cerr << "Failed to initialize mutex\n";
		return 1;
	}

	// Create first thread
	result = pthread_create(&thread1, NULL, thread_function, NULL);
	if (result) {
		std::cerr << "Error creating thread: " << result << std::endl;
		return 1;
	}

	// Create second thread
	result = pthread_create(&thread2, NULL, thread_function, NULL);
	if (result) {
		std::cerr << "Error creating thread: " << result << std::endl;
		return 1;
	}

	// Wait for threads to finish
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);

	// Output myValue
	std::cout << "myValue = " << myValue << "\n";

    return 0;
}
