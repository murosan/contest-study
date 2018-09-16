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
	sc.SetSplitter(" ")
	n, k := sc.ScanInt(), sc.ScanInt()

	count := 0

	for b := 1; b <= n; b++ {
		q := n / b
		s := n % b

		count += Max(b-k, 0) * q
		if s >= k {
			count += s - Max(k-1, 0)
		}
	}

	fmt.Println(count)
}

type Scanner struct {
	sc *bufio.Scanner
}

func NewScanner(r io.Reader) *Scanner {
	return &Scanner{bufio.NewScanner(r)}
}

func (s *Scanner) SetSplitter(sep string) {
	switch sep {
	case "":
		s.sc.Split(bufio.ScanRunes)
	case " ":
		s.sc.Split(bufio.ScanWords)
	default:
		s.sc.Split(bufio.ScanLines)
	}
}

func (s *Scanner) ScanInt() int {
	s.sc.Scan()
	i, e := strconv.Atoi(s.sc.Text())
	if e != nil {
		panic(e)
	}
	return i
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
