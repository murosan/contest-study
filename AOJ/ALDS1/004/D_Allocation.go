package main

import (
	"fmt"
)

func main() {
	var n, k int
	fmt.Scan(&n, &k)

	w := make([]int, n)
	for i := range w {
		fmt.Scan(&w[i])
	}

	fmt.Println(search(1, 1000000000, n, k, w))
}

func canLoadAll(maxWeight, k, n int, w []int) bool {
	trackCount := 0
	i := 0
	for i < n {
		weight := 0
		for i < n && weight+w[i] <= maxWeight {
			weight += w[i]
			i++
		}
		trackCount++
		if trackCount > k {
			return false
		}
	}

	return true
}

func search(lower, upper, n, k int, w []int) int {
	l := lower
	u := upper
	for u-l != 1 {
		middle := (u-l)/2 + l
		if canLoadAll(middle, k, n, w) {
			u = middle
		} else {
			l = middle
		}
	}

	if canLoadAll(l, k, n, w) {
		return l
	}
	return u
}
