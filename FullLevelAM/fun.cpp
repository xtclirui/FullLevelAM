//
// Created by MBP on 2023/4/18.
//

#include "fun.h"

namespace nsp {

    void writePolyline(std::string path, Polyline polyline, bool clear_txt) {
//        std::ofstream pl_outfile;
//        pl_outfile.open(path, std::ios::app);

    }

    Polyline readPolyline(std::string path) {
        return Polyline();
    }

    std::vector<Segment> intersectTrianglePlane(Triangle triangle, Plane plane) {
        Segment AB(triangle.A, triangle.B);
        Segment AC(triangle.A, triangle.C);
        Segment BC(triangle.B, triangle.C);
        std::vector<std::shared_ptr<Point3D>> C1 = intersectSegmentPlane(AB, plane);
        std::vector<std::shared_ptr<Point3D>> C2 = intersectSegmentPlane(AC, plane);
        std::vector<std::shared_ptr<Point3D>> C3 = intersectSegmentPlane(BC, plane);
        if (C1.size() + C2.size() + C3.size() > 4) {
            return { AB, AC, BC };
        }
        std::shared_ptr<Point3D> c1 = C1.front();
        std::shared_ptr<Point3D> c2 = C2.front();
        std::shared_ptr<Point3D> c3 = C2.front();
        if(c1 == nullptr){
            if(c2 != nullptr && c3 != nullptr){
                //if(c2->distance(*c3) != 0.0){
                return { Segment(*c2, *c3) };
                //}
            }
        }
        else if(c2 == nullptr){
            if(c1 != nullptr && c3 != nullptr){
                //if(c1->distance(*c3) != 0.0){
                return { Segment(*c1, *c3) };
                //}
            }
        }
        else if(c3 == nullptr){
            if(c1 != nullptr && c2 != nullptr){
                //if(c1->distance(*c2) != 0.0){
                return { Segment(*c1, *c2) };
                //}
            }
        }
        else if(c1 != nullptr && c2 != nullptr && c3 != nullptr){
            if(c1->isIdentical(*c2)){
                return { Segment(*c1, *c3) };
            }
            else{
                return { Segment(*c1, *c2) };
            }
        }
        return { Segment() };
    }

    int cmp_pntSmaller(const LinkPoint& lp1, const LinkPoint& lp2) {
        if (lp1.x < lp2.x) {
            return -1;
        }
        else if (lp1.x == lp2.x && lp1.y < lp2.y) {
            return -1;
        }
        else if (lp1.x == lp2.x && lp1.y == lp2.y && lp1.z < lp2.z) {
            return -1;
        }
        else if (lp1.x == lp2.x && lp1.y == lp2.y && lp1.z == lp2.z) {
            return 0;
        }
        else return 1;
    }
}