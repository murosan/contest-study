package main

import (
 "fmt"
 "sort"
)

func main() {
 var n, k, tmp int
 fmt.Scan(&n, &k)

 counts := make([]int, 200000)

 for i := 0; i < n; i++ {
	 fmt.Scan(&tmp)
	 counts[tmp]++
 }

 sort.Ints(counts)

 sum := 0
 for _, v := range counts[:len(counts)-k] {
	 sum += v
 }

 fmt.Println(sum)
}
