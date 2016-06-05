func soleTitle(doc *html.Node) (title string, err error) {
    type bailout struct {}

    defer func() {
        switch p := recover(); p {
        case nil:
            // no panic
        case bailout{}:
            // "expected" panic
            err = fmt.Errorf("multiple title elements")
        default:
            panic(p) // unexpected panic; carry on panicking
        }
    }()

    // bail out of recursion if we find more than one non-empty title
    forEachNode(doc, func(n *html.Node)) {
        if n.Type == html.ElementNode && n.Data == "title" && n.FirstChild != nil {
            if title != "" {
                panic(bailout{}) // multiple title elements
            }
            title = n.FirstChild.Data
        }
    }, nil)
    if title == "" {
        return "", fmt.Errorf("no title element")
    }
    return title, nil
}
