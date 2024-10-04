#pragma once
#include <vector>

const int size = 4;

class Matrix {
public:
    std::vector<std::vector<double>> data;

    Matrix() {
        data.resize(size, std::vector<double>(size, 0.0));
    }

    Matrix(int rows, int cols) {
        data.resize(rows, std::vector<double>(cols, 0.0));
    }

    Matrix operator*(const Matrix& other) {
        Matrix result(data.size(), other.data[0].size());
        for (int i = 0; i < data.size(); i++) {
            for (int j = 0; j < other.data[0].size(); j++) {
                for (int k = 0; k < data[0].size(); k++) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }

    static Matrix translate(double x, double y, double z) {
        Matrix matrix(4, 4);
        matrix.data[0][0] = 1;
        matrix.data[1][1] = 1;
        matrix.data[2][2] = 1;
        matrix.data[3][3] = 1;
        matrix.data[0][3] = x;
        matrix.data[1][3] = y;
        matrix.data[2][3] = z;
        return matrix;
    }

    static Matrix scale(double sx, double sy, double sz) {
        Matrix matrix(4, 4);
        matrix.data[0][0] = sx;
        matrix.data[1][1] = sy;
        matrix.data[2][2] = sz;
        matrix.data[3][3] = 1;
        return matrix;
    }

   static Matrix rotateX(double angle) {
        Matrix matrix(4, 4);
        matrix.data[0][0] = 1;
        matrix.data[1][1] = cos(angle);
        matrix.data[1][2] = -sin(angle);
        matrix.data[2][1] = sin(angle);
        matrix.data[2][2] = cos(angle);
        matrix.data[3][3] = 1;
        return matrix;
    }

   static Matrix rotateY(double angle) {
        Matrix matrix(4, 4);
        matrix.data[0][0] = cos(angle);
        matrix.data[0][2] = sin(angle);
        matrix.data[1][1] = 1;
        matrix.data[2][0] = -sin(angle);
        matrix.data[2][2] = cos(angle);
        matrix.data[3][3] = 1;
        return matrix;
    }

   static Matrix rotateZ(double angle) {
        Matrix matrix(4, 4);
        matrix.data[0][0] = cos(angle);
        matrix.data[0][1] = -sin(angle);
        matrix.data[1][0] = sin(angle);
        matrix.data[1][1] = cos(angle);
        matrix.data[2][2] = 1;
        matrix.data[3][3] = 1;
        return matrix;
   }

   static Matrix mirrorXY() {
       Matrix matrix(4, 4);
       matrix.data[0][0] = 1;
       matrix.data[1][1] = 1;
       matrix.data[2][2] = -1;
       matrix.data[3][3] = 1;
       return matrix;
   }

   static Matrix mirrorYZ() {
       Matrix matrix(4, 4);
       matrix.data[0][0] = -1;
       matrix.data[1][1] = 1;
       matrix.data[2][2] = 1;
       matrix.data[3][3] = 1;
       return matrix;
   }

   static Matrix mirrorXZ() {
       Matrix matrix(4, 4);
       matrix.data[0][0] = 1;
       matrix.data[1][1] = -1;
       matrix.data[2][2] = 1;
       matrix.data[3][3] = 1;
       return matrix;
   }

   static Matrix perspectiveProjection(double c) {
       Matrix matrix(4, 4);
       matrix.data[0][0] = 1;
       matrix.data[1][1] = 1;
       matrix.data[2][2] = 1;
       matrix.data[3][3] = 1;
       matrix.data[3][2] = -1 / c;
       return matrix;
   }
};

struct Point3 {
    float x, y, z;

    Point3(float mx, float my, float mz) {
        x = mx;
        y = my;
        z = mz;
    }

    Point3(const Matrix& vector) {
        x = vector.data[0][0];
        y = vector.data[1][0];
        z = vector.data[2][0];
    }
};

struct Point2 {
    float x, y;
};

static Point2 projectPoint(const Point3& pt3, Matrix& projectionMatrix) {
    Matrix vector(4, 1);
    vector.data[0][0] = pt3.x;
    vector.data[1][0] = pt3.y;
    vector.data[2][0] = pt3.z;
    vector.data[3][0] = 1;

    Matrix result = projectionMatrix * vector;

    Point2 projectedPoint;
    projectedPoint.x = result.data[0][0] / result.data[3][0]; 
    projectedPoint.y = result.data[1][0] / result.data[3][0]; 

    return projectedPoint;
}

static Point2 perspProj(const Point3& pt3, double c) {
    Matrix vector(4, 1);
    vector.data[0][0] = pt3.x;
    vector.data[1][0] = pt3.y;
    vector.data[2][0] = pt3.z;
    vector.data[3][0] = 1;
    Matrix result = Matrix::perspectiveProjection(c) * vector;
    Point2 pt2 = { result.data[0][0] / result.data[3][0], result.data[1][0] / result.data[3][0] };
    return pt2;
}

static Point3 affineTransform(Matrix& matrix, Point3 pt3) {
    Matrix vector(4, 1);
    vector.data[0][0] = pt3.x;
    vector.data[1][0] = pt3.y;
    vector.data[2][0] = pt3.z;
    vector.data[3][0] = 1;
    Matrix result = matrix * vector;
    return Point3(result.data[0][0], result.data[1][0], result.data[2][0]);
}
