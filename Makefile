NAME 	= ft_containers

CXX = clang++

CPPFLAGS 	= -Wall -Wextra -Werror -std=c++98 #-g #-fsanitize=address

CONTAINERS	= ./


CONTAINERS_HEADERS = $(CONTAINERS)ft_vector.hpp $(CONTAINERS)ft_map.hpp $(CONTAINERS)ft_stack.hpp $(CONTAINERS)ft_set.hpp \
$(CONTAINERS)ft_redblacktree.hpp $(CONTAINERS)ft_reverse_iterator.hpp $(CONTAINERS)ft_tree_iterator.hpp \
$(CONTAINERS)ft_utility.hpp $(CONTAINERS)ft_vector_iterator.hpp

FILES 	= main.cpp   #debug_isIntegral.cpp debugIterTraits.cpp

OBJS 	= $(FILES:.cpp=.o)

all: $(NAME)

.cpp.o: $(CONTAINERS_HEADERS) 
	$(CXX) $(CPPFLAGS) -I$(CONTAINERS) -c $< -o $(<:.cpp=.o)

$(NAME): $(OBJS) $(CONTAINERS_HEADERS) 
	$(CXX) $(CPPFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re