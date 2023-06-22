/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pkg20200104091_online03;

import java.util.concurrent.Semaphore;

/**
 *
 * @author student
 */

class ReaderWriter {
    private Semaphore readLock;
    private Semaphore writeLock;
    private int rc;

    public ReaderWriter() {
        readLock = new Semaphore(1);
        writeLock = new Semaphore(1);
        rc = 0;
    }

    public void read(String readerName) throws InterruptedException {
        readLock.acquire();
        rc++;
        if (rc == 1) {
            writeLock.acquire();
        }
        readLock.release();

        // Reading
        System.out.println(readerName + " Reading");

        Thread.sleep(2000); // Simulating read time

        System.out.println(readerName + " Leaving");

        readLock.acquire();
        rc--;
        if (rc == 0) {
            writeLock.release();
        }
        readLock.release();
    }

    public void write(String writerName) throws InterruptedException {
        writeLock.acquire();

        // Writing
        System.out.println(writerName + " Waiting");

        Thread.sleep(2000); // Simulating write time

        System.out.println(writerName + " Leaving");

        writeLock.release();
    }
}

class Reader extends Thread {
    private ReaderWriter db;
    private String readerName;

    public Reader(ReaderWriter database, String readerName) {
        this.db = database;
        this.readerName = readerName;
    }

    @Override
    public void run() {
        try {
            while (true) {
                db.read(readerName);
                System.out.println(readerName + " is leaving");
                Thread.sleep(1000); // Sleep before reading again
            }
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}

class Writer extends Thread {
    private ReaderWriter database;
    private String writerName;

    public Writer(ReaderWriter database, String writerName) {
        this.database = database;
        this.writerName = writerName;
    }

    @Override
    public void run() {
        try {
            while (true) {
                System.out.println(writerName + " is waiting");
                database.write(writerName);
                Thread.sleep(2000); // Sleep before writing again
            }
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}


public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        
        ReaderWriter database = new ReaderWriter();

        Reader[] readers = new Reader[4];
        Writer[] writers = new Writer[2];

        for (int i = 0; i < 4; i++) {
            readers[i] = new Reader(database, "Reader " + (i + 1));
            readers[i].start();
             writers[0] = new Writer(database, "Writer " + "0");
            writers[0].start();
        }

        for (int i = 0; i < 2; i++) {
           
        }
    }
    
}
