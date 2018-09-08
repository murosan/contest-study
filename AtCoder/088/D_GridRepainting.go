package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
)

var white = "."
var isNotPath = -1

func main() {
	rdr := NewReader(10)
	height, width := ReadInt(), ReadInt()

	whiteCount := 0
	lines := make([]string, height)
	for i := range lines {
		lines[i] = ReadLine(rdr)
	}

	s := make([][]int, height)
	for i, line := range lines {
		l := make([]int, width)
		for j := 0; j < len(line); j++ {
			if line[j:j+1] == white {
				l[j] = whiteCount
				whiteCount++
			} else {
				l[j] = isNotPath
			}
		}
		s[i] = l
	}

	inRange := func(i, j int) bool {
		return 0 <= i && i < height && 0 <= j && j < width
	}

	var edges []EdgeB
	for i, line := range s {
		for j, cell := range line {
			if cell == isNotPath {
				continue
			}
			if inRange(i+1, j) && s[i+1][j] != isNotPath {
				edges = append(edges, EdgeB{From: cell, To: s[i+1][j], Distance: 1})
			}
			if inRange(i-1, j) && s[i-1][j] != isNotPath {
				edges = append(edges, EdgeB{From: cell, To: s[i-1][j], Distance: 1})
			}
			if inRange(i, j+1) && s[i][j+1] != isNotPath {
				edges = append(edges, EdgeB{From: cell, To: s[i][j+1], Distance: 1})
			}
			if inRange(i, j-1) && s[i][j-1] != isNotPath {
				edges = append(edges, EdgeB{From: cell, To: s[i][j-1], Distance: 1})
			}
		}
	}

	goal := s[height-1][width-1]
	connected, distance := BellmanFord(edges, 0, goal)

	if !connected {
		fmt.Println(isNotPath)
		return
	}
	fmt.Println(goal - distance)
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

type EdgeB struct {
	From     int
	To       int
	Distance int
}

func BellmanFord(edges []EdgeB, start, goal int) (connected bool, cost int) {
	if len(edges) == 0 {
		return
	}

	// initialize
	max := math.MaxInt32
	distances := make(map[int]int)
	for _, e := range edges {
		distances[e.From] = max
		distances[e.To] = max
	}

	// solve
	distances[start] = 0
	updated := true

	for updated {
		updated = false
		for _, e := range edges {
			c := distances[e.From] + e.Distance
			if distances[e.From] != max && distances[e.To] > c {
				distances[e.To] = c
				updated = true
			}
		}
	}

	if distances[goal] != max {
		connected = true
	}
	cost = distances[goal]

	return
}
