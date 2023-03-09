import threading
import time
import random

# len of array
MAX = 100000

THREAD_MAX = 4

a = [0] * MAX

def merge(l, r):
	mid = l + (r - l) // 2
	left = a[l:mid+1]
	right = a[mid+1:r+1]

	nL = len(left)
	nR = len(right)
	i = j = 0
	k = l

	while i < nL and j < nR:
		if left[i] <= right[j]:
			a[k] = left[i]
			i += 1
		else:
			a[k] = right[j]
			j += 1
		k += 1

	while i < nL:
		a[k] = left[i]
		i += 1
		k += 1

	while j < nR:
		a[k] = right[j]
		j += 1
		k += 1

def merge_sort(l, r):
	if l < r:
		mid = l + (r - l) // 2

		merge_sort(l, mid)
		merge_sort(mid + 1, r)

		merge(l, r)

def merge_sort_threaded():
	part = 0
	
	# create thread_max thread
	for i in range(THREAD_MAX):
		t = threading.Thread(target=merge_sort, args=(part*(MAX//THREAD_MAX), (part+1)*(MAX//THREAD_MAX)-1))
		part += 1
		t.start()
		
	# join all of thread
	for i in range(THREAD_MAX):
		t.join()

	# merge all of part
	merge(0, MAX // 2 - 1)
	merge(MAX // 2, MAX - 1)
	merge(0, MAX - 1)


for i in range(MAX):
	a[i] = random.randint(0, 10000)

t1 = time.perf_counter()
merge_sort_threaded()
t2 = time.perf_counter()

print("Array after sort:", a)
print(f"Time for run merge sort parallel: {t2 - t1:.6f} (s)")
