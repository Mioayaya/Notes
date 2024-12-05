# Question

## 1. fbx文件导入unity中没有贴图
A: 需要框选fbx文件以及 fbm贴图一起导入到unity中，若仍无贴图，点击fbx在Inspector面板中选择Materials中新增Textures和Materials文件夹

## 2. 导入资源包后着色器丢失
A: 使用unity自动升级材质，若没有效果需要手动修改渲染为当前渲染线程，比如HDR渲染下 将shader修改为 HDR/Lit,并手动贴图

## 3. 在使用blend tree时，如何避免动画状态生硬切换，比如在键盘输入时，向量从1到0之间切换
A: 使用一个targetSpeed，使用Mathf.Lerp(目标,当前,插值因子)进行过度，  
如`currentSpeed = Mathf.Lerp(targetSpeed, currentSpeed, interFactor);`

## 4. 在使用InputSystem控制角色移动时，按s角色并没有后退，反而前进，按ad角色后退
A: 在使用Translate改变角色坐标时，角色默认使用的是自己的坐标系，因此's'转身后，自己的向后是世界坐标系的前，所以会出现'向后运动'的现象，在Translate的参数中添加 以世界位置为基准即可。
`transform.Translate(Time.deltaTime * currentSpeed * playerMovement, Space.World);`