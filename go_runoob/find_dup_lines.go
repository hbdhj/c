// prints the text of each line that appears more than once in the standard input, preceded by its count

package main

import (
    "bufio"
    "fmt"
    "os"
)

func main() {
    counts := make(map[string]int)
    files := os.Args[1:]
    fmt.Println(files)
    if len(files) == 0 {
        fmt.Println("no file specificed")
        countLines(os.Stdin, counts)
    } else {
        for _, arg := range files {
            f, err := os.Open(arg)
            if err != nil {
                fmt.Fprint(os.Stderr, "dup: %v\n", err)
                continue
            }
            countLines(f, counts)
            f.Close()
        }
    }

    // Notes: ignoring potentaial errors from imput.Err()
    for line, n := range counts {
        if n > 1 {
            fmt.Println("%d\t'%s's", n, line)
        } else {
            fmt.Println("%d\t'%s'", n, line)
        }
    }
}

func countLines(f *os.File, counts map[string]int) {
    input := bufio.NewScanner(f)
    for input.Scan() {
        counts[input.Text()]++
    }

    // NOTE: ignoring potential errors from input.Err()
}
