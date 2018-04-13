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
class Square
{
protected:
  double size;

public:
  virtual double getSize() { return size; }
  virtual void setSize(double value)
  {
    size = value;
  }
};
