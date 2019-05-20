#define LSP
// The Liskov Substitution Principle - принцип подстановки Барбары Лисков

using System;

namespace SOLID.LSP
{
#if LSP
  #region With LSP
  /// <summary>
  /// Автомобиль.
  /// </summary>
  public class Car
  {
    /// <summary>
    /// Скорость автомобиля.
    /// </summary>
    public double Speed { get; private set; }

    /// <summary>
    /// Максимально допустимая скорость автомобиля.
    /// </summary>
    public double SpeedLimit { get; private set; }


    /// <summary>
    /// Создаёт экземпляр класса <see cref="Car"/>.
    /// </summary>
    /// <param name="initialSpeed"></param>
    public Car(double initialSpeed, double speedLimit)
    {
      Speed = initialSpeed;
      SpeedLimit = speedLimit;
    }

    /// <summary>
    /// Изменяет скорость автомобиля.
    /// </summary>
    /// <param name="diff">Разница скорости.</param>
    public virtual void Accelerate(double diff)
    {
      Speed += diff;

      if (Speed >= SpeedLimit)
        throw new Exception();
    }
  }
  #endregion
#else
  #region Without LSP
  /// <summary>
  /// Автомобиль.
  /// </summary>
  public class Car
  {
    /// <summary>
    /// Скорость автомобиля.
    /// </summary>
    public double Speed { get; private set; }

    /// <summary>
    /// Создаёт экземпляр класса <see cref="Car"/>.
    /// </summary>
    /// <param name="initialSpeed"></param>
    public Car(double initialSpeed) => Speed = initialSpeed;

    /// <summary>
    /// Изменяет скорость автомобиля.
    /// </summary>
    /// <param name="diff">Разница скорости.</param>
    public virtual void Accelerate(double diff) => Speed += diff;
  }

  /// <summary>
  /// Сломанный автомобиль.
  /// </summary>
  public class BrokenCar : Car
  {
    /// <summary>
    /// Максимально допустимая скорость автомобиля.
    /// </summary>
    private const double SpeedLimit = 200;

    /// <summary>
    /// Создаёт экземпляр класса <see cref="BrokenCar"/>.
    /// </summary>
    /// <param name="initialSpeed"></param>
    public BrokenCar(double initialSpeed) : base(initialSpeed) { }

    /// <summary>
    /// Изменяет скорость автомобиля.
    /// </summary>
    /// <param name="diff">Разница скорости.</param>
    public override void Accelerate(double diff)
    {
      base.Accelerate(diff);

      if (Speed >= SpeedLimit)
        throw new Exception();
    }
  }
  #endregion
#endif
}