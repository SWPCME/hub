%module "JniTest"
%{
#include "jni_test.hpp"
%}

%pragma(java) jniclasscode=%{
     private static boolean available = false;

     static {
         try {
             System.loadLibrary("whub");
             available = true;
         } catch (UnsatisfiedLinkError e) {
             available = false;
             System.err.println("Native library load failed.");
             System.err.println(e);
         }
     }

     public static boolean isAvailable() {
         return available;
     }
%}

class CTestJni
{
public:
    CTestJni();
    ~CTestJni();

    int Test();
};
