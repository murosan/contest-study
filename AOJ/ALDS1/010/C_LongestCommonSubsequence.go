package main

import "fmt"

func main() {
	var n int
	fmt.Scan(&n)

	for q := 0; q < n; q++ {
		var s1, s2 string
		fmt.Scan(&s1, &s2)
		s1, s2 = " " + s1, " " + s2

		dp := make([][]int, len(s1))
		for i := range dp {
			dp[i] = make([]int, len(s2))
		}

		max := 0

		for i := 1; i < len(s1); i++ {
			for j := 1; j < len(s2); j++ {
				if s1[i] == s2[j] {
					dp[i][j] = dp[i-1][j-1] + 1
				} else {
					dp[i][j] = Max(dp[i-1][j], dp[i][j-1])
				}
				max = Max(max, dp[i][j])
			}
		}

		fmt.Println(max)
	}
}

func Max(n ...int) int {
	max := n[0]
	for _, v := range n[1:] {
		if v > max {
			max = v
		}
	}
	return max
}
