INCLUDES =	containers/Vector.hpp\
			iterators/iterator_traits.hpp\
			iterators/RandomAccessIterator.hpp\
			iterators/ReverseIterator.hpp\
			tools/tools.hpp\
			tools/type_traits.hpp

SRCS =  ft.cpp

SRCS_STL = stl.cpp

NAME = ft_containers

NAME_STL = stl_containers

CC = clang++

FLAGS = -Wall -Wextra -Werror -std=c++98

OBJS = $(SRCS:.cpp=.o)

OBJS_STL = $(SRCS_STL:.cpp=.o)

.cpp.o:
		$(CC) $(FLAGS) -c $< -o $(<:.cpp=.o)

$(NAME):	$(OBJS) $(INCLUDES)
			$(CC) -o $(NAME) $(SRCS)
			$(CC) -o $(NAME_STL) $(SRCS_STL)


all :	$(NAME)

clean :
		rm -rf $(OBJS) $(OBJS_STL)

fclean : clean
		rm -rf $(NAME) $(NAME_STL)

re :	fclean all