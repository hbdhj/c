package main

import (
    "fmt"
    "log"
    "net/http"
    "sync"
)

var mu sync.Mutex
var cnt int

func main() {
    http.HandleFunc("/", handler) // each request calls handler
    http.HandleFunc("/count", counter) // each request calls handler
    log.Fatal(http.ListenAndServe("localhost:8000", nil))
}

// handler echoes the path component of the requested url
func handler(w http.ResponseWriter, r *http.Request) {
    mu.Lock()
    cnt++
    mu.Unlock()
    fmt.Fprintf(w, "URL.path = %q\n", r.URL.Path)
}

// counter echoes the number of calls so far
func counter(w http.ResponseWriter, r *http.Request) {
    mu.Lock()
    fmt.Fprintf(w, "Count %d\n", cnt)
    mu.Unlock()
}
