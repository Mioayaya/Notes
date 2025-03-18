# Frame 

## class SingletonMono

```c#
public class SingletonMono <T> :  MonoBehaviour where T : SingletonMono<T>
{
  public static T Instance;
  protected virtual void Awake()
  {
    if(Instance == null)
    {
      Instance = (T)this;
    }
  }
}

// 正确：子类 GameManager 继承 SingletonMono<GameManager>
public class GameManager : SingletonMono<GameManager> { ... }

// 错误：泛型参数不符合约束
// 不符合单例模式的意图，会导致类型混乱和实例冲突。正确的做法是让每个单例类独立管理自己的实例
public class AudioManager : SingletonMono<GameManager> { ... }
```

## class MonoManager: SingletonMono<MonoManager>

```c#
public class MonoManager : SingletonMono<MonoManager>
{
  private Action updateAction;
  private Action lateUpdateAction;
  private Action fixedUpdateAction;

  // Func ···  
}
```
