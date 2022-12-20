class point {
	public:
		point();
		point(int, int);
		void moveLeft();
		void moveRight();
		void moveUp();
		void moveDown();
		int getX();
		int getY();
		void setX(int);
		void setY(int);

	private:
		int posX;
		int posY;
};
