import csv
with open('C:\Users\Venric\Desktop/productsales.csv') as csvfile:
    mpg = list(csv.DictReader(csvfile))
print mpg
for adict in mpg:
    print adict['PREDICT']