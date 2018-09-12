package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	rdr := NewReader(20)
	n := ReadInt()

	l := make([]int64, 5)

	for i := 0; i < n; i++ {
		name := ReadLine(rdr)
		if name[0:1] == "M" {
			l[0]++
		}
		if name[0:1] == "A" {
			l[1]++
		}
		if name[0:1] == "R" {
			l[2]++
		}
		if name[0:1] == "C" {
			l[3]++
		}
		if name[0:1] == "H" {
			l[4]++
		}
	}

	res := int64(0)
	for i := 0; i < 5; i++ {
		for j := i + 1; j < 5; j++ {
			for k := j + 1; k < 5; k++ {
				res += l[i] * l[j] * l[k]
			}
		}
	}

	fmt.Println(res)
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

func ReadInt() (i int) {
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
