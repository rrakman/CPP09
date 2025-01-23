NAME = PmergeMe
CC = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 
RM = rm -rf
SRCS = main.cpp PmergeMe.cpp
OBJS = $(SRCS:%.cpp=%.o)

$(NAME) : $(OBJS)
	$(CC) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CC) $(CXXFLAGS) -c $< -o $@

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all re clean fclean