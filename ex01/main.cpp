#include "Bureaucrat.hpp"

int main()
{
   try
   {
      Bureaucrat obj1("ali", 3);
      Bureaucrat obj2("aya", 2);
      Form taxForm("test form", 10, 11);

      obj1.signForm(taxForm);
      obj2.signForm(taxForm);
   }
   catch(const std::exception& e)
   {
      std:: cout << "Exception : " << e.what() << std :: endl;
   }
    return 0;
}
