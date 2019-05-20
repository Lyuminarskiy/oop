#define OCP
// The Open Closed Principle - принцип открытости/закрытости

namespace SOLID.OCP
{
#if OCP
  #region With OCP
  /// <summary>
  /// Дисконтная карта.
  /// </summary>
  public abstract class DiscountCard
  {
    /// <summary>
    /// Размер скидки.
    /// </summary>
    private double Discount { get; }

    /// <summary>
    /// Создаёт экземпляр объекта <see cref="DiscountCard"/>.
    /// </summary>
    /// <param name="discount">Размер скидки.</param>
    protected DiscountCard(double discount) => Discount = discount;

    /// <summary>
    /// Применяет скидку к указанной цене.
    /// </summary>
    /// <param name="price">Цена.</param>
    /// <returns>Цена со скидкой.</returns>
    public double GetDiscount(double price) => price * (1 - Discount);
  }

  /// <summary>
  /// Серебряная дисконтная карта.
  /// </summary>
  public class SilverDiscountCard : DiscountCard
  {
    /// <summary>
    /// Размер скидки серебряной дисконтной карты.
    /// </summary>
    private const double SilverCardDiscount = 0.05;

    /// <summary>
    /// Создаёт экземпляр объекта <see cref="SilverDiscountCard"/>.
    /// </summary>
    /// <param name="discount">Размер скидки.</param>
    public SilverDiscountCard() : base(SilverCardDiscount) { }
  }

  /// <summary>
  /// Золотая дисконтная карта.
  /// </summary>
  public class GoldDiscountCard : DiscountCard
  {
    /// <summary>
    /// Размер скидки золотой дисконтной карты.
    /// </summary>
    private const double GoldCardDiscount = 0.10;

    /// <summary>
    /// Создаёт экземпляр объекта <see cref="GoldDiscountCard"/>.
    /// </summary>
    /// <param name="discount">Размер скидки.</param>
    public GoldDiscountCard() : base(GoldCardDiscount) { }
  }

  /// <summary>
  /// Платиновая дисконтная карта.
  /// </summary>
  public class PlatinumDiscountCard : DiscountCard
  {
    /// <summary>
    /// Размер скидки платиновой дисконтной карты.
    /// </summary>
    private const double PlatinumCardDiscount = 0.20;

    /// <summary>
    /// Создаёт экземпляр объекта <see cref="GoldDiscountCard"/>.
    /// </summary>
    /// <param name="discount">Размер скидки.</param>
    public PlatinumDiscountCard() : base(PlatinumCardDiscount) { }
  }
  #endregion
#else
  #region Without OCP
  /// <summary>
  /// Дисконтная карта.
  /// </summary>
  public class DiscountCard
  {
    /// <summary>
    /// Типы дисконтных карт.
    /// </summary>
    public enum Type
    {
      /// <summary>
      /// Серебряная карта.
      /// </summary>
      Silver,
      /// <summary>
      /// Золотая карта.
      /// </summary>
      Gold,
      /// <summary>
      /// Платиновая карта.
      /// </summary>
      Platinum
    }

    /// <summary>
    /// Тип дисконтной карты.
    /// </summary>
    private Type _type;

    /// <summary>
    /// Создаёт экземпляр объекта <see cref="DiscountCard"/>.
    /// </summary>
    /// <param name="type">Тип дисконтной карты.</param>
    public DiscountCard(Type type = Type.Silver) => _type = type;

    /// <summary>
    /// Применяет скидку к указанной цене.
    /// </summary>
    /// <param name="price">Цена.</param>
    /// <returns>Цена со скидкой.</returns>
    public double GetDiscount(double price) =>
      _type switch
      {
        Type.Silver => price * 0.95,
        Type.Gold => price * 0.90,
        Type.Platinum => price * 0.80,
        _ => price
      };
  }
  #endregion
#endif
}