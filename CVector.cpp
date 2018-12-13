
//  Created by Wei-Hsuan Lien on 2018/5/17.
//  Copyright © 2018年 Wei-Hsuan Lien. All rights reserved.


#include "CVector.h"

ostream& operator<<(ostream& output, const CVector& sttt)
{
    for (int i = 0; i < sttt.Size; i++){
        output << sttt[i];
    }
    return output;
}

CVector::CVector()
{
    Capacity = 10;
    Size = 0;
    str = new char [Capacity];
    for (size_t i = 0; i < Capacity; i++)
        str[i] = '\0';
}

CVector::CVector(const CVector& copy)
{
    str = new char [copy.Capacity];
    for (size_t i = 0; i < copy.Capacity; i++)
        str[i] = '\0';
    for (int i = 0; i < copy.Size; i++)
        str[i] = copy.str[i];
    
    Size = copy.Size;
    Capacity = copy.Capacity;
}

CVector::~CVector()
{
    delete[] str;
}

size_t CVector::getSize() const
{
    return Size;
}

void CVector::resize(size_t reSize, char word)
{
    if (reSize >= Capacity-1){
        while (Size >= Capacity-1){
            Capacity *= 10;
            if (Capacity < reSize)
                Capacity = reSize;
            char *temp = new char [Capacity];
            for (int i = 0; i < Size; i++)
                temp[i] = str[i];
            char *move = new char [Capacity];
            for (int i = 0; i < Size; i++)
                move[i] = temp[i];
            
            delete [] str;
            delete [] temp;
            str = new char[Capacity];
            for (int i = 0; i < Capacity; i++)
                str[i] = word;
            for (int i = 0; i < Size; i++)
                str[i] = move[i];            
            
            delete [] move;
        }
         Size = reSize;
    }
    else{
        Size = reSize;
    }
}

size_t CVector::getCapacity() const
{
    return Capacity;
}

void CVector::reserve(size_t newCapacity)
{
    Capacity = newCapacity;
    CVector temp;
    for (int i = 0; i < Capacity; i++)
        temp.str[i] = str[i];
    delete[] str;
    str = new char[Capacity];
    for (int i = 0; i < Capacity; i++)
        str[i] = '\0';
    for (int i = 0; i < Capacity; i++)
        str[i] = temp.str[i];
}

void CVector::shrink_to_fit()
{
    Capacity = Size;
    CVector temp;
    for (int i = 0; i < Capacity; i++)
        temp.str[i] = str[i];
    delete[] str;
    str = new char[Capacity];
    for (int i = 0; i < Capacity; i++)
        str[i] = '\0';
    for (int i = 0; i < Capacity; i++)
        str[i] = temp.str[i];
}

void CVector::clear()
{
    delete[] str;
    str = new char [Capacity];
    for (size_t i = 0; i < Capacity; i++)
        str[i] = '\0';
    Size = 0;
}

bool CVector::empty() const
{
    if (Size == 0)
        return 1;
    else 
        return 0;
}

char &CVector::front()
{
    return str[0];
}

char &CVector::back()
{
    return str[Size-1];
}

void CVector::push_back(char push)
{
    if (Size >= Capacity-1)
        resize(Size);
    
    for (size_t i = Size; i < (Size+1); i++){
        str[i] = push;
    }
    Size++;
}

void CVector::pop_back()
{
    char *tempstr = new char [Capacity];
    for (size_t i = 0; i < Capacity; i++)
        tempstr[i] = '\0';
    
    for (size_t i = 0; i < Size-1; i++)
        tempstr[i] = str[i];
    
    delete []str;
    Size--;
    resize(Size);
    str = new char [Capacity];
    for (size_t i = 0; i < Capacity; i++)
        str[i] = '\0';
    for (size_t i = 0; i < Size; i++){
        str[i] = tempstr[i];
    }
}

char& CVector::operator[] (size_t num)
{
    return str[num];
}

char CVector::operator[](size_t num) const
{
    return str[num];
}

bool CVector::operator==(const CVector& findstr) const
{
    size_t i = 0;
    int a = 0, b = 0;
    if (Size == findstr.Size){
        for (i = 0; i < Size; i++){
            a++;
            if (str[i] == findstr.str[i]){
                b++;
                if (a == b)
                    return 1;
            }
        }
    }
    else
        return 0;
    
    return 0;
}

bool CVector::operator!=(const CVector& findstr) const
{
    size_t i = 0;
    int a = 0, b = 0;
    if (Size != findstr.Size)
        return 1;
    
    else if (Size == findstr.Size){
        for (i = 0; i < Size; i++){
            a++;
            if (str[i] != findstr.str[i])
                return 1;
            else{
                b++;
                if (a == b)
                    return 0;
            }
        }
    }
    return 0;
}


