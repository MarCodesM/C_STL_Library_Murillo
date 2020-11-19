/*
Name: Marcos Murillo
Date: 11/16/2020
Class: COSC 1437
Teacher: Dr. T
displays knowledge of vectors and algorithm
*/

#include <iostream>
#include <vector>
#include <stack>
#include <cassert>
#include <set>
#include <string>
#include <utility>
#include <map>
#include <algorithm>

//https://www.geeksforgeeks.org/passing-vector-constructor-c/ clarifications added
class MyClassVector1 
{ 
  private:  
      std::vector<int> vec; 
  public: 
      MyClassVector1 (std::vector<int> v)  
      { 
        vec = v; 
      } 
      void print() 
      {  
          for (int i = 0; i < vec.size(); i++) 
          {
              std::cout << vec[i] << " "; 
          }    
      } 
};

//bool funciton for Predicate_Algorithm9
bool less_than_7(int value)
{
  return value < 7;
}

typedef std::map<std::string,  int> MapT;
typedef MapT::const_iterator MapIterT;

int main() 
{
  /****Section_Name***Vectors*/ 
  std::vector<double> vd;
  std::vector<int> vi;
  std::vector<std::string> vs;

  //Adding 3 elements
  vd.push_back(1.1);
  vd.push_back(2.1);
  vd.push_back(3.1);

  vi.push_back(1);
  vi.push_back(2);
  vi.push_back(3);

  vs.push_back("one");
  vs.push_back("two");
  vs.push_back("three");

  //display elemets in vectors
  std::cout << "\nElements in vd:" << std::endl;
  for(double val : vd)
  {
    std::cout << val << std::endl;
  }

  std::cout << "\nElements in vi:" << std::endl;
  for(int val : vi)
  {
    std::cout << val << std::endl;
  }

  std::cout << "\nElements in vs:" << std::endl;
  for(std::string val : vs)
  {
    std::cout << val << std::endl;
  }

  /****Section_Name****Vector_as_Class_Member*/
   std::cout << "\nVector_as_Class_Member (MyClassVector1)" << std::endl; 
    std::vector<int> vec; 
        for (int i = 1; i <= 5; i++) 
            vec.push_back(i); 
        MyClassVector1 obj(vec); 
        obj.print(); 

   std::cout << "\nVector_as_Class_Member (MyClassVector2)" << std::endl; 
    std::vector<int> vec1; 
        for (int i = 1; i <= 5; i++) 
            vec.push_back(i); 
        MyClassVector1 obj1(vec); 
        obj.print(); 

   std::cout << "\nVector_as_Class_Member (MyClassVector3)" << std::endl; 
    std::vector<int> vec2; 
        for (int i = 1; i <= 5; i++) 
            vec.push_back(i); 
        MyClassVector1 obj2(vec); 
        obj.print(); 

  /****Section_Name***STL_Iterators*/  
  std::cout << "\n\nUsing STL_Iterators\n";
  std::vector<int> vint(10);
  vint[0] = 10;
  vint[1] = 20;
  vint[2] = 30;
  vint[3] = 40;
  vint[4] = 50;
  vint[5] = 60;
  vint[6] = 70;
  vint[7] = 80;
  vint[8] = 90;
  vint[9] = 100;

  std::vector<int>::iterator it;

  for(it = vint.begin(); it != vint.end(); ++it)
  {
    std::cout << " " << *it;
  }

  /****Section_Name***Stack*/
  std::stack<int> st;
  st.push(100); //Push number on stack
  assert(st.size() == 1); //verify one ele is on stack
  assert(st.top() == 100); // verify ele value

  st.top() = 456; //assign new value
  assert(st.top() == 456); // verify ele value

  st.pop(); //remove ele
  assert(st.empty() == true);

  /****Section_Name***Set*/
  std::set<int> iset; //set of unique int numbers

  iset.insert(11); // populate iset with int values
  iset.insert(-11); // populate iset with int values
  iset.insert(55); // populate iset with int values
  iset.insert(22); // populate iset with int values
  iset.insert(22); // populate iset with int values

  //checks if value is already stored. if not it stores 55
  if(iset.find(55) != iset.end())
  {
    iset.insert(55);
  }

  assert(iset.size() == 4);
  std::set<int>::iterator itt;
  //prints ele in iset
  std::cout << "\n\nUsing Set<>\n";
  for(itt = iset.begin(); itt != iset.end(); itt++)
  {
    std::cout << " " << *itt;
  }

  /****Section_Name***Pair_Structure*/
  std::pair<std::string, std::string> strstr; //creating a pair that will hold two strings
  strstr.first = "Hello"; //populating first ele
  strstr.second = "world"; //populating second ele

  std::pair<int, std::string> intstr; //creating a pair that will hold int and string
  intstr.first = 1; //populating first ele
  intstr.second = "one"; //populating second ele

  std::pair<std::string, int> strint("two", 2); //creates and populates a pair with string and int
  assert(strint.first == "two"); //checks if string == two
  assert(strint.second == 2); //checks if int == 2

  /****Section_Name***Map_Insert*/
  MapT amap; // creats a Mapt calls amap
  std::pair<MapIterT, bool> result = amap.insert(std::make_pair("Fred", 45)); //creats a pair that will hold Fred and 45
  assert(result.second == true); //checks if the second pair == true
  assert(result.first->second == 45);
  result = amap.insert(std::make_pair("Fred", 45)); // same as line 165

  assert(result.second == false);
  assert(result.first->second == 45); 

  /****Section_Name***Map_Summary*/
  std::map<std::string, std::string> phone_book; //creates map called phone_book
  phone_book["411"] = "Directory"; //creates key 411 to Directory
  phone_book["911"] = "Emergency"; //creates key 911 to Emergency
  phone_book["508-678-2811"] = "BCC"; //creats 508-678-2811 to BCC
  
  //if 411 is not the last ele make it the last ele
  if(phone_book.find("411") != phone_book.end())
  {
    phone_book.insert(std::make_pair(std::string("411"), std::string("Direcotry")));
  }

  assert(phone_book.size() == 3); //checks if phone_book is size 3

  std::map<std::string, std::string>::const_iterator ittt; //creates iterator

  //print contents in phone_book
  std::cout << "\n\nMap_Summary\n";
  for(ittt = phone_book.begin(); ittt != phone_book.end(); ++ittt)
  {
    std::cout << " " << ittt->first << " " << ittt->second << std::endl;
  }

  /****Section_Name***Sort_Algorithm*/
  int arr[100]; //creates an array with 100 ele
  std::sort(arr, arr + 100); //sorts arry 1 - 100

  std::vector<int> v1; //creates vector called v1
  std::sort(v1.begin(), v1.end()); //sorts vector

  /****Section_Name***Predicate_Algorithm*/
  std::vector<int> v2; //creats v2 as int vector
  int count_less = std::count_if(v2.begin(), v2.end(), less_than_7); //will return 0 becuase v2 is less than 7




}