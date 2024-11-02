#include "Node.h"

double BoxImplicit::value(const Vector &p) const {

    Vector d = Abs(p - center) - halfSize;
    double outsideDist = Norm(Vector(std::max(d[0], 0.0), std::max(d[1], 0.0), std::max(d[2], 0.0)));
    double insideDist = std::min(std::max(d[0], std::max(d[1], d[2])), 0.0);

    return outsideDist + insideDist;
}

Node * BoxImplicit::clone() const {
    return new BoxImplicit(center, halfSize);
}

double Sphere::value(const Vector &p) const {
    return Norm(p - center) - radius;
}

Node * Sphere::clone() const {
    return new Sphere(center, radius);
}

double Torus::value(const Vector &p) const {

    double q = Norm(Vector(p[0], 0, p[2])) - maxRadius;
    return Norm(Vector(q, p[1], 0)) - minRadius;
}

Node * Torus::clone() const {
    return new Torus(center, minRadius, maxRadius);
}

double Capsule::value(const Vector &p) const {

    Vector newPoint = p - center;
    newPoint[1] -= Math::Clamp(newPoint[1], 0.0, height);
    return Norm(newPoint) - radius;
}

Node * Capsule::clone() const {
    return new Capsule(center, height, radius);
}

double Cone::value(const Vector &p) const {

    const double q = Norm(Vector(p[0], 0, p[2]));
    return std::max(Vector(cos, sin, 0) * Vector(q, p[1], 0), -height - p[1]);

}

Node * Cone::clone() const {
    return new Cone(center, sin, cos, height);
}

double Cylinder::value(const Vector& p) const {
    Vector d = p - center;

    double horizontalDist = std::sqrt(d[0] * d[0] + d[2] * d[2]) - radius;

    if (height < 0) {
        return horizontalDist;
    } else {
        double verticalDist = std::abs(d[1]) - (height / 2);
        double outsideDist = std::sqrt(std::max(horizontalDist, 0.0) * std::max(horizontalDist, 0.0) +
                                       std::max(verticalDist, 0.0) * std::max(verticalDist, 0.0));
        double insideDist = std::min(std::max(horizontalDist, verticalDist), 0.0);
        return outsideDist + insideDist;
    }
}

Node* Cylinder::clone() const {
    return new Cylinder(center, radius, height);
}

double Union::value(const Vector &p) const {
    return std::min(left->value(p),  right->value(p));
}

Node * Union::clone() const {
    return new Union(*left, *right);
}

double Intersection::value(const Vector &p) const {
    return std::max(left->value(p), right->value(p));
}

Node * Intersection::clone() const {
    return new Intersection(*left, *right);
}

double Difference::value(const Vector &p) const {
    return std::max(left->value(p), -right->value(p));
}

Node * Difference::clone() const {
    return new Difference(*left, *right);
}

double UnionSmooth::offset(const Vector &p) const{
    double h = std::max(0., radius - std::abs(left->value(p) - right->value(p)))/radius;
    return (1./6.)*radius*std::pow(h, 3);
}

double UnionSmooth::value(const Vector &p) const {
    return std::min(left->value(p), right->value(p)) - offset(p);
}

Node * UnionSmooth::clone() const {
    return new UnionSmooth(*left, *right);
}

double IntersectionSmooth::offset(const Vector &p) const{
    double h = std::max(0., radius - std::abs(left->value(p) - right->value(p)))/radius;
    return (1./6.)*radius*std::pow(h, 3);
}

double IntersectionSmooth::value(const Vector &p) const {
    return std::max(left->value(p), right->value(p)) + offset(p);
}

Node * IntersectionSmooth::clone() const {
    return new IntersectionSmooth(*left, *right);
}

double DifferenceSmooth::offset(const Vector &p) const{
    double h = std::max(0., radius - std::abs(left->value(p) - right->value(p)))/radius;
    return (1./6.)*radius*std::pow(h, 3);
}

double DifferenceSmooth::value(const Vector &p) const {
    return std::max(left->value(p), -right->value(p)) + offset(p);
}

Node * DifferenceSmooth::clone() const {
    return new DifferenceSmooth(*left, *right);
}

double Translation::value(const Vector &p) const {
    return node->value(p - t);
}

Node * Translation::clone() const {
    return new Translation(*node, t);
}

double RotationX::value(const Vector &p) const {
    double t = Math::DegreeToRadian(theta);
    Vector res = Vector(
        p[0],
        std::cos(t) * p[1] + (-std::sin(t)) * p[2],
        std::sin(t) * p[2] + std::cos(t) * p[2]
        );
    return node->value(res);
}

Node * RotationX::clone() const {
    return new RotationX(*node, theta);
}

double RotationY::value(const Vector &p) const {
    double t = Math::DegreeToRadian(theta);
    Vector res = Vector(
        std::cos(t) * p[0] + (-std::sin(t)) * p[2],
        p[1],
        std::sin(t) * p[0] + std::cos(t) * p[2]
        );
    return node->value(res);
}

Node * RotationY::clone() const {
    return new RotationY(*node, theta);
}

double RotationZ::value(const Vector &p) const {
    double t = Math::DegreeToRadian(theta);
    Vector res = Vector(
        std::cos(t) * p[0] + (-std::sin(t)) * p[1],
        std::sin(t) * p[0] + std::cos(t) * p[1],
        p[2]
        );
    return node->value(res);
}

Node * RotationZ::clone() const {
    return new RotationZ(*node, theta);
}

double Scale::value(const Vector &p) const {
    double res = node->value(Vector(p[0]/s[0], p[1]/s[1], p[2]/s[2]));
    return res;
}

Node * Scale::clone() const {
    return new Scale(*node, s);
}

double Twist::value(const Vector &p) const {
    double theta = angle * p[1];
    double cosTheta = std::cos(theta);
    double sinTheta = std::sin(theta);

    Vector twistedPoint(
        cosTheta * p[0] - sinTheta * p[2],
        sinTheta * p[0] + cosTheta * p[2],
        p[2]
        );

    return node->value(twistedPoint);
}

Node * Twist::clone() const {
    return new Twist(*node, angle);
}

Node * computeDNA() {

    const Node &body = Scale(
            DifferenceSmooth(
                Twist(Cylinder(Vector(0.,0.,0), 5.0, 5.0), 0.5),
                Twist(Cylinder(Vector(0.,0.,0.), 4.5, 5.0), 0.5)),
            Vector(0.5, 0.5, 0.5)
        );

    const Node &horizontalSticks = Union(
        Scale(
            RotationZ(
                Cylinder(Vector(0.,0.,0.), 0.3, 10.),
                90.),
            Vector(0.5, 0.5, 0.5)),
        Union(
            Scale(
                RotationZ(
                    Translation(
                        Cylinder(Vector(0.,0.,0.), 0.3, 10.),
                        Vector(6.5,0.,0.)),
                    90.),
                Vector(0.5, 0.5, 0.5)
                ),
            Scale(
                RotationZ(
                    Translation(
                        Cylinder(Vector(0.,0.,0.), 0.3, 10.),
                        Vector(-6.5,0.,0.)),
                    90.),
                Vector(0.5, 0.5, 0.5)
                )
            )
        );


    const Node &verticalSticks = Union(
        Scale(
            RotationY(
                RotationZ(
                    Translation(
                        Cylinder(Vector(0.,0.,0.), 0.3, 6.5),
                        Vector(-3.25,0.,0.)),
                    90.),
                90.),
            Vector(0.5, 0.5, 0.5)),
        Union(
            Scale(
                RotationY(
                    RotationZ(
                        Translation(
                            Cylinder(Vector(0.,0.,0.), 0.3, 6.5),
                            Vector(3.25,0.,0.)),
                        90.),
                    90.),
                Vector(0.5, 0.5, 0.5)),
            Union(
                Scale(
                    RotationY(
                        RotationZ(
                            Translation(
                                Cylinder(Vector(0.,0.,0.), 0.3, 6.5),
                                Vector(9.75,0.,0.)),
                            90.),
                        90.),
                    Vector(0.5, 0.5, 0.5)),
                Scale(
                    RotationY(
                        RotationZ(
                            Translation(
                                Cylinder(Vector(0.,0.,0.), 0.3, 6.5),
                                Vector(-9.75,0.,0.)),
                            90.),
                        90.),
                    Vector(0.5, 0.5, 0.5))
                )
            )
        );

    const Node &midSticks = Union(
        Scale(
            RotationY(
                RotationZ(
                    Translation(
                        Cylinder(Vector(0.,0.,0.), 0.3, 7.),
                        Vector(1.625,0.,0.)),
                    90.),
                -45.),
            Vector(0.5, 0.5, 0.5)),
        Union(
            Scale(
                RotationY(
                    RotationZ(
                        Translation(
                            Cylinder(Vector(0.,0.,0.), 0.3, 7.),
                            Vector(-1.625,0.,0.)),
                        90.),
                    45.),
                Vector(0.5, 0.5, 0.5)),
            Union(
                Scale(
                    RotationY(
                        RotationZ(
                            Translation(
                                Cylinder(Vector(0.,0.,0.), 0.3, 7.),
                                Vector(4.875,0.,0.)),
                            90.),
                        45.),
                    Vector(0.5, 0.5, 0.5)),
                Union(
                    Scale(
                        RotationY(
                            RotationZ(
                                Translation(
                                    Cylinder(Vector(0.,0.,0.), 0.3, 7.),
                                    Vector(-4.875,0.,0.)),
                                90.),
                            -45.),
                        Vector(0.5, 0.5, 0.5)),
                    Union(
                        Scale(
                            RotationY(
                                RotationZ(
                                    Translation(
                                        Cylinder(Vector(0.,0.,0.), 0.3, 7.),
                                        Vector(8.125,0.,0.)),
                                    90.),
                                -45.),
                            Vector(0.5, 0.5, 0.5)),
                        Scale(
                            RotationY(
                                RotationZ(
                                    Translation(
                                        Cylinder(Vector(0.,0.,0.), 0.3, 7.),
                                        Vector(-8.125,0., 0.)),
                                    90.),
                                45.),
                            Vector(0.5, 0.5, 0.5))
                        )
                    )
                )
            )
        );

    return new UnionSmooth(UnionSmooth(body, Union(horizontalSticks, Union(verticalSticks, midSticks))));

}
