import numpy as np

arr = [0.523651,0.498521,0.517575,0.542992,0.49858]
arr_var = np.var(arr)
sum =0.0
for i in arr:
    #print(i)
    sum =sum + i

print("len%d"%len(arr))

expec = sum /len(arr)

print("expec:%f"%expec)


arr_std = np.std(arr,ddof =1)

print("方差为 :%f"%arr_var)
print("标准差为:%f"%arr_std)
finalresult = expec + arr_std

print("the final result: %.9f:"%finalresult)
