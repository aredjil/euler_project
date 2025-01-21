#! /usr/bin/env python3 
import numpy as np 

def sum_of_sq(arr):
    arr = arr * arr 
    return np.sum(arr)
def sq_of_sum(arr):
    return np.sum(arr) * np.sum(arr)

arr = np.arange(0, 101, 1)

print(f"The difference: {sq_of_sum(arr)-sum_of_sq(arr)}")
