#include "globals.h"

class Gate{
	public:
		// Getters
		bool isMoving();
		bool isOpen();
		bool isClosed();

		// Setter
		void setState(bool state);

		// Commands
		void stop();
		void open();
		void close();
	private:
		bool move;
		bool state;
};