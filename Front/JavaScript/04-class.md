# Class

```js
class Test {
  #x = 1; // 私有属性
  // 构造函数
  constructor() {

  }

  // 静态方法，不会被继承 通过类来调用 Test.StaticMethod()
  static StaticMethod() {}
  // 私有方法
  #foo() {}
  get #x { return this.#x}
  set #x(value) {this.#x = value}
}

class Child extends Test {
  constructor {
    super(); //调用父类的构造函数，必须先完成父类的继承
  }

  // 私有属性和方法不会被继承
  // 父类的静态属性和静态方法，也会被子类继承
  
}
```

- in 判断某个私有属性是否存在
- 不存在变量提升
- 