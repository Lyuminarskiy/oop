// Прямоугольник.
class Rectangle
{
protected:
  double width;
  double height;

public:
  virtual double getWidth() { return width; }
  virtual void setWidth(double value)
  {
    width = value;
  }

  virtual double getHeight() { return height; }
  virtual void setHeight(double value)
  {
    height = value;
  }
};

// Квадрат.
struct Square : public Rectangle
{
  virtual void setWidth(double value) override
  {
    Rectangle::setWidth(value);
    Rectangle::setHeight(value);
  }

  virtual void setHeight(double value) override
  {
    Rectangle::setHeight(value);
    Rectangle::setWidth(value);
  }
};

void calculateRectangleSquare(Rectangle* rectangle, double width, double height)
{
	rectangle->setWidth(width);
	rectangle->setHeight(height);

	return rectangle->getHeight * rectangle->getWidth;
}

int main()
{
  calculateRectangleSquare(new Rectangle(), 4, 5); // 20
  calculateRectangleSquare(new Square(), 4, 5);    // 25 (!!!)

  return 0;
}