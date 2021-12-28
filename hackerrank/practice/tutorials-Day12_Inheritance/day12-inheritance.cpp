#include <iostream>
#include <vector>

using namespace std;


class Person{
	protected:
		string firstName;
		string lastName;
		int id;
	public:
		Person(string firstName, string lastName, int identification){
			this->firstName = firstName;
			this->lastName = lastName;
			this->id = identification;
		}
		void printPerson(){
			cout<< "Name: "<< lastName << ", "<< firstName <<"\nID: "<< id << "\n";
		}
	
};

class Student :  public Person{
  private:
    vector<int> testScores;
  public:
        /*	
        *   Class Constructor
        *   
        *   Parameters:
        *   firstName - A string denoting the Person's first name.
        *   lastName - A string denoting the Person's last name.
        *   id - An integer denoting the Person's ID number.
        *   scores - An array of integers denoting the Person's test scores.
        */
        // Write your constructor here

        /*	
        *   Function Name: calculate
        *   Return: A character denoting the grade.
        */
        // Write your function here
    Student(string firstName, string lastName, int identification, vector<int> scores ) :
      Person(firstName, lastName, identification), testScores(scores)
    {

    }

    double averageScores(){
      int sum{0};
      for( auto score : testScores ){
        sum += score;
      }
      return static_cast<double>(sum)/testScores.size();
    }

    string calculate(){
      double result = this->averageScores();
      if( result < 40 ){ return "T";}
      else if( result >= 40 && result < 55){ return "D";}
      else if( result >= 55 && result < 70){ return "P";}
      else if( result >= 70 && result < 80){ return "A";}
      else if( result >= 80 && result < 90){ return "E";}
      else { return "O";}
    }
};
int main(){
  Student* s = new Student("firstName", "lastName", 123, {1,2,3});
  s->printPerson();
  cout << "Grade: " << s->calculate() << "\n";
}

int hackerRankMain() {
  // string firstName;
  // string lastName;
  // int id;
  // int numScores;
  // cin >> firstName >> lastName >> id >> numScores;
  // vector<int> scores;
  // for(int i = 0; i < numScores; i++){
  //   int tmpScore;
  //   cin >> tmpScore;
  //   scores.push_back(tmpScore);
  // }
  // Student* s = new Student(firstName, lastName, id, scores);
  // s->printPerson();
  // cout << "Grade: " << s->calculate() << "\n";
  return 0;
}