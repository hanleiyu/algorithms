package main

import (
	"fmt"
	"time"
)

func partition(a []float64, low, high int) int{
	i := low
	j := high + 1
	v := a[low]
	for{
		for i ++; a[i] < v; i ++ {
			if i == high {
				break
			}
		}
		for j --; v < a[j]; j -- {
			if j == low {
				break
			}
		}
		if i >= j {
			break
		}
		a[i], a[j] = a[j], a[i]
	}
	a[low], a[j] = a[j], a[low]
	return j
}

func quickSort(a []float64, low, high int) time.Duration{
	start := time.Now()

	if high <= low {
		return time.Nanosecond
	}
	j := partition(a, low, high)
	quickSort(a, low, j-1)
	quickSort(a, j+1, high)
	//fmt.Println(a)
	return time.Since(start)/time.Nanosecond
}

func quickSortImprove(a []float64, low, high int) time.Duration{
	start := time.Now()

	if high <= low + 15 {
		insertionSort(a[low:high])
		return time.Nanosecond
	}
	j := partition(a, low, high)
	quickSort(a, low, j-1)
	quickSort(a, j+1, high)
	//fmt.Println(a)
	return time.Since(start)/time.Nanosecond
}

func quick3way(a []float64, low, high int) time.Duration{
	start := time.Now()

	if high <= low {
		return time.Nanosecond
	}
	lt := low
	i := low + 1
	gt := high
	v := a[low]
	for i <= gt {
		fmt.Println(a)
		if a[i] < v {
			a[lt], a[i] = a[i], a[lt]
			lt++
			i++
		}else if a[i] > v {
			a[i], a[gt] = a[gt], a[i]
			gt--
		}else{
			i++
		}
	}
	quick3way(a, low, lt-1)
	quick3way(a, gt+1, high)
	return time.Since(start)/time.Nanosecond
}