#include "Bureaucrat.hpp"

int main()
{
   try
   {
      Bureaucrat obj1("ali", 100);
      Bureaucrat obj2("aya", 2);
      Bureaucrat obj3("khalid", 33);
      Bureaucrat obj4("bro", 10);
      Bureaucrat obj5("emrah", 111);
      Form taxForm("my_tax_form", 100, 11);

      obj1.signForm(taxForm);
      obj2.signForm(taxForm);
      obj3.signForm(taxForm);
      obj4.signForm(taxForm);
      obj5.signForm(taxForm);
      std::cout<<taxForm<<std::endl;
   }
   catch(const std::exception& e)
   {
      std:: cout << "Exception : " << e.what() << std :: endl;
   }
    return 0;
}
