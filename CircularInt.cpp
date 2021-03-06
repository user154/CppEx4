#include "CircularInt.hpp"//
// Created by Gal on 16/04/2018.
//

using namespace std;
//Constructor
CircularInt::CircularInt(int min, int max) {
    if (min >= max) {
        cout << "Left value need to be larger than right one!" << endl;
    } else {
        maxValue = max;
        minValue = min;
        CurrTime = min;
    }
}
CircularInt::CircularInt() {
    maxValue = 12;
    minValue = 1;
    CurrTime = 1;
}

CircularInt::~CircularInt() = default;

int norm(int num, int minValue, int maxValue){
    num = num % (maxValue-minValue+1);
    if(num < minValue) num += (maxValue-minValue+1);
    if(num > maxValue) num -= (maxValue-minValue+1);
    return num;
}
CircularInt& CircularInt::operator += (int const num){
    CurrTime = norm(CurrTime + num, minValue, maxValue);
    return *this;
}
CircularInt& CircularInt::operator -= (int const num){
    CurrTime = norm(CurrTime - num, minValue, maxValue);
    return *this;
}
CircularInt& CircularInt::operator++(){
    *this += 1;
    return *this;
}
const CircularInt CircularInt::operator ++ (int){
    CircularInt temp {minValue, maxValue};
    temp.CurrTime= CurrTime;
    CurrTime = norm(CurrTime + 1, minValue, maxValue);
    return temp;
}
CircularInt CircularInt::operator - (){
    CircularInt temp {minValue, maxValue};
    temp.CurrTime= CurrTime;
    temp.CurrTime -= maxValue;
    temp.CurrTime *= -1;
    return temp;
}
CircularInt operator - (int num, const CircularInt  &r){
    CircularInt temp {r.minValue, r.maxValue};
    temp.CurrTime = norm(temp.CurrTime - num-1, temp.minValue, temp.maxValue);
    return temp;
}
CircularInt operator + (const CircularInt const &r, const CircularInt  &l) {
    if(r.minValue != l.minValue || r.maxValue != l.maxValue) throw string("Cant do this!");
    else{
        CircularInt temp {r.minValue,r.maxValue};
        temp.CurrTime = norm(r.CurrTime + l.CurrTime, r.minValue, r.maxValue);
        return temp;
    }
}
CircularInt& CircularInt::operator *= (int const num){
    CurrTime = norm(CurrTime * num, minValue, maxValue);
    return *this;
}
CircularInt& CircularInt::operator /= (const CircularInt  & r){
    CurrTime /= r.CurrTime;
    CurrTime = CurrTime % maxValue;
    if(CurrTime < minValue) CurrTime+= maxValue;
    return *this;
}
CircularInt& CircularInt::operator /= (int num){
    CurrTime /= num;
    CurrTime = CurrTime % maxValue;
    if(CurrTime < minValue) CurrTime += maxValue;
    return *this;
}
CircularInt& operator / (const CircularInt  &r, int num) {
    CircularInt temp {r.minValue, r.maxValue};
    temp.CurrTime = r.CurrTime;
    if(temp.CurrTime % num == 0 ) temp /= num;
    else throw "\"There is no number x in {"+to_string(r.minValue)+","+to_string(r.maxValue)+"} such that x*"+to_string(num)+"="+to_string(r.CurrTime)+"\" ";
    return temp;
}
CircularInt &CircularInt::operator=(const CircularInt  & l) {
    CurrTime= norm(l.CurrTime,minValue,maxValue);
    return *this;
}
bool operator==(const CircularInt  & r ,const CircularInt  & l ) {
    return r.CurrTime == l.CurrTime;;
}
bool operator==(const CircularInt  & r , int const l ) {
    return r.CurrTime == l;
}
bool operator==(int const r, const CircularInt  & l) {
    return r == l.CurrTime;
}
bool operator!=(const CircularInt & r , const CircularInt & l ) {
    return !(r.CurrTime == l.CurrTime);
}
bool operator!=(int const r, CircularInt const & l) {
    return !(r == l.CurrTime);
}
bool operator!=(const CircularInt & r , int const l ) {
    return !(r.CurrTime == l);
}
CircularInt &CircularInt::operator+=(const CircularInt &r) {
    CurrTime = norm(CurrTime+r.CurrTime,minValue,maxValue);
    return *this;
}
CircularInt &CircularInt::operator-=(const CircularInt &r) {
    CurrTime = norm(CurrTime-r.CurrTime,minValue,maxValue);
    return *this;
}

CircularInt &CircularInt::operator*=(const CircularInt &r) {
    CurrTime = norm(CurrTime*r.CurrTime,minValue,maxValue);
    return *this;
}

CircularInt &CircularInt::operator--() {
    *this -= 1;
    return *this;
}

const CircularInt CircularInt::operator--(int) {
    CircularInt temp {minValue, maxValue};
    temp.CurrTime= CurrTime;
    CurrTime = norm(CurrTime - 1, minValue, maxValue);
    return temp;
}

CircularInt &CircularInt::operator=(int num) {
    return <#initializer#>;
}

//CircularInt &operator-(int num);
//CircularInt &operator-=(int num);
//CircularInt &operator+=(int num);
