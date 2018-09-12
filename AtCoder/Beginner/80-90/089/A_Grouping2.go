package main

import (
	"fmt"
)

func main() {
	n := ReadInt()
	fmt.Println(n / 3)
}

func ReadInt() (i int) {
	fmt.Scan(&i)
	return
}
