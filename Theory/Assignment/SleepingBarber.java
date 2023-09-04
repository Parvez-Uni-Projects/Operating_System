
package sleepingbarber;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Random;
import java.util.concurrent.Semaphore;



public class SleepingBarber {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        int numberOfSeatsWR = 5;
        BarberShop barberShop = new BarberShop(numberOfSeatsWR);

        Thread barberThread = new Thread(barberShop::barber);
        barberThread.start();

        // Continuously create and start customer threads
        int customerId = 1;
        while (true) {
            final int finalCustomerId = customerId;
            Thread customerThread = new Thread(() -> barberShop.customer(finalCustomerId));
            customerThread.start();
            customerId++;

            try {
                // Delay between customer arrivals
                Thread.sleep(2000); // Simulating new customer arrival every 2 seconds
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    } 
}


class BarberShop {
        private int numberOfSeatsWR;
        private final Semaphore barberReady;
        private final Semaphore accessWRSeats;
        private final Semaphore custReady;
        private final Queue<Integer> waitingCustomers;
        private final Queue<Integer> orderOfCustomers;
        private final Random random;

        public BarberShop(int numberOfSeatsWR) {
            this.numberOfSeatsWR = numberOfSeatsWR;
            this.barberReady = new Semaphore(0);
            this.accessWRSeats = new Semaphore(1);
            this.custReady = new Semaphore(0);
            this.waitingCustomers = new LinkedList<>();
            this.orderOfCustomers = new LinkedList<>();
            this.random = new Random();
        }

        public void barber() {
        while (true) {
            try {
                accessWRSeats.acquire();
                if (orderOfCustomers.isEmpty()) {
                    System.out.println("No customers waiting. Barber is sleeping.");
                    accessWRSeats.release();
                    Thread.sleep(2000); // Barber is sleeping, check again after a delay
                    continue;
                }
                int customerId = orderOfCustomers.peek(); // Get the first customer in the order
                if (waitingCustomers.peek() == customerId) {
                    waitingCustomers.poll(); // Remove the customer from the waiting queue
                    orderOfCustomers.poll(); // Remove the customer from the order queue
                    numberOfSeatsWR++;
                    barberReady.release();
                    accessWRSeats.release();

                    System.out.println("Customer " + customerId + " arrived and entered the waiting room.");

                    Thread.sleep(1000); // Simulating hair cutting process
                    System.out.println("Barber is cutting hair for Customer " + customerId);
                    Thread.sleep(1000); // Simulating hair cutting process
                    System.out.println("Customer " + customerId + " has finished the haircut and left the shop.");
                } else {
                    accessWRSeats.release();
                    Thread.sleep(500); // Give time for other threads to make progress
                }
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }


        public void customer(int customerId) {
        try {
            Thread.sleep(random.nextInt(5000)); // Random delay before customer arrival

            accessWRSeats.acquire();
            if (numberOfSeatsWR > 0) {
                numberOfSeatsWR--;
                waitingCustomers.add(customerId);
                orderOfCustomers.add(customerId); // Maintain the order of customers
                custReady.release();
                accessWRSeats.release();
                barberReady.acquire();


                System.out.println("Customer " + customerId + " is getting a haircut");

                Thread.sleep(2000); // Simulating time taken for haircut
            } else {

                accessWRSeats.release();
                System.out.println("Customer " + customerId + " arrived but found no seats in the waiting room. Leaving the shop.");
            }
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }

}

