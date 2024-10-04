#include "MyForm.h"
#include "Matrix.h"
#include <math.h>
#include <vector>

int OFFSET_X = 0;
int OFFSET_Y = 0;

int prevX = 0, prevY = 0, prevZ = 0;
int prevRX = 0, prevRY = 0, prevRZ = 0;
double prevSX = 1, prevSY = 1, prevSZ = 1;

const int axisX = 1000, axisY = 1000, axisZ = 1000;

const double startScale = 10, 
                startRX = CompGraphic::Math::PI + CompGraphic::Math::PI / 16, 
                startRY = 2 * CompGraphic::Math::PI - CompGraphic::Math::PI / 8, 
                startRZ = 0;

double cameraScale = startScale;                    // current camera scale
double rx = startRX, ry = startRY, rz = startRZ;    // current camera rotate
Matrix cameraView;

std::vector<Point3> verticesQube = {
    Point3(0, 0, 0),
    Point3(20, 0, 0),
    Point3(20, 20, 0),
    Point3(0, 0, 20),
    Point3(20, 0, 20),
    Point3(20, 20, 20),
    Point3(0, 20, 20)
};

std::vector<std::pair<int, int>> edgesQube = {
    {0, 1}, {1, 2}, {2, 3}, {3, 0},
    {4, 5}, {5, 6}, {6, 7}, {7, 4},
    {0, 4}, {1, 5}, {2, 6}, {3, 7}
};

std::vector<Point3> vertices = {
    Point3(0, 0, 0),
    Point3(2, 0, 0),
    Point3(0, 0, -2),
    Point3(2, 0, -2),
    Point3(0, 10, 0),
    Point3(2, 10, 0),
    Point3(0, 10, -2),
    Point3(2, 10, -2),

    Point3(-8, 10, 0),
    Point3(-8, 10, -2),
    Point3(-8, 12, 0),
    Point3(-8, 12, -2),
    Point3(10, 10, 0),
    Point3(10, 10, -2),
    Point3(10, 12, 0),
    Point3(10, 12, -2),
};

std::vector<std::pair<int, int>> edges = {
    {0,1},
    {0,2},
    {1,3},
    {2,3},
    {0,4},
    {1,5},
    {2,6},
    {3,7},
    {8,12},
    {9,13},
    {8,9},
    {12,13},
    {8,10},
    {9,11},
    {12,14},
    {13,15},
    {10,14},
    {11,15},
    {10,11},
    {14,15},
};

System::Void CompGraphic::MyForm::panel_draw_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e)
{ 
    drawObject(vertices, edges); // draw main object

    // draw second object (lab task)
    if (checkBox_anim->Checked) {
        std::vector<Point3> vertices1 = vertices;
        if (radioButton_oyz->Checked)
            for (auto& it : vertices1) it = affineTransform(Matrix::mirrorYZ(), it);
        else if (radioButton_oxz->Checked)
            for (auto& it : vertices1) it = affineTransform(Matrix::mirrorXZ(), it);
        else
            for (auto& it : vertices1) it = affineTransform(Matrix::mirrorXY(), it);

        drawObject(vertices1, edges);
    }

    drawAxis();
    if (checkBox1->Checked) drawPerspectivePoint();
    if (checkBox2->Checked) drawPerspectiveLines();
}

void CompGraphic::MyForm::setupCamera(double scale, double rx, double ry, double rz)
{
    // Define the camera position and orientation
    cameraView = Matrix::translate(0, 0, 0);
    cameraView = cameraView * Matrix::rotateX(rx);
    cameraView = cameraView * Matrix::rotateY(ry);
    cameraView = cameraView * Matrix::rotateZ(rz); 
    cameraView = cameraView * Matrix::scale(scale, scale, scale);
}

void CompGraphic::MyForm::drawObject(std::vector<Point3> vertices, std::vector<std::pair<int, int>> edges)
{
    Pen^ pen = gcnew Pen(Color::Black, 2);
    Graphics^ graphics = panel_draw->CreateGraphics();
    int perspZ = trackBar_perspZ->Value;

    Point2 perspP = projectPoint(Point3(0, 0, perspZ), cameraView);
    for (auto& it : vertices) it = affineTransform(cameraView, it);
    

    // Project and draw each edge
    for (auto edge : edges)
    {
        Point2 projectedPoint1 = perspProj(vertices[edge.first], perspZ);
        Point2 projectedPoint2 = perspProj(vertices[edge.second], perspZ);

        graphics->DrawLine(pen, (int)projectedPoint1.x + OFFSET_X, (int)projectedPoint1.y + OFFSET_Y, (int)projectedPoint2.x + OFFSET_X, (int)projectedPoint2.y + OFFSET_Y);
    }
}

void CompGraphic::MyForm::drawAxis()
{
    Graphics^ graphics = panel_draw->CreateGraphics();
    std::vector<Point3> axis = { { axisX, 0, 0 }, { 0, axisY, 0 }, { 0, 0, axisZ } };
    array<Color>^ colors = {Color::Green, Color::Blue, Color::Red};
    int colorIndex = 0;

    for (auto it : axis) {
        Point2 projectedPoint = projectPoint(it, cameraView);
        graphics->DrawLine(gcnew Pen(colors[colorIndex++]), OFFSET_X, OFFSET_Y, (int)projectedPoint.x + OFFSET_X, (int)projectedPoint.y + OFFSET_Y);
    }
}

void CompGraphic::MyForm::drawPerspectivePoint()
{
    Graphics^ graphics = panel_draw->CreateGraphics();
    int perspZ = trackBar_perspZ->Value;
    Point2 perspP = projectPoint(Point3(0, 0, perspZ), cameraView);
    graphics->DrawEllipse(gcnew Pen(Color::Blue, 5), (int)perspP.x + OFFSET_X, (int)perspP.y + OFFSET_Y, 2, 2);
}

void CompGraphic::MyForm::drawPerspectiveLines()
{
    Graphics^ graphics = panel_draw->CreateGraphics();
    int perspZ = trackBar_perspZ->Value;
    Point2 perspP = projectPoint(Point3(0, 0, perspZ), cameraView);
    for (auto it : vertices) {
        it = affineTransform(cameraView, it);
        Point2 projPoint = perspProj(it, perspZ);
        graphics->DrawLine(gcnew Pen(Color::Yellow, 2), (int)perspP.x + OFFSET_X, (int)perspP.y + OFFSET_Y, (int)projPoint.x + OFFSET_X, (int)projPoint.y + OFFSET_Y);
    }
}

System::Void CompGraphic::MyForm::trackBar_tX_Scroll(System::Object^ sender, System::EventArgs^ e)
{
    int currX = trackBar_tX->Value;
    int changeX = currX - prevX;
    prevX = currX;
    
    for (auto& it : vertices) it = affineTransform(Matrix::translate(changeX, 0, 0), it);

    panel_draw->Refresh();
}

System::Void CompGraphic::MyForm::trackBar_tY_Scroll(System::Object^ sender, System::EventArgs^ e)
{
    int currY = trackBar_tY->Value;
    int changeY = currY - prevY;
    prevY = currY;

    for (auto& it : vertices) it = affineTransform(Matrix::translate(0, changeY, 0), it);

    panel_draw->Refresh();
}

System::Void CompGraphic::MyForm::trackBar_tZ_Scroll(System::Object^ sender, System::EventArgs^ e)
{
    int currZ = trackBar_tZ->Value;
    int changeZ = currZ - prevZ;
    prevZ = currZ;

    for (auto& it : vertices) it = affineTransform(Matrix::translate(0, 0, changeZ), it);   

    panel_draw->Refresh();
}

System::Void CompGraphic::MyForm::MyForm_Load(System::Object^ sender, System::EventArgs^ e)
{
    OFFSET_X = this->Width / 2;
    OFFSET_Y = this->Height / 2;
    setupCamera(cameraScale, rx, ry, rz);
}

System::Void CompGraphic::MyForm::trackBar_rX_Scroll(System::Object^ sender, System::EventArgs^ e)
{
    int currRX = trackBar_rX->Value;
    int changeX = currRX - prevRX;
    prevRX = currRX;

    Matrix rotate = Matrix::rotateX(changeX * Math::PI / 180);

    for (auto &it : vertices) it = affineTransform(rotate, it);
    
    panel_draw->Refresh();
}

System::Void CompGraphic::MyForm::trackBar_rY_Scroll(System::Object^ sender, System::EventArgs^ e)
{
    int currRY = trackBar_rY->Value;
    int changeY = currRY - prevRY;
    prevRY = currRY;

    Matrix rotate = Matrix::rotateY(changeY * Math::PI / 180);

    for (auto& it : vertices) it = affineTransform(rotate, it);

    panel_draw->Refresh();
}

System::Void CompGraphic::MyForm::trackBar_rZ_Scroll(System::Object^ sender, System::EventArgs^ e)
{
    int currRZ = trackBar_rZ->Value;
    int changeZ = currRZ - prevRZ;
    prevRZ = currRZ;

    Matrix rotate = Matrix::rotateZ(changeZ * Math::PI / 180);

    for (auto& it : vertices) it = affineTransform(rotate, it);

    panel_draw->Refresh();
}

System::Void CompGraphic::MyForm::trackBar_sX_Scroll(System::Object^ sender, System::EventArgs^ e)
{
    // Calculate the object's center coordinates
    double centerX = vertices[0].x;
    double centerY = vertices[0].y;
    double centerZ = vertices[0].z;

    // Apply translation to move the object's center to the origin
    Matrix translateToOrigin = Matrix::translate(-centerX, -centerY, -centerZ);

    // Apply scaling
    double currSX = trackBar_sX->Value / 10.;
    Matrix scaleX = Matrix::scale(1 / prevSX, 1, 1) * Matrix::scale(currSX, 1, 1);
    prevSX = currSX;

    // Apply translation to move the object back to its original position
    Matrix translateBack = Matrix::translate(centerX, centerY, centerZ);

    // Combine the transformations
    Matrix finalTransform = translateBack * scaleX * translateToOrigin;

    for (auto& it : vertices) {
        it = affineTransform(finalTransform, it);
    }

    panel_draw->Refresh();
}

System::Void CompGraphic::MyForm::trackBar_sY_Scroll(System::Object^ sender, System::EventArgs^ e)
{
    // Calculate the object's center coordinates
    double centerX = vertices[0].x;
    double centerY = vertices[0].y;
    double centerZ = vertices[0].z;

    // Apply translation to move the object's center to the origin
    Matrix translateToOrigin = Matrix::translate(-centerX, -centerY, -centerZ);

    // Apply scaling
    double currSY = trackBar_sY->Value / 10.;
    Matrix scaleY = Matrix::scale(1, 1 / prevSY, 1) * Matrix::scale(1, currSY, 1);
    prevSY = currSY;

    // Apply translation to move the object back to its original position
    Matrix translateBack = Matrix::translate(centerX, centerY, centerZ);

    // Combine the transformations
    Matrix finalTransform = translateBack * scaleY * translateToOrigin;

    for (auto& it : vertices) {
        it = affineTransform(finalTransform, it);
    }

    panel_draw->Refresh();
}

System::Void CompGraphic::MyForm::trackBar_sZ_Scroll(System::Object^ sender, System::EventArgs^ e)
{
    // Calculate the object's center coordinates
    double centerX = vertices[0].x;
    double centerY = vertices[0].y;
    double centerZ = vertices[0].z;

    // Apply translation to move the object's center to the origin
    Matrix translateToOrigin = Matrix::translate(-centerX, -centerY, -centerZ);

    // Apply scaling
    double currSZ = trackBar_sZ->Value / 10.;
    Matrix scaleZ = Matrix::scale(1, 1, 1 / prevSZ) * Matrix::scale(1, 1, currSZ);
    prevSZ = currSZ;

    // Apply translation to move the object back to its original position
    Matrix translateBack = Matrix::translate(centerX, centerY, centerZ);

    // Combine the transformations
    Matrix finalTransform = translateBack * scaleZ * translateToOrigin;

    for (auto& it : vertices) {
        it = affineTransform(finalTransform, it);
    }

    panel_draw->Refresh();
}

System::Void CompGraphic::MyForm::trackBar_cscale_Scroll(System::Object^ sender, System::EventArgs^ e)
{
    double currScale = trackBar_cscale->Value / 10.;
    Matrix scale = Matrix::scale(1 / cameraScale, 1 / cameraScale, 1 / cameraScale) * Matrix::scale(currScale, currScale, currScale);
    cameraView = cameraView * scale;
    cameraScale = currScale;

    panel_draw->Refresh();
}

System::Void CompGraphic::MyForm::trackBar_rcx_Scroll(System::Object^ sender, System::EventArgs^ e)
{
    rx = trackBar_rcx->Value * Math::PI / 180;
    setupCamera(cameraScale, rx, ry, rz);
    panel_draw->Refresh();
}

System::Void CompGraphic::MyForm::trackBar_rcy_Scroll(System::Object^ sender, System::EventArgs^ e)
{
    ry = trackBar_rcy->Value * Math::PI / 180;
    setupCamera(cameraScale, rx, ry, rz);
    panel_draw->Refresh();
}

System::Void CompGraphic::MyForm::trackBar_rcz_Scroll(System::Object^ sender, System::EventArgs^ e)
{
    rz = trackBar_rcz->Value * Math::PI / 180;
    setupCamera(cameraScale, rx, ry, rz);
    panel_draw->Refresh();
}

System::Void CompGraphic::MyForm::button_crefresh_Click(System::Object^ sender, System::EventArgs^ e)
{
    cameraScale = startScale;
    rx = startRX, ry = startRY, rz = startRZ;
    setupCamera(cameraScale, rx, ry, rz);
    panel_draw->Refresh();

    trackBar_cscale->Value = cameraScale * 10;
    trackBar_rcx->Value = rx * 180 / Math::PI;
    trackBar_rcy->Value = ry * 180 / Math::PI;
    trackBar_rcz->Value = rz * 180 / Math::PI;
}

System::Void CompGraphic::MyForm::checkBox_anim_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
    panel_draw->Refresh();
}

System::Void CompGraphic::MyForm::radioButton_oyz_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
    panel_draw->Refresh();
}

System::Void CompGraphic::MyForm::radioButton_oxz_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
    panel_draw->Refresh();
}

System::Void CompGraphic::MyForm::radioButton_oxy_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
    panel_draw->Refresh();
}

System::Void CompGraphic::MyForm::trackBar_perspZ_Scroll(System::Object^ sender, System::EventArgs^ e)
{
    panel_draw->Refresh();
}

System::Void CompGraphic::MyForm::checkBox1_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
    panel_draw->Refresh();
}

System::Void CompGraphic::MyForm::checkBox2_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
    panel_draw->Refresh();
}
 


