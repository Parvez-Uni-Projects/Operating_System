
package diningphilosopher;

import java.util.concurrent.Semaphore;

public class DiningPhilosopher {
    private static final int NUM_PHILOSOPHERS = 5;
    private static final int NUM_FORKS = 5;

    private static Semaphore[] forks;
    private static Philosopher[] philosophers;

    public static void main(String[] args) {
        forks = new Semaphore[NUM_FORKS];
        philosophers = new Philosopher[NUM_PHILOSOPHERS];

        // Initialize forks
        for (int i = 0; i < NUM_FORKS; i++) {
            forks[i] = new Semaphore(1); // Semaphore with initial permit of 1
        }

        // Create philosophers and start their threads
        for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
            forks[i] = new Semaphore(1); // Semaphore with initial permit of 1
        }

        // Create philosophers and start their threads
        for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
            Semaphore leftFork = forks[i];
            Semaphore rightFork = forks[(i + 1) % NUM_FORKS];
            // Adjusting priority for deadlock avoidance
            if (i == NUM_PHILOSOPHERS - 1) {
                philosophers[i] = new Philosopher(i, rightFork, leftFork); // Last philosopher picks up right fork first
            } else {
                philosophers[i] = new Philosopher(i, leftFork, rightFork);
            }
            new Thread(philosophers[i]).start();
        }
    }

    public static class Philosopher implements Runnable {
        private int id;
        private Semaphore firstFork;
        private Semaphore secondFork;

        public Philosopher(int id, Semaphore firstFork, Semaphore secondFork) {
            this.id = id;
            this.firstFork = firstFork;
            this.secondFork = secondFork;
        }

        @Override
        public void run() {
            try {
                while (true) {
                    // Thinking
                    System.out.println("Philosopher " + id + " is thinking.");
                    Thread.sleep((long) (Math.random() * 1000));

                    // Pick up forks
                    pickUpForks();

                    // Eating
                    System.out.println("Philosopher " + id + " is eating.");
                    Thread.sleep((long) (Math.random() * 1000));

                    // Put down forks
                    putDownForks();
                }
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }
        }

        private void pickUpForks() throws InterruptedException {
            // Acquire the forks in the proper order
            if (id % 2 == 0) {
                firstFork.acquire();
                secondFork.acquire();
            } else {
                secondFork.acquire();
                firstFork.acquire();
            }
        }

        private void putDownForks() {
            // Release the forks
            firstFork.release();
            secondFork.release();
        }
    }
}
