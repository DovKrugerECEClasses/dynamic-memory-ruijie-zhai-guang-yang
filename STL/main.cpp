#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;
#define PI 3.14159265

void push_vertex(vector<double> &v, double x, double y, double z) {
    v.push_back(x);
    v.push_back(y);
    v.push_back(z);
}

class Shape {
protected:
    double x, y, z;
public:
    Shape(double x=0, double y=0, double z=0) : x(x), y(y), z(z) {}
   // virtual ~Shape()=0;
    virtual vector<double> getFacetsData() {}
};

class Cylinder:public Shape {
private:
    double r, h;
    int facets;
public:
    Cylinder (double r, double h, double x=0, double y=0, double z=0, int facets=100) : Shape(x, y, z), r(r), h(h), facets(facets) {}

    vector<double> getFacetsData() override {
        vector<double> facetsData;

        for (int i = 0; i < facets; i++) {
            push_vertex(facetsData, 0, 0, 1);
            push_vertex(facetsData, x + r * sin(360.0 / facets * i * PI / 180.0), y + r * cos(360.0 / facets * i * PI / 180.0) , z + h);
            push_vertex(facetsData, x + r * sin(360.0 / facets * (i + 1) * PI / 180.0), y + r * cos(360.0 / facets * (i + 1) * PI / 180.0) , z + h);
            push_vertex(facetsData, x, y, z + h);
        }

        for (int i = 0; i < facets; i++) {
            push_vertex(facetsData, 0, 0, -1);
            push_vertex(facetsData, x + r * sin(360.0 / facets * i * PI / 180.0), y + r * cos(360.0 / facets * i * PI / 180.0) , z);
            push_vertex(facetsData, x, y, z);
            push_vertex(facetsData, x + r * sin(360.0 / facets * (i + 1) * PI / 180.0), y + r * cos(360.0 / facets * (i + 1) * PI / 180.0) , z);
        }

        for (int i = 0; i < facets; i++) {
            push_vertex(facetsData, sin(360.0 / 2 / facets * i * PI / 180.0), cos(360.0 / 2 / facets * i * PI / 180), 0);
            push_vertex(facetsData, x + r * sin(360.0 / facets * i * PI / 180.0), y + r * cos(360.0 / facets * i * PI / 180.0) , z + h);
            push_vertex(facetsData, x + r * sin(360.0 / facets * i * PI / 180.0), y + r * cos(360.0 / facets * i * PI / 180.0) , z);
            push_vertex(facetsData, x + r * sin(360.0/ facets * (i + 1) * PI / 180.0), y + r * cos(360.0 / facets * (i + 1) * PI / 180.0) , z + h);
            push_vertex(facetsData, sin(360.0 / 2 / facets * i * PI / 180.0), cos(360.0 / 2 / facets * i * PI / 180.0), 0);
            push_vertex(facetsData, x + r * sin(360.0 / facets * i * PI / 180.0), y + r * cos(360.0 / facets * i * PI / 180) , z);
            push_vertex(facetsData, x + r * sin(360.0 / facets * (i + 1) * PI / 180.0), y + r * cos(360.0 / facets * (i + 1) * PI / 180.0) , z);
            push_vertex(facetsData, x + r * sin(360.0 / facets * (i + 1) * PI / 180.0), y + r * cos(360.0 / facets * (i + 1) * PI / 180.0) , z + h);
        }
        return facetsData;
    }
};

class Cube:public Shape {
private:
    double size;
public:
    Cube (double size, double x=0, double y=0, double z=0): Shape(x, y, z), size(size) {}

    void translate(double dx, double dy, double dz){
        x+=dx;
        y+=dy;
        z+=dz;
    }

    vector<double> getFacetsData() {
        vector<double> facetsData;

        push_vertex(facetsData, 0, 0, 1);
        push_vertex(facetsData, x, y + size, z + size);
        push_vertex(facetsData, x + size, y + size, z + size);
        push_vertex(facetsData, x + size, y, z + size);
        push_vertex(facetsData, 0, 0, 1);
        push_vertex(facetsData, x, y + size, z + size);
        push_vertex(facetsData, x + size, y, z + size);
        push_vertex(facetsData, x, y, z + size);

        push_vertex(facetsData, 0, 0, -1);
        push_vertex(facetsData, x, y + size, z);
        push_vertex(facetsData, x + size, y, z);
        push_vertex(facetsData, x + size, y + size, z);
        push_vertex(facetsData, 0, 0, -1);
        push_vertex(facetsData, x, y + size, z);
        push_vertex(facetsData, x, y, z);
        push_vertex(facetsData, x + size, y, z);

        push_vertex(facetsData, 0, 1, 0);
        push_vertex(facetsData, x, y + size, z + size);
        push_vertex(facetsData, x, y + size, z);
        push_vertex(facetsData, x + size, y + size, z);
        push_vertex(facetsData, 0, 1, 0);
        push_vertex(facetsData, x, y + size, z + size);
        push_vertex(facetsData, x + size, y + size, z);
        push_vertex(facetsData, x + size, y + size, z + size);
        // 0 -1 0
        push_vertex(facetsData, 0, -1, 0);
        push_vertex(facetsData, x, y, z + size);
        push_vertex(facetsData, x + size, y, z);
        push_vertex(facetsData, x, y, z);
        push_vertex(facetsData, 0, -1, 0);
        push_vertex(facetsData, x, y, z + size);
        push_vertex(facetsData, x + size, y, z + size);
        push_vertex(facetsData, x + size, y, z);

        push_vertex(facetsData, 1, 0, 0);
        push_vertex(facetsData, x + size, y + size, z);
        push_vertex(facetsData, x + size, y, z);
        push_vertex(facetsData, x + size, y, z + size);
        push_vertex(facetsData, 1, 0, 0);
        push_vertex(facetsData, x + size, y + size, z + size);
        push_vertex(facetsData, x + size, y + size, z);
        push_vertex(facetsData, x + size, y, z + size);

        push_vertex(facetsData, -1, 0, 0);
        push_vertex(facetsData, x, y + size, z);
        push_vertex(facetsData, x, y, z + size);
        push_vertex(facetsData, x, y, z);
        push_vertex(facetsData, -1, 0, 0);
        push_vertex(facetsData, x, y + size, z + size);
        push_vertex(facetsData, x, y, z + size);
        push_vertex(facetsData, x, y + size, z);
        return facetsData;
    }

    double volume(){
        return pow(size,3);
    }

    void write(string fileName) {
        ofstream myfile;
        myfile.open(fileName);
        myfile << "solid test_model" << endl;
        vector<double> facetsData = getFacetsData();
        int size = facetsData.size();
        for (int i = 0; i < size; i += 3 * 4) {
            myfile << "  facet normal " << facetsData[i] << " " << facetsData[i + 1] << " " << facetsData[i + 2] << endl;
            myfile << "    outer loop" << endl;
            myfile << "      vertex " << facetsData[i + 3] << " " << facetsData[i + 4] << " " << facetsData[i + 5] << endl;
            myfile << "      vertex " << facetsData[i + 6] << " " << facetsData[i + 7] << " " << facetsData[i + 8] << endl;
            myfile << "      vertex " << facetsData[i + 9] << " " << facetsData[i + 10] << " " << facetsData[i + 11] << endl;
            myfile << "    endloop" << endl;
            myfile << "  endfacet" << endl;
        }
        myfile << "endsolid test_model" << endl;
        myfile.close();
    }
};

class Design {
private:
    vector<Shape*> shapes;
public:
    Design()=default;
//    ~Design() {
//        int size = shapes.size();
//        for (int i = 0; i < size; i++) {
//            delete shapes[i];
//        }
//    }
    void add(Shape* s) {
        shapes.push_back(s);
    }
    //TODO: rewrite this
    void write(string fileName) {
        ofstream myfile;
        myfile.open(fileName);
        myfile << "solid test_model" << endl;
        for (Shape* s : shapes) {
            vector<double> facetsData = s->getFacetsData();
            int size = facetsData.size();
            for (int i = 0; i < size; i += 3 * 4) {
                myfile << "  facet normal " << facetsData[i] << " " << facetsData[i + 1] << " " << facetsData[i + 2] << endl;
                myfile << "    outer loop" << endl;
                myfile << "      vertex " << facetsData[i + 3] << " " << facetsData[i + 4] << " " << facetsData[i + 5] << endl;
                myfile << "      vertex " << facetsData[i + 6] << " " << facetsData[i + 7] << " " << facetsData[i + 8] << endl;
                myfile << "      vertex " << facetsData[i + 9] << " " << facetsData[i + 10] << " " << facetsData[i + 11] << endl;
                myfile << "    endloop" << endl;
                myfile << "  endfacet" << endl;
            }
        }
        myfile << "endsolid test_model" << endl;
        myfile.close();
    }
};


int main() {
    Design d;
    double s = 10;
    Cube c(s);
    c.translate(12,10,8);
    // rotate??
    cout << c.volume() << '\n';
    c.write("out.stl"); // how to get all my shapes into the same file
    d.add(&c);
    double r = 10, height  = 20;
    Cylinder cyl(r, height);
    d.add(&cyl);
    d.write("test.stl");
}