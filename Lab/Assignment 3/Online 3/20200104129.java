package pkg20200104129_online3;

/**
 *
 * @author student
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        
        ReaderWriter db = new ReaderWriter();
        
        Reader[] rs = new Reader[3];
         Writer[] ws = new Writer[3];
         
         for (int i = 0 ; i < 3 ; i++)
         {
             rs[i] = new Reader(db , " Reader " + (i +1));
             rs[i].start();
             ws[i] = new Writer(db , " Writer " + (i+1));
             ws[i].start();
         }
    }
    
}

package pkg20200104129_online3;
import java.util.concurrent.Semaphore;

/**
 *
 * @author student
 */
public class ReaderWriter {
    private Semaphore readLock ,writeLock;
    
    private int rc;
    
    public ReaderWriter()
    {
        readLock = new Semaphore(1);
        writeLock = new Semaphore(1);
        rc = 0;
    }
    
    public void read (String readerName) throws InterruptedException{
        
        readLock.acquire();
        rc++;
        if (rc==1) writeLock.acquire();
        readLock.release();
        
        System.out.println(readerName  + " Reading");
        Thread.sleep(2000);
        System.out.println(readerName  + " Leaving");
        readLock.acquire();
        rc--;
        if (rc== 0) writeLock.release();
        readLock.release();
        
    }
    
    public void write (String name) throws InterruptedException{
        
        writeLock.acquire();
       
        // Writing
        System.out.println(name  + " Writing");
        Thread.sleep(2000);
        System.out.println(name + " Leaving");
        
         writeLock.release();
        
    }
    
}


package pkg20200104129_online3;

/**
 *
 * @author student
 */
public class Reader extends Thread{
    private ReaderWriter db;
    private String readerName;
    public Reader(ReaderWriter db , String readerName)
    {
        this.db = db;
        this.readerName = readerName;
    }
    
    @Override
    public void run()
    {
        
        try{
            while(true)
            {
                db.read(readerName);
                System.out.println(readerName + " is leaving ");
                Thread.sleep(1000);
            }
        }catch(InterruptedException e){
            e.printStackTrace();
        }
    }
}


package pkg20200104129_online3;

/**
 *
 * @author student
 */
public class Writer extends Thread{
    private ReaderWriter db;
    private String writerName;
    public Writer(ReaderWriter db , String writerName)
    {
        this.db = db;
        this.writerName = writerName;
    }
    
    @Override
    public void run()
    {
        
        try{
            while(true)
            {
                
                System.out.println(writerName + " is waiting ");
                db.write(writerName);
                Thread.sleep(2000);
            }
        }catch(InterruptedException e){
            e.printStackTrace();
        }
    }
}