# 浮动
float:  
浮动只对后面的元素影响、且父元素感受不到(不会被撑开)，但是受padding影响  

对行级元素使用float会变成块级元素  

# 清除浮动
- 被影响的元素 `clear: lleft/right/both`
- 清除父元素的浮动:  
  添加一个空的子元素，添加clear: both效果
- 使用伪元素after
  ```css
  .main::after {
    content: "";
    clear: both;
    display: block;
  }
  ``` 
- 使用BFC