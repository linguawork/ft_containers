NAME 	= ft_containers

CXX = clang++

CPPFLAGS 	= -Wall -Wextra -Werror -std=c++98 #-g #-fsanitize=address

CONTAINERS	= ./

# UTILS		= containers/additional/

# TESTS		= tests/

CONTAINERS_HEADERS = $(CONTAINERS)ft_vector.hpp $(CONTAINERS)ft_map.hpp $(CONTAINERS)ft_stack.hpp $(CONTAINERS)ft_set.hpp \
$(CONTAINERS)ft_redblacktree.hpp $(CONTAINERS)ft_reverse_iterator.hpp $(CONTAINERS)ft_tree_iterator.hpp \
$(CONTAINERS)ft_utility.hpp $(CONTAINERS)ft_vector_iterator.hpp

# UTILS_HEADERS = $(UTILS)algorithm.hpp $(UTILS)iterator_traits.hpp $(UTILS)reverse_iterator.hpp $(UTILS)vector_iterator.hpp \
# 				$(UTILS)binary_search_tree.hpp

# TESTS_HEADERS = $(TESTS)tests.hpp $(TESTS)test_vector.hpp $(TESTS)test_stack.hpp $(TESTS)test_map.hpp

FILES 	=  debugIterTraits.cpp #debug_isIntegral.cpp main.cpp 

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