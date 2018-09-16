package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	rdr := NewReader(10000)
	a := ReadLine(rdr)
	b := ReadLine(rdr)
	c := ReadLine(rdr)

	fmt.Println(a[0:1] + b[1:2] + c[2:3])
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
