#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

double rescale(double v, double a, double b, double c, double d)
{
    double m = (c-d)/(a-b);
    double n = d - b*m;
    double rval = m*v + n;
    return rval;
}

int main()
{
    string fileName = "data.csv";
    ifstream infile(fileName);

    if(infile.fail())
    {
        cerr << "File does not exist" << endl;
        return 1;
    }

    double a = 1;
    double b = 5;
    double c = -1;
    double d = 2;

    double v = 0;
    unsigned int counter = 0;
    double sum = 0;
    double mean = 0;

    ofstream outfile("result.csv");
    outfile << "# N Mean" << endl;

    while (infile >> v)
    {
        double newv = rescale(v,a,b,c,d);
        counter++;
        sum += newv;
        mean = sum/counter;

        outfile << counter << " " << scientific << setprecision(16) << mean << endl;

    }

    infile.close();
    outfile.close();

    return 0;
}

