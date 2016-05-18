// prints its command-line arguments

package main

import (
    "fmt"
    "os"
)

func main() {
    fmt.Println(os.Args[1:])

    var s, sep string
    for i := 1; i<len(os.Args); i++ {
        s += sep + os.Args[i]
        sep = ", "
    }
    fmt.Println(s)

    s1, sep1 := "", ": "
    for _, arg := range os.Args[1:] {
        s1 += sep1 + arg
    }
    fmt.Println(s1)
}
