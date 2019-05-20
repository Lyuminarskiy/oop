#define ISP
// The Interface Segregation Principle - принцип разделения интерфейса.

using System;

namespace SOLID.ISP
{
#if ISP
  #region With ISP
  /// <summary>
  /// Компьютер.
  /// </summary>
  public interface IComputer
  {
    /// <summary>
    /// Включить компьютер.
    /// </summary>
    void TurnOn();

    /// <summary>
    /// Выключить компьютер.
    /// </summary>
    void TurnOff();
  }

  /// <summary>
  /// Ноутбук.
  /// </summary>
  public interface ILaptop : IComputer
  {
    /// <summary>
    /// Уровень заряда батареи.
    /// </summary>
    double BatteryLevel { get; }

    /// <summary>
    /// Включить веб-камеру.
    /// </summary>
    void TurnOnWebcam();

    /// <summary>
    /// Выключить веб-камеру.
    /// </summary>
    void TurnOfWebcam();
  }

  /// <summary>
  /// Персональный компьютер.
  /// </summary>
  public class Pc : IComputer
  {
    /// <summary>
    /// Включить компьютер.
    /// </summary>
    public void TurnOn() => Console.WriteLine("Компьютер включен");
    
    /// <summary>
    /// Выключить компьютер.
    /// </summary>
    public void TurnOff() => Console.WriteLine("Компьютер выключен");
  }

  /// <summary>
  /// Ноутбук.
  /// </summary>
  public class Laptop : IComputer
  {
    /// <summary>
    /// Уровень заряда батареи.
    /// </summary>
    public double BatteryLevel => new Random().Next(0, 100);

    /// <summary>
    /// Включить компьютер.
    /// </summary>
    public void TurnOn() => Console.WriteLine("Компьютер включен");
    
    /// <summary>
    /// Выключить компьютер.
    /// </summary>
    public void TurnOff() => Console.WriteLine("Компьютер выключен");
    
    /// <summary>
    /// Включить веб-камеру.
    /// </summary>
    public void TurnOnWebcam() => Console.WriteLine("Веб-камера включена");

    /// <summary>
    /// Выключить веб-камеру.
    /// </summary>
    public void TurnOfWebcam() => Console.WriteLine("Веб-камера выключена");
  }
  #endregion
#else
  #region Without ISP
  /// <summary>
  /// Компьютер.
  /// </summary>
  public interface IComputer
  {
    /// <summary>
    /// Уровень заряда батареи.
    /// </summary>
    double BatteryLevel { get; }

    /// <summary>
    /// Включить компьютер.
    /// </summary>
    void TurnOn();

    /// <summary>
    /// Выключить компьютер.
    /// </summary>
    void TurnOff();

    /// <summary>
    /// Включить веб-камеру.
    /// </summary>
    void TurnOnWebcam();

    /// <summary>
    /// Выключить веб-камеру.
    /// </summary>
    void TurnOfWebcam();
  }

  /// <summary>
  /// Персональный компьютер.
  /// </summary>
  public class Pc : IComputer
  {
    /// <summary>
    /// Уровень заряда батареи.
    /// </summary>
    public double BatteryLevel => throw new NotImplementedException();
  
    /// <summary>
    /// Включить компьютер.
    /// </summary>
    public void TurnOn() => Console.WriteLine("Компьютер включен");
  
    /// <summary>
    /// Выключить компьютер.
    /// </summary>
    public void TurnOff() => Console.WriteLine("Компьютер выключен");
  
    /// <summary>
    /// Включить веб-камеру.
    /// </summary>
    public void TurnOnWebcam() => throw new NotImplementedException();
  
    /// <summary>
    /// Выключить веб-камеру.
    /// </summary>
    public void TurnOfWebcam() => throw new NotImplementedException();
  }

  /// <summary>
  /// Ноутбук.
  /// </summary>
  public class Laptop : IComputer
  {
    /// <summary>
    /// Уровень заряда батареи.
    /// </summary>
    public double BatteryLevel => new Random().Next(0, 100);

    /// <summary>
    /// Включить компьютер.
    /// </summary>
    public void TurnOn() => Console.WriteLine("Компьютер включен");
    
    /// <summary>
    /// Выключить компьютер.
    /// </summary>
    public void TurnOff() => Console.WriteLine("Компьютер выключен");
    
    /// <summary>
    /// Включить веб-камеру.
    /// </summary>
    public void TurnOnWebcam() => Console.WriteLine("Веб-камера включена");

    /// <summary>
    /// Выключить веб-камеру.
    /// </summary>
    public void TurnOfWebcam() => Console.WriteLine("Веб-камера выключена");
  }
  #endregion
#endif
}