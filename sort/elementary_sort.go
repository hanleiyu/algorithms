package main

import (
	"fmt"
	"time"
)

func selectionSort(a []float64) time.Duration{
	start := time.Now()

	for i := 0; i < len(a); i++ {
		min := i
		for j := i; j < len(a); j++ {
			if a[j] < a[min] {
				min = j
			}
		}
		a[i], a[min] = a[min], a[i]
	}
	//fmt.Println("selectionSort : ",a)

	return time.Since(start)/ time.Nanosecond
}

func insertionSort(a []float64) time.Duration{
	start := time.Now()
	//defer fmt.Printf("insertionSort cost %d ns", time.Since(start)/time.Nanosecond)

	for i:= 1; i < len(a); i++ {
		for j := i; j > 0 && a[j] < a[j-1]; j-- {
			a[j], a[j-1] = a[j-1], a[j]
		}
	}
	//fmt.Println("insertionSort : ",a)

	return time.Since(start)/time.Nanosecond
}

func insertionSortImprove(a []int){
	for i:= 1; i < len(a); i++ {
		for j := i; j > 0; j-- {
			if a[j] < a[i] || j == 0{

				a[j], a[j-1] = a[j-1], a[j]
			}
		}
	}
	fmt.Println("insertionSort : ",a)
}

func shellSort(a []float64) time.Duration{
	start := time.Now()

	h := 1
	for h < len(a)/3 {
		h = 3 * h + 1
	}
	for h >= 1 {
		for i:= h; i < len(a); i++ {
			for j := i; j > h && a[j] < a[j-h]; j-=h {
				a[j], a[j-h] = a[j-h], a[j]
			}
		}
		h = h/3
	}

	return time.Since(start)/time.Nanosecond
}
