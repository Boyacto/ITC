import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import datetime
import glob

counter = 1

for filen in glob.glob("./"+'*.csv'):
    # Read in your file as a pandas.DataFrame
    # using 'any number of whitespace' as the seperator
    print(f"Iniciando {filen}")
    df = pd.read_csv(f"./{filen}",parse_dates=['DATE'],index_col=0)
    print(df)

    df[df.columns] = df[df.columns].apply(pd.to_numeric, errors='coerce')
    #df.resample('M').mean()
    print("Replacing nan")
    df.fillna(df.mean(), inplace=True)
    print(df)
    print("Starting monthly average")
    monthly=df.resample('M').mean()
    #monthly =df.groupby(df.index.Date).mean()
    print(monthly)

    monthly['T.Media'] = monthly.apply(lambda row: ((row.TMAX + row.TMIN)/2), axis = 1) 
    filen= filen[:-4]
    nfile = f"{filen}_processed_data.csv"

    monthly = monthly[(monthly.index >= "2010-01-01")]

    monthly.to_csv(nfile)

    print(f"Se completo el archivo {filen}| Counter: {counter}")
    counter+=1