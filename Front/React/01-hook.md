# Hooks
不能在循环或条件语句中调用

# useState
- 使用`数组解构`来命名状态变量, 因为useState返回一个由两个值组成的数组  
set函数
- set 函数 **仅更新 下一次** 渲染的状态变量。如果在调用 set 函数后读取状态变量，则 仍会得到在调用之前显示在屏幕上的旧值。  
  可以向`Set`传递一个更新函数 解决此问题
- 避免重复初始化状态  
  ```js
  // ✅传递的是 createInitialTodos 函数本身，而不是 createInitialTodos() 调用该函数的结果。如果将函数传递给 useState，React 仅在初始化期间调用它
  function TodoList() {
  const [todos, setTodos] = useState(createInitialTodos);

  // 🚩仍然在每次渲染时调用此函数仍然在每次渲染时调用此函数
  function TodoList() {
  const [todos, setTodos] = useState(createInitialTodos());
  ```
- 使用 key 重置状态, 通过向组件传递不同的 key 来重置组件的状态

Tips:   
更新状态中的对象和数组  
官方推荐✅ React 认为 state 变化, 使用Object.is()方法比较，比较boj时，看内存中的引用地址是否相同
```js
// ✅ 使用新对象替换 state
setForm({
  ...form,
  firstName: 'Taylor'
});
```

```js
// 🚩 不要像下面这样改变一个对象：
user.age = 25; // 直接修改原对象
setUser(user); // 传递同一引用
```

# useEffect
Effect 允许组件 连接到外部系统并与之同步。这包括处理网络、浏览器、DOM、动画、使用不同 UI 库编写的小部件以及其他非 React 代码。 
- 传递参数  
  1.setup函数，用来连接到外部系统，返回一个清理函数`cleanup 代码`  
  2.依赖列表项，
- 组件挂载到页面时，先运行setup代码，依赖项更新后，使用旧的 props 和 state 运行 cleanup 代码， 然后用新的 props 和 state 运行 setup代码

# useRef
`useRef(initialValue)`

ref 允许组件 保存一些不用于渲染的信息，比如 DOM 节点或 timeout ID。与状态不同，更新 ref 不会重新渲染组件

返回一个只有一个属性的对象 `current` 初始值为传入的(initialValue),之后可设置为其他值。 如果将一个JSX节点的ref属性传入，则React将它设置 current属性

- 改变 ref.current 属性时，React 不会重新渲染组件
- 不要在渲染期间写入或者读取 ref.current

# useCallback
`useCallback(fn, dependencies)` 多次渲染中缓存函数  
fn: 缓存函数，React不会调用此函数，而是返回此函数  
dependencies： []  React 使用 Object.is 比较每一个依赖和它的之前的值  
- 子组件使用 memo 包裹，如果props相同，则跳过渲染
- 通常情况下只能 事件处理程序或者 Effect 中读取和写入 ref ，除非是可预测的
- 通过 ref 操作 DOM
- 避免重复创建 ref 的内容

# useMemo
传递参数:   
1.一个没有任何参数的 calculation 函数，像这样 () =>，并且返回任何你想要的计算结果。  
2.一个由包含在你的组件中并在 calculation 中使用的所有值组成的 依赖列表。

- 跳过代价昂贵的重新计算
- 跳过组件的重新渲染
- 防止过于频繁地触发 Effect
- 记忆另一个 Hook 的依赖
- 记忆一个函数

Tips: 
返回对象时使用 return {}, 避免遗忘 ({}) 

# useContex
跨组件通信

# useReducer
管理复杂状态逻辑的 Hook