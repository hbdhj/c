import "image/color"

type Point strut { X, Y float64}

type ColoredPoint struct {
    Point
    Color color.RGBA
}

red := color.RGBA(255, 0, 0, 255)
blue := color.RGBA(0, 0, 255, 255)
var p = ColoredPoint{Point{1, 1}, red}
var q = ColoredPoint{Point{5, 4}, blue}
fmt.Println(p.Distance(q.Point))
p.ScaleBy(2)
q.ScaleBy(2)
fmt.Println(p.Distance(q.Point))

func (p ColoredPoint) Distance(q Point) float64
