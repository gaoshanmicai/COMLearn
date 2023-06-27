import os
afterFile ="JLCzuobiao.csv"

def stringHandler(str1):
    res=str1.split(" !")

    dfp=open(afterFile,mode ='a+')

    str1 ="      m"
    if((len(res[4])==7)and( res[4]!=str1)):
        res[4]="T"
    else:
        res[4]="B"

    tempstr = res[0]+","+res[1]+"mm,"+res[2]+"mm,"+res[3]+","+res[4]+"\n"
    dfp.write(tempstr)
    dfp.close()
def ItemNameput():
    dfp=open(afterFile,mode ='a+')
    headnamestr="Designator,Mid X,Mid Y,Rotation,Layer\n"

    dfp.write(headnamestr)
    dfp.close()


def gerbersPlaceFile2JLCPFile(filename):
    fp=open(filename,mode ='r')
    for i in range(5):
        print(fp.readline())

    ItemNameput()

    while True:
        changestr=fp.readline()
        if changestr !="":
            stringHandler(changestr)
        else:
            break
    fp.close()







if __name__ =="__main__":
    desfile = "./place_txt.txt"
    gerbersPlaceFile2JLCPFile(desfile)


