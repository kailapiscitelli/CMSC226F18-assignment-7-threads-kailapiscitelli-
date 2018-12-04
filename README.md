# CMSC226F18-assignment-7-threads-kailapiscitelli-
Bank Simulation with pthreads in C

 Describe the results of using locks vs. not and the resulting race condition.
 
 When two or more threads access shared data and try to change it at the same time, a race condition occurs.  This is sown in the bank simulation example since the global variable which represents a persons bank account is going to be added to when that person saves and subtracted from when that person spends.  Since the threads can swap between them any time, they are racing to access the data.  In order to prevent race conditions we use a lock around the critical data area to ensure only one thread is being accessed at a time.  
 In
