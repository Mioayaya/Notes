# Animation

## 1.角色移动

使用InputSystem控制角色动画切换  
但是角色动画播放速度与实际位移速度不相匹配，并且走路与跑步的动画如何过度，以及各种方向的运动--Blend Tree

### 1.1 Blend Tree

#### 1.1.1 1D Blend Tree
在Animator(状态机)中右键 Create State 选择 From New Blen Tree，双击进入编辑界面。 右键Blend Tree或者在Inspector界面中点击 `+` 号均可添加动画栏位，将所需要的动画切片拖入Motion中。

Parameters新建float变量Speed，将blend tree中的parameter(影响动画的参数)修改为Speed  

在Threshold中根据实际的移动速度修改阈值，比如前进的速度为2，则在前进的动画阈值里填2，其他动画同理

### 1.2 摇杆误触
在locomotion中MoveProcessors中新增一个Stick Deadzone，在 -0.125~0.125中视为0，不足1同理