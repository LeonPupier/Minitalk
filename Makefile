# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpupier <lpupier@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/02 08:32:06 by lpupier           #+#    #+#              #
#    Updated: 2022/12/16 12:15:38 by lpupier          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Constants
NAME_SERVER		=	server
NAME_CLIENT		=	client
CFLAGS			=	-Wall -Wextra -Werror #-fsanitize=address -g3

# Directories path
DIR_SRCS		=	sources/
DIR_HEADERS		=	headers/
DIR_PRINTF		=	ft_printf/

# Files path
HEADERS			=	$(DIR_HEADERS)minitalk.h

SRCS_SERVER		=	$(DIR_SRCS)server.c \
					$(DIR_SRCS)ft_atoi.c

SRCS_CLIENT		=	$(DIR_SRCS)client.c \
					$(DIR_SRCS)ft_atoi.c

OBJS_SERVER		=	$(SRCS_SERVER:.c=.o)
OBJS_CLIENT		=	$(SRCS_CLIENT:.c=.o)

# Rules
.PHONY :		all re clean fclean printf dragon

all :			${NAME_SERVER} ${NAME_CLIENT}

%.o: %.c		$(HEADERS) Makefile
				$(CC) $(CFLAGS) -I ${HEADERS} -c $< -o $@

${NAME_CLIENT}:	printf ${OBJS_CLIENT}
				$(CC) $(CFLAGS) $(OBJS_CLIENT) $(DIR_PRINTF)libftprintf.a -o $(NAME_CLIENT)

${NAME_SERVER}:	printf ${OBJS_SERVER}
				$(CC) $(CFLAGS) $(OBJS_SERVER) $(DIR_PRINTF)libftprintf.a -o $(NAME_SERVER)

clean :
				${RM} ${OBJS_SERVER} ${OBJS_CLIENT}
				make clean -C $(DIR_PRINTF)

fclean :		clean
				${RM} ${NAME_SERVER} ${NAME_CLIENT}
				make fclean -C $(DIR_PRINTF)

re :			fclean all

printf:
				make -C $(DIR_PRINTF)

dragon:
				@echo "$$DRAGON"

# Text art
define DRAGON
																 ¶¶¶                     
															¶¶¶¶                       
														¶¶¶¶                         
													¶¶¶¶¶¶                         
												¶¶¶¶¶¶    ¶¶¶  ¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶   
							 ¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶         
								 ¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶            
										¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶    
								¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶          
							 ¶¶¶   ¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶       
						¶¶¶¶¶  ¶¶¶¶¶¶¶¶¶¶¶  ¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶      
					 ¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶ ¶¶    ¶¶¶¶¶¶¶¶¶¶¶¶¶  ¶¶¶¶¶    
			 ¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶   ¶     ¶¶¶¶¶¶¶¶¶¶¶¶¶   ¶¶¶¶   
		 ¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶         ¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶    ¶¶¶  
		¶¶¶¶¶¶¶¶                     ¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶     ¶¶ 
		 ¶¶¶¶¶                     ¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶        
			 ¶                   ¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶       
						 ¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶       
							 ¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶  ¶¶¶¶¶       
					 ¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶    ¶¶¶¶¶       
				¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶      ¶¶¶¶       
			¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶         ¶¶¶¶       
		¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶           ¶¶¶¶       
	 ¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶   ¶¶¶¶¶¶               ¶¶¶        
	¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶                            ¶¶         
 ¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶                 ¶¶                      
¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶                     ¶¶¶¶                 
¶¶¶¶¶¶¶¶¶¶ ¶¶¶                        ¶¶¶¶¶              
¶¶¶¶¶¶¶¶¶¶  ¶¶                          ¶¶¶¶¶¶¶          
¶¶¶¶¶¶¶¶¶¶¶   ¶            ¶¶¶     ¶¶¶¶   ¶¶¶¶¶¶¶        
¶¶¶¶¶¶¶¶¶¶¶¶                 ¶¶¶     ¶¶¶¶¶¶¶¶¶¶¶¶¶¶      
¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶              ¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶    
¶ ¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶         ¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶  
¶¶  ¶¶¶¶¶¶¶¶¶¶¶¶         ¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶   ¶¶¶¶¶¶¶¶¶¶¶¶ 
 ¶  ¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶           ¶¶¶¶¶¶¶¶
		¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶              ¶¶¶¶¶¶
		¶¶¶¶¶ ¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶  ¶¶¶¶¶¶¶¶              ¶¶¶¶¶
		 ¶¶¶     ¶¶¶¶¶¶¶¶¶¶¶¶¶     ¶¶¶¶¶¶¶¶¶¶              ¶¶
		¶¶¶        ¶¶¶ ¶¶¶¶¶¶¶¶¶     ¶¶¶¶¶                 ¶¶
		¶¶¶               ¶¶¶¶¶¶¶       ¶¶¶¶¶¶¶¶            ¶
		 ¶¶                   ¶¶¶¶¶                         ¶
			¶                    ¶¶¶¶                          
														¶¶¶                          
														 ¶¶                          
endef
export DRAGON