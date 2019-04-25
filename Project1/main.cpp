/*
	Park, David
	CS A200
	October 28, 2015

	Exercise 13 Final
*/

#include "BST.h"
#include "BST.cpp"
#include "Student.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

template<typename T>
void processTree(BST<T>&,char fileName[]);

void processStudentTree(BST<Student>&, char fileName[]);

template<typename T>
void testTree(const BST<T>& bst);

int main()
{
    cout << "TESTING: int_1 BST\n\n";
    BST<int> int1BST;
    char fileNameInt1[] = "data_int_1.txt";
    processTree(int1BST,fileNameInt1);
    testTree(int1BST);
    
    cout << "\n\n---------------------------------------------------\n";
    cout << "TESTING: int_2 BST\n\n";
    BST<int> int2BST;
    char fileNameInt2[] = "data_int_2.txt";
    processTree(int2BST,fileNameInt2);
    testTree(int2BST);
    
    cout << "\n\n---------------------------------------------------\n";
    cout << "TESTING: int_3 BST\n\n";
    BST<int> int3BST;
    char fileNameInt3[] = "data_int_3.txt";
    processTree(int3BST, fileNameInt3);
    testTree(int3BST);
    
    cout << "\n\n---------------------------------------------------\n";
    cout << "TESTING: char BST\n\n";
    BST<char> charBST;
    char fileNameChar[] = "data_char.txt";
    processTree(charBST, fileNameChar);
    testTree(charBST);
    
    cout << "\n\n---------------------------------------------------\n";
    cout << "TESTING: double BST \n\n";
    BST<double> doubleBST;
    char fileNameDouble[] = "data_double.txt";
    processTree(doubleBST, fileNameDouble);
    testTree(doubleBST);
    
    cout << "\n\n---------------------------------------------------\n";
    cout << "TESTING: Student BST \n\n";
    BST<Student> studentBST;
    char fileNameStudent[] = "data_student_1.txt";
    processStudentTree(studentBST, fileNameStudent);
    testTree(studentBST);
    
    cout << "\n\n---------------------------------------------------\n";
    cout << "TESTING: Deleting tree...\n\n";
    int1BST.destroyTree();
    testTree(int1BST);
    
    cout << endl << endl;
    system("Pause");
    return 0;
}

template<typename T>
void processTree(BST<T>& bst, char fileName[])
{
    ifstream infile;
    infile.open(fileName);
    
    if(!infile)
        cerr << "Cannot open the input file." << endl;
    else
    {
        T data;
        infile >> data;
   
        while (data != -999 && data != '*')
        {
            bst.insert(data);
            infile >> data;
        }
        
        infile.clear(); //reset eof for next input
    }
    
    infile.close();
}

void processStudentTree(BST<Student>& bst, char fileName[])
{
    ifstream infile;
    infile.open(fileName);
    
    if(!infile)
        cerr << "Cannot open the input file." << endl;
    else
    {
        int studentID;
        infile >> studentID;
        
        while (studentID != -999)
        {
            string fName, lName;
            infile >> fName >> lName;
            
            Student student;
            student.setStudentInfo(studentID, fName, lName);
            
            bst.insert(student);
            infile >> studentID;
        }
        
        infile.clear(); //reset eof for next input
    }
    
    infile.close();
}

template<typename T>
void testTree(const BST<T>& bst)
{
    //TEST: inorderTraversal
    cout << "Inorder traversal: ";
    bst.inorderTraversal();
    
    //TEST: treeHeight
    cout << "\nHeight: " << bst.treeHeight();
    
    //TEST: totalNodes
    cout << "\nTotal nodes: " << bst.totalNodes();
}