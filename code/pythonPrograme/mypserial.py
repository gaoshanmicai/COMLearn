
from cushy_serial import CushySerial
import time
import random
import threading
import logging
ser = CushySerial("COM56",115200)


instruction = bytes([0x7E, 0x77, 0x81, 0x0d, 0x0a])
instruction2 = bytes([0x7E, 0x61, 0x64, 0x0d, 0x0a])
instruction3 = bytes([0x7E, 0x61, 0x73, 0x0d, 0x0a])
instruction4 = bytes([0x7E, 0x72, 0x40, 0x0d, 0x0a])
instruction5 = bytes([0x7E, 0x72, 0x48, 0x0d, 0x0a])
   # ser.send("I am python client")
instructionsum =[instruction,instruction2,instruction3,instruction4,instruction5]

def loop():
    i =0
    while True:
        time.sleep(1)
        ser.send(random.choice(instructionsum))
def loop2():
    while True:
        @ser.polling_task(msg=instruction, interval=1, times=5)
        def handle_rec_msg(rec_msg):
            #print(f"[serial] rec polling message: {rec_msg}")
            logger.info(f"[serial] rec polling message: {rec_msg}")

            
            
            #logging.info(f"[serial] rec polling message: {rec_msg}")
           
if __name__=='__main__':
    print("helloworld\n")
    # logging.basicConfig(format='%(asctime)s - %(filename)s[line:%(lineno)d] - %(levelname)s: %(message)s',
    #                 level=logging.INFO,
    #                 filename='test.log',
    #                 filemode='w')
    # logger = logging.getLogger('test')

    # logger.debug('debug级别，一般用来打印一些调试信息，级别最低')
    # logger.info('info级别，一般用来打印一些正常的操作信息')
    # logger.warning('waring级别，一般用来打印警告信息')
    # logger.error('error级别，一般用来打印一些错误信息')
    # logger.critical('critical级别，一般用来打印一些致命的错误信息，等级最高')
    
    # logging.info("this is start\n")
    # logging.debug("jdkfkdkfkdkfk\n")
    # logging.error("ekerkrekrkekrk\n")

    # logger = logging.getLogger('test')
    # logger.setLevel(level=logging.DEBUG)

    # formatter = logging.Formatter('%(asctime)s - %(filename)s[line:%(lineno)d] - %(levelname)s: %(message)s')
    # stream_handler = logging.StreamHandler()
    # stream_handler.setLevel(logging.DEBUG)
    # stream_handler.setFormatter(formatter)
    # logger.addHandler(stream_handler)
    logger = logging.getLogger('test')
    logger.setLevel(level=logging.INFO)

    formatter = logging.Formatter('%(asctime)s - %(filename)s[line:%(lineno)d] - %(levelname)s: %(message)s')

    file_handler = logging.FileHandler('test2.log')
    file_handler.setLevel(level=logging.INFO)
    file_handler.setFormatter(formatter)

    stream_handler = logging.StreamHandler()
    stream_handler.setLevel(logging.DEBUG)
    stream_handler.setFormatter(formatter)

    logger.addHandler(file_handler)
    logger.addHandler(stream_handler)

    t = threading.Thread(target=loop,name ='LoopThread')
    v = threading.Thread(target=loop2,name= "loopThread2")
    v.start()
    t.start()


    t.join()
    print("thread%s ended"%threading.current_thread().name)