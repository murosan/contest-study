//////////////////////
// TLE
//////////////////////

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
	tmpa := sc.ScanBigInts(n)
	tmpb := sc.ScanBigInts(n)

	var res int64
	for bit := 0; bit < 29; bit++ {
		var t int64 = 1 << uint32(bit)
		a, b := make(BigInts, n), make(BigInts, n)
		for i := range a {
			a[i], b[i] = tmpa[i]%(2*t), tmpb[i]%(2*t)
		}
		sort.Sort(b)

		c := 0
		for _, aa := range a {
			c1 := SearchBigInts(b, t-aa)
			c2 := SearchBigInts(b, 2*t-aa)
			c3 := SearchBigInts(b, 3*t-aa)
			c4 := SearchBigInts(b, 4*t-aa)
			c = (c + c2 - c1 + c4 - c3) % 2
		}

		if c == 1 {
			res += t
		}
	}

	fmt.Println(res)
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

func (s *Scanner) ScanBigInt() int64 {
	s.sc.Scan()
	i, e := strconv.ParseInt(s.sc.Text(), 10, 64)
	if e != nil {
		panic(e)
	}
	return i
}

func (s *Scanner) ScanBigInts(len int) []int64 {
	a := make([]int64, len)
	for i := 0; i < len; i++ {
		a[i] = s.ScanBigInt()
	}
	return a
}

type BigInts []int64

func (a BigInts) Len() int {
	return len(a)
}

func (a BigInts) Swap(i, j int) {
	a[i], a[j] = a[j], a[i]
}

func (a BigInts) Less(i, j int) bool {
	return a[i] < a[j]
}

func SearchBigInts(a []int64, x int64) int {
	return sort.Search(len(a), func(i int) bool { return a[i] >= x })
}
