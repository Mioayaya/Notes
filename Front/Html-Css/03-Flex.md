# Flex 布局

# 父元素(容器)

```css
.parent {
  display: flex;  // 转行为块
  display: inline-flex;  // 行内块
  flex-direction: row | column | row-reverse | column-reverse;  // 水平 垂直 反转
  flex-wrap: wrap; // 溢出换行
  flex-flow: row wrap; // 同时设置
  /* 主轴和 flex-direction 一致，副轴为与之垂直 */
  justify-content: flex-start; // 主轴开始的地方

  /* 交叉轴元素对齐 */
  align-items: center;

  /* 多行的交叉轴 */
  align-content: center;
}

```
`justifi-content` 属性
- flex-start	元素向主轴起点对齐（默认值）	[左对齐]
- flex-end	元素向主轴终点对齐	[右对齐]
- center	元素居中对齐	[居中]
- space-between	元素均匀分布，首元素在起点，末元素在终点	[两端分散]
- space-around	元素均匀分布，每个元素两侧有相等空间	[环绕等距]
- space-evenly	元素均匀分布，元素间间隔与容器边缘间隔相等	[完全均匀]

`align-items` 属性
- stretch	默认值，元素拉伸填满容器高度（需未设置固定高度）	[垂直拉伸]
- flex-start	元素向交叉轴起点对齐	[顶部对齐]
- flex-end	元素向交叉轴终点对齐	[底部对齐]
- center	元素在交叉轴居中对齐	[垂直居中]
- baseline	元素按文本基线对齐	[基线对齐]

`align-content` 属性
- stretch	默认值，行拉伸平分剩余空间	[行等高拉伸]
- flex-start	行向交叉轴起点紧凑排列	[顶部集中]
- flex-end	行向交叉轴终点紧凑排列	[底部集中]
- center	行在交叉轴居中紧凑排列	[垂直居中]
- space-between	首行在起点，末行在终点，中间行等距分布	[两端分散]
- space-around	所有行等距分布，首末行有半间距	[均匀环绕]
- space-evenly	所有行（包含首末行）等距分布	[完全均匀]

# 子元素

```css
.child {
  /* 显示顺序控制 */
  order: number; // 默认，越小越考前
  /* 单个元素的交叉轴控制 */
  align-self: center;

  flex-grow: 1;  // 扩展比例 0 默认  number 比例
  flex-shrink: 0; // 缩小比例 0不缩小 number 比例 (空间不够下)
  flex-basis: 20px; // 基准尺寸，默认auto 优先级高于width
  flex: [grow] [shrink] [basis]; // 简写 1：1 1 0%

}
```