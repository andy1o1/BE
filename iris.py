
import pandas as pd
import matplotlib.pyplot as plt

x=pd.read_csv("iris.csv")

print("Max is : ",x["sepal_length"].max())
print("Min is : ",x["sepal_length"].min())
print("Mean is : ",x["sepal_length"].mean())
print("Range is : ",x["sepal_length"].max()-x["sepal_length"].min())
print("Standard Deviation is : ",x["sepal_length"].std())
print("Variance is : ",x["sepal_length"].var())
print("Percentiles : ",x["sepal_length"].quantile(.25),x["sepal_length"].quantile(.5),x["sepal_length"].quantile(.75))
x["sepal_length"].plot(kind="hist")
x.iloc[:,0:2].plot(kind="hist")
#x.plot(kind="box") 
print(x.describe(include="all"))  # include all to not exclude other datatypes
print("Number of features : ",x.iloc[0].count())#.count(axis=1))
print(x.dtypes) # returns datatypes of objects

x.hist(edgecolor='black',linewidth=0.8)
plt.show()
dataset.plot(kind='box',sharex=False,sharey=False)
x.show()	
