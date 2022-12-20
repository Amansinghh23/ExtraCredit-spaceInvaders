#include "point.h"

class object: public point
{
	public:
		object();
		object(int, int);
		bool isLive();
		void setLive(bool);

	private:
		bool live;
};

