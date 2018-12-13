
//  Created by Wei-Hsuan Lien on 2018/5/17.
//  Copyright © 2018年 Wei-Hsuan Lien. All rights reserved.


#include "MyString.h"

MyString::MyString()
:CVector(){}

MyString::MyString(const MyString& copy)
{
    for (int i = 0; i < copy.getCapacity(); i++)
        (*this)[i] = copy.operator[](i);
    resize(copy.getSize());
}


MyString::MyString(const char* sttt)
{
    for (int i = 0; i < getCapacity(); i++)
        (*this)[i] = '\0';
    for (size_t i = 0; i < strlen(sttt); i++){
        resize(i+1);
        (*this)[i] = sttt[i];
    }
}

MyString::MyString(const MyString& sttt, size_t findbegin, size_t findend = msize)
:CVector()
{
    resize(findend);
    for (int i = 0; i < getCapacity(); i++)
        (*this)[i] = '\0';
    size_t j = 0;
    for (size_t i = findbegin; i < (findbegin+findend); i++){
         (*this)[j] = sttt.operator[](i);
        j++;
    }
}
    

MyString::~MyString(){}

MyString &MyString::append(const MyString& sttt){
    
    this->resize(getSize());
    if (getSize() >= (getCapacity()-1)){
        resize(getSize()+1);
    }
    
    size_t j = getSize();
    for (int i = 0; i < sttt.getSize(); i++){
         resize(j+1);
        (*this)[j] = sttt.operator[](i);
//        resize(j+1);
        j++;
    }
    return *this;
}

MyString MyString::substr(size_t cutfrom, size_t cutend) const
{
    char *temp = new char[getCapacity()];
    for (int i = 0; i < getCapacity(); i++)
        temp[i] = '\0';
    size_t j = 0;
    for (size_t i = cutfrom; i < (cutfrom+cutend); i++){
        temp[j] = (*this)[i];
        j++;
    }

    return temp;
}

MyString &MyString::insert(size_t num, const MyString& word)
{
    resize(getSize() + word.getSize());
    char *temp = new char[getCapacity()];
    for (int i = 0; i < getCapacity(); i++)
        temp[i] = '\0';
    for (int i = 0; i < getSize(); i++)
        temp[i] = (*this)[i];
    
    size_t j = num;
    for (size_t i = 0; i < word.getSize(); i++){
        (*this)[j] = word.operator[](i);
        j++;
        if (getSize() >= (getCapacity()-1)){
            resize(getSize()+1);
        }
    }
    
    for (size_t i = num; i < getSize(); i++){
        (*this)[j] = temp[i];
        j++;
    }
    
    return *this;
}

MyString &MyString::insert(size_t from, const MyString& newstr, size_t num1, size_t num2)
{
    resize(getSize() + num2);
    if (getSize() >= (getCapacity()-1))
        resize(getSize()+1);
    char *temp = new char[getCapacity()];
    for (int i = 0; i < getCapacity(); i++)
        temp[i] = '\0';
    for (int i = 0; i < getSize(); i++)
        temp[i] = (*this)[i];
    
    size_t j = from;
    for (size_t i = num1; i < (num1+num2); i++){
        (*this)[j] = newstr.operator[](i);
        j++;
        
        if (getSize() >= (getCapacity()-1)){
            resize(getSize()+1);
        }
    }
    
    for (size_t i = from; i < getSize(); i++){
        (*this)[j] = temp[i];
        j++;
    }
    return *this;
}

MyString &MyString::erase(size_t num1, size_t num2)
{
    if (getSize() >= (getCapacity()-1)){
        resize(getSize());
    }
    resize(getSize()-num2);
    size_t j = num1;
    for (size_t i = num1+num2; j < getSize(); i++){
        (*this)[j] = (*this)[i];
        j++;
    }
    return *this;
}

size_t MyString::find(const MyString& findstr, size_t num) const
{
    size_t i = 0; size_t a = 0, b = findstr.getSize();
    for (i = 0; i < getSize(); i++){
        for (size_t j = num; j < findstr.getSize(); j++){
            if ((*this)[i+j] == findstr.operator[](j)){
                a++;
                if (a == b)
                    return i;
            }
        }
        a = 0;
    }
    return msize;
}

size_t MyString::find_first_of(const MyString& findstr, size_t num) const
{
    size_t i = 0;
    for (i = 0; i < getSize(); i++){
        for (size_t j = num; j < findstr.getSize(); j++){
            if ((*this)[i] == findstr.operator[](j)){
                return i;
            }
        }
    }
    return msize;
}
//
MyString MyString::operator+(const MyString& sttt) const
{
    char *temp = new char[getCapacity()+sttt.getCapacity()];
    for(size_t i = 0; i < getCapacity()+sttt.getCapacity(); i++)
        temp[i] = '\0';
    
    for (size_t i = 0; i < getSize(); i++)
         temp[i] = (*this)[i];
    
    size_t j = getSize();
    for (size_t i = 0; i < sttt.getSize(); i++){
        temp[j] = sttt.operator[](i);
        j++;
    }
    
    return temp;
}

MyString MyString::operator+(const char* sttt) const
{
    char *temp = new char[getCapacity()+strlen(sttt)];
    for(size_t i = 0; i < getCapacity()+strlen(sttt); i++)
        temp[i] = '\0';
    for (size_t i = 0; i < getSize(); i++)
        temp[i] = (*this)[i];
    
    size_t j = getSize();
    for (size_t i = 0; i < strlen(sttt); i++){
        temp[j] = sttt[i];
        j++;
    }
    return temp;
}

MyString MyString::operator+(char word)
{
    (*this)[getSize()] = word;
    resize(getSize()+sizeof(word));
    return *this;
}

MyString operator+(const char* sttt1, const MyString& sttt2)
{
    MyString convert(sttt1);
    return (convert + sttt2);
}

MyString &MyString::operator=(const MyString& sttt)
{
    resize(sttt.getSize());
    for(int i = 0 ; i < sttt.getSize();i++){
        (*this)[i] = sttt[i];
        resize(i+1);
    }
    return *this;
}

MyString &MyString::operator=(const char* sttt)
{
    for(int i = 0 ; i < strlen(sttt);i++){
        (*this)[i] = sttt[i];
        resize(i+1);
    }
    return *this;
}

