#ifndef DUMMY_HPP
#define DUMMY_HPP

#include"ATarget.hpp"

class Dummy : public ATarget
{
	public:
		Dummy(void);
		virtual ~Dummy(void);
		virtual	ATarget *clone(void) const;
};

#endif
