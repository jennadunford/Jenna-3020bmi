#include <iostream>
#include <fstream>
#include <string>

using namespace std;

double ounces2pounds(int x)
{
    return(x/16);
}

double stones2pounds(int x)
{
    return(x*14);//This needs to be multiplied
}

double weight2kg(int stones, int pounds, int ounces)
{
    return (stones2pounds(stones)+pounds+ounces2pounds(ounces))/2.2;
}

double height2metres(int feet, double inches)
{
    return(feet/3.28)+((inches/12)/3.28);//Tried to neaten this calculation
}

//Changed all function variables to doubles
char categorise(double kg, double metre)
{
	cout <<  "Kg : " << kg << " Metres: " << metre << endl;
    double bmi = (kg)/(metre*metre); //Changed this calculation
	cout << "calculated bmi: " << bmi << endl; //Added output log to check values
    char cat;
    if (bmi<19)
        cat='A';
    else if (bmi<=25)//This value was incorrect, changed
        cat='B';
    else if (bmi<=30)//This value was incorrect, changed
        cat='C';
    else
        cat='D';
    return(cat);
}

void process_data(char* input_file, char* output_file)
{
    ifstream f_in;
    ofstream f_out;
    string data;
    string person_id;
    int pounds, stones, ounces, feet;
    double inches;
    double kg, m;
    char cat;

    f_in.open(input_file,ios::in);
    f_out.open(output_file,ofstream::out);
    while (!f_in.eof())
    {
    	f_in >> person_id >> stones >> pounds >> ounces >> feet >> inches;//Stones and pounds were in incorrect places
	cout << "Inches: " << inches << endl;
        kg=weight2kg(int(stones),int(pounds),int(ounces));
        m =height2metres(int(feet),double(inches));
        cat=categorise(kg,m);
	if(f_in.eof()){break;}
	f_out << person_id << " " << cat << endl;
    }
    f_in.close();
    f_out.close();
}
        
int main(int argc, char *argv[])
{
    process_data(argv[1], argv[2]);
}
