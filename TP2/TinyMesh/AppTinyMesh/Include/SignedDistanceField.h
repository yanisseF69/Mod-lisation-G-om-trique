#ifndef SIGNEDDISTANCEFIELD_H
#define SIGNEDDISTANCEFIELD_H

#include "implicits.h"
#include "Node.h"


class SignedDistanceField : public AnalyticScalarField {

public:
    SignedDistanceField() {}
    SignedDistanceField(Node * r) : root(r) {}
    ~SignedDistanceField() { if(root != nullptr) delete root; }

    double Value(const Vector &p) const {return root->value(p);}

private:
    Node * root;

};

#endif // SIGNEDDISTANCEFIELD_H
