package main

import (
	"math"
	"time"
)

func merge(a, b []float64, low, mid, high int){
	i := low
	j := mid + 1
	for k := low; k <= high; k++ {
		b[k] = a[k]
	}
	for k := low; k <= high; k++ {
		if i > mid {
			a[k] = b[j]
			j++
		}else if j > high {
			a[k] = b[i]
			i++
		}else if b[j] < b[i]{
			a[k] = b[j]
			j++
		}else{
			a[k] = b[i]
			i++
		}
	}
}

func mergeSort(a, b []float64, low, high int) time.Duration{
	start := time.Now()

	if high <= low {
		return time.Nanosecond
	}
	mid := low + (high - low)/2
	mergeSort(a, b, low, mid)
	mergeSort(a, b, mid+1, high)
	merge(a, b, low, mid, high)
	return time.Since(start)/time.Nanosecond
}

func mergeSortImprove(a, b []float64, low, high int) time.Duration{
	start := time.Now()

	if high <= low {
		return time.Nanosecond
	}
	mid := low + (high - low)/2
	mergeSort(a, b, low, mid)
	mergeSort(a, b, mid+1, high)

	if a[mid] <= a[mid+1] {
		return time.Nanosecond
	}else if (high-low)<15 {
		insertionSort(a[low:high])
	}else{
		merge(a, b, low, mid, high)
	}
	//fmt.Println(a)
	return time.Since(start)/time.Nanosecond
}

func mergeSort2(a, b []float64, low, high int) time.Duration{
	start := time.Now()

	for sz := 1; sz < len(a); sz*=2 {
		for low := 0; low < len(a)-sz; low += sz*2 {
			merge(a, b, low, low+sz-1, int(math.Min(float64(low+sz*2-1), float64(len(a)-1))))
		}
	}

	return time.Since(start)/time.Nanosecond
}
