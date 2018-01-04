package main

import "fmt"

func main() {
	var n int
	fmt.Scan(&n)

	maxAbsIndex := 0

	a := make([]int, n)
	for i := range a {
		fmt.Scan(&a[i])
		if Abs(a[i]) > Abs(a[maxAbsIndex]) {
			maxAbsIndex = i
		}
	}

	fmt.Println(2*n - 1)

	for i := range a {
		fmt.Println(maxAbsIndex+1, i+1)
	}

	if a[maxAbsIndex] < 0 {
		for i := n; i > 1; i-- {
			fmt.Println(i, i-1)
		}
	} else {
		for i := range a[:len(a)-1] {
			fmt.Println(i+1, i+2)
		}
	}
}

func Abs(n int) int {
	if n < 0 {
		return -n
	}
	return n
}
