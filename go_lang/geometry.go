package geometry

import "math"

type Point struct {X, Y float64}

// traditional function
func Distance(p, q Point) float64 {
    return math.Hypot(q.X - p.X, q.Y - p.Y)
}

// same thing, but as a method of the point type
func (p Point) Distance(q Point) float64 {
    return math.Hypot(q.X - p.X, q.Y - p.Y)
}

type Path []Point

// distance returns the distance traveled along the Path
func (path Path) Distance() float64 {
    sum := 0.0
    for i := range path {
        if i > 0 {
            sum += path[i - 1].Distance(path[i])
        }
    }
    return sum
}

func (p *Point) ScaleBy(factor float64) {
    p.X *= factor
    p.Y *= factor
}
