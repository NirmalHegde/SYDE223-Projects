#include <iostream>

// MyClass is used to store three private values
// an integer (should have default value 1)
// a double (should have default value 1.0)
// a boolean (should have default value true)
// all functions should be implemented properly following their descriptions in the comments below
// below is the implementation of MyClass (but it has many errors and bugs)
// can you correct the errors and make it pass all the test cases?
// you can only modify MyClass. Do not change AutoGrading or the main function.

class MyClass {
    int myIntValue;
    double myDoubleValue;
    bool myBoolValue;

    public:
        MyClass () {
            myIntValue = 1;
            myDoubleValue = 1.0;
            myBoolValue = true;
        }

        void setInt (int x){         //this function gives myIntValue a new value
            myIntValue = x;
        }

        int doIntPlusOne (){    //this function returns the value of myIntValue plus 1, without changing myIntValue
            int returnValue = myIntValue;
            return ++returnValue;
        }

        double doDoublePlusOnePointOne (){     //this function return the value of myDoubleValue plus 1.1, without changing myDoubleValue
            double returnValue = myDoubleValue;
            return returnValue += 1.1;
        }

        void setDouble (double x){      //this function gives myDoubleValue a new value
            myDoubleValue = x;
        }

        bool getBool(){        //return myBoolValue
            return myBoolValue;
        }

        double getDouble(){     //return myDoubleValue
            return myDoubleValue;
        }

        int getInt (){      //return myIntValue
            return myIntValue;
        }

        void setBool (bool x){        //this function gives myBoolValue a new value
            myBoolValue = x;
        }

        bool doBoolNot(){       //this function return the opposite (NOT) value of myBoolValue, i.e., true to false, false to true, without changing myBoolValu
            return !myBoolValue;
        }
};




#define ASSERT_TRUE(T) if (!(T)) return false;
#define ASSERT_FALSE(T) if ((T)) return false;

class AutoGrading{
public:
    bool test1()    //the integer should have default value 1
    {
        MyClass obj;
        ASSERT_TRUE(obj.getInt() == 1)
        return true;
    }

    static bool test2()    //the double should have default value 1.0
    {
        MyClass obj;
        ASSERT_TRUE(obj.getDouble() == 1.0)
        return true;
    }

    bool test3()    //the boolean should have default value true
    {
        MyClass obj;
        ASSERT_TRUE(obj.getBool())
        return true;
    }

    bool test4()    //test doIntPlusOne
    {
        MyClass obj;
        obj.setInt(5);
        ASSERT_TRUE(obj.doIntPlusOne() == 6)
        ASSERT_TRUE(obj.doIntPlusOne() == 6)
        ASSERT_TRUE(obj.doIntPlusOne() == 6)
        return true;
    }

    bool test5()    //test doDoublePlusOnePointOne
    {
        MyClass obj;
        obj.setDouble(2);
        ASSERT_TRUE(obj.doDoublePlusOnePointOne()== 3.1)
        ASSERT_TRUE(obj.doDoublePlusOnePointOne()== 3.1)

        obj.setDouble(100.001);
        ASSERT_TRUE(obj.doDoublePlusOnePointOne()== 101.101)
        ASSERT_TRUE(obj.doDoublePlusOnePointOne()== 101.101)
        return true;
    }

    bool test6()    //test doBoolNot
    {
        MyClass obj;
        obj.setBool(true);
        ASSERT_TRUE(obj.doBoolNot() == false)
        ASSERT_TRUE(obj.doBoolNot() == false)

        obj.setBool(false);
        ASSERT_TRUE(obj.doBoolNot() == true)
        ASSERT_TRUE(obj.doBoolNot() == true)
        return true;
    }



};


std::string get_status_str(bool status)
{
    return status ? "PASSED" : "FAILED";
}



int main() {
    std::cout << "Testing start." << std::endl;  	
    AutoGrading grading;
    std::cout << "Test 1: " <<  get_status_str( grading.test1() ) << std::endl;
    std::cout << "Test 2: " <<  get_status_str( grading.test2() ) << std::endl;
    std::cout << "Test 3: " <<  get_status_str( grading.test3() ) << std::endl;
    std::cout << "Test 4: " <<  get_status_str( grading.test4() ) << std::endl;
    std::cout << "Test 5: " <<  get_status_str( grading.test5() ) << std::endl;
    std::cout << "Test 6: " <<  get_status_str( grading.test6() ) << std::endl;
    return 0;
}
