package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
)

func main() {
	sc := NewScanner(os.Stdin)
	n := sc.ScanInt()
	s := sc.ScanStrs(n)

	m := sc.ScanInt()
	t := sc.ScanStrs(m)

	r := make(map[string]int)

	for _, v := range s {
		r[v]++
	}
	for _, v := range t {
		r[v]--
	}

	max := 0
	for _, v := range r {
		if v > max {
			max = v
		}
	}

	fmt.Println(max)
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

func (s *Scanner) ScanStr() string {
	s.sc.Scan()
	return s.sc.Text()
}

func (s *Scanner) ScanStrs(len int) []string {
	a := make([]string, len)
	for i := 0; i < len; i++ {
		a[i] = s.ScanStr()
	}
	return a
}
