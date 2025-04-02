# Promise

状态: pending(进行中)、fulfilled(已成功)、rejected(已失败)

# Promise.all()
方法接受一个数组作为参数 如果不是 先调用 Promise.resolve  
只有Promise实例都成功了，或者有一个变为 rejected 才会调用promise.all后面的回调函数

# Promise.race()
同样是将多个 Promise 实例 作为数组  
只要有一个实例率先改变状态，p的状态就跟着改变，取决于率先改变的状态

# Promise.allSettled()   
确定一组异步操作是否都结束了（不管成功或失败）

# Promise.any()  
只要参数实例有一个变成fulfilled状态，包装实例就会变成fulfilled状态；如果所有参数实例都变成rejected状态，包装实例就会变成rejected状态  
要等到所有实例变成 rejected 状态

