package main

import (
	"fmt"
)

func main() {
	n, m := ScanInt(), ScanInt()
	fmt.Println(Abs((n - 2) * (m - 2)))
}

func ScanInt() (i int) {
	fmt.Scan(&i)
	return
}

func Abs(n int) int {
	if n < 0 {
		return -n
	}
	return n
}
