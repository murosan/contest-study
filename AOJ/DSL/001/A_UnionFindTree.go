package Typical

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// UnionFind tree for programming contest
type UnionFind struct {
	par  []int
	rank []int
}

func (uf *UnionFind) root(i int) int {
	if uf.par[i] == i {
		return i
	}
	uf.par[i] = uf.root(uf.par[i])
	return uf.par[i]
}

func (uf *UnionFind) same(x, y int) bool {
	return uf.root(x) == uf.root(y)
}

func (uf *UnionFind) unite(x, y int) {
	x = uf.root(x)
	y = uf.root(y)
	if x == y {
		return
	}

	if uf.rank[x] < uf.rank[y] {
		uf.par[x] = y
	} else {
		uf.par[y] = x
		if uf.rank[x] == uf.rank[y] {
			uf.rank[x]++
		}
	}
}

func main() {
	var n, q int
	fmt.Scan(&n, &q)

	orders := make([][]int, q)
	for i := range orders {
		orders[i] = readIntArray()
	}

	uf := &UnionFind{make([]int, n), make([]int, n)}

	for i := range uf.par {
		uf.par[i] = i
		uf.rank[i] = 0
	}

	for _, q := range orders {
		if q[0] == 0 {
			uf.unite(q[1], q[2])
		} else {
			if uf.same(q[1], q[2]) {
				fmt.Println("Yes")
			} else {
				fmt.Println("No")
			}
		}
	}
}

// reader
var size = 1000000
var rdr = bufio.NewReaderSize(os.Stdin, size)

func readLine() string {
	buf := make([]byte, 0, size)
	for {
		line, isPrefix, err := rdr.ReadLine()
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

func readArray() []string {
	s := readLine()
	return strings.Split(s, " ")
}

func readIntArray() []int {
	a := readArray()
	n := make([]int, 0)
	for _, v := range a {
		if i, e := strconv.Atoi(v); e == nil {
			n = append(n, i)
		}
	}
	return n
}
