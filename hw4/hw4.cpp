//
//  main.cpp
//  hw4
//
//  Created by Patricia Antlitz on 2/10/23.
//
/**
 Author: <Dr. Sirong Lin - Main function>
 Co-Author: <Patricia Antlitz - Class and methods>
 Date: <02/10/2023 - Version 1>
 Date: <02/14/2023 - Version 2>
 Purpose: <Convert a set of binary numbers into a decimal bar code and vice versa>
 Sources of Help: <substring: https://www.udacity.com/blog/2021/05/our-guide-to-cpp-substrings.html#:~:text=What%20Is%20a%20Substring%20in,string%20from%20within%20a%20string.
 string stream: https://www.geeksforgeeks.org/stringstream-c-applications/
 string index: https://www.w3schools.com/cpp/cpp_strings_access.asp
 I took a look at this code, and used it as an inspiration. I took the binary values for each decimal number (switch case) from this code: https://github.com/proshan/Absolute-Cpp-Solutions/blob/master/Chapter%207/Programming%20Projects/9.cpp>
 Time Spent: <unknown>
 ***/
/*
 Computing III -- COMP.2010 Honor Statement
 The practice of good ethical behavior is essential for maintaining
 good order in the classroom, providing an enriching learning
 experience for students, and as training as a practicing computing
 professional upon graduation. This practice is manifested in the
 University’s Academic Integrity policy. Students are expected to
 strictly avoid academic dishonesty and adhere to the Academic
 Integrity policy as outlined in the course catalog. Violations will
 be dealt with as outlined therein.
 All programming assignments in this class are to be done by the
 student alone. No outside help is permitted except the instructor and
 approved tutors.
 I certify that the work submitted with this assignment is mine and was
 generated in a manner consistent with this document, the course
 academic policy on the course website on Blackboard, and the UMass
 Lowell academic code.
 Date: 02/10/2023
 Name: Patricia Antlitz
 
 ----------------------------------------------------------------------
 
 Description: The bar code on an envelope used by the US Postal Service represents a five (or more) digit zip code using a format
 called POSTNET (this format is being deprecated in favor of a new system, OneCode, in 2009).
 
 The bar code consists of long and short bars as shown below: For this program we will represent the bar code as a string of digits.
 The digit 1 represents a long bar and the digit 0 represents a short bar. Therefore, the bar code above would be represented in our
 program as: 110100101000101011000010011.
 
 The first and last digits of the bar code are always 1. Removing these leave 25 digits. If these 25 digits are split into groups of
 five digits each then we have: 10100 10100 01010 11000 01001. Next, consider each group of five digits.
 There will always be exactly two 1’s in each group of digits. Each digit stands for a number. From left to right the digits encode
 the values 7, 4, 2, 1, and 0. Multiply the corresponding value with the digit and compute the sum to get the final encoded digit for
 the zip code. The table below shows the encoding for 10100.
 
 Zip Code Digit = 7 + 0 + 2 + 0 + 0 = 9
 
 Repeat this for each group of five digits and concatenate to get the complete zip code. There is one
 special value. If the sum of a group of five digits is 11, then this represents the digit 0 (this is necessary
 because with two digits per group it is not possible to represent zero). The zip code for the sample bar code decodes to 99504. While
 the POSTNET scheme may seem unnecessarily complex, its design allows machines to detect if errors have been made in scanning the zip
 code.
 
 Problems:
It was hard to make sense of the main function
 */

//create a project called hw4
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

//Write a zip code class that encodes and decodes five-digit bar codes used by the US Postal Service on envelopes
class ZipCode
{
public:
    ZipCode();
    //The class should have two constructors
    //The first constructor should input the zip code as an integer
    ZipCode(int zipCodeNum);
    // the second constructor should input the zip code as a bar code string consisting of 0’s and 1’s
    ZipCode(string zipCodeString);
    
    //The class should also have at least two public member functions
    //one to return the zip code as an integer
    int getZipCode(void) const;
    //the other to return the zip code in bar code format as a string
    string getBarCode(void);
 
private:
    string numberCode;
    string stringCode;
    
    //these two mutators are used as helper functions
    //the bar code converts the integer passed in the parameter to a binary string
    void setBarCode(string zipCode);
    //this method takes a string of binary numbers, and converts it to decimal digits
    void setZipCode(string barCode);
};

//copy the main function from the instructions document:
//main function CANNOT be altered
int main(int argc, char * argv[])
{
    ZipCode zip(99504),
    zip2("100101010011100001100110001"),
    zip3(12345),
    zip4(67890);
    cout << zip.getZipCode() << "'s bar code is '"
    << zip.getBarCode() << "'" << endl;
    cout << zip2.getZipCode() << "'s bar code is '"
    << zip2.getBarCode() << "'" << endl;
    cout << zip3.getZipCode() << "'s bar code is '"
    << zip3.getBarCode() << "'" << endl;
    cout << zip4.getZipCode() << "'s bar code is '"
    << zip4.getBarCode() << "'" << endl;
    
    cout << endl;
    
    // Test a range of values by first constructing a zip code
    // with an integer, then retrieving the bar code and using
    // that to construct another ZipCode.
    int zip_int = 0;
    for (int i = 0; i < 25; i++)
    {
        // Make an arbitrary 5-digit zip code integer, and use it
        // to construct a ZipCode
        int five_digit_zip = (zip_int * zip_int) % 100000;
        ZipCode z1(five_digit_zip);
        
        // Construct a second ZipCode from the first's bar code
        string z1_barcode = z1.getBarCode();
        ZipCode z2(z1_barcode);
        
        cout.width(3);
        cout << (i + 1) << ": ";
        cout.width(5);
        cout << z2.getZipCode() << " has code '"
        << z1_barcode << "'";
        
        if ((z1_barcode == z2.getBarCode()) &&
            (z1.getZipCode() == z2.getZipCode()) &&
            (z2.getZipCode() == five_digit_zip))
        {
            cout << " [OK]" << endl;
        }
        else
        {
            cout << " [ERR]" << endl;
        }
        
        // Increment the test value arbitrarily
        zip_int += (233 + zip_int % 7);
    }
    cout << endl;
    // Test some error conditions. This test assumes that
    // ZipCode will simply set its value to a flag that indicates
    // an error, and will not exit the program.
    int BAD_ZIP_COUNT = 2;
    string bad_zips[][2] = {
        { "100101010011100001100110000", "bad start/end character" },
        { "100101010011100001100110021", "bad digit" },
    };
    for (int i = 0; i < BAD_ZIP_COUNT; i++)
    {
        cout << "Testing: " << bad_zips[i][1] << " " << bad_zips[i][0] <<
        endl;
        ZipCode test(bad_zips[i][0]);
        cout << endl;
    }
    cout << "Enter a character to quit." << endl;
    char c;
    cin >> c;
    return 0;
}

//default
ZipCode::ZipCode()
{
    numberCode = "";
}
//decimal numbers passed as integer
ZipCode::ZipCode(int zipCodeNum)
{
    //numberCode is a string, the integer passed must be converted to one
    numberCode = to_string(zipCodeNum);
    //takes a string
    setBarCode(numberCode);
}
//binary numbers passes as a string
ZipCode::ZipCode(string zipCodeString)
{
    //helper function will turn this string into a zip code number
    stringCode = zipCodeString;
    setZipCode(zipCodeString);
}

//helper/mutator -> gets the binary string "bar code"
void ZipCode::setZipCode(string barString)
{
    string newString;
    string shrinkSize;
    
    int sum;
    int stringToInt;
    
    for(int i = 1; i <= barString.length(); i+=5)
    {
        //we want 5 digits, starting from the position i currently running
        shrinkSize = barString.substr(i, 5);
        
        //multiply the binary numbers by 7 4 2 1 or 0 then add them together
        sum = 7*(shrinkSize[0] - '0') + 4*(shrinkSize[1] - '0') + 2*(shrinkSize[2] - '0') + 1*(shrinkSize[3] - '0') + 0*(shrinkSize[4] - '0');
        //if the sum is equal to 11
        if(sum == 11)
        {
            //then we set the total to 0
            sum = 0;
        }
        //we will add the numbers to the string
        newString += to_string(sum);
    }
    //assigning to the class member variable
    numberCode = newString;
}

int ZipCode::getZipCode(void) const
{
    //we can then return this value to be used by the main function
    //turn the string into a number
    return atoi(numberCode.c_str());
}

//convert zip code number into bar code
void ZipCode::setBarCode(string zipCode)
{
    string startBarCode = "1";
    //turn the integers into a string
    string subDigits;
    
    for(int i = 0; i < zipCode.length(); i++)
    {
        //current digit
        int current = zipCode[i] - '0';
        
        //the correct assignment based on each possible decimal numbers
        switch(current)
        {
            case 0:
                subDigits = "11000";
                break;
            case 1:
                subDigits = "00011";
                break;
            case 2:
                subDigits = "00101";
                break;
            case 3:
                subDigits = "00110";
                break;
            case 4:
                subDigits = "01001";
                break;
            case 5:
                subDigits = "01010";
                break;
            case 6:
                subDigits = "01100";
                break;
            case 7:
                subDigits = "10001";
                break;
            case 8:
                subDigits = "10010";
                break;
            case 9:
                subDigits = "10100";
                break;
            default:
                subDigits = "00000";
                cout << "Error!" << endl;
        }
        //append substring to converted string
        startBarCode += subDigits;
    }
    //add 1 to the end (must start with 1, and end with 1)
    startBarCode += "1";
    stringCode = startBarCode;
}

string ZipCode::getBarCode(void)
{
    return stringCode;
}
