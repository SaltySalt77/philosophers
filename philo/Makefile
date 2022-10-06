# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyna <hyna@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/18 15:40:24 by hyna              #+#    #+#              #
#    Updated: 2022/09/25 18:07:24 by hyna             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = cc
CCFLAGS = -Wall -Werror -Wextra
INC_LINK = -I./incs
SRCS_DIRS = acts\
			utils\

SRCS_NAME = main.c philo_routine.c check_death.c check_eaten_time.c\
			acts/take_fork.c acts/eat_spaghetti.c acts/go_asleep.c acts/think.c\
			acts/print_status.c\
			utils/init_s_info.c utils/ft_atoi.c\
			utils/free_philo.c\
			utils/ft_isdigit.c utils/init_philo_lst.c utils/get_timestamp.c\
			
SRCS_PATH = ./srcs
SRCS = $(addprefix $(SRCS_PATH)/, $(SRCS_NAME))

OBJS_NAME = $(SRCS_NAME:.c=.o)
OBJS_PATH = ./objs
OBJS = $(addprefix $(OBJS_PATH)/, $(OBJS_NAME))
DIRS = $(addprefix $(OBJS_PATH)/, $(SRCS_DIRS))

all : $(NAME)

$(NAME) : $(DIRS) $(OBJS) 
	$(CC) $(CCFLAGS) -o $(NAME) $(OBJS)

$(DIRS) :
	@mkdir $(OBJS_PATH) 2> /dev/null || true
	@mkdir $(DIRS) 2> /dev/null || true

$(OBJS_PATH)/%.o : $(SRCS_PATH)/%.c
	$(CC) $(INC_LINK) $(CCFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJS_PATH)

fclean : clean
	rm -rf $(NAME)
re :
	$(MAKE) fclean
	$(MAKE) all


.PHONY: all clean fclean bonus
