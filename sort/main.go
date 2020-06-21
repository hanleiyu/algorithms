package main

import (
	"fmt"
	"math/rand"
	"strconv"
)

func randFloat64(n int) []float64{
	a := make([]float64,0)
	for i := 0; i < n; i++{
		a = append(a, rand.Float64())
	}
	return a
}

func main(){
	captureId, _ := strconv.ParseUint("1586952265", 10, 64)
	fmt.Println(captureId)

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
	fmt.Println(t1, t2, t3, t5, t6, t7)

	//c := []float64{4,4,4,2,2,7,1}
	//quick3way(c,0,6)
	//fmt.Printf("for %d random float64\n insertionSort is %.3f times faster than selectionSort\n", n, float64(t1/t2))
	//fmt.Printf("for %d random float64\n shell is %.3f times faster than insertion\n", n, float64(t2/t3))
	//fmt.Printf("for %d random float64\n merge is %.3f times faster than selection\n", n, float64(t1/t4))

	//a := queue.NewPriorityQueue(5)

	//a.Put(priorityItems(1))

	//fmt.Println(a)

}