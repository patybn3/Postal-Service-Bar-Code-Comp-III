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
