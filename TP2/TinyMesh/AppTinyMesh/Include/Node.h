#ifndef NODE_H
#define NODE_H

#include <memory>
#include "mathematics.h"

enum Axis  {
    X = 0,
    Y = 1,
    Z = 2
};

class Node {

public:

    virtual double value(const Vector &p) const = 0;
    virtual Node * clone() const = 0;
    virtual ~Node() = default;

};

class BoxImplicit : public Node {
public:
    BoxImplicit(const Vector &c, const Vector &h) : center(c), halfSize(h) {}
    virtual double value(const Vector &p) const override;
    virtual Node * clone() const override;

private:
    Vector center;
    Vector halfSize;
};

class Sphere : public Node {

public:

    Sphere(const Vector & c, const double &r) : center(c), radius(r) {}
    virtual double value(const Vector &p) const override;
    virtual Node * clone() const override;

private:

    Vector center;
    double radius;

};

class Torus : public Node {
public:
    Torus(const Vector & c, const double &minR, const double &maxR) : center(c), minRadius(minR), maxRadius(maxR) {}
    virtual double value(const Vector &p) const override;
    virtual Node * clone() const override;

private:
    Vector center;
    double minRadius;
    double maxRadius;
};

class Capsule : public Node {
public:
    Capsule(const Vector & c, const double &h, const double &r) : center(c), height(h), radius(r) {}
    virtual double value(const Vector &p) const override;
    virtual Node * clone() const override;

private:
    Vector center;
    double height;
    double radius;
};

class Cone : public Node {
public:
    Cone(const Vector & c, const double &sin, const double &cos, const double &h) : center(c), sin(sin), cos(cos), height(h){}
    virtual double value(const Vector &p) const override;
    virtual Node * clone() const override;

private:
    Vector center;
    double sin;
    double cos;
    double height;
};

class Cylinder : public Node {
public:
    Cylinder(const Vector& center, double radius, double height = -1)
        : center(center), radius(radius), height(height) {}

    virtual double value(const Vector& p) const override;
    virtual Node* clone() const override;

private:
    Vector center;
    double radius;
    double height;
};

class BinaryOperation : public Node {
public:
    BinaryOperation(const Node &l, const Node &r) : left(l.clone()), right(r.clone()) {}
    ~BinaryOperation() {
        delete left;
        delete right;
    }

protected:
    Node *left;
    Node *right;

};

class Union : public BinaryOperation {
public:

    Union(const Node &l, const Node &r) : BinaryOperation(l, r) {}
    virtual double value(const Vector &p) const override;
    virtual Node * clone() const override;
};

class Intersection : public BinaryOperation {
public:

    Intersection(const Node &l, const Node &r) : BinaryOperation(l, r) {}
    virtual double value(const Vector &p) const override;
    virtual Node * clone() const override;
};

class Difference : public BinaryOperation {
public:

    Difference(const Node &l, const Node &r) : BinaryOperation(l, r) {}
    virtual double value(const Vector &p) const override;
    virtual Node * clone() const override;
};

class UnionSmooth : public BinaryOperation {
public:
    UnionSmooth(const Node &l, const Node &r) : BinaryOperation(l, r), radius(1.0) {}
    virtual double value(const Vector &p) const override;
    virtual Node * clone() const override;

private:

    double offset(const Vector &p) const;

    double radius;
};

class IntersectionSmooth : public BinaryOperation {
public:
    IntersectionSmooth(const Node &l, const Node &r) : BinaryOperation(l, r), radius(1.0) {}
    virtual double value(const Vector &p) const override;
    virtual Node * clone() const override;

private:

    double offset(const Vector &p) const;

    double radius;
};

class DifferenceSmooth : public BinaryOperation {
public:
    DifferenceSmooth(const Node &l, const Node &r) : BinaryOperation(l, r), radius(1.0) {}
    virtual double value(const Vector &p) const override;
    virtual Node * clone() const override;

private:

    double offset(const Vector &p) const;

    double radius;
};

class Transform : public Node {
public:
    Transform(const Node &n) : node(n.clone()){}
    ~Transform() { delete node; }

protected:

    Node * node;
};

class Translation : public Transform {
public:
    Translation(const Node &n, const Vector &t) : Transform(n), t(t) {}
    virtual double value(const Vector &p) const override;
    virtual Node * clone() const override;

private:

    Vector t;
};

class Rotation : public Transform {
public:

    Rotation(const Node &n, const double &t) : Transform(n), theta(t) {}

protected:

    double theta;
};

class RotationX : public Rotation {
public:
    RotationX(const Node &n, const double &t) : Rotation(n, t) {}
    virtual double value(const Vector &p) const override;
    virtual Node * clone() const override;
};

class RotationY : public Rotation {
public:
    RotationY(const Node &n, const double &t) : Rotation(n, t) {}
    virtual double value(const Vector &p) const override;
    virtual Node * clone() const override;
};

class RotationZ : public Rotation {
public:
    RotationZ(const Node &n, const double &t) : Rotation(n, t) {}
    virtual double value(const Vector &p) const override;
    virtual Node * clone() const override;
};

class Scale : public Transform {
public:
    Scale(const Node &n, const double &s) : Transform(n), s(Vector(s)) {}
    Scale(const Node &n, const Vector &s) : Transform(n), s(s) {}
    virtual double value(const Vector &p) const override;
    virtual Node * clone() const override;

private:

    Vector s;
};

class Twist : public Transform {
public:
    Twist(const Node &n, const double& a) : Transform(n), angle(a) {}
    virtual double value(const Vector &p) const override;
    virtual Node * clone() const override;

private:

    double angle;
};

Node * computeDNA();

#endif // NODE_H
