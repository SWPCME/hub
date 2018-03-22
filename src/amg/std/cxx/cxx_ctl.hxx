[+ AutoGen5 template hxx +]
[+ Include "cxx_licence.cxx" +]

#ifndef [+ file_def +]
#define [+ file_def +]

class [+ lib +] [+ class_name +]
{
  public:
    [+ class_name +]();
    ~[+ class_name +]();

    UErrCodeT Init();

  protected:
  private:
};
[+ (out-push-new "cxx_ctl.cxx") +]
[+ Include "tpl/cxx/cxx_ctl.cxx" +]
[+ (out-pop) +]
#endif  // [+ file_def +]
