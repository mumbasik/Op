

#include <iostream>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
class Drob {
    int chesl;
    int znam;
    

public:
    Drob() {
        chesl = 0;
        znam = 0;
    }
    Drob(int x, int y) {
        chesl = x;
        znam = y;
    }
    void Ssumma(Drob sum) {

        cout << "First drob: ";
        cout << chesl + sum.chesl << endl;

        cout << "Second drob: ";
        cout << znam + sum.znam << endl;
    }
    void Summof2dorbs(Drob sum) {

        cout << "Summ of 2 drobs: ";
        cout << chesl * sum.znam + sum.chesl * znam << endl; 
        cout << "/: " << znam * sum.znam << endl;
    }
    void Minus(Drob minus) {

        cout << "Minus first drob: ";
        cout << chesl - minus.chesl << endl;

        cout << "Minus second drob: ";
        cout << znam - minus.znam << endl;
    }
    void MinusOf2drobs(Drob minus) {

        cout << "Minus of 2 drobs: ";
        cout << chesl * minus.znam - minus.chesl * znam << endl; 
        cout << "/: " << znam * minus.znam << endl;
    }
    void multiplication(Drob mult) {

        cout << "multiplication first drob: ";
        cout << chesl * mult.chesl << endl;
        cout << "multiplication second drob: ";
        cout << znam * mult.znam << endl;

    }

    void delen(Drob del) {
        if (del.chesl == 0) {
            cout << "Imossible if chesl = 0 " << endl;
            return;
        }
        cout << "first drob " << chesl * del.znam << endl;
        cout << "Second drob " << znam * del.chesl << endl;
    }
    Drob operator*(const Drob& other) {
        Drob temp;
        temp.chesl = this->chesl * other.chesl;
        temp.znam = this->znam * other.znam;
        return temp;
    }
    
    Drob operator*(int value) {
        Drob temp;
        temp.znam = this->znam * value;
        temp.chesl = this->chesl * value;
        return temp;
    }
    
    void OutPut() {
        cout << "Chesl: " << chesl << endl;
        cout << "Znam: " << znam << endl;
    }
  
    friend Drob operator*(int y, const Drob& x);
};
 Drob operator*(int y, const Drob& x) {
     Drob temp;
     temp.chesl = y * x.chesl;
     temp.znam = y * x.znam;
     return temp;
 }
 class MyString {
     char* st;
     static int amount;
     int size;

 public:
     MyString() {
         st = new char[80]();
         amount++;
     }

     MyString(int size) {
         this->size = size;
         st = new char[this->size + 1];
         amount++;
     }

     void String(const char* ad) {

         st = new char[strlen(ad) + 1];
         strcpy_s(st, strlen(ad) + 1, ad);
     }
     MyString(const MyString& obj) {
         st = new char[strlen(obj.st) + 1];
         strcpy_s(st, strlen(obj.st) + 1, obj.st);
     }
     
   
   
     static int GetAmount() {
         return amount;
     }

     void Prin() const {
         cout << "String: " << st << endl;
         cout << "Amount: " << amount << endl;
     }

     ~MyString() {
         delete[] st;
         amount--;
     }
     friend MyString operator+(int x, const MyString& obj);
 };
 MyString operator+(int x, const MyString& obj) {
     MyString result(obj);
     char* temp = new char[x + 1];
     for (int i = 0; i < x; i++) {
         temp[i] = 'x';
     }
     temp[x] = '\0';
     char* last = new char[strlen(obj.st) + x + 1];
     strcpy_s(last, strlen(obj.st) + x + 1, temp);
     strcat_s(last, strlen(obj.st) + x + 1,  obj.st);
     delete[] temp;
     result.st = last;
     return result;

 }
 int MyString::amount = 0;
void main() {
    //N1
    Drob obj(1, 8);
    Drob obj2(4, 9);
   /* obj.Ssumma(obj2);
    obj.Summof2dorbs(obj2);
    obj.Minus(obj2);
    obj.MinusOf2drobs(obj2);
    obj.multiplication(obj2);

    obj.delen(obj2);*/
    Drob obj3 = obj * obj2;
    obj3.OutPut();
    
    
    
   
    Drob obj6 = 5 * obj;
    obj6.OutPut();
    Drob obj7 = obj * 5;
    obj7.OutPut();
    //N2
    MyString q;
    MyString q2(100);
    MyString q3;
    q3.String("Andrey");

    q3.GetAmount();

    q3.Prin();
    MyString b = q3;
    b.Prin();
    MyString sum = 4 + q3;
    sum.Prin();
}