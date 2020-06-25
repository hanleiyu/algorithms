package main

import (
	"bufio"
	"errors"
	"flag"
	"fmt"
	"io"
	"os"
	"strings"
)

func main(){
	minlen := flag.Int("len", 1, "the min len of key")
	filePath := flag.String("path", "", "file path")
	flag.Parse()
	m := make(map[string]int)
	f, err := os.Open(*filePath)
	if err != nil {
		fmt.Println("no")
		fmt.Errorf("open %s failed", *filePath)
	}else{
		fmt.Println("ok")
		defer f.Close()
	}


	buf := bufio.NewReader(f)
	lines := make([]string, 0)
	for {
		line, err := buf.ReadBytes('\n')
		if err != nil {
			if errors.Is(err, io.EOF) { //文件已经结束
				break
			}
			fmt.Errorf("read [%s] failed", *filePath)
			break
		}
		lineStr := string(line)

		if strings.HasSuffix(lineStr, string('\n')) {
			lineStr = lineStr[0 : len(lineStr)-1]
			lines = append(lines, lineStr)
		} else {
			lines = append(lines, lineStr)
		}
	}

	for i := range lines {
		word := strings.Split(lines[i], " ")
		for j := range word {
			w := word[j]
			if len(w) < *minlen {
				break
			}
			if _, ok := m[w]; ok {
				m[w]++
			}else{
				m[w] = 1
			}
		}
	}

	max := ""
	m[max] = 0
	for k, v := range m {
		if v > m[max] {
			max = k
		}
	}

	fmt.Println(max, " ", m[max])
}