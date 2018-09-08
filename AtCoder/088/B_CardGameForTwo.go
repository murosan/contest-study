package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

func main() {
	rdr := NewReader(200)
	rdr.ReadInt()
	a := rdr.ReadInts()

	ReverseSort(a)

	diff := 0
	for i, v := range a {
		if i%2 == 0 {
			diff += v
		} else {
			diff -= v
		}
	}

	fmt.Println(diff)
}

type Reader struct {
	rdr  *bufio.Reader
	size int
}

func NewReader(size int) Reader {
	return Reader{
		bufio.NewReaderSize(os.Stdin, size),
		size,
	}
}

func (r *Reader) ReadInt() (i int) {
	fmt.Scan(&i)
	return
}

func (r *Reader) ReadLine() string {
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

func (r *Reader) ReadStrs() []string {
	s := r.ReadLine()
	return strings.Split(s, " ")
}

func (r *Reader) ReadInts() []int {
	a := r.ReadStrs()
	n := make([]int, 0)
	for _, v := range a {
		if i, e := strconv.Atoi(v); e == nil {
			n = append(n, i)
		}
	}
	return n
}

func ReverseSort(ints []int) {
	sort.Sort(sort.Reverse(sort.IntSlice(ints)))
}
