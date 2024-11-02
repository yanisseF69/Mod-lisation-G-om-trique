/********************************************************************************
** Form generated from reading UI file 'interface.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INTERFACE_H
#define UI_INTERFACE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Assets
{
public:
    QAction *actionExit;
    QAction *actionNew_Scene;
    QAction *actionExport_obj;
    QAction *actionExport_ma;
    QAction *actionLoad_ma;
    QAction *actionGL;
    QAction *actionVectorized;
    QAction *actionExport_svg;
    QAction *actionSphere_Tracing_png;
    QWidget *centralwidget;
    QHBoxLayout *hboxLayout;
    QGroupBox *Objects_groupBox;
    QPushButton *boxMesh;
    QPushButton *resetcameraButton;
    QPushButton *sphereImplicitEx;
    QPushButton *sphereImplicit;
    QPushButton *torusImplicit;
    QPushButton *unionImplicit;
    QPushButton *intersectionImplicit;
    QPushButton *differenceImplicit;
    QPushButton *capsuleImplicit;
    QPushButton *coneImplicit;
    QPushButton *unionImplicit_2;
    QPushButton *intersectionImplicit_2;
    QPushButton *differenceImplicit_2;
    QPushButton *translation;
    QPushButton *rotation;
    QPushButton *scale;
    QPushButton *boxImplicit;
    QPushButton *complexImplicit;
    QPushButton *upCamera;
    QPushButton *cylinderImplicit;
    QPushButton *front;
    QPushButton *twistImplicit;
    QPushButton *performances;
    QWidget *widget_GL;
    QGroupBox *Parameters_groupBox;
    QGroupBox *groupBox_4;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QLabel *label_3;
    QLineEdit *lineEdit;
    QLabel *label_4;
    QLineEdit *lineEdit_3;
    QGroupBox *groupBox_13;
    QRadioButton *radioShadingButton_1;
    QCheckBox *wireframe;
    QRadioButton *radioShadingButton_2;
    QMenuBar *menubar;
    QMenu *menuFile;

    void setupUi(QMainWindow *Assets)
    {
        if (Assets->objectName().isEmpty())
            Assets->setObjectName("Assets");
        Assets->resize(1200, 1000);
        Assets->setMinimumSize(QSize(420, 300));
        actionExit = new QAction(Assets);
        actionExit->setObjectName("actionExit");
        actionNew_Scene = new QAction(Assets);
        actionNew_Scene->setObjectName("actionNew_Scene");
        actionExport_obj = new QAction(Assets);
        actionExport_obj->setObjectName("actionExport_obj");
        actionExport_ma = new QAction(Assets);
        actionExport_ma->setObjectName("actionExport_ma");
        actionLoad_ma = new QAction(Assets);
        actionLoad_ma->setObjectName("actionLoad_ma");
        actionGL = new QAction(Assets);
        actionGL->setObjectName("actionGL");
        actionVectorized = new QAction(Assets);
        actionVectorized->setObjectName("actionVectorized");
        actionExport_svg = new QAction(Assets);
        actionExport_svg->setObjectName("actionExport_svg");
        actionSphere_Tracing_png = new QAction(Assets);
        actionSphere_Tracing_png->setObjectName("actionSphere_Tracing_png");
        centralwidget = new QWidget(Assets);
        centralwidget->setObjectName("centralwidget");
        hboxLayout = new QHBoxLayout(centralwidget);
        hboxLayout->setSpacing(0);
        hboxLayout->setObjectName("hboxLayout");
        hboxLayout->setContentsMargins(0, 0, 0, 0);
        Objects_groupBox = new QGroupBox(centralwidget);
        Objects_groupBox->setObjectName("Objects_groupBox");
        Objects_groupBox->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Objects_groupBox->sizePolicy().hasHeightForWidth());
        Objects_groupBox->setSizePolicy(sizePolicy);
        Objects_groupBox->setMinimumSize(QSize(350, 250));
        boxMesh = new QPushButton(Objects_groupBox);
        boxMesh->setObjectName("boxMesh");
        boxMesh->setGeometry(QRect(20, 20, 131, 23));
        boxMesh->setCheckable(false);
        resetcameraButton = new QPushButton(Objects_groupBox);
        resetcameraButton->setObjectName("resetcameraButton");
        resetcameraButton->setGeometry(QRect(90, 430, 141, 23));
        resetcameraButton->setCheckable(true);
        resetcameraButton->setAutoDefault(false);
        resetcameraButton->setFlat(false);
        sphereImplicitEx = new QPushButton(Objects_groupBox);
        sphereImplicitEx->setObjectName("sphereImplicitEx");
        sphereImplicitEx->setGeometry(QRect(20, 50, 131, 23));
        sphereImplicitEx->setCheckable(false);
        sphereImplicit = new QPushButton(Objects_groupBox);
        sphereImplicit->setObjectName("sphereImplicit");
        sphereImplicit->setGeometry(QRect(180, 50, 141, 26));
        torusImplicit = new QPushButton(Objects_groupBox);
        torusImplicit->setObjectName("torusImplicit");
        torusImplicit->setGeometry(QRect(20, 80, 131, 26));
        unionImplicit = new QPushButton(Objects_groupBox);
        unionImplicit->setObjectName("unionImplicit");
        unionImplicit->setGeometry(QRect(20, 190, 131, 26));
        intersectionImplicit = new QPushButton(Objects_groupBox);
        intersectionImplicit->setObjectName("intersectionImplicit");
        intersectionImplicit->setGeometry(QRect(20, 220, 131, 26));
        differenceImplicit = new QPushButton(Objects_groupBox);
        differenceImplicit->setObjectName("differenceImplicit");
        differenceImplicit->setGeometry(QRect(20, 250, 131, 26));
        capsuleImplicit = new QPushButton(Objects_groupBox);
        capsuleImplicit->setObjectName("capsuleImplicit");
        capsuleImplicit->setGeometry(QRect(180, 80, 141, 26));
        coneImplicit = new QPushButton(Objects_groupBox);
        coneImplicit->setObjectName("coneImplicit");
        coneImplicit->setGeometry(QRect(20, 110, 131, 26));
        unionImplicit_2 = new QPushButton(Objects_groupBox);
        unionImplicit_2->setObjectName("unionImplicit_2");
        unionImplicit_2->setGeometry(QRect(180, 190, 141, 26));
        intersectionImplicit_2 = new QPushButton(Objects_groupBox);
        intersectionImplicit_2->setObjectName("intersectionImplicit_2");
        intersectionImplicit_2->setGeometry(QRect(180, 220, 141, 26));
        differenceImplicit_2 = new QPushButton(Objects_groupBox);
        differenceImplicit_2->setObjectName("differenceImplicit_2");
        differenceImplicit_2->setGeometry(QRect(180, 250, 141, 26));
        translation = new QPushButton(Objects_groupBox);
        translation->setObjectName("translation");
        translation->setGeometry(QRect(20, 280, 131, 26));
        rotation = new QPushButton(Objects_groupBox);
        rotation->setObjectName("rotation");
        rotation->setGeometry(QRect(180, 280, 141, 26));
        scale = new QPushButton(Objects_groupBox);
        scale->setObjectName("scale");
        scale->setGeometry(QRect(20, 310, 131, 26));
        boxImplicit = new QPushButton(Objects_groupBox);
        boxImplicit->setObjectName("boxImplicit");
        boxImplicit->setGeometry(QRect(180, 20, 141, 26));
        complexImplicit = new QPushButton(Objects_groupBox);
        complexImplicit->setObjectName("complexImplicit");
        complexImplicit->setGeometry(QRect(80, 150, 171, 26));
        upCamera = new QPushButton(Objects_groupBox);
        upCamera->setObjectName("upCamera");
        upCamera->setGeometry(QRect(90, 460, 141, 23));
        upCamera->setCheckable(true);
        upCamera->setAutoDefault(false);
        upCamera->setFlat(false);
        cylinderImplicit = new QPushButton(Objects_groupBox);
        cylinderImplicit->setObjectName("cylinderImplicit");
        cylinderImplicit->setGeometry(QRect(180, 110, 141, 26));
        front = new QPushButton(Objects_groupBox);
        front->setObjectName("front");
        front->setGeometry(QRect(90, 490, 141, 26));
        twistImplicit = new QPushButton(Objects_groupBox);
        twistImplicit->setObjectName("twistImplicit");
        twistImplicit->setGeometry(QRect(180, 310, 141, 26));
        performances = new QPushButton(Objects_groupBox);
        performances->setObjectName("performances");
        performances->setGeometry(QRect(80, 350, 181, 26));

        hboxLayout->addWidget(Objects_groupBox);

        widget_GL = new QWidget(centralwidget);
        widget_GL->setObjectName("widget_GL");

        hboxLayout->addWidget(widget_GL);

        Parameters_groupBox = new QGroupBox(centralwidget);
        Parameters_groupBox->setObjectName("Parameters_groupBox");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(Parameters_groupBox->sizePolicy().hasHeightForWidth());
        Parameters_groupBox->setSizePolicy(sizePolicy1);
        Parameters_groupBox->setMinimumSize(QSize(450, 141));
        groupBox_4 = new QGroupBox(Parameters_groupBox);
        groupBox_4->setObjectName("groupBox_4");
        groupBox_4->setGeometry(QRect(10, 20, 171, 121));
        label_2 = new QLabel(groupBox_4);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 20, 61, 21));
        lineEdit_2 = new QLineEdit(groupBox_4);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(70, 50, 81, 20));
        lineEdit_2->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        label_3 = new QLabel(groupBox_4);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 50, 61, 21));
        lineEdit = new QLineEdit(groupBox_4);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(70, 20, 81, 20));
        lineEdit->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        label_4 = new QLabel(groupBox_4);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(10, 80, 61, 21));
        lineEdit_3 = new QLineEdit(groupBox_4);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(70, 80, 81, 20));
        lineEdit_3->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        groupBox_13 = new QGroupBox(Parameters_groupBox);
        groupBox_13->setObjectName("groupBox_13");
        groupBox_13->setGeometry(QRect(190, 20, 251, 121));
        radioShadingButton_1 = new QRadioButton(groupBox_13);
        radioShadingButton_1->setObjectName("radioShadingButton_1");
        radioShadingButton_1->setGeometry(QRect(20, 20, 61, 20));
        radioShadingButton_1->setChecked(true);
        wireframe = new QCheckBox(groupBox_13);
        wireframe->setObjectName("wireframe");
        wireframe->setGeometry(QRect(90, 20, 81, 17));
        wireframe->setChecked(true);
        radioShadingButton_2 = new QRadioButton(groupBox_13);
        radioShadingButton_2->setObjectName("radioShadingButton_2");
        radioShadingButton_2->setGeometry(QRect(20, 50, 61, 20));
        radioShadingButton_2->setChecked(false);

        hboxLayout->addWidget(Parameters_groupBox);

        Assets->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Assets);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1200, 23));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName("menuFile");
        Assets->setMenuBar(menubar);

        menubar->addAction(menuFile->menuAction());

        retranslateUi(Assets);

        resetcameraButton->setDefault(false);
        upCamera->setDefault(false);


        QMetaObject::connectSlotsByName(Assets);
    } // setupUi

    void retranslateUi(QMainWindow *Assets)
    {
        Assets->setWindowTitle(QCoreApplication::translate("Assets", "Implicit Terrain", nullptr));
        actionExit->setText(QCoreApplication::translate("Assets", "Exit", nullptr));
#if QT_CONFIG(shortcut)
        actionExit->setShortcut(QCoreApplication::translate("Assets", "Esc", nullptr));
#endif // QT_CONFIG(shortcut)
        actionNew_Scene->setText(QCoreApplication::translate("Assets", "New Scene", nullptr));
        actionExport_obj->setText(QCoreApplication::translate("Assets", "OBJ File (.obj)", nullptr));
        actionExport_ma->setText(QCoreApplication::translate("Assets", "Maya File (.ma)", nullptr));
        actionLoad_ma->setText(QCoreApplication::translate("Assets", "Load", nullptr));
        actionGL->setText(QCoreApplication::translate("Assets", "GL", nullptr));
        actionVectorized->setText(QCoreApplication::translate("Assets", "Vectorized", nullptr));
        actionExport_svg->setText(QCoreApplication::translate("Assets", "SVG File (.svg)", nullptr));
        actionSphere_Tracing_png->setText(QCoreApplication::translate("Assets", "Sphere Tracing (.png)", nullptr));
        Objects_groupBox->setTitle(QString());
#if QT_CONFIG(tooltip)
        boxMesh->setToolTip(QCoreApplication::translate("Assets", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#5500ff;\">Callback #01</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-style:italic; color:#aa00ff;\">Create Eurographics 1996 Bear</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        boxMesh->setText(QCoreApplication::translate("Assets", "Box Mesh", nullptr));
#if QT_CONFIG(tooltip)
        resetcameraButton->setToolTip(QCoreApplication::translate("Assets", "<html><head/><body><p><span style=\" color:#5500ff;\">Callback #03</span></p><p><span style=\" font-style:italic; color:#aa00ff;\">Create Eurographics 1996 Bird</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        resetcameraButton->setText(QCoreApplication::translate("Assets", "Reset Camera", nullptr));
#if QT_CONFIG(tooltip)
        sphereImplicitEx->setToolTip(QCoreApplication::translate("Assets", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#5500ff;\">Callback #01</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-style:italic; color:#aa00ff;\">Create Eurographics 1996 Bear</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        sphereImplicitEx->setText(QCoreApplication::translate("Assets", "Sphere Implicit", nullptr));
        sphereImplicit->setText(QCoreApplication::translate("Assets", "Sph\303\250re", nullptr));
        torusImplicit->setText(QCoreApplication::translate("Assets", "Tore", nullptr));
        unionImplicit->setText(QCoreApplication::translate("Assets", "Union", nullptr));
        intersectionImplicit->setText(QCoreApplication::translate("Assets", "Intersection", nullptr));
        differenceImplicit->setText(QCoreApplication::translate("Assets", "Diff\303\251rence", nullptr));
        capsuleImplicit->setText(QCoreApplication::translate("Assets", "Capsule", nullptr));
        coneImplicit->setText(QCoreApplication::translate("Assets", "C\303\264ne", nullptr));
        unionImplicit_2->setText(QCoreApplication::translate("Assets", "Union Smooth", nullptr));
        intersectionImplicit_2->setText(QCoreApplication::translate("Assets", "Intersection Smooth", nullptr));
        differenceImplicit_2->setText(QCoreApplication::translate("Assets", "Diff\303\251rence Smooth", nullptr));
        translation->setText(QCoreApplication::translate("Assets", "Translation", nullptr));
        rotation->setText(QCoreApplication::translate("Assets", "Rotation", nullptr));
        scale->setText(QCoreApplication::translate("Assets", "Homoth\303\251tie", nullptr));
        boxImplicit->setText(QCoreApplication::translate("Assets", "Bo\303\256te", nullptr));
        complexImplicit->setText(QCoreApplication::translate("Assets", "Forme Complexe", nullptr));
#if QT_CONFIG(tooltip)
        upCamera->setToolTip(QCoreApplication::translate("Assets", "<html><head/><body><p><span style=\" color:#5500ff;\">Callback #03</span></p><p><span style=\" font-style:italic; color:#aa00ff;\">Create Eurographics 1996 Bird</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        upCamera->setText(QCoreApplication::translate("Assets", "Haut Camera", nullptr));
        cylinderImplicit->setText(QCoreApplication::translate("Assets", "Cylindre", nullptr));
        front->setText(QCoreApplication::translate("Assets", "Devant Camera", nullptr));
        twistImplicit->setText(QCoreApplication::translate("Assets", "Torsion", nullptr));
        performances->setText(QCoreApplication::translate("Assets", "Performances", nullptr));
        Parameters_groupBox->setTitle(QString());
        groupBox_4->setTitle(QCoreApplication::translate("Assets", " Statistics", nullptr));
        label_2->setText(QCoreApplication::translate("Assets", "Vertex", nullptr));
        label_3->setText(QCoreApplication::translate("Assets", "Triangles", nullptr));
        lineEdit->setText(QString());
        label_4->setText(QCoreApplication::translate("Assets", "Tps 10\342\201\267", nullptr));
        groupBox_13->setTitle(QCoreApplication::translate("Assets", "Shading", nullptr));
        radioShadingButton_1->setText(QCoreApplication::translate("Assets", "Normal", nullptr));
        wireframe->setText(QCoreApplication::translate("Assets", "Wireframe", nullptr));
        radioShadingButton_2->setText(QCoreApplication::translate("Assets", "Color", nullptr));
        menuFile->setTitle(QCoreApplication::translate("Assets", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Assets: public Ui_Assets {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTERFACE_H
