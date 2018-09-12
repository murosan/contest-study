package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type Point struct {
	x int
	y int
}

func main() {
	rdr := NewReader(10000)
	H, W, D := ScanInt(), ScanInt(), ScanInt()

	max := H*W + 1
	px := make([]int, max)
	py := make([]int, max)
	for i := 0; i < H; i++ {
		s := ReadInts(rdr)
		for j, v := range s {
			px[v] = i
			py[v] = j
		}
	}

	memo := make([]int, max)
	for i := 1 + D; i <= H*W; i++ {
		memo[i] = memo[i-D] + Abs(px[i]-px[i-D]) + Abs(py[i]-py[i-D])
	}

	Q := ReadInt(rdr)

	for i := 0; i < Q; i++ {
		ints := ReadInts(rdr)
		L, R := ints[0], ints[1]
		fmt.Println(memo[R] - memo[L])
	}
}

type Reader struct {
	rdr  *bufio.Reader
	size int
}

func NewReader(size int) *Reader {
	return &Reader{
		bufio.NewReaderSize(os.Stdin, size),
		size,
	}
}

func ScanInt() (i int) {
	fmt.Scan(&i)
	return
}

func ReadLine(r *Reader) string {
	buf := make([]byte, 0, r.size)
	for {
		line, isPrefix, err := r.rdr.ReadLine()
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

func ReadStrs(r *Reader) []string {
	return strings.Split(ReadLine(r), " ")
}

func ReadInts(r *Reader) []int {
	a := ReadStrs(r)
	n := make([]int, 0)
	for _, v := range a {
		if i, e := strconv.Atoi(v); e == nil {
			n = append(n, i)
		}
	}
	return n
}

func Abs(n int) int {
	if n < 0 {
		return -n
	}
	return n
}

func ReadInt(r *Reader) (n int) {
	if i, e := strconv.Atoi(ReadLine(r)); e == nil {
		n = i
	}
	return
}
