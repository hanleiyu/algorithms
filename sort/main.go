package main

import (
	"fmt"
	"math"
	"math/rand"
	"strconv"
	"time"
)

func randFloat64(n int) []float64{
	a := make([]float64,0)
	for i := 0; i < n; i++{
		a = append(a, rand.Float64())
	}
	return a
}

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

	for i:= 0; i < len(a); i++ {
		for j := i; j > 0 && a[j] < a[j-1]; j-- {
				a[j], a[j-1] = a[j-1], a[j]
		}
	}
	//fmt.Println("insertionSort : ",a)

	return time.Since(start)/time.Nanosecond
}

func insertionSortImprove(a []int){
	for i:= 0; i < len(a); i++ {
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

func main(){
	captureId, _ := strconv.ParseUint("1586952265", 10, 64)
	fmt.Println(captureId)
	/*
	n := 50000

	c := make([]float64, 0)
	for i := 0; i < n; i++{
		c = append(c, 0.05)
	}

	t1 := selectionSort(randFloat64(n))
	t2 := insertionSort(randFloat64(n))
	//a := []int{10,9,5,1,7,6,2,0}
	//a := []int{1,4,6,2,3,5}

	t3 := shellSort(randFloat64(n))
	b := make([]float64, n)
	//t4 := mergeSort(randFloat64(n), b, 0, n-1)
	t5 := mergeSortImprove(randFloat64(n), b, 0, n-1)
	//fmt.Println(a)
	t6 := quickSort(randFloat64(n), 0, n-1)
	t7 := quickSortImprove(randFloat64(n), 0, n-1)
	fmt.Println(t3, t5, t6, t7)
	*/
	//c := []float64{4,4,4,2,2,7,1}
	//quick3way(c,0,6)
	//fmt.Printf("for %d random float64\n insertionSort is %.3f times faster than selectionSort\n", n, float64(t1/t2))
	//fmt.Printf("for %d random float64\n shell is %.3f times faster than insertion\n", n, float64(t2/t3))
	//fmt.Printf("for %d random float64\n merge is %.3f times faster than selection\n", n, float64(t1/t4))

	//a := queue.NewPriorityQueue(5)

	//a.Put(priorityItems(1))

	//fmt.Println(a)

}