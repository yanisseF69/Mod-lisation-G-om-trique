#include "qte.h"
#include "implicits.h"
#include "ui_interface.h"
#include "SignedDistanceField.h"
#include "Node.h"

#include <chrono>

MainWindow::MainWindow() : QMainWindow(), uiw(new Ui::Assets)
{
	// Chargement de l'interface
    uiw->setupUi(this);

	// Chargement du GLWidget
	meshWidget = new MeshWidget;
	QGridLayout* GLlayout = new QGridLayout;
	GLlayout->addWidget(meshWidget, 0, 0);
	GLlayout->setContentsMargins(0, 0, 0, 0);
    uiw->widget_GL->setLayout(GLlayout);

	// Creation des connect
	CreateActions();

    meshWidget->SetCamera(Camera(Vector(-10., 0., 0.), Vector(0.0, 0.0, 0.0)));

}

MainWindow::~MainWindow()
{
	delete meshWidget;
}

void MainWindow::CreateActions()
{
	// Buttons
    connect(uiw->boxMesh, SIGNAL(clicked()), this, SLOT(BoxMeshExample()));
    connect(uiw->sphereImplicitEx, SIGNAL(clicked()), this, SLOT(SphereImplicitExample()));
    connect(uiw->boxImplicit, SIGNAL(clicked()), this, SLOT(boxImplicit()));
    connect(uiw->sphereImplicit, SIGNAL(clicked()), this, SLOT(sphereImplicit()));
    connect(uiw->torusImplicit, SIGNAL(clicked()), this, SLOT(torusImplicit()));
    connect(uiw->capsuleImplicit, SIGNAL(clicked()), this, SLOT(capsuleImplicit()));
    connect(uiw->coneImplicit, SIGNAL(clicked()), this, SLOT(coneImplicit()));
    connect(uiw->cylinderImplicit, SIGNAL(clicked()), this, SLOT(cylinderImplicit()));

    connect(uiw->complexImplicit, SIGNAL(clicked()), this, SLOT(complexFormImplicit()));

    connect(uiw->unionImplicit, SIGNAL(clicked()), this, SLOT(unionImplicit()));
    connect(uiw->intersectionImplicit, SIGNAL(clicked()), this, SLOT(intersectionImplicit()));
    connect(uiw->differenceImplicit, SIGNAL(clicked()), this, SLOT(differenceImplicit()));
    connect(uiw->unionImplicit_2, SIGNAL(clicked()), this, SLOT(unionSmoothImplicit()));
    connect(uiw->intersectionImplicit_2, SIGNAL(clicked()), this, SLOT(intersectionSmoothImplicit()));
    connect(uiw->differenceImplicit_2, SIGNAL(clicked()), this, SLOT(differenceSmoothImplicit()));
    connect(uiw->translation, SIGNAL(clicked()), this, SLOT(translationImplicit()));
    connect(uiw->rotation, SIGNAL(clicked()), this, SLOT(rotationImplicit()));
    connect(uiw->scale, SIGNAL(clicked()), this, SLOT(scaleImplicit()));
    connect(uiw->twistImplicit, SIGNAL(clicked()), this, SLOT(twistImplicit()));

    connect(uiw->performances, SIGNAL(clicked(bool)), this, SLOT(performances()));

    connect(uiw->resetcameraButton, SIGNAL(clicked()), this, SLOT(ResetCamera()));
    connect(uiw->upCamera, SIGNAL(clicked()), this, SLOT(Haut()));
    connect(uiw->front, SIGNAL(clicked()), this, SLOT(Front()));

    connect(uiw->wireframe, SIGNAL(clicked()), this, SLOT(UpdateMaterial()));
    connect(uiw->radioShadingButton_1, SIGNAL(clicked()), this, SLOT(UpdateMaterial()));
    connect(uiw->radioShadingButton_2, SIGNAL(clicked()), this, SLOT(UpdateMaterial()));

	// Widget edition
	connect(meshWidget, SIGNAL(_signalEditSceneLeft(const Ray&)), this, SLOT(editingSceneLeft(const Ray&)));
	connect(meshWidget, SIGNAL(_signalEditSceneRight(const Ray&)), this, SLOT(editingSceneRight(const Ray&)));
}

void MainWindow::editingSceneLeft(const Ray&)
{
}

void MainWindow::editingSceneRight(const Ray&)
{
}

void MainWindow::BoxMeshExample()
{
	Mesh boxMesh = Mesh(Box(1.0));

	std::vector<Color> cols;
	cols.resize(boxMesh.Vertexes());
    for (size_t i = 0; i < cols.size(); i++)
		cols[i] = Color(double(i) / 6.0, fmod(double(i) * 39.478378, 1.0), 0.0);

	meshColor = MeshColor(boxMesh, cols, boxMesh.VertexIndexes());
	UpdateGeometry();
}

void MainWindow::SphereImplicitExample()
{
  AnalyticScalarField implicit;

  Mesh implicitMesh;
  implicit.Polygonize(31, implicitMesh, Box(2.0));

  std::vector<Color> cols;
  cols.resize(implicitMesh.Vertexes());
  for (size_t i = 0; i < cols.size(); i++)
    cols[i] = Color(0.8, 0.8, 0.8);

  meshColor = MeshColor(implicitMesh, cols, implicitMesh.VertexIndexes());
  UpdateGeometry();
}

void MainWindow::boxImplicit() {
    SignedDistanceField sdf(new BoxImplicit(Vector(0., 0., 0.), Vector(3.0, 2.0, 1.0)));

    Mesh implicitMesh;
    sdf.Polygonize(50, implicitMesh, Box(5.0));

    std::vector<Color> cols;
    cols.resize(implicitMesh.Vertexes());
    for (size_t i = 0; i < cols.size(); i++)
        cols[i] = Color(0.8, 0.8, 0.8);

    meshColor = MeshColor(implicitMesh, cols, implicitMesh.VertexIndexes());
    UpdateGeometry();

}

void MainWindow::sphereImplicit() {

    SignedDistanceField sdf(new Sphere(Vector(0., 0., 0.), 2.0));

    Mesh implicitMesh;
    sdf.Polygonize(50, implicitMesh, Box(5.0));

    std::vector<Color> cols;
    cols.resize(implicitMesh.Vertexes());
    for (size_t i = 0; i < cols.size(); i++)
        cols[i] = Color(0.8, 0.8, 0.8);

    implicitMesh.SaveObj("Result/Ovni.obj", "OvniMesh");

    meshColor = MeshColor(implicitMesh, cols, implicitMesh.VertexIndexes());
    UpdateGeometry();

}

void MainWindow::torusImplicit() {

    SignedDistanceField sdf(new Torus(Vector(0., 0., 0.), 2.0, 3.0));

    Mesh implicitMesh;
    sdf.Polygonize(50, implicitMesh, Box(5.0));

    std::vector<Color> cols;
    cols.resize(implicitMesh.Vertexes());
    for (size_t i = 0; i < cols.size(); i++)
        cols[i] = Color(0.8, 0.8, 0.8);

    meshColor = MeshColor(implicitMesh, cols, implicitMesh.VertexIndexes());
    UpdateGeometry();
}

void MainWindow::capsuleImplicit() {

    SignedDistanceField sdf(new Capsule(Vector(0., 0., 0.), 8.0, 1.0));

    Mesh implicitMesh;
    sdf.Polygonize(50, implicitMesh, Box(5.0));

    std::vector<Color> cols;
    cols.resize(implicitMesh.Vertexes());
    for (size_t i = 0; i < cols.size(); i++)
        cols[i] = Color(0.8, 0.8, 0.8);

    meshColor = MeshColor(implicitMesh, cols, implicitMesh.VertexIndexes());
    UpdateGeometry();
}

void MainWindow::coneImplicit() {

    SignedDistanceField sdf(new Cone(Vector(0., 0., 0.), 0.4, 0.6, 5.0));

    Mesh implicitMesh;
    sdf.Polygonize(50, implicitMesh, Box(5.0));

    std::vector<Color> cols;
    cols.resize(implicitMesh.Vertexes());
    for (size_t i = 0; i < cols.size(); i++)
        cols[i] = Color(0.8, 0.8, 0.8);

    meshColor = MeshColor(implicitMesh, cols, implicitMesh.VertexIndexes());
    UpdateGeometry();
}

void MainWindow::cylinderImplicit() {

    SignedDistanceField sdf(new Cylinder(Vector(0., 0., 0.), 3., 5.0));

    Mesh implicitMesh;
    sdf.Polygonize(50, implicitMesh, Box(5.0));

    std::vector<Color> cols;
    cols.resize(implicitMesh.Vertexes());
    for (size_t i = 0; i < cols.size(); i++)
        cols[i] = Color(0.8, 0.8, 0.8);

    meshColor = MeshColor(implicitMesh, cols, implicitMesh.VertexIndexes());
    UpdateGeometry();
}

void MainWindow::unionImplicit() {
    SignedDistanceField sdf(new Union(Sphere(Vector(0., 0., 0.), 4.0),  Sphere(Vector(-3, 0., 0.), 2.0)));

    Mesh implicitMesh;
    sdf.Polygonize(50, implicitMesh, Box(5.0));

    std::vector<Color> cols;
    cols.resize(implicitMesh.Vertexes());
    for (size_t i = 0; i < cols.size(); i++)
        cols[i] = Color(0.8, 0.8, 0.8);

    meshColor = MeshColor(implicitMesh, cols, implicitMesh.VertexIndexes());
    UpdateGeometry();
}

void MainWindow::intersectionImplicit() {
    SignedDistanceField sdf(new Intersection(Sphere(Vector(0., 0., 0.), 2.0),  Sphere(Vector(1., 0., 0.), 2.0)));

    Mesh implicitMesh;
    sdf.Polygonize(50, implicitMesh, Box(5.0));

    std::vector<Color> cols;
    cols.resize(implicitMesh.Vertexes());
    for (size_t i = 0; i < cols.size(); i++)
        cols[i] = Color(0.8, 0.8, 0.8);

    meshColor = MeshColor(implicitMesh, cols, implicitMesh.VertexIndexes());
    UpdateGeometry();
}

void MainWindow::differenceImplicit() {
    SignedDistanceField sdf(new Difference(Sphere(Vector(1., 0., 0.), 3.0),  Sphere(Vector(-1., -2., 0.), 1.0)));

    Mesh implicitMesh;
    sdf.Polygonize(50, implicitMesh, Box(5.0));

    std::vector<Color> cols;
    cols.resize(implicitMesh.Vertexes());
    for (size_t i = 0; i < cols.size(); i++)
        cols[i] = Color(0.8, 0.8, 0.8);

    meshColor = MeshColor(implicitMesh, cols, implicitMesh.VertexIndexes());
    UpdateGeometry();
}

void MainWindow::unionSmoothImplicit() {
    SignedDistanceField sdf(new UnionSmooth(Sphere(Vector(0., 0., 0.), 4.0),  Sphere(Vector(-3, 0., 0.), 2.0)));

    Mesh implicitMesh;
    sdf.Polygonize(50, implicitMesh, Box(5.0));

    std::vector<Color> cols;
    cols.resize(implicitMesh.Vertexes());
    for (size_t i = 0; i < cols.size(); i++)
        cols[i] = Color(0.8, 0.8, 0.8);

    meshColor = MeshColor(implicitMesh, cols, implicitMesh.VertexIndexes());
    UpdateGeometry();
}

void MainWindow::intersectionSmoothImplicit() {
    SignedDistanceField sdf(new IntersectionSmooth(Sphere(Vector(0., 0., 0.), 2.0),  Sphere(Vector(1., 0., 0.), 2.0)));

    Mesh implicitMesh;
    sdf.Polygonize(50, implicitMesh, Box(5.0));

    std::vector<Color> cols;
    cols.resize(implicitMesh.Vertexes());
    for (size_t i = 0; i < cols.size(); i++)
        cols[i] = Color(0.8, 0.8, 0.8);

    meshColor = MeshColor(implicitMesh, cols, implicitMesh.VertexIndexes());
    UpdateGeometry();
}

void MainWindow::differenceSmoothImplicit() {
    SignedDistanceField sdf(new DifferenceSmooth(Sphere(Vector(1., 0., 0.), 3.0),  Sphere(Vector(-1., -2., 0.), 1.0)));

    Mesh implicitMesh;
    sdf.Polygonize(50, implicitMesh, Box(5.0));

    std::vector<Color> cols;
    cols.resize(implicitMesh.Vertexes());
    for (size_t i = 0; i < cols.size(); i++)
        cols[i] = Color(0.8, 0.8, 0.8);

    meshColor = MeshColor(implicitMesh, cols, implicitMesh.VertexIndexes());
    UpdateGeometry();
}

void MainWindow::translationImplicit() {


    Sphere s(Vector(0., 0., 0.), 2.0);
    Scale s2 = Scale(s, 0.5);

    SignedDistanceField sdf(new Union(s, Translation(s2, Vector(-1., -1., -1.))));
    Mesh implicitMesh;
    sdf.Polygonize(50, implicitMesh, Box(5.0));

    std::vector<Color> cols;
    cols.resize(implicitMesh.Vertexes());
    for (size_t i = 0; i < cols.size(); i++)
        cols[i] = Color(0.8, 0.8, 0.8);

    meshColor = MeshColor(implicitMesh, cols, implicitMesh.VertexIndexes());

    UpdateGeometry();
}

void MainWindow::rotationImplicit() {
    Torus t(Vector(0., 0., 0.), 2.0, 3.0);
    SignedDistanceField sdf(new RotationZ(t, 90));

    Mesh implicitMesh;
    sdf.Polygonize(50, implicitMesh, Box(5.0));

    std::vector<Color> cols;
    cols.resize(implicitMesh.Vertexes());
    for (size_t i = 0; i < cols.size(); i++)
        cols[i] = Color(0.8, 0.8, 0.8);

    meshColor = MeshColor(implicitMesh, cols, implicitMesh.VertexIndexes());
    UpdateGeometry();
}

void MainWindow::scaleImplicit() {
    Torus t(Vector(0., 0., 0.), 2.0, 3.0);

    SignedDistanceField sdf(new Scale(t, 0.5));

    Mesh implicitMesh;
    sdf.Polygonize(50, implicitMesh, Box(5.0));

    std::vector<Color> cols;
    cols.resize(implicitMesh.Vertexes());
    for (size_t i = 0; i < cols.size(); i++)
        cols[i] = Color(0.8, 0.8, 0.8);

    meshColor = MeshColor(implicitMesh, cols, implicitMesh.VertexIndexes());
    UpdateGeometry();
}

void MainWindow::twistImplicit() {
    const Node &c = Scale(Cylinder(Vector(0.,0.,0), 5.0, 5.0), 0.5);

    SignedDistanceField sdf = new Twist(c, 0.5);

    Mesh implicitMesh;
    sdf.Polygonize(50, implicitMesh, Box(5.0));

    std::vector<Color> cols;
    cols.resize(implicitMesh.Vertexes());
    for (size_t i = 0; i < cols.size(); i++)
        cols[i] = Color(0.8, 0.8, 0.8);

    meshColor = MeshColor(implicitMesh, cols, implicitMesh.VertexIndexes());
    UpdateGeometry();

}

void MainWindow::complexFormImplicit() {

    /*const Node &body =  Scale(
         Torus(Vector(0, 0, 0), 1.0, 0.2),
        Vector(2.0, 0.8, 2.0)
        );

    const Node &cabin =  Translation(
         Sphere(Vector(0, 0, 0), 0.8),
        Vector(0, 0.8, 0)
        );

    const Node &leg1 =  Translation(
         Cone(Vector(0, 0, 0), 0.4, 0.6, 0.5),
        Vector(0.8, -0.8, 0)
        );

    const Node &leg2 =  Translation(
         Cone(Vector(0, 0, 0), 0.4, 0.6, 0.5),
        Vector(-0.8, -0.8, 0.8)
        );

    const Node &leg3 =  Translation(
         Cone(Vector(0, 0, 0), 0.4, 0.6, 0.5),
        Vector(-0.8, -0.8, -0.8)
        );

    const Node& legs = Union(Union(leg1, leg2), leg3);

    Node* flyingSaucer = new Union(Union(body, cabin), legs);*/


    Node * dna = computeDNA();

    SignedDistanceField sdf(dna);

    Mesh implicitMesh;
    sdf.Polygonize(100, implicitMesh, Box(5.0));

    std::vector<Color> cols;
    cols.resize(implicitMesh.Vertexes());
    for (size_t i = 0; i < cols.size(); i++)
        cols[i] = Color(0.8, 0.8, 0.8);

    // implicitMesh.SaveObj("Result/flyingSaucer.obj", "FlyingSaucerMesh");
    // implicitMesh.SaveObj("Result/DNA.obj", "DNAMesh");

    meshColor = MeshColor(implicitMesh, cols, implicitMesh.VertexIndexes());
    UpdateGeometry();
}

void MainWindow::performances() {


    const Node &n = Cone(Vector(0.,0.,0.), 0.4, 0.6, 5.);

    auto start= std::chrono::high_resolution_clock::now();
    for(int i = 0; i < 10000000; i++) {
        n.value(Vector(0.,0.,0));
    }
    auto stop= std::chrono::high_resolution_clock::now();
    int cpu= std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count();

    uiw->lineEdit_3->setText(QString::number(cpu));

}

void MainWindow::UpdateGeometry()
{
	meshWidget->ClearAll();
	meshWidget->AddMesh("BoxMesh", meshColor);

    uiw->lineEdit->setText(QString::number(meshColor.Vertexes()));
    uiw->lineEdit_2->setText(QString::number(meshColor.Triangles()));

	UpdateMaterial();
}

void MainWindow::UpdateMaterial()
{
    meshWidget->UseWireframeGlobal(uiw->wireframe->isChecked());

    if (uiw->radioShadingButton_1->isChecked())
		meshWidget->SetMaterialGlobal(MeshMaterial::Normal);
	else
		meshWidget->SetMaterialGlobal(MeshMaterial::Color);
}

void MainWindow::ResetCamera()
{
    meshWidget->SetCamera(Camera(Vector(-10.0), Vector(0.0)));
}

void MainWindow::Haut()
{
    meshWidget->SetCamera(Camera(Vector(10.0, 10.0, -10.0), Vector(0.0)));
}

void MainWindow::Front()
{
    meshWidget->SetCamera(Camera(Vector(10.0, 0.0, 10.0), Vector(0.0)));
}
