package main

import (
	"fmt"
	"sort"
	"bufio"
	"os"
	"strings"
	"strconv"
)

func main() {
	var n, k int
	fmt.Scan(&n, &k)

	a := ReadIntArray()

	counts := make([]int, 200000)

	for _, v := range a {
		counts[v-1]++
	}

	sort.Ints(counts)

	sum := 0
	for _, v := range counts[:len(counts)-k] {
		sum += v
	}

	fmt.Println(sum)
}

// reader
var size = 200000
var rdr = bufio.NewReaderSize(os.Stdin, size)

func ReadLine() string {
	buf := make([]byte, 0, size)
	for {
		line, isPrefix, err := rdr.ReadLine()
		if err != nil {
			panic(err)
		}
		buf = append(buf, line...)
		if !isPrefix {
			break
		}
	}
	return string(buf)
}

func ReadArray() []string {
	s := ReadLine()
	return strings.Split(s, " ")
}

func ReadIntArray() []int {
	a := ReadArray()
	n := make([]int, 0)
	for _, v := range a {
		if i, e := strconv.Atoi(v); e == nil {
			n = append(n, i)
		}
	}
	return n
}
