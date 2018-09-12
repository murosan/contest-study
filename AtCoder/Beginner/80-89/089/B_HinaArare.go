package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	ReadInt()
	rdr := NewReader(120)
	s := ReadStrs(rdr)

	m := make(map[string]bool)
	for _, c := range s {
		m[c] = true
	}

	if len(m) == 3 {
		fmt.Println("Three")
		return
	}
	if len(m) == 4 {
		fmt.Println("Four")
		return
	}
}

func ReadInt() (i int) {
	fmt.Scan(&i)
	return
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
