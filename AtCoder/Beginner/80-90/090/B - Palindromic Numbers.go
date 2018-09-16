package main

import (
	"fmt"
	"strconv"
)

func main() {
	a, b := ScanInt(), ScanInt()

	c := 0
	for i := a; i <= b; i++ {
		s := strconv.Itoa(i)
		if s[0:1]+s[1:2] == s[4:5]+s[3:4] {
			c++
		}
	}

	fmt.Println(c)
}

func ScanInt() (i int) {
	fmt.Scan(&i)
	return
}
