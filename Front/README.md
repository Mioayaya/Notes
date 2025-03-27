# css 
- [中国传统颜色](https://www.zhongguose.com/#anyuzi)
- [生成相关配色](https://mycolor.space/?hex=%235EBFC2&sub=1)
- [生成渐变色](https://hypercolor.dev/)
- [获取随机图片](https://picsum.photos/)
- [Css可视化](https://css.bqrdh.com/button-animate)

# React

- [Emotion Css](https://emotion.sh/docs/introduction)
- [react-hot-toast](https://react-hot-toast.com/docs)
- [React-Spring 动画](https://react-spring.dev/)
- [Framer motion](https://www.framer.com/developers/) | [中文版](https://motion.framer.wiki/)
- [滚动](https://scrollrevealjs.org/guide/hello-world.html)

# 流程图
- [draw.io](https://app.diagrams.net/) 


# Node环境安装
- [Node官网下载](https://nodejs.org/en/download/)
- cmd `node -v` `npm -v` 查看版本
- 将npm全局包迁移到 自定义路径中  
  在node目录下，创建两个新文件夹 `node_cache` `node_global`  
  打开cmd输入  
  ```bash
  npm config set prefix "$\node_global"
  ```
  ```bash
  npm config set cache "$\node_cache"
  ```
- 设置环境变量   
  环境变量 -> 系统变量 -> 新建 `NODE_PATH` value: `$\node_global\node_modules` 
  用户变量 -> Path `$\npm` 修改为 `$\node_global`

ps: `npm config get prefix` 查看当前global路径