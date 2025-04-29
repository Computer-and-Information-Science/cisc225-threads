// Threads executed sequentially, avoiding race condition

#include <iostream>
#include <pthread.h>

const int X = 1;
const int Y = 1;
const int MAX = 1000000;
int myValue = 0;

// Function to be executed by each thread
void* thread_function(void* arg) {
	   
	for (int i = 0; i < MAX / 2; i++)
		myValue = myValue / X + Y;

    pthread_exit(NULL);
    return NULL;
}

int main() {
	pthread_t thread1;
	pthread_t thread2;
	int result;

	// Create first thread
	result = pthread_create(&thread1, NULL, thread_function, NULL);
	if (result) {
		std::cerr << "Error creating thread: " << result << std::endl;
		return 1;
	}

	// Wait for thread to finish
	pthread_join(thread1, NULL);

	// Create second thread
	result = pthread_create(&thread2, NULL, thread_function, NULL);
	if (result) {
		std::cerr << "Error creating thread: " << result << std::endl;
		return 1;
	}

	// Wait for thread to finish
	pthread_join(thread2, NULL);

	// Output myValue
	std::cout << "myValue = " << myValue << "\n";

    return 0;
}
