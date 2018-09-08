package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	rdr := NewReader(10)
	l1 := ReadInts(rdr)
	l2 := ReadInts(rdr)
	l3 := ReadInts(rdr)

	a1 := l2[0] - l1[0]
	a2 := l3[0] - l1[0]

	x := a1 == l2[1]-l1[1] && a1 == l2[2]-l1[2]
	y := a2 == l3[1]-l1[1] && a2 == l3[2]-l1[2]

	if x && y {
		fmt.Println("Yes")
		return
	}

	fmt.Println("No")
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
