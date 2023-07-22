import pandas as pd
import numpy as np

def perform_csv_operation():
    df = pd.read_csv("iris.csv")

    numeric_attributes = df[["sepal.length", "sepal.width", "petal.length", "petal.width"]]
    data = np.array(numeric_attributes)

    print("Numeric Attributes (NumPy Matrix):")
    print(data)

    # Extract the target column into a list
    target = df["variety"].tolist()

    print("\nTarget Column (List):")
    print(target)

perform_csv_operation()
