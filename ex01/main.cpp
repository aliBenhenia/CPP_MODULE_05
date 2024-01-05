#include "Bureaucrat.hpp"

int main()
{
   try
   {
      Bureaucrat obj1("ali", 3);
      Bureaucrat obj2("aya", 2);
      Bureaucrat obj3("khalid", 33);
      Bureaucrat obj4("bro", 10);
      Form taxForm("test form", 10, 11);

      obj1.signForm(taxForm);
      obj2.signForm(taxForm);
      obj3.signForm(taxForm);
      obj4.signForm(taxForm);
      std::cout<<taxForm<<std::endl;
   }
   catch(const std::exception& e)
   {
      std:: cout << "Exception : " << e.what() << std :: endl;
   }
    return 0;
}
