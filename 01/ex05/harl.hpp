#ifndef HARL_H
#define HARL_H

#include <iostream>

#define MSG_DEBUG	"I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do !"
#define MSG_INFO	"I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !"
#define MSG_WARNING "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month."
#define MSG_ERROR	"This is unacceptable ! I want to speak to the manager now."

class Harl {
	public:
		Harl();
		~Harl();
		void complain (std::string level);
	private:
		static void debug (void);
		static void info (void);
		static void warning (void);
		static void error (void);
};

#endif /* HARL_H */
