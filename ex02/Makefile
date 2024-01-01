NAME = fixed
CC = c++
RM = rm -f
CFLAGS =  -std=c++98
SRC =  main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp
OBJ = $(SRC:%.cpp=%.o)
all : $(NAME)
$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ)  -o $(NAME)
%.o : %.cpp Bureaucrat.hpp AForm.hpp ShrubberyCreationForm.hpp RobotomyRequestForm.hpp PresidentialPardonForm.hpp
	$(CC) $(CFLAGS)  -c $< -o $@
clean :
	$(RM) $(OBJ)
fclean : clean
	$(RM) $(NAME)
re : fclean all