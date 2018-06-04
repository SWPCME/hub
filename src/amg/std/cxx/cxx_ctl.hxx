[+ AutoGen5 template hxx +]
[+ Include "cxx_licence.cxx" +]

#ifndef [+ file_def +]
#define [+ file_def +]

#include [+ include_base +]

class [+ lib +] [+ class_name +]
{
  public:
    [+ class_name +]();
    ~[+ class_name +]();

    UErrCodeT Init();

  protected:
  private:
    UErrCodeT InitPointer();
};

#endif  // [+ file_def +]
