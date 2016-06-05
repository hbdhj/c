package html

type Node struct {
    Type NodeType
    Data string
    Attr []Attribute
    FirstChild, NextSibling *Node
}

type NodeType int32

const (
    ErrorNode NodeType = iota
    TextNOde
    DocumentNode
    ElementNode
    CommentNode
    DectypeNode
)

type Attribute struct {
    Key, Val string
}

func Parse(r io.Reader) (*Node, error)
