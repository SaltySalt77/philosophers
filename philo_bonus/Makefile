# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyna <hyna@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/18 15:40:24 by hyna              #+#    #+#              #
#    Updated: 2022/09/29 00:17:34 by hyna             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = cc
CCFLAGS = -Wall -Werror -Wextra -g3 #-fsanitize=thread
INC_LINK = -I./incs
SRCS_DIRS = acts\
			utils\

SRCS_NAME = main_bonus.c philo_routine_bonus.c check_death_bonus.c\
			acts/take_fork_bonus.c acts/eat_spaghetti_bonus.c acts/go_asleep_bonus.c acts/think_bonus.c\
			acts/print_status_bonus.c\
			utils/init_s_info_bonus.c utils/ft_atoi_bonus.c\
			utils/free_philo_bonus.c\
			utils/ft_isdigit_bonus.c utils/init_philo_lst_bonus.c utils/get_timestamp_bonus.c\
			
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
