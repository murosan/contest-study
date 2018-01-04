package main

import (
	"fmt"
)

func main() {
	var n, q int
	fmt.Scan(&n)

	a := make([]int, n)
	for i := range a {
		fmt.Scan(&a[i])
	}

	fmt.Scan(&q)

	// uninvestigated:0, true:1, false:-1
	memo := make([][2000]int, n)

	var solve func(int, int) bool
	solve = func(i, m int) bool {
		if m == 0 {
			return true
		}

		if i >= n || m < 0 {
			return false
		}

		if memo[i][m] != 0 {
			if memo[i][m] == 1 {
				return true
			}
			return false
		}

		unused := solve(i+1, m)
		used := solve(i+1, m-a[i])
		res := unused || used
		if res {
			memo[i][m] = 1
		} else {
			memo[i][m] = -1
		}

		return res
	}

	for i := 0; i < q; i++ {
		var m int
		fmt.Scan(&m)
		if solve(0, m) {
			fmt.Println("yes")
		} else {
			fmt.Println("no")
		}
	}
}
