// prints the text of each line that appears more than once in the standard input, preceded by its count

package main

import (
    "io/ioutil"
    "fmt"
    "os"
    "strings"
)

func main() {
    counts := make(map[string]int)

    for _, filename := range os.Args[1:] {
        data, err := ioutil.ReadFile(filename)
        if err != nil {
            fmt.Fprint(os.Stderr, "dup: %v\n", err)
            continue
        }
        for _, line := range strings.Split(string(data), "\n") {
            counts[line]++
        }
    }

    // Notes: ignoring potentaial errors from imput.Err()
    for line, n := range counts {
        if n > 1 {
            fmt.Printf("%d\t'%s's\n", n, line)
        } else {
            fmt.Printf("%d\t'%s'\n", n, line)
        }
    }
}
