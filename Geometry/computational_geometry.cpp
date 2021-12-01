#include<bits/stdc++.h>
using namespace std;


// A point 
// A point ( or vector ) is defined by its co-ordinates x,y,z. In case of 
// 2-D problems, z =0 
// A point can be represented by a struct in C as follows : 

typedef struct
{
    int x,y,z;

}Point; // set z = 0 , for 2D point 

/* 
Vector:
What is a vector? A vector is one of the simplest structures which 
is used when one is dealing with a geometry problem. A vector has a direction 
and a magnitude. In case of two dimensions, a vector is represented as a pair of 
numbers: x and y, which gives both a direction and a magnitude

Vectors are commonly used to represent directed line segments. Representation of 
a vector is usually in its component-ized form, where its projections 
along the major axes are used as quantities by which it is defined.

in 3 dimensions: 
V = Vx(i) + Vy(j) + Vz(k)

*/

/* 
    Addition 

    Adding two vectors will result in a new vector. If you have two vectors 
    (x1, y1) and (x2, y2), then, the sum of the two vectors is simply (x1+x2, y1+y2). 
    It doesn’t matter which order you add them up in – just like regular addition.
*/

/*
    Dot Product 

    The dot product is a quantity which is the length of one vector times 
    the length of the amount of another vector parallel to that vector. Given 
    two vectors u and v, the dot product of the two vectors would be: |u||v|cos (θ).
    θ is the angle between the two vectors u and v. |u| is called the norm of the 
    vector, and in a 2-D geometry problem is simply the length of the vector, √(x2+y2). 
    From this, one can see that if two vectors are perpendicular, the dot product 
    would be 0. The dot product is greatest when the lines are parallel. We can take
    dot products of vectors with any number of elements.
    So, the point to note? Adding two vectors and multiplying a vector by a scalar 
    is done component-wise.

*/

/*
    Cross Product 

    Cross Product:
The cross product of two 2-D vectors is (x1y2 - y1x2).

The cross product takes two vectors and produces a vector 
that is perpendicular to both vectors.
Like the dot product, A x B = |A||B|Sin(θ). |θ| is the angle between the 
two vectors, but θ is negative or positive based on the right-hand rule. 
It means that if A is less than 180 degrees clockwise from B, the value is positive. 
t also means that cross-product of two parallel vectors is zero.The cross product 
is also NOT commutative: u x v = -v x u.

Fun fact: Absolute value of |A||B|Sin(θ) is equal to the area of the 
parallelogram with two of its sides formed by A and B.

*/


//  implementation
void code(int a[]  int b[] , int c[])
{
    int ab[2] ={0};
    int bc[2] = {0};
    
    ab[0] =b[0]  - a[0];
    ab[1] = b[1] -a[1];
    bc[0] = c[0] - b[0];
    bc[1] = c[1] - b[1];
    return (ab[0] * bc[0] + ab[1] * bc[1]);
}

void cross(int a[] , int b[] , int c[])
{
    int ab[2]= {0};
    int bc[2] = {0};
    int ac[2] = {0};

    ab[0] = b[0] - a[0];
    ab[1] = b[1] - a[1];
    ac[0] = c[0] - a[0];
    ac[1] = c[1] - a[1];
    return (ab[0] * ac[1] + ab[1] * ac[0]);
}


/* 
    CCW ( Clock-wise counter function ):
One of the most important operation that is essential to many 
geometric solutions is the counter-clockwise-function. Given the three 
coordinates of 3 points, this function returns 1 if the points are in 
counter-clockwise order, returns -1, if they are in clockwise order and 
returns 0 if they are collinear.

*/

// implementation
int ccw(int a , int b , int c)
{
    int dx1 ,dx2 ,dy1 , dy2;
    dx1 = b[0]- a[0];
    dx2 = c[0] -a[0];
    dy1 = b[1] - a[1];
    dy2 = c[1] - a[1];
    if(dx1*dy2 > dy1*dx2)
    {
        return 1;
    }
    else if(dx1*dy2 < dy1*dx2)
    {
        return -1;
    }
    return 0;
}


/* 
    Polygon:
    Polygons are two-dimensional shapes. They are made of straight lines,
    and the shape is "closed". If all angles are equal and all sides are 
    equal, then it is regular, otherwise it is irregular.

    The general formula of area of a polygon:

    Area = 1/2 * Σ (From i=0 to n-1) Xi * Yi+1 - Xi+1 + Yi
*/



// final code
/* 
Assume that we already have the classes for the following objects: 
Point and Vector with coordinates {float x, y, z;} (z=0  for 2D)
and appropriate operators for:
           Point  = Point ± Vector
               Vector = Point - Point
               Vector = Scalar * Vector
     Line with defining endpoints {Point P0, P1;}
     Segment with defining endpoints {Point P0, P1;}
Plane with a point and a normal vector {Point V0; Vector  n;}
*/


// dot product (3D) which allows vector operations in arguments
#define dot(u,v) ((u).x * (v).x + (u).y *(v).y + (u).z * (v).z)
#define norm(v) sqrt(dot(v,v))  // norm = length of vector 
#define d(u,v) norm(u-v)    // distance = norm of difference 
// ----------------------

/* 
    dist_point_to_line() ;: get the distance of a point to a line 
    input: a Point P and a line L ( in any dimension )
    return : the shortest distance form P to L 
*/

float dist_point_to_line(Point P , Line L)
{
    Vector v = L.P1 - L.P0;
    Vector w = P - L.P0;
    double c1 = dot(x,v);
    double c2 = dot(v,v);
    double b = c1 /c2;
    Point Pb = L.P0 + b*v;
    return d(P ,Pb);
}

// ------------------------------
/* 
    dist_Point_to_Segment(): get the distance of a point to a segment
    Input:  a Point P and a Segment S (in any dimension)
    Return: the shortest distance from P to S
*/
float dist_point_to_segment(Point P , Segment S )
{
    Vector v = S.P1 - S.P0;
    Vecotr w = P - S.P0;

    double c1 = dot(w,v);
    if(c1 < =0)
    {
        return d(P , S.P0);
    }

    double c2 =dot(v,v);
    if(c2 <= c1)
    {
        return d(P , S.P1);
    }

    double b = c1 /c2;
    Point Pb = S.P0 + b*v;
    return d(P , Pb);
}


//===================================================================
/* dist_Point_to_Plane(): get distance (and perp base) from a point to a plane
    Input:  P  = a 3D point
            PL = a  plane with point V0 and normal n
    Output: *B = base point on PL of perpendicular from P
    Return: the distance from P to the plane PL
*/
float dist_Point_to_Plane( Point P, Plane PL, Point* B)
{
    float    sb, sn, sd;

    sn = -dot( PL.n, (P - PL.V0));
    sd = dot(PL.n, PL.n);
    sb = sn / sd;

    *B = P + sb * PL.n;
    return d(P, *B);
}
//===================================================================




int main()
{

    return 0;
}