#include <iostream>
#include <vector>
#include <string>
#include <iterator>

using namespace std;

class Task
{
    vector<string> Student;
    vector<double> Ball;
public:
    Task(){};

    void set(string Input_Student, double Input_Ball)
    {
        Student.insert(Student.end(), Input_Student);
        Ball.insert(Ball.end(), Input_Ball);
    }

    double Middle(vector<double> Ball)
    {
        double sum = 0;
        double end;
        for (int i = 0; i < Ball.size(); i++)
        {
            sum += Ball[i];
        }
        end = sum/(Ball.end()-Ball.begin());
        return end;
    }
    void print()
    {
        cout << Task::Middle( Ball);
    }
};




int main() {
    Task student;
    string Input_Student;
    int answer;
    double Input_Ball;
    int p =1;
    while (p == 1)
    {
        cout << "Would you like to continue ? If you would, type in '1'" << endl;
        cin >> answer;
        switch(answer)
        {
            case 1:
            {
                cin >> Input_Student;
                cin >> Input_Ball;
                student.set(Input_Student, Input_Ball);
                break;
            }
            default : p = 0;
        }
    }
    cout << "The median mark is "; student.print();

    return 0;
}