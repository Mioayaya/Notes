# Grid 布局

# 父元素 (容器)
```css 
.contain {
  display: grid;
  /* 可设置 最小 最大值 */
  grid-template-rows: repeat(2,50%); // 行 几行、高度  
  grid-template-columns: repeat(3, 1fr); // 列 等份
  grid-template-areas: "header header"
    "nav main"
    "footer footer";
  /* 间距 */
  row-gap: ;
  column-gap: ;
  gap: ; //简写

  justify-content: ;

}

```

# 子元素 (内容)
```css
.item {
  /* 行 列 的结束开始 */
  grid-row-start: 1;
  grid-row-end: 2;
  grid-column-start: 1;
  grid-column-end: 4;

  /* 偏移 */
  grid-xx-yy: span number;
  // 简写
  grid-row: 1/ span 1;
  grid-column: 2/ 2;

  /* 区域定位 */
  grid-area: 行/列/行/列;
  grid-area: header; // ···

  justify-self: ;
  align-self: ;

}

```