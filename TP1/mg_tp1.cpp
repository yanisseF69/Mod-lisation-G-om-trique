#include "orbiter.h"
#include "draw.h"        
#include "app_camera.h"
#include "uniforms.h"  

#include <functional>


float binomialCoeff(float n, float k) {
    if(k == 0 || n == k) return 1;
    return binomialCoeff(n - 1, k - 1) + binomialCoeff(n - 1, k);
}

class Curve {

    public:

    virtual Point position(float u) const = 0;

    void controlPoints(std::vector<Point> pos) { std::copy(pos.begin(), pos.end(), std::back_inserter(p)); }


    Vector deriv(float t) const{
        float e = 1e-5;
        return Vector((position(t + e) - position(t - e))/(2*e));
    }

    Vector deriv2(float t) const{
        float e = 1e-5;
        return Vector((position(t + e) - 2*position(t) + position(t - e))/(std::pow(e, 2)));
    }

    Vector tangent(float t) const{
        Vector d = deriv(t);
        return normalize(d);
    }

    Vector normal(float t) const{
        Vector d = deriv2(t);
        return normalize(d);
    }

    Vector binormal(float t) const{
        Vector tan = tangent(t);
        Vector nor = normal(t);

        return cross(tan, nor);
    }
        std::vector<Point> p;
        std::vector<Vector> tangents;

        void computeTangents() {
        int n = p.size();
        tangents.resize(n);

        for (int i = 0; i < n; ++i) {
            if (i == 0) {
                tangents[i] = normalize(p[i + 1] - p[i]);
            } else if (i == n - 1) {
                tangents[i] = normalize(p[i] - p[i - 1]);
            } else {
                tangents[i] = normalize(p[i + 1] - p[i - 1]);
            }
        }
    }

        

};

class Spline : public Curve {
    
    
    public:    

        virtual Point position(float u) const override{
            int numSegments = p.size() - 1;
            int i = std::min(static_cast<int>(u * numSegments), numSegments - 1);
            float localU = (u*numSegments) - i;

            Point p0 = p[i];
            Point p1 = p[i + 1];

            Vector t0 = tangents[i];
            Vector t1 = tangents[i+1];

            float u2 = std::pow(localU, 2);
            float u3 = std::pow(localU, 3);

            Point p = p0 + localU*t0 + u2*(-3*p0 - 2*t0 + 3*p1 - t1) + u3*(2*p0 + t0 - 2*p1 + t1);

            return p;
        }
};

class Bezier : public Curve {

    public:
        virtual Point position(float u) const override{
            int n = p.size() - 1;
            Point pos = {0.0, 0.0, 0.0};

            for(int k = 0; k <= n; k++) {
                float binom = binomialCoeff(n, k);
                float bernstein = binom * pow(u, k) * pow(1 - u, n - k);
                pos = pos + (p[k] * bernstein);
            }

            return pos;
        }
};

class Revolution {
    
    private:
        const Curve &c;
        int resolution;
        float step;

        virtual Point nextVertex(const Point &p, const float &cosTheha, const float &sinTheta, const float &j) const = 0;

    public:
        Revolution(const Curve &c, const int &resolution, const float &step) : c(c), resolution(resolution), step(step) {}

        virtual ~Revolution() {}

        Mesh polygonize() const {
            Mesh m;
            for(auto & point : c.p) {
                m.color(White());
                m.vertex(point);
                
            }

            for(int i = 0; i < resolution; i++) {
                float theta = 2.0*M_PI * i/float(resolution);
                float cosTheha = cos(theta);
                float sinTheta = sin(theta);
                m.color(White());
                for(float j = 0.0; j < 1.0; j = j + step) {
                    Point p = c.position(j);
                    Point vertex = nextVertex(p, cosTheha, sinTheta, j);
                    m.normal(c.normal(j));
                    m.vertex(vertex);
                    
                }
            }
            

            return m;
        }

};

class Rotate : public Revolution {

    public :
        Rotate(const Curve &c, const int &resolution, const float &step) : Revolution(c, resolution, step) {}
    private : 
    virtual Point nextVertex(const Point &p, const float &cosTheha, const float &sinTheta, const float &j) const override {
        return Point(
            cosTheha * p.x - sinTheta * p.y,
            sinTheta * p.x + cosTheha * p.y,
            p.z
        );
    }
};

class Gabriel : public Revolution {

    public :
        Gabriel(const Curve &c, const int &resolution, const float &step) : Revolution(c, resolution, step) {}
    private : 
    virtual Point nextVertex(const Point &p, const float &cosTheha, const float &sinTheta, const float &j) const override {
        return Point(j*cosTheha*p.x,
                     j*sinTheta*p.x,
                     (1/j)*p.z
        );
    }
};

class TP : public AppCamera {

    public:
        TP( ) : AppCamera(1024, 640), m_revolution(new Rotate(m_spline, 1, 0.001)) {}

        int init() {

            // std::vector<Point> controlPoints = {
            //     Point(0, 0, 0), Point(0,1,1), Point(-1, -2, -1.5), Point(-2, 3, 2.5), Point(3, 1.5, 2), Point(0, 1.5, 4), Point(0, 0, 6)
            //     };
            std::vector<Point> controlPoints = {
                Point(0.0,0.0,0.0), Point(0.5,0.0,0.2), Point(2.0,0.0,0.6),
                Point(0.8,0.0,1.2), Point(1.5,0.0,1.7), Point(0.6,0.0,2.5),
                Point(1.8,0.0,3.0), Point(0.7,0.0,3.8), Point(2.5,0.0,4.2),
                Point(0.0,0.0,5.0)
            };

            std::vector<Point> chessTower = {
                Point(0.0,0.0,0.0), Point(1.5,0.0,0.0), Point(1.5,0.0,0.5),
                Point(1.2,0.0,0.6), Point(1.2,0.0,2.0), Point(1.0,0.0,4.0),
                Point(1.4,0.0,4.2), Point(1.4,0.0,4.5), Point(1.0,0.0,4.7),
                Point(1.0,0.0,5.0), Point(1.2,0.0,5.0), Point(1.0,0.0,5.3),
                Point(1.0,0.0,6.0)
            };


            m_spline.controlPoints(chessTower);
            m_spline.computeTangents();

            m_bezier.controlPoints(controlPoints);
            m_bezier.computeTangents();

            
            

            m_vectors = Mesh(GL_LINES);

            m_vectors.color(Red());
            m_vectors.vertex(m_spline.position(0.65));
            m_vectors.vertex(m_spline.position(0.65) + m_spline.tangent(0.65));

            m_vectors.color(Blue());
            m_vectors.vertex(m_spline.position(0.65));
            m_vectors.vertex(m_spline.position(0.65) + m_spline.normal(0.65));

            m_vectors.color(Green());
            m_vectors.vertex(m_spline.position(0.65));
            m_vectors.vertex(m_spline.position(0.65) + m_spline.binormal(0.65));
            glLineWidth(2);

            m_mesh = m_revolution->polygonize();

            m_program = read_program("data/shaders/mg.glsl");
            program_print_errors(m_program);

            glClearColor(0.2f, 0.2f, 0.2f, 1.f);        // couleur par defaut de la fenetre
        
            glClearDepth(1.f);                          // profondeur par defaut
            glDepthFunc(GL_LESS);                       // ztest, conserver l'intersection la plus proche de la camera
            glEnable(GL_DEPTH_TEST);

            return 0;
        }

        int quit() {

            m_mesh.release();
            if(m_revolution != nullptr) delete m_revolution;
            return 0;
        }

        int render() {

            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
            Transform model = Identity()*Scale(0.05);
            Transform view = m_camera.view();
            Transform projection = m_camera.projection(window_width(), window_height(), 45);

            glUseProgram(m_program);

            Transform mvp = projection * view * model;

            program_uniform(m_program, "mvpMatrix", mvp);

            draw(m_mesh, model, camera());
            draw(m_vectors, model, camera());
            // m_mesh.draw(m_program, true, false, true, false, false);

            return 1;


        }

    protected:
    
    Spline m_spline;
    Bezier m_bezier;
    Mesh m_mesh;
    Mesh m_vectors;
    Rotate *m_revolution;
    GLuint m_program;


};

int main( )
{
    TP tp;
    tp.run();
    
    return 0;
}
