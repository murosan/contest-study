package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"sort"
	"strconv"
)

var sc = NewScanner(os.Stdin)

func main() {
	n := sc.ScanInt()

	red := make(map[int]int)
	for i := 0; i < n; i++ {
		red[sc.ScanInt()] = sc.ScanInt()
	}

	blue := make(TupleArray, n)
	for i := range blue {
		blue[i] = []int{sc.ScanInt(), sc.ScanInt()}
	}
	sort.Sort(blue)

	ans := 0

	for _, t := range blue {
		x, maxY := -1, -1
		for a, b := range red {
			if a < t[0] && b < t[1] && b > maxY {
				x, maxY = a, b
			}
		}
		if maxY != -1 {
			ans++
			delete(red, x)
		}
	}

	fmt.Println(ans)
}

type TupleArray [][]int

func (a TupleArray) Len() int {
	return len(a)
}

func (a TupleArray) Swap(i, j int) {
	a[i], a[j] = a[j], a[i]
}

func (a TupleArray) Less(i, j int) bool {
	return a[i][0] < a[j][0]
}

type Scanner struct {
	sc *bufio.Scanner
}

func NewScanner(r io.Reader) *Scanner {
	s := &Scanner{bufio.NewScanner(r)}
	s.sc.Split(bufio.ScanWords)
	return s
}

func (s *Scanner) ScanInt() int {
	s.sc.Scan()
	i, e := strconv.Atoi(s.sc.Text())
	if e != nil {
		panic(e)
	}
	return i
}
