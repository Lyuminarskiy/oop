// Товар.
struct Item
{
	virtual void applyDiscount() = 0;
	virtual void applyPromocode() = 0;

	virtual void setColor() = 0;
	virtual void setSize() = 0;
	virtual void setMaterial() = 0;

	virtual void setCondition() = 0;
	virtual void setPrice() = 0;
}