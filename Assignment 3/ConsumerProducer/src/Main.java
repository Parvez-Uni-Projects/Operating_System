import java.util.concurrent.Semaphore;

// Press Shift twice to open the Search Everywhere dialog and type `show whitespaces`,
// then press Enter. You can now see whitespace characters in your code.
public class Main {
    public static void main(String[] args) throws InterruptedException {
        int size = 5; // Size of the buffer
        int[] buffer = new int[size]; // Shared buffer
        Semaphore empty = new Semaphore(size); // Semaphore to track available empty spaces in the buffer
        Semaphore full = new Semaphore(0); // Semaphore to track available filled spaces in the buffer
        Semaphore mutex = new Semaphore(1); // Semaphore for mutual exclusion

        // Create producer and consumer threads
        Thread producer1 = new Thread(new Producer(empty, full, mutex, buffer));
        Thread producer2 = new Thread(new Producer(empty, full, mutex, buffer));
        Thread consumer1 = new Thread(new Consumer(empty, full, mutex, buffer));
        Thread consumer2 = new Thread(new Consumer(empty, full, mutex, buffer));

        // Start the producer and consumer threads
        producer1.start();
        producer2.start();
        consumer1.start();
        consumer2.start();
    }
}


class Consumer implements Runnable {

    private final Semaphore empty; // Semaphore to track available empty spaces in the buffer
    private final Semaphore full; // Semaphore to track available empty spaces in the buffer
    private final Semaphore mutex; // Semaphore for mutual exclusion
    private final int[] buffer; // Shared buffer
    private int index;   // Index to track the next item to consume from the buffer

    public Consumer(Semaphore empty, Semaphore full, Semaphore mutex, int[] buffer) {
        this.empty = empty;
        this.full = full;
        this.mutex = mutex;
        this.buffer = buffer;
        this.index = 0;
    }

    @Override
    public void run() {
        try {
            int iterations = 0;
            while (iterations < 10) {
                full.acquire();       // Wait until there is a filled space in the buffer
                mutex.acquire();      // Acquire the mutex to ensure mutual exclusion
                consumeItem();        // Consume an item from the buffer
                mutex.release();      // Release the mutex
                empty.release();      // Signal that an empty space is available in the buffer
                iterations++;  // Increment the counter after each iteration
            }
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }
    }

    private void consumeItem() {
        int item = buffer[index];  // Get the item at the current index
        index = (index + 1) % buffer.length; // Move the index to the next position in a circular manner
        System.out.println("Consumer " + Thread.currentThread().getId() + ": Consumed Data " + item + " from the buffer");
        System.out.println("Empty space: " + empty.availablePermits());  // Number of available empty spaces in the buffer
        System.out.println("Full space: " + (buffer.length - empty.availablePermits())); // Number of available filled spaces in the buffer

    }
}


class Producer implements Runnable {

    private final Semaphore empty; // Semaphore to track available empty spaces in the buffer
    private final Semaphore full; // Semaphore to track available filled spaces in the buffer
    private final Semaphore mutex; // Semaphore for mutual exclusion
    private final int[] buffer; // Shared buffer
    private int index; // Index to track the next position to produce in the buffer

    public Producer(Semaphore empty, Semaphore full, Semaphore mutex, int[] buffer) {
        this.empty = empty;
        this.full = full;
        this.mutex = mutex;
        this.buffer = buffer;
        this.index = 0;
    }

    @Override
    public void run() {
        try {
            int iterations = 0;
            while (iterations < 10) {
                empty.acquire(); // Wait until there is an empty space in the buffer
                mutex.acquire(); // Acquire the mutex to ensure mutual exclusion
                produceItem();   // Produce an item and insert it into the buffer
                mutex.release(); // Release the mutex
                full.release();  // Signal that a filled space is available in the buffer
                iterations++;  // Increment the counter after each iteration
            }
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }
    }

    private void produceItem() {
        int item = (int) (Math.random() * 100); // Generate a random item
        buffer[index] = item; // Insert the item into the buffer at the current index
        index = (index + 1) % buffer.length; // Move the index to the next position in a circular manner
        System.out.println("Producer " + Thread.currentThread().getId() + ": Data " + item + " is inserted in the buffer");
        System.out.println("Empty space: " + empty.availablePermits()); // Number of available empty spaces in the buffer
        System.out.println("Full space: " + (buffer.length - empty.availablePermits())); // Number of available filled spaces in the buffer

    }
}



