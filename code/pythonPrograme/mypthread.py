from concurrent.futures import thread
import threading,time


def loop():
    print("thread %s is runing"%threading.current_thread().name)
    n =0
    while n <5:
        n = n +1
        print("thread %s >>>>%d"%(threading.current_thread().name,n))
        time.sleep(1)

def loop2():
    n=0
    while n < 10:
        n = n+1
        print("n = %d"%n)
        time.sleep(1)
        if n == 9:
            s = threading.Thread(target= loop3,name = 'loop3thread')
            s.start()
            #s.join()

def loop3():
    n =5
    while n < 20:
        n = n+1
        print("the thread n = ***%d"%n)
        time.sleep(1)



if __name__=='__main__':
    print("helloworld\n")
    t = threading.Thread(target=loop,name ='LoopThread')
    v = threading.Thread(target=loop2,name= "loopThread2")
    v.start()
    t.start()


    t.join()
    print("thread%s ended"%threading.current_thread().name)
