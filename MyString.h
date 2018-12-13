
//  Created by Wei-Hsuan Lien on 2018/5/17.
//  Copyright © 2018年 Wei-Hsuan Lien. All rights reserved.


#ifndef MyString_h
#define MyString_h
#include "CVector.h"
#include <stdio.h>
using namespace std;

class MyString : public CVector
{
    //friend ostream &operator<<(ostream& output, const MyString& str);
    friend MyString operator+ (const char*, const MyString&);
public:
    MyString(); 
    // Constructs an empty string, with a length of zero characters. 
    // *default capacity = 10
    
    MyString( const MyString &); 
    // Constructs a copy of "str". (copy constructor)
    
    MyString( const MyString &, size_t, size_t); // (substring constructor)
    // Copies the portion of str that begins at the character position "pos" and spans "len" characters 
    // (or until the end of str, if either str is too short or if len is string::msize).
    
    MyString( const char *); 
    // Copies the array of character (C-string) pointed by s.
    // The char *s is a pointer to a null-terminated sequence of characters. (all following char* are the same/)
    // The sequence is copied as the new value for the string.
    
    ~MyString(); 
    // Destroys the string object.
    
    static const size_t msize = 999;
    //Note: maximum size.
    
    MyString& append( const MyString &); 
    // Appends a str on the tail of current MyString. 
    // *Return the reference of itself
    
    MyString substr(size_t pos = 0, size_t len = msize) const;
    // The substring is the portion of the object that starts at character position pos and spans len characters 
    // (or until the end of the string, whichever comes first).
    // *Returns a newly constructed string object with its value initialized to a copy of a substring of this object.
    
    MyString& insert( size_t, const MyString &);
    // Inserts a copy of a str at "pos".
    // example: str = "to be question", str2 = "the "
    // str.insert(6,str2); 
    // = to be (the )question = to be the question
    // *Return the reference of itself
    
    MyString& insert( size_t, const MyString &, size_t, size_t);
    // Inserts a copy of a substring of str at "pos". The substring is the portion of "str" that
    // begins at the character position subpos and spans sublen characters (or until the end of str).
    // example: str = "to be the question", str3 = "or not to be"
    // str.insert(6,str3,3,4); // to be (not )the question
    // *Return the reference of itself
    
    MyString& erase( size_t, size_t); 
    // Erases the portion of the string value that begins at the character position pos and spans len characters 
    // (or until the end of the string, if either the content is too short or if len is string::msize.)
    // *Return the reference of itself
    
    size_t find( const MyString&, size_t pos = 0 ) const;
    // Searches the portion of the string value that begins at the character position "pos" until the end of the string
    // for the first occurrence of the string str.
    // Return Value: The position of the first character of the first match. If no matches were found, the function returns MyString::msize.
    
    size_t find_first_of( const MyString &, size_t pos = 0 ) const;
    // Searches the portion of the string value that begins at the character position "pos" until the end of the string
    // for the first character that matches *any* of the characters of the string str.
    // Return Value: The position of the first character that matches. If no matches are found, the function returns MyString::msize.
    
    //Add several operators
    MyString operator+ (const MyString&) const;
    MyString operator+ (const char*) const;
    MyString operator+(char); //自己加的
    // Returns a newly constructed string object with its value 
    // being the *concatenation* of the characters in lhs followed by those of rhs.
    // Note: If of type char*, it shall point to a null-terminated character sequence.
    
    MyString& operator= (const MyString&);
    MyString& operator= (const char*);
    //Assigns a new value to the string, replacing its current contents.
//private:
//    char* mystr;
//    size_t mySize = 0;
//    size_t myCapacity = 10;
}; // end class MyString
#endif /* s1042701_MyString_hpp */

