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



# useRef
ref 允许组件 保存一些不用于渲染的信息，比如 DOM 节点或 timeout ID。与状态不同，更新 ref 不会重新渲染组件

# useCallback

# useMemo

# useContex