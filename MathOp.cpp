#include<iostream>
#include<math.h>

using namespace std;

double perimeter(){
    cout << "Enter side of square : ";
    int s;
    cin >> s;
    return 4*s;
}

double circumference(){
    cout << "Enter Radius: ";
    double r;
    cin >> r;
    return 2*3.14*r;
}

double volumeCube(){
    cout << "Enter Side : ";
    double s;
    cin >> s;
    return s*s*s;
}

double volumeSphere(){
    cout << "Enter Radius : ";
    double r;
    cin >> r;
    return (4.0/3)*3.14*r*r*r;
}

double slope(){
    cout << "Enter coordinates of first point : ";
    double x1, y1, x2, y2;
    cin >> x1 >> y1;
    cout << "Enter coordinates of second point : ";
    cin >> x2 >> y2;
    return (y1 - y2) / (x1 - x2);
}

double pythagorus(){
    cout << "Enter base of the triangle : ";
    double b, p;
    cin >> b;
    cout << "Enter perpendicular of the triangle : ";
    cin >> p;
    return sqrt(b*b + p*p);
}

double maximum(){
    int n, a, mx = -1;
    cout << "How many numbers do you want to enter : ";
    cin >> n;
    cout << "Enter all numbers separated by space\n";
    while(n--){
        cin >> a;
        mx = max(mx, a);
    }
    return mx;
}

double distance(){
    double s, t;
    cout << "Enter Speed : ";
    cin >> s;
    cout << "Enter Time : ";
    cin >> t;
    return s*t; 
} 

int main(){
    int ch;
    do{
        cout << "\nChoose any operation from below: \n\n";
        cout << "1. Perimeter of a Square\n";
        cout << "2. Circumference of a circle\n";
        cout << "3. Volume of a cube\n";
        cout << "4. Volume of a sphere\n";
        cout << "5. Slope of a line\n";
        cout << "6. Pythagorean Theorem\n";
        cout << "7. Max of numbers\n";
        cout << "8. Distance from speed and time\n";
        cout << "9. Quit\n\n";

        cout << "Enter you choice : "; 
        double output;
        cin >> ch;

        switch(ch){
            case 1:
            output = perimeter();
            cout << "Perimeter = " << output << endl;
            break;

            case 2:
            output = circumference();
            cout << "Circumferencce = " << output << endl; 
            break;

            case 3:
            output = volumeCube();
            cout << "Volume = " << output << endl; 
            break;

            case 4:
            output = volumeSphere();
            cout << "Volume = " << output << endl; 
            break;

            case 5:
            output = slope();
            cout << "Slope = " << output << endl; 
            break;

            case 6:
            output = pythagorus();
            cout << "Hypotenuse = " << output << endl; 
            break;

            case 7:
            output = maximum();
            cout << "Max = " << output << endl; 
            break;

            case 8:
            output = distance();
            cout << "Distance = " << output << endl; 
            break;

            case 9:
            break;

            default:
            cout << "Invalid choice. Please Try again\n\n";
        }
    } while(ch != 9);
}