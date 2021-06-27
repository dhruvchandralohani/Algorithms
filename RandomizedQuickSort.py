import random

def partition(arr,low,high):
	pivot = low
	i = low + 1
	for j in range(low + 1, high + 1):
		if arr[j] <= arr[pivot]:
			arr[i] , arr[j] = arr[j] , arr[i]
			i = i + 1
	arr[pivot] , arr[i - 1] = arr[i - 1] , arr[pivot]
	pivot = i - 1
	return (pivot)

def randompartition(arr , low, high):
	randpivot = random.randrange(low, high)
	arr[low], arr[randpivot] = arr[randpivot], arr[low]
	return partition(arr, low, high)

def quicksort(arr, low , high):
	if(low < high):
		pivotindex = randompartition(arr,low, high)
		quicksort(arr , low , pivotindex-1)
		quicksort(arr, pivotindex + 1, high)

array = [10, 7, 8, 9, 1, 5, 2, 4, 3, 6, 41, 0]
quicksort(array, 0, len(array) - 1)
print(array)